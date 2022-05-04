import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class TCPClient {
    final static String HOSTNAME = "localhost";
    final static int SERVER_PORT = 2345;

    public static void main(String[] args) throws Exception {
        String sentence, modifiedSentence;
        System.out.print("Enter the sentence : ");
        BufferedReader inputFromUser = new BufferedReader(new InputStreamReader(System.in));
        Socket clientSocket = new Socket(HOSTNAME, SERVER_PORT);
        DataOutputStream outputToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inputFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        sentence = inputFromUser.readLine();
        outputToServer.writeBytes(sentence + "\n");
        modifiedSentence = inputFromServer.readLine();
        System.out.print("From server : " + modifiedSentence);
        clientSocket.close();
    }
}
