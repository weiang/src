#!/usr/bin/env python
#coding=utf-8

from socket import *

serverPort = 12000
serverName = "localhost"
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
message = raw_input("Input lowcase sentence")
clientSocket.send(message)
modifiedMessage = clientSocket.recv(2048)
print modifiedMessage
