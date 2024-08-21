import os
import matplotlib.pyplot as plt

def read_merged_log(filename):
    logs = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            if len(parts) < 5:
                continue  # Skip invalid lines
            node_name = parts[0]
            topic = parts[1]
            msg_type = parts[2]  # 's' for receiver, 'p' for sender
            timestamp = float(parts[3])
            content = parts[4]
            logs.append((node_name, topic, msg_type, timestamp, content))
    return logs

def check_sequence_and_data(logs):
    topic_map = {}
    for log in logs:
        topic = log[1]
        if topic not in topic_map:
            topic_map[topic] = []
        topic_map[topic].append(log)

    delays = []
    for topic, topic_logs in topic_map.items():
        sent_messages = [log for log in topic_logs if log[2] == 'p']
        received_messages = [log for log in topic_logs if log[2] == 's']

        for received in received_messages:
            received_time = received[3]
            received_content = received[4]

            # Find the most recent sent message with the same topic
            relevant_sent_messages = [msg for msg in sent_messages if msg[3] <= received_time]
            if not relevant_sent_messages:
                print(f"No corresponding sent message found for received message at {received_time} with topic '{topic}'")
                return False

            closest_sent_message = max(relevant_sent_messages, key=lambda x: x[3])
            sent_time = closest_sent_message[3]
            sent_content = closest_sent_message[4]

            # Check if contents match
            if sent_content != received_content:
                print(f"Data inconsistency in topic '{topic}': sent '{sent_content}' but received '{received_content}'")
                return False

            # Calculate delay
            delay = received_time - sent_time
            delays.append(delay)

    print("All messages are in correct sequence and data is consistent")
    return True, delays

def calculate_metrics_and_delays(logs):
    topic_map = {}
    for log in logs:
        topic = log[1]
        if topic not in topic_map:
            topic_map[topic] = []
        topic_map[topic].append(log)

    overall_delays = []
    overall_time_intervals = []
    overall_throughputs = []
    topic_metrics = {}

    for topic, topic_logs in topic_map.items():
        sent_messages = [log for log in topic_logs if log[2] == 'p']
        received_messages = [log for log in topic_logs if log[2] == 's']

        delays = []
        for received in received_messages:
            received_time = received[3]
            received_content = received[4]

            # Find the most recent sent message with the same topic
            relevant_sent_messages = [msg for msg in sent_messages if msg[3] <= received_time]
            if not relevant_sent_messages:
                continue  # No corresponding sent message found

            closest_sent_message = max(relevant_sent_messages, key=lambda x: x[3])
            sent_time = closest_sent_message[3]
            delay = received_time - sent_time
            delays.append(delay)

        if not delays:
            raise ValueError(f"No matching sent and received messages found for delay calculation on topic {topic}")

        avg_delay = sum(delays) / len(delays)
        jitter = sum(abs(delays[i] - delays[i-1]) for i in range(1, len(delays))) / (len(delays) - 1)

        # Calculate throughput (data size) over time intervals
        time_intervals = []
        throughputs = []
        interval = 1  # 1 second interval
        start_time = topic_logs[0][3]
        end_time = topic_logs[-1][3]
        current_time = start_time

        while current_time < end_time:
            interval_sent_messages = [msg for msg in topic_logs if msg[3] >= current_time and msg[3] < current_time + interval]
            total_data_size = sum(len(msg[4]) for msg in interval_sent_messages)  # Sum of data sizes
            throughputs.append(total_data_size / interval)  # Data size per second
            time_intervals.append(current_time)
            current_time += interval

        topic_metrics[topic] = {
            "average_delay": avg_delay,
            "jitter": jitter,
            "delays": delays,
            "time_intervals": time_intervals,
            "throughputs": throughputs
        }

        overall_delays.extend(delays)
        overall_time_intervals.extend(time_intervals)
        overall_throughputs.extend(throughputs)

    overall_metrics = {
        "average_delay": sum(overall_delays) / len(overall_delays),
        "jitter": sum(abs(overall_delays[i] - overall_delays[i-1]) for i in range(1, len(overall_delays))) / (len(overall_delays) - 1),
        "delays": overall_delays,
        "time_intervals": overall_time_intervals,
        "throughputs": overall_throughputs
    }

    return overall_metrics, topic_metrics

def plot_metrics(delays, time_intervals, throughputs, delay_output_file='../img/delays.png', throughput_output_file='../img/throughput.png'):
    # Plot delays
    plt.figure(figsize=(10, 6))
    plt.plot(delays, linestyle='-', color='b')  # Only line, no markers
    plt.title('Message Transmission Delays')
    plt.xlabel('Message Index')
    plt.ylabel('Delay (seconds)')
    plt.grid(True)
    plt.savefig(delay_output_file)  # Save the figure to a file
    print(f"Delay plot saved as {delay_output_file}")

    # Plot throughput
    plt.figure(figsize=(10, 6))
    plt.plot(time_intervals, throughputs, linestyle='-', color='r')  # Only line, no markers
    plt.title('Message Throughput Over Time')
    plt.xlabel('Time (seconds)')
    plt.ylabel('Throughput (bytes/second)')
    plt.grid(True)
    plt.savefig(throughput_output_file)  # Save the figure to a file
    print(f"Throughput plot saved as {throughput_output_file}")

def main():
    log_file = '../log2/merge_log.txt'
    
    logs = read_merged_log(log_file)
    if check_sequence_and_data(logs):
        print("Time sequence and data correctness check passed")
    else:
        print("Time sequence and data correctness check failed")

    overall_metrics, topic_metrics = calculate_metrics_and_delays(logs)

    # Plot overall metrics
    plot_metrics(
        overall_metrics['delays'],
        overall_metrics['time_intervals'],
        overall_metrics['throughputs'],
        delay_output_file='../img/overall_delays.png',
        throughput_output_file='../img/overall_throughput.png'
    )

    # Plot topic-specific metrics
    for topic, metrics in topic_metrics.items():
        sanitized_topic = topic.replace('/', '_')
        delay_output_file = f'../img/{sanitized_topic}_delays.png'
        throughput_output_file = f'../img/{sanitized_topic}_throughput.png'
        plot_metrics(
            metrics['delays'],
            metrics['time_intervals'],
            metrics['throughputs'],
            delay_output_file=delay_output_file,
            throughput_output_file=throughput_output_file
        )

if __name__ == '__main__':
    main()
