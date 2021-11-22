/**
 * StaticDemo
 */
class StaticDemo {
    static int a;
    static int b;
    static{
        a = 5;
        System.out.println("Static block 1");
    };
    static{
        b = 4*a;
        System.out.println("Static block 2 & value of b is : "+b);
    }
    public static void member(int val) {
        System.out.println("Value of a is : "+a);
        System.out.println("Value of argument : "+val);
    }
}

public class Day8_1 {
    // static{
    //     System.out.println("Run...");
    // };
    public static void main(String[] args) {
        StaticDemo.member(26);
    }
}