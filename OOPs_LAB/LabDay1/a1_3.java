//Soumyadeep Datta , Roll - 26
import java.util.Scanner;

public class a1_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Name : ");
        String sname = sc.nextLine();
        System.out.print("Roll : ");
        int roll = sc.nextInt();
        sc.nextLine();
        System.out.print("Department : ");
        String dept = sc.nextLine();
        
        System.out.println();
        System.out.println("***********Output***********");
        System.out.println("Name : "+sname);
        System.out.println("Roll : "+roll);
        System.out.println("Department : "+dept);


        sc.close();
    }
}
