U=http://ddebs.ubuntu.com
D=$(lsb_release -cs)
cat <<EOF | sudo tee /etc/apt/sources.list.d/ddebs.list
deb ${U} ${D} main restricted universe multiverse
#deb ${U} ${D}-security main restricted universe multiverse
deb ${U} ${D}-updates main restricted universe multiverse
deb ${U} ${D}-proposed main restricted universe multiverse
EOF
