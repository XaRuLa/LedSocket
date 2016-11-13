#!/usr/bin/python

import socket
import RPi.GPIO as GPIO
import time

s = socket.socket()
host = 'localhost'
port = 22226
s.bind((host,port))

s.listen(5)
while True:
	c, addr = s.accept()
	print 'Get connection from :', addr
	GPIO.setmode(GPIO.BCM)
	GPIO.setwarnings(False)
	GPIO.setup(17,GPIO.OUT)
	print "Lights On"
	GPIO.output(17,GPIO.HIGH)
	time.sleep(7)
	c.send('WelcomeToServer')

	print"Light Off"
	GPIO.output(17,GPIO.LOW)
	
	
	c.shutdown(0)
	c.close

