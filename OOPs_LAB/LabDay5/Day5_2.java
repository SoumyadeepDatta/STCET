class Student{
	public static String college = "STCET";
	public static int code = 122;
	public String s_name;
	public Student(String sname) {
		// TODO Auto-generated constructor stub
		this.s_name = sname;
	}
	public void display() {
		System.out.println(code+", "+college+", "+s_name);
	}
}
public class Day5_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = new Student("ABC");
		Student s2 = new Student("XYZ");
		//the member variables college & code are common to both student objects here the member variables college & code shares same heap memory space for both s1 & s2 if those 2 variables were not static they would have been residing in separate memory space for s1 & s2 in this way we can save huge amount of memory space for the variables which are common for several instances
		s1.display();
		s2.display();
	}

}
