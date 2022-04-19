import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;

public class MulticastDateServer {

    // class-D IP address for multicast group
    private final static String MULTICAST_GROUP = "230.0.0.1";

    private final static int SERVER_PORT = 5050;

    // port number for multicast group
    private final static int GROUP_PORT = 1313;

    public static void main(String[] args) throws IOException, InterruptedException {
        DatagramSocket socket = new DatagramSocket(SERVER_PORT);
        for(int i = 0; i < 100; i++) {
            byte[] buffer = new Date().toString().getBytes();
            InetAddress group = InetAddress.getByName(MULTICAST_GROUP);
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, group, GROUP_PORT);
            socket.send(packet);
            Thread.sleep(1500);
        }
        socket.close();
    }
}
