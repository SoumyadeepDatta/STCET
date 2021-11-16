abstract class Employee{
	private int emp_id;
	private String name;
	private String doj;
	public Employee(int emp_id,String name,String doj) {
		this.emp_id = emp_id;
		this.name = name;
		this.doj = doj;
	}
	public void getInfo() {
		System.out.println(emp_id+" "+name+" "+doj);
	}
	public abstract double getsal();
}
class Manager extends Employee{
	public Manager(int emp_id, String name, String doj) {
		super(emp_id, name, doj);
	}
	public double getsal() {
		double salary = 65000;
		salary += salary*0.99;
		return salary;
	}
}
class Salesman extends Employee{
	public Salesman(int emp_id, String name, String doj) {
		super(emp_id, name, doj);
	}
	public double getsal() {
		double salary = 15000;
		salary += salary*0.85;
		return salary;
	}
}

public class Day7_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Manager m1 = new Manager(1024,"ABC","23-09-2009");
		Salesman s1 = new Salesman(11391,"XYZ","12-11-2015");
		m1.getInfo();
		System.out.println("Manager's salary : "+m1.getsal());
		System.out.println();
		s1.getInfo();
		System.out.println("Salesman's salary : "+s1.getsal());
	}

}
