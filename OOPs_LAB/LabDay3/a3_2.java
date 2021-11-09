//Soumyadeep Datta , Roll 26
class Employee{
    int EID;
    String Ename;
    String Dept;
    Employee(int id, String name, String dept){
        this.EID = id;
        this.Ename = name;
        this.Dept = dept;
    }
    void display(){
        System.out.println("EID : "+this.EID);
        System.out.println("Ename : "+this.Ename);
        System.out.println("Dept : "+this.Dept);
        System.out.println();
    }
}
public class a3_2 {
    public static void main(String[] args) {
        Employee e1 = new Employee(101, "Mike", "IT");
        Employee e2 = new Employee(234, "Alan", "Sales");
        Employee e3 = new Employee(437, "Mark", "Accounts");
        Employee e4 = new Employee(315, "John", "IT");
        Employee e5 = new Employee(272, "Dave", "HR");

        e1.display();
        e2.display();
        e3.display();
        e4.display();
        e5.display();
        
        
    }
}
