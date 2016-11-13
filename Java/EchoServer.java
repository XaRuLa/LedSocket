import java.net.*;
import java.io.IOException;
import java.io.*;
import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.PinState;
import com.pi4j.io.gpio.RaspiPin;


public class EchoServer
{
 public static void main(String[] args) throws IOException,InterruptedException 
   {
    ServerSocket serverSocket = null;

    try {
         serverSocket = new ServerSocket(12345);
        }
    catch (IOException e)
        {
         System.err.println("Could not listen on port: 12345.");
         System.exit(1);
        }

    Socket clientSocket = null;
System.out.println ("Waiting for connection.....");

    try {
         clientSocket = serverSocket.accept();
        }
    catch (IOException e)
        {
         System.err.println("Accept failed.");
         System.exit(1);
        }

    System.out.println ("Connection successful");

        final GpioController gpio = GpioFactory.getInstance();
        final GpioPinDigitalOutput pin = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_03, "MyLED", PinState.HIGH);
	Thread.sleep(5000);

        pin.setShutdownOptions(true, PinState.LOW);
        System.out.println("LED OFF");

    serverSocket.close();
   }
   }

