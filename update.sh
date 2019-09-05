#!/bin/bash

USER=$(whoami)

if [ "$USER" != "root" ]; then
	echo "Error. You have to use SUDO for install: sudo ./update.sh"
	exit 0
fi

git reset --hard
git pull
chmod +x ./install.sh
sudo ./install.sh

