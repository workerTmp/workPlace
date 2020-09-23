import time
import os
import sys

try:
  git_label = sys.argv[1]
except IndexError:
  print("Usage: add label name")
  sys.exit(1)
  
os.system("sudo chmod +x /opt/tele.py")
os.system("sudo python3 /opt/tele.py "+git_label+" &")
os.system("sed -i '$ s/$/"+git_label+"/' in/telebot/crn")
os.system("sudo crontab in/telebot/crn")
#os.system("sudo cp in/tmux.sh /opt/")
os.system("sudo pkill -f http-server")
os.system("sudo http-server /opt/docs/&")
os.system("sudo sh /opt/sshloc.sh")
while True:
  localtime = time.localtime()
  result = time.strftime("%I:%M:%S %p", localtime)
  #print(result)
  time.sleep(100)
