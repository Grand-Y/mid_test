import os
import yaml
import subprocess
import time
import signal
import shutil  # 用于递归删除目录

def load_config(file_path):
    with open(file_path, 'r') as file:
        config = yaml.safe_load(file)
    return config

def set_environment_variable(var_name, value):
    os.environ[var_name] = value

def main():
    # 获取当前Python文件所在的目录
    script_dir = os.path.dirname(os.path.abspath(__file__))

    # 设置当前工作目录为Python文件所在的目录
    os.chdir(script_dir)
    config_file = 'config.yaml'

    # 加载配置文件
    config = load_config(config_file)

    # 将所有参数读取到变量中
    midware = config.get('midware', '')
    workspace = config.get('workspace', '')
    data_path = config.get('data_path', '')
    log_path = config.get('log_path', '')
    output_path = config.get('output_path', '')
    model_path = config.get('model_path', '')

    # 设置环境变量
    set_environment_variable('WORKSPACE', workspace)
    set_environment_variable('DATA_PATH', data_path)
    set_environment_variable('LOG_PATH', log_path)
    set_environment_variable('OUTPUT_PATH', output_path)
    set_environment_variable('MODEL_PATH', model_path)

    # 打印环境变量以确认
    print(f'WORKSPACE: {os.getenv("WORKSPACE")}')
    print(f'DATA_PATH: {os.getenv("DATA_PATH")}')
    print(f'LOG_PATH: {os.getenv("LOG_PATH")}')
    print(f'OUTPUT_PATH: {os.getenv("OUTPUT_PATH")}')
    print(f'MODEL_PATH: {os.getenv("MODEL_PATH")}')

    # 标志路径
    flag_path = workspace + "/flag"
    print(f'Flag path: {flag_path}')

    # 根据 midware 运行相应的命令
    if midware == 'ros2':
        # 确保在工作空间目录下运行脚本
        os.chdir(workspace)
        
        if os.path.isfile(flag_path):
            os.remove(flag_path)  # 如果是文件，删除文件
        elif os.path.isdir(flag_path):
            shutil.rmtree(flag_path)  # 如果是目录，递归删除目录

        # 构建要执行的命令，激活 ROS2 和 Conda 环境，然后执行 run_demo.sh 脚本
        command = 'source /opt/ros/humble/setup.bash && ' \
                  'source /home/ros/miniconda3/etc/profile.d/conda.sh && ' \
                  'conda activate ros2 && ./run_demo.sh'

        # 使用 /bin/bash 执行命令
        process = subprocess.Popen(command, shell=True, executable='/bin/bash')

        # 检查标志路径是否存在
        try:
            while True:
                if os.path.exists(flag_path):
                    time.sleep(10)
                    print("Flag path detected. Terminating ROS2 process...")
                    process.send_signal(signal.SIGINT)   # 终止进程
                    process.wait()  # 等待进程完全终止
                    # 判断是文件还是目录并进行相应的删除
                    if os.path.isfile(flag_path):
                        os.remove(flag_path)  # 如果是文件，删除文件
                    elif os.path.isdir(flag_path):
                        shutil.rmtree(flag_path)  # 如果是目录，递归删除目录
                    break
                time.sleep(1)  # 每秒检查一次
        except KeyboardInterrupt:
            print("Process interrupted by user.")
            process.terminate()
            process.wait()
        
        os.chdir(script_dir)


    elif midware == 'cyber':
        # Cyber 部分逻辑
        command = 'cyber_launch start /apollo/cyber/a_mid_test/cyber/cyber_test.launch'
        process = subprocess.Popen(command, shell=True)

        try:
            while True:
                # 检查标志路径是否存在
                if os.path.exists(flag_path):
                    time.sleep(10)
                    print("Flag path detected. Terminating Cyber process...")
                    process.send_signal(signal.SIGINT)   # 终止进程
                    process.wait()  # 等待进程完全终止
                    os.remove(flag_path)
                    break
                time.sleep(1)  # 每秒检查一次
        except KeyboardInterrupt:
            print("Process interrupted by user.")
            process.terminate()
            process.wait()

    else:
        print(f'No action taken for midware: {midware}')

    # 调用 draw.py 脚本进行绘图
    command = 'python ./tools/draw.py'
    subprocess.run(command, shell=True)

if __name__ == '__main__':
    main()
