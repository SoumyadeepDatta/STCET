//Soumyadeep Datta , Roll 26
import java.util.Scanner;
class EG {
    int member1;
    String member2;
    public void create(int m1, String m2){
        this.member1 = m1;
        this.member2 = m2;
        System.out.println("Object has been created...");
    }
    public void display(){
        System.out.println("Displaying...");
        System.out.println("Member1 : "+this.member1+"\n"+"Member2 : "+this.member2);
    }
}
public class a2_2 {
    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter integer : ");
        int obj_int = sc.nextInt();
        System.out.print("Enter string : ");
        sc.nextLine();
        String obj_string = sc.nextLine();
        sc.close();
        
        EG obj = new EG();
        obj.create(obj_int, obj_string);
        obj.display();
    }
}
