//Soumyadeep Datta , Roll 26
import java.util.Scanner;

class student {
    int id;
    String name;
    String department;
    int year;
    public void insertinfo(int id_,String name_,String dept_,int yr_){
        this.id = id_;
        this.name = name_;
        this.department = dept_;
        this.year = yr_;
    }
    public void displayinfo(){
        System.out.println("-------------displayinfo()-------------");
        System.out.println("ID : "+this.id);
        System.out.println("Name : "+this.name);
        System.out.println("Department : "+this.department);
        System.out.println("Year : "+this.year);
        
    }
}
public class a2_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("ID : ");
        int id__= sc.nextInt();
        System.out.print("Name : ");
        sc.nextLine();
        String name__ = sc.nextLine();
        System.out.print("Department : ");
        String dept__ = sc.nextLine();
        System.out.print("Year : ");
        int yr__ = sc.nextInt();
        student s1 = new student();
        s1.insertinfo(id__, name__, dept__, yr__);
        s1.displayinfo();
        sc.close();
    }
}
