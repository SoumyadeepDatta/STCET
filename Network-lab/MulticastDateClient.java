import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class MulticastDateClient {

    // class-D IP address for multicast group
    private final static String MULTICAST_GROUP = "230.0.0.1";

    // port number for multicast group
    private final static int GROUP_PORT = 1313;

    public static void main(String[] args) throws IOException {
        MulticastSocket socket = new MulticastSocket(GROUP_PORT);
        InetAddress group = InetAddress.getByName(MULTICAST_GROUP);
        socket.joinGroup(group);
        for(int i = 0; i < 100; i++) {
            byte[] buffer = new byte[256];
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);
            String received = new String(packet.getData());
            System.out.println("Current server time : " + received);
        }
        socket.leaveGroup(group);
        socket.close();
    }
}
