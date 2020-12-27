#!/bin/sh
cd /opt/
sudo apt install iftop
sudo apt install nmon
tmux new-session -d
tmux split-window -v
tmux split-window -v 'sudo iftop'
tmux split-window -h 'export NMON=c&&nmon'
tmux split-window -h 'sudo /bin/sh /opt/RM.sh' 
