public class Day9_1_b {
    /**
     * Unchecked Exceptions
     * These are the exceptions that are checked at run time.
     * It is not forced by the compiler to either handle or specify the exception.
     * It is up to the programmers to decide wether he/she should specify/catch the exceptions or not.
     * In Java exceptions under Error and RuntimeException classes are unchecked exceptions, everything else under throwable is checked.
     */
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        System.out.println(arr[11]);
    }
    /**
     * OUTPUT:
     * Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 11 out of bounds for length 5
        at Day9_1_b.main(Day9_1_b.java:11)
     */
}
