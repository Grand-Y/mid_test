import os
import matplotlib.pyplot as plt
import numpy as np

LOG_DIR = '/apollo/cyber/a_mid_test/cyber/logs'
OUTPUT_DIR = '/apollo/cyber/a_mid_test/cyber/output'
COLORS = ['#A90900', '#A34E00', '#A87E00', '#76A300', '#009936', '#01A49D', '#0064A3', '#0008A3', '#6300A3', '#9600A3', '#A30176']

def read_data(file_path):
    """读取文件中的数据"""
    with open(file_path, 'r') as file:
        data = [float(line.strip()) / 1e6 for line in file]
    return data

def trim_data(data):
    """去除前后各 3% 的数据"""
    n = len(data)
    trim_size = int(n * 0.03)
    trimmed_data = data[trim_size:n - trim_size]
    return trimmed_data

def plot_data(data, title, save_path, color):
    """绘制折线图"""
    data = trim_data(data)
    x = np.arange(len(data))
    
    plt.subplots(figsize=(10, 6))
    plt.plot(x, data, linestyle='-', marker=None, color=color)
    plt.xlabel('Transmission')
    plt.ylabel('Value (ms)')
    plt.title(title)

    mean_value = np.mean(data)
    perc_90 = np.percentile(data, 90)
    perc_95 = np.percentile(data, 95)
    perc_99 = np.percentile(data, 99)
    min_value = np.min(data)
    max_value = np.max(data)
    std_dev = np.std(data)
    median_value = np.median(data)

    titles_text = (
        f'Average:\n'
        f'Min:\n'
        f'Max:\n'
        f'Std Dev:\n'
        f'Median:\n'
        f'90%:\n'
        f'95%:\n'
        f'99%:'
    )

    values_text = (
        f'{mean_value:0.6f} ms\n'
        f'{min_value:0.6f} ms\n'
        f'{max_value:02.6f} ms\n'
        f'{std_dev:0.6f} ms\n'
        f'{median_value:0.6f} ms\n'
        f'{perc_90:0.6f} ms\n'
        f'{perc_95:0.6f} ms\n'
        f'{perc_99:0.6f} ms'
    )

    plt.annotate(titles_text, xy=(1.05, 1), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
    plt.annotate(values_text, xy=(1.15, 1), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))

    plt.tight_layout()
    plt.savefig(save_path)
    plt.close()

def plot_combined_data(group_data, prefix, save_path, name_colors):
    """绘制组合图表"""
    plt.subplots(figsize=(10, 6))

    for file_path, data in group_data.items():
        data = trim_data(data)
        name = os.path.basename(file_path).split('_')[1]
        color = name_colors[name]
        x = np.arange(len(data))
        plt.plot(x, data, linestyle='-', marker=None, color=color, label=os.path.basename(file_path))

    plt.xlabel('Transmission')
    plt.ylabel('Value (ms)')
    plt.title(f'{prefix} Combined')
    plt.legend(loc='upper right', bbox_to_anchor=(1.3, 1))

    mean_values = {file_path: np.mean(trim_data(data)) for file_path, data in group_data.items()}
    
    # 显示平均值在图像框右侧
    mean_text = '\n'.join([f'{os.path.basename(file_path)}: {mean:.6f} ms' for file_path, mean in mean_values.items()])

    plt.annotate(mean_text, xy=(1.05, 0.5), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))

    plt.tight_layout()
    plt.savefig(save_path)
    plt.close()

def main():
    # 创建输出目录
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)
    
    # 读取日志目录下的所有文件
    all_files = [os.path.join(LOG_DIR, f) for f in os.listdir(LOG_DIR) if os.path.isfile(os.path.join(LOG_DIR, f))]
    
    # 分组文件按前缀
    prefix_groups = {}
    name_colors = {}

    for file_path in all_files:
        prefix, name, num = os.path.basename(file_path).split('_')
        if prefix not in prefix_groups:
            prefix_groups[prefix] = {}
        prefix_groups[prefix][file_path] = read_data(file_path)

    # 为每个文件名分配颜色
    unique_names = sorted({os.path.basename(file_path).split('_')[1] for file_path in all_files})
    num_names = len(unique_names)
    step = len(COLORS) // num_names

    for i, name in enumerate(unique_names):
        name_colors[name] = COLORS[i * step]

    # 为每个文件单独绘制图表
    for file_path in all_files:
        data = read_data(file_path)
        prefix, name, num = os.path.basename(file_path).split('_')
        color = name_colors[name]
        save_path = os.path.join(OUTPUT_DIR, f'{prefix}_{name}_{num}.png')
        plot_data(data, f'{prefix}_{name}_{num}', save_path, color)
    
    # 为每个前缀分组的文件整合绘制图表
    for prefix, group_data in prefix_groups.items():
        save_path = os.path.join(OUTPUT_DIR, f'{prefix}_combined.png')
        plot_combined_data(group_data, prefix, save_path, name_colors)

if __name__ == "__main__":
    main()
