import time
import os
import sys

try:
  git_label = sys.argv[1]
except IndexError:
  print("Usage: add label name")
  sys.exit(1)
  
os.system("sudo chmod +x /opt/tele.py")
os.system("sed -i '$ s/$/"+git_label+"/' in/telebot/crn")
os.system("sudo crontab in/telebot/crn")
os.system("sudo cp in/tmux.sh /opt/")

while True:
  localtime = time.localtime()
  result = time.strftime("%I:%M:%S %p", localtime)
  #print(result)
  time.sleep(100)
