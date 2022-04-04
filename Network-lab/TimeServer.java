import java.io.*;
import java.net.*;
import java.util.Date;

public class TimeServer {
    final static int PORT_NUMBER = 1313;
    public static void main(String[] args) throws IOException {
        ServerSocket servSock = null;
        try {
            servSock = new ServerSocket(PORT_NUMBER);
            System.out.println("Server listening on port: " + PORT_NUMBER + "...");
        } catch (IOException e) {
            System.out.println("Could not listen to port: " + PORT_NUMBER);
        }
        Socket clntSocket = null;
        for(;;) {
            try {
                clntSocket = servSock.accept();
            } catch (IOException e) {
                System.err.println("Accept failed");
                System.exit(1);
            }
            ObjectOutputStream timeOut = new ObjectOutputStream(clntSocket.getOutputStream());
            timeOut.writeObject(new Date());
            timeOut.close();
            clntSocket.close();
        }
    }
    
}