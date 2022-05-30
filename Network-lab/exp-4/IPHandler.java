public class IPHandler {
    
    public static int[] toIPArray(String ip, int base) {
        String[] srr = ip.split("\\.");
        int[] arr = new int[srr.length];
        for (int i = 0; i < srr.length; i++) {
            arr[i] = Integer.parseInt(srr[i], base);
        }
        return (arr.length != 4) ? null : arr;
    }

    public static String toIPString(int[] arr) {
        String ip = "";
        for (int i = 0; i < arr.length; i++) {
            ip += arr[i];
            ip = (i == arr.length - 1) ? ip : ip + ".";
        }
        return ip;
    }

    public static String getIPClass(int[] arr) {
        int val = arr[0];
        if (val < 0)
            return "n/a";
        String[] classIP = { "A", "B", "C", "D", "E" };
        int div = 128, i = 0;
        while (val > 0) {

            // System.out.println("div " + div + " " + "i " + i + " " + "val " + val);

            if (div == 8) {
                break;
            } else {
                i += val / div;
                val = val - div;
                div /= 2;
            }

        }
        try {
            return classIP[i];
        } catch (ArrayIndexOutOfBoundsException e) {
            return "n/a";
        }
    }

    public static int[] getNetBits(int[] arr) {
        switch (getIPClass(arr)) {
            case "A":
                return new int[] { arr[0] };
            case "B":
                return new int[] { arr[0], arr[1] };
            case "C":
                return new int[] { arr[0], arr[1], arr[2] };
            case "D":
            case "E":
            default:
                return new int[] {};
        }
    }

    public static int[] getNetworkAddr(int[] arr) {
        return addrUtil(arr, 0);
    }

    public static int[] getBroadcastAddr(int[] arr) {
        return addrUtil(arr, 255);
    }

    // util function
    public static int[] addrUtil(int[] arr, int i) {
        switch (getIPClass(arr)) {
            case "A":
                return new int[] { arr[0], i, i, i };
            case "B":
                return new int[] { arr[0], arr[1], i, i };
            case "C":
                return new int[] { arr[0], arr[1], arr[2], i };
            case "D":
            case "E":
            default:
                return new int[] {};
        }
    }

    public static int[] getHostBits(int[] arr) {
        switch (getIPClass(arr)) {
            case "A":
                return new int[] { arr[1], arr[2], arr[3] };
            case "B":
                return new int[] { arr[2], arr[3] };
            case "C":
                return new int[] { arr[3] };
            case "D":
            case "E":
            default:
                return new int[] {};
        }
    }

    public static void main(String[] args) {
        String ip = "192.16.78.61";

        System.out.println(getIPClass(toIPArray(ip, 10)));
        System.out.println(toIPString(getNetBits(toIPArray(ip, 10))));
        System.out.println(toIPString(getHostBits(toIPArray(ip, 10))));
        System.out.println(toIPString(getNetworkAddr(toIPArray(ip, 10))));
        System.out.println(toIPString(getBroadcastAddr(toIPArray(ip, 10))));
        
        
    }
}
