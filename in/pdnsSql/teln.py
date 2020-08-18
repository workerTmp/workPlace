import telnetlib

host = "127.0.0.1"
port = 5300
timeout = 10

with telnetlib.Telnet(host, port, timeout) as session:
    session.write(b"00")
    for i in range(0x3030):
        session.write(b"p")
