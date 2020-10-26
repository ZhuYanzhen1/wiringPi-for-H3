#!/bin/sh

if [ "$(id -u)" -ne "0" ]; then
	echo "This script requires root."
	exit 1
fi

DEVICE="/dev/mmcblk0"

PART="2"

echo "Resizing Disk, Please Wait..."

resize() {
	start=$(fdisk -l ${DEVICE}|grep ${DEVICE}p${PART}|awk '{print $2}')
	echo $start

	set +e
	fdisk ${DEVICE} <<EOF
p
d
2
n
p
2
$start

w
EOF
	partx -u ${DEVICE}
	resize2fs ${DEVICE}p${PART}
}

resize 1>/tmp/resize_rootfs.log 2>&1

echo "Resize Disk Done!"
echo "Changing Sources, Please Wait..."
sudo tee /etc/apt/sources.list <<-'EOF'
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial main restricted universe multiverse
#deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-updates main restricted universe multiverse
#deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-backports main restricted universe multiverse
#deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-security main restricted universe multiverse
EOF
sudo apt-get clean
cd /var/lib/apt
sudo mv lists lists.old
sudo mkdir -p lists/partial
sudo apt-get clean
sudo apt update
sudo apt -y upgrade --fix-missing
sudo apt-get install -y htop git i2c-tools screen
echo "Change Sources Success!"
echo "Creating Swap Area, Please Wait..."
free -h
sudo fallocate -l 2G /swapfile
ls -lh /swapfile
sudo chmod 600 /swapfile
ls -lh /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
sudo swapon --show
free -h
sudo cp /etc/fstab /etc/fstab.bak
echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
echo "Swap Area Create Success!"
echo "Installing wirinPi, Please Wait..."
cd wiringOP
sudo chmod +x build
sudo ./build
cd ..
echo "Install Success!!!"
