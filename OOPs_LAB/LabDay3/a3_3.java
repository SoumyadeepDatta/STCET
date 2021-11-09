import java.util.Scanner;

//Soumyadeep Datta , Roll 26
//Using class Student of a3_1
public class a3_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student[] students = new Student[5];
        for(int i = 0; i<5; i++){
            System.out.println("Student "+(i+1));
            System.out.print("ID : ");
            int Sid = sc.nextInt();
            sc.nextLine();
            System.out.print("Name : ");
            String Sname = sc.nextLine();
            students[i] = new Student(Sid,Sname);
        }
        sc.close();
        System.out.println("\nDisplaying details...\n");
        for(int t = 0; t<5; t++){
            System.out.println("Student "+(t+1));
            students[t].Display();
        }
    }
}
