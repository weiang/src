from socket import *

msg = "\r\n I love computer networks!"
endmsg = "\r\n.\r\n"
mailServer = raw_input('Please enter mail server name:') 
mailPort = 25

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailServer, mailPort))

recv = clientSocket.recv(1024)
print recv
if recv[:3] != '220':
	print '220 reply not received from server.'

# Send HELO command and print server response.
heloCommand = 'HELO localhost\r\n'
clientSocket.send(heloCommand)
recv1 = clientSocket.recv(1024)
print recv1
if recv1[:3] != '250':
	print '250 reply not received from server.'

# Send MAIL FROM command and print server response.
fromAddress = raw_input('Please enter from mail address: ')
mailFromCommand = 'MAIL FROM: <' + fromAddress + '>'
clientSocket.send(mailFromCommand)
recv2 = clientSocket.recv(1024)
print recv2
if recv2[:3] != '250':
	print '250 reply not received from server.'

toAddress = raw_input('Please enter to mail address: ')
recpToCommand = 'RCPT TO: <' + toAddress +'>'
clientSocket.send(recpToCommand)
recv3 = clientSocket.recv(1024)
print recv3
if recv3[:3] != '250':
	print '250 reply not received from server.'

dataCommand = 'DATA'
clientSocket.send(dataCommand)
recv4 = clientSocket.recv(1024)
print recv4
if recv4[:3] != '354':
	print '354 reply not received from server.'

# Send message
clientSocket.send(msg)
clientSocket.send(endmsg)

recv5 = clientSocket.recv(1024)
print recv5
if recv5[:3] != '250':
	print '250 reply not received from server.'

clientSocket.send('QUIT')
recv6 = clientSocket.recv(1024)
print recv6
if recv6[:3] != '221':
	print '221 reply not received from server.'

clientSocket.close()
