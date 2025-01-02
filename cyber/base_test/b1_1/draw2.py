import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import font_manager



size_s = "KB"

def size_to_number(size_str):
    if size_str.endswith(('K', 'k')):
        return int(size_str[:-1]) * 1_000
    elif size_str.endswith(('M', 'm')):
        return int(size_str[:-1]) * 1_000_000
    else:
        return int(size_str)

def format_label(label):
    return label.replace('k', 'K').replace('m', 'M')

def plot_logs():
    log_dir = './logs/k'
    
    if not os.path.exists(log_dir):
        print(f"Directory {log_dir} does not exist.")
        return

    files = [f for f in os.listdir(log_dir) if os.path.isfile(os.path.join(log_dir, f))]
    
    data_list = []

    for filename in files:
        file_path = os.path.join(log_dir, filename)
        
        try:
            data = np.loadtxt(file_path)
            if data.size == 0:
                print(f"File {file_path} is empty.")
                continue
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
            continue

        data_ms = data / 1_000_000

        mean_value = np.mean(data_ms)
        perc_90 = np.percentile(data_ms, 90)
        std_dev = np.std(data_ms)
        
        # 计算变异系数
        cv = std_dev / mean_value if mean_value != 0 else 0

        parts = filename.split('-')
        if len(parts) < 2:
            print(f"Filename {filename} does not match expected format.")
            continue
        label = format_label(parts[1] + parts[0])

        data_list.append((label, mean_value, perc_90, cv))

    if not data_list:
        print("No valid data found.")
        return

    data_list.sort(key=lambda x: size_to_number(x[0]))

    labels, averages, percentiles_90, cvs = zip(*data_list)

    x = np.arange(len(labels))

    fig, ax1 = plt.subplots(figsize=(8, 6))

    font_path = '/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc'
    font_prop = font_manager.FontProperties(fname=font_path)
    plt.rcParams['font.family'] = font_prop.get_name()

    # 左侧 y 轴：平均值和 90 分位数
    ax1.bar(x - 0.1, averages, width=0.2, label='Latency (ms)', color='skyblue', align='center')
    ax1.bar(x + 0.1, percentiles_90, width=0.2, label='90th百分数 (ms)', color='salmon', align='center')
    ax1.set_xlabel('数据大小', fontproperties=font_prop)
    ax1.set_ylabel('延迟 (ms)', fontproperties=font_prop)
    ax1.set_title(size_s)
    ax1.set_xticks(x)
    ax1.set_xticklabels(labels)
    ax1.legend(loc='upper left')

    # 右侧 y 轴：变异系数
    ax2 = ax1.twinx()
    ax2.plot(x, cvs, label='变异系数', color='purple', marker='o', linestyle='--')
    ax2.set_ylabel('变异系数')
    ax2.legend(loc='upper right')

    # 调整布局
    fig.tight_layout()

    # 保存图像
    plt.savefig('./plot_with_cv.png')
    plt.close()
    print("Plot saved as plot_with_cv.png")

if __name__ == '__main__':
    plot_logs()