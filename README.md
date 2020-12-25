# wiringPi for H3
***
**Description: This project is a package of wiringPi which repair some initialized function. Extend examples on board orange pi one which using allwinner H3 CPU is contained as well.**

***

#### Test Environment:

+ CPU: Allwinner H3 with Quard Core Cortex-A7 1.2GHz
+ Memory: 256MB DDR3 * 2
+ Operating System: Ubuntu16.04.7 LTS
+ Linux Version: 5.3.5
+ TF Card: Sandisk 16GB Class10
+ ROS Version: Kinetic 1.12.16

***
#### Directory

+ clash: clash client for armv7 with Country.mmdb
+ examples: hardware (oled, gpio, pcf8591, serial, pwm, mcp2515) examples
+ wiringOP: repaired wiringPi Library

***

#### Install 

 run configure script  as below:

```bash
$cd wiringPi-for-H3
$sudo chmod +x config.sh
$sudo ./config.sh
#choose item 5 as it poop out
```

It'll download other components automatically so you don't need to clone this on your board.

After that, you'll be able to use wiringPi command such as:

```bash
$gpio readall					#return gpio function table
$sudo i2cdetect -y 0			#get devices which mount on /dev/i2c-0

#or you can enable read/write permission:
#$sudo chmod 777 /dev/i2c-0
#$i2cdetect -y 0
```

Also, it'll expand rootfs space and create 2GB of swap area mounted on /swapfile
Run ros_install script as below:

```bash
$cd wiringPi-for-H3
$sudo chmod +x ros_install.sh
$sudo ./ros_install.sh

#after script have finished, run "rosdep update" manually!!!
```

Then reboot, you can run ros command now.

***
#### How to use clash client to setup VPN:

1. configure proxy in global environment:

```bash
$sudo echo "export http_proxy=http://127.0.0.1:7890/" >> ~/.bashrc
$sudo echo "export https_proxy=http://127.0.0.1:7890/" >> ~/.bashrc
```

2. Download file
 + Download clash configure file operator provided you to "clash" directory
 + Reboot your device

3. Run and Configure
 + Enter the "clash" directory using "cd" command
 + Run clash client: <br>

```bash
$sudo chmod +x clash && ./clash -d . 
```

 + If you want the app to run in the background, install screen first and run:<br>

```bash
$screen -dmS clash ./clash -d .
```

 + Now you can configure it on website: http://clash.razord.top/#/proxies

