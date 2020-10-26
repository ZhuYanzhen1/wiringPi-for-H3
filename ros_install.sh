#!/bin/sh
if [ "$(id -u)" -ne "0" ]; then
	echo "This script requires root."
	exit 1
fi
sudo apt-get update
sudo apt-get -y upgrade
sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.ustc.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
sudo apt-get update
sudo apt-get install -y ros-kinetic-ros-base
sudo apt-get install -y ros-kinetic-ros-base --fix-missing
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
source /opt/ros/kinetic/setup.bash
sudo apt install -y python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
sudo echo "151.101.0.133 raw.githubusercontent.com" >> /etc/hosts
sudo rosdep init
echo "Now Run Command: rosdep update"
