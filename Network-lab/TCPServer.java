import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
    final static int PORT_NUMBER = 2345;

    public static void main(String[] args) throws Exception {
        String clientSentence, capitalizedSentence;
        ServerSocket welcomeSocket = new ServerSocket(PORT_NUMBER);
        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            BufferedReader inputFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));
            DataOutputStream outputToClient = new DataOutputStream(connectionSocket.getOutputStream());
            clientSentence = inputFromClient.readLine();
            capitalizedSentence = clientSentence.toUpperCase() + "\n";
            outputToClient.writeBytes(capitalizedSentence);
        }
    }
}
