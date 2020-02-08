#!/usr/bin/python
# -*- coding: utf-8 -*-
 
# The modules require
import sys
import socket
import struct
import string


 
def send_and_receive_tcp(address, port, message):
    print("You gave arguments: {} {} {}".format(address, port, message))
    # create TCP socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   
    # connect socket to given address and port
    s.connect((address,port))
    
    # python3 sendall() requires bytes like object. encode the message with str.encode() command
    message += '\r\n'
    encodeStr = message.encode()
    
    # send given message to socket
    s.sendall(encodeStr)
    
    # receive data from socket
    data = s.recv(1024)
 
    # data you received is in bytes format. turn it to string with .decode() command
    decodeStr = data.decode()
    
    # print received data

    print("Received (TCP): " +decodeStr)
    
    # close the socket

    s.close()
    
    # Get your CID and UDP port from the message
    list  = decodeStr.split('\r\n')
    infoList = list[0].split(' ')
    cid = infoList[1]
    udpPort = infoList[2]
    # Continue to UDP messaging. You might want to give the function some other parameters like the above mentioned cid and port.
    send_and_receive_udp(address, udpPort, cid)
    return
 
 
def send_and_receive_udp(address, port, token):
    '''
    Implement UDP part here.
    '''
    ##print(address)
    ##print(port)
    ##print(token)
    
    ack = True
    eom = False
    dataRemaining = 0
    content = "Hello from " + token
    conLenght= len(content)
    content_utf = content.encode()
    token_utf = token.encode()

    #create udp sockets
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    
    

    while True:
        ##pack and send
        sendData = struct.pack('!8s??HH128s', token_utf, ack, eom, dataRemaining, conLenght, content_utf)
        s.sendto(sendData, (address, int(port)))
        print("Sent: " + content_utf)

        ##get the data and address
        rcvData, addr = s.recvfrom(1024)
    
        ##unpack
        token, ack, eom, dataRemaining, conLenght, content = struct.unpack('!8s??HH128s', rcvData)
        
        ##decode received message
        message_rcvd = content.decode()
        print("Received: " + message_rcvd)  
        
        ##break the loop if last message
        if eom == True:
            s.close()
            break

        ##remove padding
        message_rcvd = message_rcvd.strip('\x00')

        
        #reverse the word string
        message_rcvd = message_rcvd.split(' ')
        message_rcvd = reversed(message_rcvd)
        reversed_msg = ' '.join(message_rcvd)

        ##lenght
        conLenght = len(reversed_msg)

        ##encode reversed message
        content_utf = reversed_msg.encode()
        
        


    return
 
 
def main():
    USAGE = 'usage: %s <server address> <server port> <message>' % sys.argv[0]
 
    try:
        # Get the server address, port and message from command line arguments
        server_address = str(sys.argv[1])
        server_tcpport = int(sys.argv[2])
        message = str(sys.argv[3])
    except IndexError:
        print("Index Error")
    except ValueError:
        print("Value Error")
    # Print usage instructions and exit if we didn't get proper arguments
        sys.exit(USAGE)
 
    send_and_receive_tcp(server_address, server_tcpport, message)
 
 
if __name__ == '__main__':
    # Call the main function when this script is executed
    main()
