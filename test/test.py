import os
import matplotlib.pyplot as plt

def read_messages(filename):
    messages = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(',')
            if len(parts) == 1: continue
            node_name = parts[0]
            topic = parts[1]
            timestamp = float(parts[2])
            content = parts[3]
            messages.append((node_name, topic, timestamp, content))
    return messages

def calculate_metrics_and_delays(sent_messages, received_messages):
    if len(sent_messages) != len(received_messages):
        raise ValueError("The number of sent and received messages does not match")

    delays = []
    for sent, received in zip(sent_messages, received_messages):
        sent_time = sent[2]
        received_time = received[2]
        delay = received_time - sent_time
        delays.append(delay)

    avg_delay = sum(delays) / len(delays)
    throughput = len(sent_messages) / (sent_messages[-1][2] - sent_messages[0][2])
    jitter = sum(abs(delays[i] - delays[i-1]) for i in range(1, len(delays))) / (len(delays) - 1)

    # Calculate throughput over time intervals
    time_intervals = []
    throughputs = []
    interval = 1  # 1 second interval
    start_time = sent_messages[0][2]
    end_time = sent_messages[-1][2]
    current_time = start_time

    while current_time < end_time:
        interval_sent_messages = [msg for msg in sent_messages if current_time <= msg[2] < current_time + interval]
        throughputs.append(len(interval_sent_messages) / interval)
        time_intervals.append(current_time)
        current_time += interval

    return {
        "average_delay": avg_delay,
        "throughput": throughput,
        "jitter": jitter,
        "delays": delays,
        "time_intervals": time_intervals,
        "throughputs": throughputs
    }

def plot_metrics(delays, time_intervals, throughputs, delay_output_file='../img/delays.png', throughput_output_file='../img/throughput.png'):
    # Plot delays
    plt.figure(figsize=(10, 6))
    plt.plot(delays, linestyle='-', color='b', marker='None')
    plt.title('Message Transmission Delays')
    plt.xlabel('Message Index')
    plt.ylabel('Delay (seconds)')
    plt.grid(True)
    plt.savefig(delay_output_file)  # Save the figure to a file
    print(f"Delay plot saved as {delay_output_file}")

    # Plot throughput
    plt.figure(figsize=(10, 6))
    plt.plot(time_intervals, throughputs, linestyle='-', color='r', marker='None')
    plt.title('Message Throughput Over Time')
    plt.xlabel('Time (seconds)')
    plt.ylabel('Throughput (messages/second)')
    plt.grid(True)
    plt.savefig(throughput_output_file)  # Save the figure to a file
    print(f"Throughput plot saved as {throughput_output_file}")

def main():
    sent_messages = read_messages('../log/DINGZHEN_1.txt')
    received_messages = read_messages('../log/DINGZHEN_2.txt')

    metrics = calculate_metrics_and_delays(sent_messages, received_messages)
    print(f"Average Delay: {metrics['average_delay']:.6f} seconds")
    print(f"Throughput: {metrics['throughput']:.6f} messages/second")
    print(f"Jitter: {metrics['jitter']:.6f} seconds")

    # Plot the delays
    plot_metrics(metrics['delays'], metrics['time_intervals'], metrics['throughputs'])

if __name__ == '__main__':
    main()
