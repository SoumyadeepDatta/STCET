import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class DaytimeClient {
    final static int DAYTIME_SERVER_PORT = 13;

    public static void main(String[] args) {
        Socket theSocket;
        String hostname;
        DataInputStream theTimeStream;

        hostname = (args.length > 0) ? args[0] : "localhost";

        try {
            theSocket = new Socket(hostname, DAYTIME_SERVER_PORT);
            theTimeStream = new DataInputStream(theSocket.getInputStream());

            // The following line uses a deprecated API
            // String theTime = theTimeStream.readLine();

            // The proper implementation is ...

            BufferedReader br = new BufferedReader(new InputStreamReader(theTimeStream));

            String theTime = br.readLine();

            System.out.println("It is " + theTime + " at " + hostname);

        } catch (UnknownHostException e) {
            System.err.println(e);
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}
