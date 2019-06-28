#!/bin/bash

USER=$(whoami)

if [ "$USER" != "root" ]; then
	echo "Error. You have to use SUDO for install: sudo ./install.sh"
	exit 0
fi

apt-get install wiringpi php -y

cp ./source/gpiod.ini /etc/gpiod.ini

echo "Compiling gpio_btn.c..."
gcc ./source/gpio_btn.c -o /usr/local/bin/gpio_btn -lwiringPi

echo "installing gpiod..."
cp ./source/gpiod /usr/local/bin/gpiod
chmod +x /usr/local/bin/gpiod

echo "Finish\n\n"
