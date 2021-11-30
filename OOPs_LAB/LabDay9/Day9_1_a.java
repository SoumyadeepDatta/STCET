import java.io.BufferedReader;
import java.io.FileReader;

/**
 * Day9_1
 * Errors --> can't be handled
 * Exceptions --> can be handled
 * Checked Exceptions --> If not handled, will lead to an error
 */
public class Day9_1_a {

    public static void main(String[] args) {
        // Checked Exceptions
        /**
         * These are the exceptions that are checked at compile time. If some code within a method throws a checked exception,
         * then the method must either handle the exception or it must specify the exception using the throws keyword.
         * Otherwise it will give an error by saying that the exception was not caught/handled.
         */
        FileReader file = new FileReader("not_there.txt");
        BufferedReader fileReader = new BufferedReader(file);
        for(int line=0;line<5;line++){
            System.out.println(fileReader.readLine());
        }
        /**
         *  OUTPUT:
         *  Day9_1_a.java:16: error: unreported exception FileNotFoundException; must be caught or declared to be thrown
            FileReader file = new FileReader("not_there.txt");
                          ^
            Day9_1_a.java:19: error: unreported exception IOException; must be caught or declared to be thrown
            System.out.println(fileReader.readLine());
                                                  ^
            2 errors
         */
    }
}