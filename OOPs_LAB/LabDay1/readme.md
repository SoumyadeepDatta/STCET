# Introduction to OOPs using Java
1. Create a program in java for printing “ Welcome to STCET” .
2. Implement a program to compare three numbers and identify the largest.
3. Create a program to take user input from the Scanner class of student name, roll number, department.
# Example 1
```
class simple1{  
    public static void main(){  
        System.out.println("Welcome to STCET");  
    }  
} 
```
# Example 2
```
import java.util.Scanner;
public class uip{
    public static void main(String[] args) {

        // Creates a reader instance which takes
        // input from standard input - keyboard
        Scanner reader = new Scanner(System.in);
        System.out.print("Enter a number: ");

        // nextInt() reads the next integer from the keyboard
        int number = reader.nextInt();

        // println() prints the following line to the output screen
        System.out.println("You entered: " + number);
    }
}
```
