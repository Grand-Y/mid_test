from setuptools import find_packages
from setuptools import setup

setup(
    name='comp_topic_rclcpp',
    version='0.0.0',
    packages=find_packages(
        include=('comp_topic_rclcpp', 'comp_topic_rclcpp.*')),
)
