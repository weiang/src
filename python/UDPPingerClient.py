from socket import *
import time	

serverName = "localhost"
serverPort = 12000

clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1.0)
timeOut = "Request timed out"

packetLoss = 0
totalRTT = 0.0
maxRTT = 0.0
minRTT = 1.0
for i in range(1, 11):
	pingMessage = 'Ping ' + str(i) + ' ' + time.asctime()
	sendTime = time.time()
	clientSocket.sendto(pingMessage, (serverName, serverPort))
	try:
		message, serverAddr = clientSocket.recvfrom(1024)
		endTime = time.time()
#		timestr = message[2].split(',')[0]
#		ftr = [3600, 60, 1]
#		sendTime = sum([a * b for a,b in zip(ftr, map(int, timestr.split(':'))))])
		responseTime = endTime - sendTime
		if responseTime > maxRTT:
			maxRTT = responseTime
		if responseTime < minRTT:
			minRTT = responseTime
		totalRTT += responseTime
		print(message, responseTime)
		
	except timeout: 
		packetLoss = packetLoss + 1
		print(timeOut)
		

print "Packet Loss rate: ", packetLoss / 10.0
print "Maximum RTT: ", maxRTT
print "Minimun RTT: ", minRTT
print "Average RTT: ", totalRTT / (10 - packetLoss)
