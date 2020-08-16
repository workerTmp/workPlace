#!/bin/sh
sudo apt install iftop
sudo apt install nmon
tmux new-session -d
tmux split-window -v
tmux split-window -v 'export NMON=c&&nmon'
tmux split-window -h 'sudo iftop'
#tmux new-window 'sudo top'
tmux -2 attach-session -d
