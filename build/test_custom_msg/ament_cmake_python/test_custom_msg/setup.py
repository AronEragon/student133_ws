from setuptools import find_packages
from setuptools import setup

setup(
    name='test_custom_msg',
    version='0.0.0',
    packages=find_packages(
        include=('test_custom_msg', 'test_custom_msg.*')),
)
