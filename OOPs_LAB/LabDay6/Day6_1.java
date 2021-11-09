class Student{
	String name;
	static String college="STCET";
	int s_id;
	public Student(String s_n, int s_i) {
		this.name=s_n;
		this.s_id=s_i;
	}
	public static void show() {
		System.out.println(college);
		// cannot make a static reference to the non-static field name
		// System.out.println(name);
	}
	public void display() {
		System.out.println(s_id+" "+name);
	}
}
public class Day6_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student.show();
		Student s1 = new Student("ABC",123);
		Student s2 = new Student("XYZ",456); 
		s1.display();
		s2.display();
		// changing the static variable
		Student.college = "IITKGP";
		Student.show();
		s1.show(); // accesses the same memory location 
	}

}
