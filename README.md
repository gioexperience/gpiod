# gpiod

```sudo apt-get install -y git-core```

## for install first time

```
cd ~
git clone https://github.com/gioexperience/gpiod.git'
cd gpiod
chmod +x install.sh
```

Now edit gpiod.ini

```
sudo nano ~/gpiod/source/gpiod.ini
```

Now install

```
sudo ~/gpiod/install.sh
```


## for update from git-hub

```
cd ~/gpiod
git reset --hard
git pull
chmod +x ~/gpiod/install.sh
sudo ~/gpiod/install.sh
```

## for retrieve your old ini for re-installing

```
cp /etc/gpiod.ini ~/gpiod/source
```
Now you can re-install

## before using, remember to setup pins in read and set pull-up (maybe in rc.local)

```sudo nano /etc/rc.local
gpio -g mode 4 in
gpio -g mode 4 up```

