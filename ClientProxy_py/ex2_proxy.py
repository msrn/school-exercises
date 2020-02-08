#!/usr/bin/python

import select
import socket
import string

'''
This is a template for lab3 exercise 2. It creates a server that listens for TCP and UDP connections and when it receives one it will execute either handle_tcp() or handle_udp() function. 
'''

# Hard coded values. You are allowed to hard code the target servers address if you like.
'''
If the port is not available use another one. You can't use the same ports as other groups so find a unique value from around 21XX port range 
'''
ADDRESS = "185.38.3.233"
HOST = ''
TCP_PORT = 21450
UDP_PORT = 21450
PORT = 20000

def handle_tcp(sock):
    '''
    This function should do the following:
    * When receiving a message from the client print the message content and somehow implicate where it came from. For example "Client sent X"
    * Create a TCP socket.
    * Forward the message to the server using the socket.
    * Print what you received from the server
    * Forward it to the client.
    * Close socket
    '''
    ##get the content from client
    sock.listen(10)
    conn, addr = sock.accept()
    data = conn.recv(20)

    print 'Address (client): ' + addr[0] + ':' + str(addr[1])
    print(" Sent: " + data)

    ##create new socket and send data to the server
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ADDRESS, PORT))
    s.sendall(data)

    data = s.recv(1024)
    print("Address (server): " + ADDRESS + ":" + str(PORT))
    print(" Sent: " + data)


    ##send data from server back to the client
    conn.sendall(data)

    ##close socket
    s.close()

    print("TCP happended")

    return


def handle_udp(sock):
    '''
    This function should do the following
    * When receiving a message from the client print the message content and somehow implicate where it came from. For example "Client sent X"
    * Create a UDP socket
    * Forward the message to the server using the socket.
    * A loop that does the following:
        * Print what you received from the server
        * Forward it to the client.
        * Break. DO NOT use message content as your break logic (if "QUIT" in message). Use socket timeout or some other mean.  
    * Close socket
    '''
    print("In UDP")
    ##content from client
    data, addr = sock.recvfrom(1024)
    print 'Address (client): ' + addr[0] + ':' + str(addr[1])
    print(" Sent: " + data)

    ##create udp socket
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    ##s.settimeout(5)

    ##send data to server
    s.sendto(data, (ADDRESS, int(PORT)))
    
    while True:
        

        ##received from server
        data, srvAddr = s.recvfrom(1024)
        print 'Address (server): ' + srvAddr[0] + ':' + str(srvAddr[1])
        print(" Sent: " + data)

        ##send back to client
        sock.sendto(data, addr)

        ##couldn't get socket.timeout to work :-(
        if "QUIT" in data:
            break



    print("UDP happened")
    s.close()
    return




def main():
    try:
        print("Creating sockets")
        '''
        Create and bind TCP and UDP sockets here. Use hard coded values TCP_PORT and UDP_PORT to choose your port. 
        Note that while loop below  uses these sockets, so name them tcp_socket and udp_socket or modify the loop below.
        '''
        #create
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        #bind
        tcp_socket.bind((HOST, TCP_PORT))
        udp_socket.bind((HOST, UDP_PORT))
    except OSError:
        '''
    This will be raised if you are trying to create a socket but it is still active. Likely your code crashed or otherwise closed before you closed the socket. Wait a second and the socket should become available. Alternatively you can create a logic here that binds the socket to X_PORT+1. Doing this is not mandatory
        '''
        print("OSError was rised. Port is in use. Wait a second.")

    try:
        while True:
            i, o, e = select.select([tcp_socket, udp_socket], [], [], 5)
            if tcp_socket in i:
                handle_tcp(tcp_socket)
            if udp_socket in i:
               handle_udp(udp_socket)
    except NameError:
        print("Please create the sockets. NameError was raised doe to them missing.")
    finally:
        '''
        !!Close sockets here!!
        '''
        tcp_socket.close()
        udp_socket.close()
    


if __name__ == '__main__':
    main()
