# gpiod

sudo apt-get install -y git-core
git clone https://github.com/gioexperience/gpiod.git

cd gpiod
chmod +x install.sh

#Now edit gpiod.ini


sudo ./install.sh




#before using, remember to setup pins in read and set up pull-up or pull-down
#maybe in rc.local?

example

gpio -g mode 4 in
gpio -g mode 4 up
