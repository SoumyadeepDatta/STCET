public class Day10_2 {
    public static void main(String[] args) {
        try {
            try {
                int x=0,y=5;
                int[] arr={2,3,4};
                arr[11] = y/x;
                System.out.println(arr[11]);
                System.out.println("Unreachable code");
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println(e);
            }
        } catch (ArithmeticException e) {
            System.out.println(e);
        }
        finally{
            System.out.println("Always reachable");
        }
    }
}
