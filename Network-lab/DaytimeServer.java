import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class DaytimeServer {
    // for daytime protocol, port number must be 13
    final static int DAYTIME_PORT = 13;

    public static void main(String[] args) throws IOException {
        ServerSocket theServer;
        Socket theConnection;
        PrintStream p;
        try {
            theServer = new ServerSocket(DAYTIME_PORT);
            try {
                while (true) {
                    theConnection = theServer.accept();
                    p = new PrintStream(theConnection.getOutputStream());
                    p.println(new Date());
                    theConnection.close();
                }
            } catch (IOException e) {
                theServer.close();
                System.err.println(e);
            }
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}
