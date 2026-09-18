from setuptools import find_packages
from setuptools import setup

setup(
    name='turtlebot_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('turtlebot_interfaces', 'turtlebot_interfaces.*')),
)
