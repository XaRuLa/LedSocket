This is Tcp Client and Server for LED for RPI 3

--------------------------------------------------------------------

To COMPILE the Server C
hostname$ gcc -o [what ever name] tcpserver.c -l wiringPi
example = gcc -o tcpserver tcpserver.c -l wiringPi

To RUN the Server 
hostname$ ./[what ever name] [port]
example : ./tcpserver 22222

--------------------------------------------------------------------

To COMPILE the Client C
hostname$ gcc -o [what ever name] tcpclient.c
example = gcc -o tcpclient tcpclient.c 

To RUN the Client
hostname$ ./[what ever name] [IP address of server] [Port of server]
example = ./tcpclient localhost 22222
