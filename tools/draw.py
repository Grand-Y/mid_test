import os
import numpy as np
import matplotlib.pyplot as plt

# 日志目录和输出目录
log_dir = os.getenv("LOG_PATH")
output_dir = os.getenv("OUTPUT_PATH")

# 确保输出目录存在
os.makedirs(output_dir, exist_ok=True)

# 处理 cal 开头的文件
def process_cal_file(file_path, file_name):
    data = np.loadtxt(file_path) / 1e6  # 纳秒转毫秒
    plt.figure(figsize=(10, 6))
    plt.plot(data)
    plt.title(file_name)
    plt.xlabel('Index')
    plt.ylabel('Time (ms)')
    
    # 计算统计指标
    mean_value = np.mean(data)
    min_value = np.min(data)
    max_value = np.max(data)
    std_dev = np.std(data)
    median_value = np.median(data)
    perc_90 = np.percentile(data, 90)
    perc_95 = np.percentile(data, 95)
    perc_99 = np.percentile(data, 99)
    
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
        f'{max_value:0.6f} ms\n'
        f'{std_dev:0.6f} ms\n'
        f'{median_value:0.6f} ms\n'
        f'{perc_90:0.6f} ms\n'
        f'{perc_95:0.6f} ms\n'
        f'{perc_99:0.6f} ms'
    )
    
    # 在图像框右侧增加数据指标
    plt.annotate(titles_text, xy=(1.05, 1), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
    plt.annotate(values_text, xy=(1.2, 1), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
   
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, f'{file_name}.png'))
    plt.close()

# 处理 tra 开头的文件
def process_tra_files(file_paths, base_name):
    plt.figure(figsize=(10, 6))
    
    n = 0
    for file_path in file_paths:
        data = np.loadtxt(file_path) / 1e6  # 纳秒转毫秒
        plt.plot(data, label=os.path.basename(file_path))
        
        # 计算统计指标
        mean_value = np.mean(data)
        min_value = np.min(data)
        max_value = np.max(data)
        std_dev = np.std(data)
        median_value = np.median(data)
        perc_90 = np.percentile(data, 90)
        perc_95 = np.percentile(data, 95)
        perc_99 = np.percentile(data, 99)
        
        name = file_path.split('/')[-1]
        titles_text = (
            f'{name}:\n'
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
            f'\n'
            f'{mean_value:0.6f} ms\n'
            f'{min_value:0.6f} ms\n'
            f'{max_value:0.6f} ms\n'
            f'{std_dev:0.6f} ms\n'
            f'{median_value:0.6f} ms\n'
            f'{perc_90:0.6f} ms\n'
            f'{perc_95:0.6f} ms\n'
            f'{perc_99:0.6f} ms'
        )
        # 在图像框右侧增加数据指标
        plt.annotate(titles_text, xy=(1.05, 1 + 2 * n), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
        plt.annotate(values_text, xy=(1.2, 1 + 2 * n), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
        n -= 0.16

    plt.title(base_name)
    plt.xlabel('Index')
    plt.ylabel('Time (ms)')
    plt.legend()
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, f'{base_name}.png'))
    plt.close()

# 遍历日志目录
for root, dirs, files in os.walk(log_dir):
    tra_files = {}
    
    for file in files:
        if file.startswith('cal_'):
            process_cal_file(os.path.join(root, file), file)
        elif file.startswith('tra_'):
            base_name = file.split('_')[1]
            if base_name not in tra_files:
                tra_files[base_name] = []
            tra_files[base_name].append(os.path.join(root, file))
    
    for base_name, file_paths in tra_files.items():
        process_tra_files(file_paths, base_name)
