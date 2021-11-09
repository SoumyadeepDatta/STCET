//Soumyadeep Datta , Roll 26
class Student{
    int s_id;
    String s_name;
    Student(int id , String name ){
        this.s_id = id;
        this.s_name = name;
    }
    Student(){
        this.s_id = 122;
        this.s_name = "STCET student";
    }
    void Display(){
        System.out.println("ID : "+this.s_id);
        System.out.println("Name : "+this.s_name);
        System.out.println();
    }
}
public class a3_1{
    public static void main(String[] args) {
        System.out.println("With Constructor");
        Student s1 = new Student(1234,"Soumyadeep");
        s1.Display();
        System.out.println("Without Constructor");
        Student s2 = new Student();
        s2.Display();
    }
}