JAVA Led 
*** Must install package pi4j for java library to on and off led
hostname$ curl -s get.pi4j.com | sudo bash


To COMPILE java Server
hostname$ javac -classpath .:classes:/opt/pi4j/lib'*' -d . EchoServer.java

To RUN java Server
hostname$ java -classpath .:classes:/opt/pi4j/lib'*' EchoServer




To COMPILE java CLient
hostname$ javac EchoClient.java

To RUN java CLient
hostname$ java EchoClient