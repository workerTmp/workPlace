#!/bin/sh
sudo apt install iftop
sudo apt install nmon
tmux new-session -d
tmux split-window -v
tmux split-window -v 'sudo iftop'
tmux split-window -h 'export NMON=c&&nmon'
[ -f "/opt/RM.sh" ] || tmux split-window -h 'sh /opt/RM.sh' 
#tmux new-window 'sudo top'
tmux -2 attach-session -d
