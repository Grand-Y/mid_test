import os
import numpy as np
import matplotlib.pyplot as plt

def plot_logs():
    log_dir = './logs'
    img_dir = './img'
    
    # 创建 img 目录如果不存在
    os.makedirs(img_dir, exist_ok=True)

    if not os.path.exists(log_dir):
        print(f"Directory {log_dir} does not exist.")
        return

    for filename in os.listdir(log_dir):
        file_path = os.path.join(log_dir, filename)

        # 检查文件是否是普通文件（没有后缀）
        if os.path.isfile(file_path):
            try:
                data = np.loadtxt(file_path)
                print(f"Data from {filename}: {data[:5]}...")  # 打印前5个数据点
            except Exception as e:
                print(f"Error reading {file_path}: {e}")
                continue

            # 将数据从纳秒转换为毫秒
            data_ms = data / 1e6

            # 计算统计数据
            mean_value = np.mean(data_ms)
            min_value = np.min(data_ms)
            max_value = np.max(data_ms)
            std_dev = np.std(data_ms)
            median_value = np.median(data_ms)
            perc_90 = np.percentile(data_ms, 90)
            perc_95 = np.percentile(data_ms, 95)
            perc_99 = np.percentile(data_ms, 99)

            # 创建图表
            plt.figure(figsize=(10, 6))
            plt.plot(data_ms, marker='o', linestyle='-')
            plt.title(f'Log File: {filename}')
            plt.xlabel('Line Number')
            plt.ylabel('Value (ms)')

            # 标注统计数据
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

            # plt.text(0.02, 0.95, titles_text, transform=plt.gca().transAxes, fontsize=10, verticalalignment='top')
            # plt.text(0.15, 0.95, values_text, transform=plt.gca().transAxes, fontsize=10, verticalalignment='top')
            plt.annotate(titles_text, xy=(1.05, 1), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
            plt.annotate(values_text, xy=(1.2, 1), xycoords='axes fraction', verticalalignment='top', bbox=dict(facecolor='white', alpha=0.0))
   

            # 保存图表到 img 目录
            try:
                plt.tight_layout()
                plt.savefig(os.path.join(img_dir, f'{filename}_plot.png'))
                plt.close()
                print(f"Saved plot for {filename}")
            except Exception as e:
                print(f"Error saving plot for {filename}: {e}")

if __name__ == '__main__':
    plot_logs()