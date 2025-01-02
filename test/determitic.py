import os

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

def check_sequence_and_data(sent_messages, received_messages):
    if len(sent_messages) != len(received_messages):
        print("Mismatch in the number of sent and received messages")
        return False

    for sent, received in zip(sent_messages, received_messages):
        sent_time = sent[2]
        received_time = received[2]
        sent_content = sent[3]
        received_content = received[3]

        # Check if the received message comes after the sent message
        if received_time < sent_time:
            print(f"Time sequence error: sent at {sent_time} but received at {received_time}")
            return False
        
        # Check if the message content matches
        if sent_content != received_content:
            print(f"Data error: sent '{sent_content}' but received '{received_content}'")
            return False

    print("All messages are in correct sequence and data is consistent")
    return True

def main():
    sent_messages = read_messages('../log/DINGZHEN_1.txt')
    received_messages = read_messages('../log/DINGZHEN_2.txt')

    if check_sequence_and_data(sent_messages, received_messages):
        print("Time sequence and data correctness check passed")
    else:
        print("Time sequence and data correctness check failed")

if __name__ == '__main__':
    main()
