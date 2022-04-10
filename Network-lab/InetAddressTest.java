import java.net.InetAddress;
import java.net.UnknownHostException;

public class InetAddressTest {
    public static void main(String[] args) throws UnknownHostException{
        InetAddress ia1 = InetAddress.getLocalHost();
        InetAddress ia2 = InetAddress.getByName("www.amazon.in");

        System.out.println(ia1);
        System.out.println(ia2);
    }
}
