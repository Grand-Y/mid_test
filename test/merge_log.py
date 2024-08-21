import os
import glob

def read_logs(directory):
    logs = []
    log_files = glob.glob(os.path.join(directory, '*.txt'))
    
    for log_file in log_files:
        with open(log_file, 'r') as file:
            for line in file:
                parts = line.strip().split(',')
                if len(parts) < 5:
                    continue  # Skip invalid lines
                node_name = parts[0]
                topic = parts[1]
                ps = parts[2]
                timestamp = parts[3]
                content = parts[4]
                logs.append((node_name, topic, ps, timestamp, content))
    
    return logs

def write_sorted_logs(logs, output_file):
    logs.sort(key=lambda x: x[3])  # Sort by timestamp
    
    with open(output_file, 'w') as file:
        for log in logs:
            file.write(','.join([log[0], log[1], log[2], log[3], log[4]]) + '\n')

def main():
    log_directory = '../log2'
    output_file = '../log2/merge_log.txt'
    
    logs = read_logs(log_directory)
    write_sorted_logs(logs, output_file)
    print(f"Logs have been merged and sorted by timestamp into {output_file}")

if __name__ == '__main__':
    main()
