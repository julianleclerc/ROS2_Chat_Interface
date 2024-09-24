from setuptools import find_packages, setup

package_name = 'chat_service'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'openai', 'rclpy',],
    zip_safe=True,
    maintainer='fyier',
    maintainer_email='fyier@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'chat_service_node = chat_service.chat_service_node:main',
        ],
    },
)
