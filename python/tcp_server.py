#!/usr/bin/env python
#coding=utf-8

from socket import *

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)

while 1:
	connectionSocket, clientAddress = serverSocket.accept()
	message = connectionSocket.recv(2048)
	modifiedMessage = message.upper()
	connectionSocket.send(modifiedMessage)
	connectionSocket.close()

