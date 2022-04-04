import java.io.*;
import java.net.*;
import java.util.Date;

public class TimeClient {
    final static int PORT_NUMBER = 1313;
    final static String SERVER = "localhost";
    public static void main(String[] args) throws IOException{
        Socket timeSocket = null;
        ObjectInputStream timeIn = null;
        try {
            timeSocket = new Socket(SERVER, PORT_NUMBER);
            timeIn = new ObjectInputStream(timeSocket.getInputStream());
        } catch (UnknownHostException e) {
            System.err.println("Server '" + SERVER + "' is unknown");
            System.exit(1);
        }
        catch (IOException e) {
            System.err.println("Failed to connect to " + SERVER);
            System.exit(1);
        }

        try {
            Date serverDate = (Date) timeIn.readObject();
            System.out.println("Current server time: " + serverDate);
        } catch (ClassNotFoundException e) {
            System.err.println("Not a date object returned");
            System.exit(1);
        }

        timeIn.close();
        timeSocket.close();
    }
}
