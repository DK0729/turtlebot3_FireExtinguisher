from setuptools import find_packages, setup

package_name = 'fire_detect'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'sensor_msgs','turtlebot_interfaces'],
    zip_safe=True,
    maintainer='kyungmin',
    maintainer_email='kyungmin@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'fire_detector = fire_detect.detector_node:main',
            'sub_test = fire_detect.sub_test:main',
        ],
    },
)
