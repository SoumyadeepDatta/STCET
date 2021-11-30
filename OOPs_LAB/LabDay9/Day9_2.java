public class Day9_2 {
    public static void main(String[] args) {
        try {
            int x = 0;
            int y = 55;
            int z = y / x;
            // Rest of the lines inside try block are not going to be executed after exception is found
            System.out.println(z);
            System.out.println("Unreachable code");
        } catch (ArithmeticException e) {
            // Handle exception
            System.out.println(e.getClass()); // name of the exception class (i.e. like ArithmeticException)
            System.out.println(e.getMessage()); // message of the exception (i.e. reason)
            System.out.println(e);
        }
    }
}
