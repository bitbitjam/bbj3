sudo apt-get update

# personal dependencies
sudo apt-get install -y git

# If `make build-dep` hangs installing g++
# you can try installing g++ separately first.
# but it doesn't seem to be necessary all the time.
#sudo apt-get install -y g++
cd /vagrant/gbdk
sudo make build-dep
sudo make install

#make lcc available in the shell
sudo ln -s /opt/gbdk/bin/lcc /usr/local/bin/lcc

# YCM dependencies
sudo apt-get install -y build-essential cmake python-dev python3-dev

# YCM-Generator dependencies
sudo apt-get install -y clang
