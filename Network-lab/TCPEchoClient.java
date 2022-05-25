import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.SocketException;

public class TCPEchoClient {

    public static void main(String[] args) throws IOException {

        // 1st part
        if(args.length < 2 || args.length > 3) {
            // port inside [] bcz it is optional
            throw new IllegalArgumentException("Parameter(s):<server><word>[<port>]");
        }
        String server = args[0];
        byte[] byteBuffer = args[1].getBytes();
        int serverPort = (args.length == 3)? Integer.parseInt(args[2]) : 7;
        Socket sock = new Socket(server, serverPort);
        System.out.println("Connected to server... sending Echo string");
        InputStream in = sock.getInputStream();
        OutputStream out = sock.getOutputStream();
        out.write(byteBuffer);

        // 2nd part
        int totalBytesRcvd = 0;
        int bytesRcvd;
        while(totalBytesRcvd < byteBuffer.length) {
            if((bytesRcvd = in.read(byteBuffer, totalBytesRcvd, byteBuffer.length - totalBytesRcvd)) == -1) {
                throw new SocketException("Connection closed prematurely");
            }
            totalBytesRcvd += bytesRcvd;
        }
        System.out.println("Received : " + new String(byteBuffer));
        sock.close();
    }
}