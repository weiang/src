# import socket module

from socket import *

serverSocket = socket(AF_INET, SOCK_STREAM)
# Prepare a server socket

serverPort = 6789
serverName = 'localhost'
serverSocket.bind((serverName, serverPort))
serverSocket.listen(1)

responseHeader = 'HTTP/1.1 200 OK\nConnection: close\n'
while True:
	# Establish the connection
	print('Ready to serve...')
	
	connectionSocket, clientAddr = serverSocket.accept()

	try:
		message = connectionSocket.recv(2048)
		filename = message.split()[1]
		f = open(filename[1:])
		outputdata = f.read()
		# print(outputdata)		
		# Send one HTTP header line into socket
		connectionSocket.send(responseHeader)

		# Send the content of the requested file to the client
		for i in range(0, len(outputdata)):
			connectionSocket.send(outputdata[i])
		connectionSocket.close()
	except IOError:
		# Send response message for file not found
		connectionSocket.send("404 Not Found\n")
				
		# Close client socket
		connectionSocket.close()
	
serverSocket.close()
