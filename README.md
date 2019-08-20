# gpiod

sudo apt-get install -y git-core

## for install first time

git clone https://github.com/gioexperience/gpiod.git'

```cd gpiod
chmod +x install.sh
```

#Now edit gpiod.ini

```sudo ./install.sh```


## for update from git-hub

```git reset --hard
git pull```

## before using, remember to setup pins in read and set pull-up (maybe in rc.local)

```sudo nano /etc/rc.local
gpio -g mode 4 in
gpio -g mode 4 up```

