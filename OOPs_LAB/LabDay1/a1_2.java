//Soumyadeep Datta , Roll - 26
import java.util.Scanner;

public class a1_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 3 no.s :");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        if(a==b & b==c){
            System.out.println("All are equal");
        }
        else{
            if(a>b & a>c){
                System.out.println("Largest : "+a);
                if(b>c){
                    System.out.println("Smallest : "+c);
                }
                else{
                    System.out.println("Smallest : "+b);
                }
            }
            else if(b>a & b>c){
                System.out.println("Largest : "+b);
                if(a>c){
                    System.out.println("Smallest : "+c);
                }
                else{
                    System.out.println("Smallest : "+a);
                }
            }
            else{
                System.out.println("Largest : "+c);
                if(a>b){
                    System.out.println("Smallest : "+b);
                }
                else{
                    System.out.println("Smallest : "+a);
                }
            }
        }

        sc.close();
    }
}
