import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPEchoServer {

    private static final int BUFFSIZE = 80;
    public static void main(String[] args) throws IOException {
        if(args.length != 1) {
            throw new IllegalArgumentException("Parameter:<Port>");
        }
        int servPort = Integer.parseInt(args[0]);
        ServerSocket servSock = new ServerSocket(servPort);
        int recvMsgSize;
        byte[] byteBuffer = new byte[BUFFSIZE];
        for(;;) {
            Socket clntSock = servSock.accept();
            InputStream in = clntSock.getInputStream();
            OutputStream out = clntSock.getOutputStream();
            while((recvMsgSize = in.read(byteBuffer)) != -1) {
                out.write(byteBuffer, 0, recvMsgSize);
            }
            clntSock.close();
        }
    }
}
