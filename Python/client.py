#!/usr/bin/python           # Client.py file

import socket               

s = socket.socket()         
host = "localhost" 
port = 22226            

s.connect((host, port))
print s.recv(1024)
s.close                    

