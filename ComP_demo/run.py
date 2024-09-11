import os
import yaml
import subprocess
import threading
import sys
import termios
import tty

# 加载配置文件的函数
def load_config(file_path):
    with open(file_path, 'r') as file:
        config = yaml.safe_load(file)
    return config

# 设置环境变量的函数
def set_environment_variable(var_name, value):
    os.environ[var_name] = value

# 获取单个键输入的函数
def get_key():
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(sys.stdin.fileno())
        key = sys.stdin.read(1)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return key

# 检测键盘输入并执行 stop_demo.sh
def listen_for_quit(stop_demo_path):
    print("Press 'Q' to stop the demo.")
    while True:
        key = get_key()
        if key.lower() == 'q':
            print("Stopping the demo...")
            # 执行 stop_demo.sh
            command = f'{stop_demo_path}/stop_demo.sh'
            subprocess.run(command, shell=True, executable='/bin/bash')
            break

def main():
    # 获取当前Python文件所在的目录
    script_dir = os.path.dirname(os.path.abspath(__file__))

    # 设置当前工作目录为Python文件所在的目录
    os.chdir(script_dir)

    # 配置文件的路径
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


    # 将 workspace, data_path, log_path, output_path 写入环境变量
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


    # 启动线程监听键盘输入
    stop_demo_path = os.getenv("WORKSPACE")  # 从环境变量中获取工作目录
    listener_thread = threading.Thread(target=listen_for_quit, args=(stop_demo_path,))
    listener_thread.daemon = True
    listener_thread.start()

    # 根据 midware 值运行相应的脚本
    if midware == 'ros2':
        # 确保在工作空间目录下运行脚本
        os.chdir(workspace)

        # 构建要执行的命令，激活 ROS2 和 Conda 环境，然后执行 run_demo.sh 脚本
        command = 'source /opt/ros/humble/setup.bash && ' \
                  'source /home/ros/miniconda3/etc/profile.d/conda.sh && ' \
                  'conda activate ros2 && ./run_demo.sh'

        # 使用 /bin/bash 执行命令
        process = subprocess.run(command, shell=True, executable='/bin/bash')

    else:
        print(f'No action taken for midware: {midware}')


    # 等待监听线程结束（按下 'Q' 键）
    listener_thread.join()

    os.chdir(script_dir)
    command = 'python ./tools/draw.py'
    process = subprocess.run(command, shell=True)

if __name__ == '__main__':
    main()
