grep '^deb ' /etc/apt/sources.list |  sed 's/^deb /deb-src /g' | sudo tee /etc/apt/sources.list.d/deb-src.list
sudo apt update  -y
