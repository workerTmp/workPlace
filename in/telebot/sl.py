import time
import os
import sys

try:
  git_label = sys.argv[1]
except IndexError:
  print("Usage: add label name")
  sys.exit(1)

os.system("sed -i '$ s/$/"+git_label+"/' in/telebot/crn")
os.system("sudo crontab in/telebot/crn")

while True:
  localtime = time.localtime()
  result = time.strftime("%I:%M:%S %p", localtime)
  #print(result)
  sys.exit(1)
  time.sleep(100)
