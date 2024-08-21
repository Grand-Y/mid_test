import os
import yaml
import subprocess
import time
import signal

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

    # 将 data_path, log_path, output_path 写入环境变量
    set_environment_variable('WORKSPACE', workspace)
    set_environment_variable('DATA_PATH', data_path)
    set_environment_variable('LOG_PATH', log_path)
    set_environment_variable('OUTPUT_PATH', output_path)

    # 打印环境变量以确认
    print(f'WORKSPACE: {os.getenv("WORKSPACE")}')
    print(f'DATA_PATH: {os.getenv("DATA_PATH")}')
    print(f'LOG_PATH: {os.getenv("LOG_PATH")}')
    print(f'OUTPUT_PATH: {os.getenv("OUTPUT_PATH")}')

    flag_path = workspace + "/flag"
    print(flag_path)

    # 根据 midware 运行相应的命令
    if midware == 'cyber':
        command = 'cyber_launch start /apollo/cyber/a_mid_test/cyber/cyber_test.launch'
        process = subprocess.Popen(command, shell=True)
        try:
            while True:
                if os.path.exists(flag_path):
                    time.sleep(10)
                    print("Flag file detected. Terminating process...")
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

    command = 'python ./tools/draw.py'
    process = subprocess.run(command, shell=True)

if __name__ == '__main__':
    main()
