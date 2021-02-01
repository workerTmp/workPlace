#!/bin/sh
#export PROMPT_COMMAND="history -a;"
cd /tmp/works/
#sudo apt install iftop
#sudo apt install nmon
#tmux new-session -d
tmux split-window -v
tmux split-window -v 'sudo iftop'
tmux split-window -h 'export NMON=c&&nmon'
tmux split-window -h 'sudo /bin/sh /opt/RM.sh' 
tmux select-pane -t 0
tmux split-window -h
tmux select-pane -t 2
tmux split-window -h
