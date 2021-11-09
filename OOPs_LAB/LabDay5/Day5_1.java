class Parent{
	int member1;
	int member2;
	public Parent(int a, int b) {
		this.member1 = a;
		this.member2 = b;
	}
	public void show() {
		System.out.println(member1);
		System.out.println(member2);
	}
}
class Child extends Parent{
	String child_member;
	public Child(int a, int b, String c) {
		super(a,b);
		this.child_member = c;
	}
	public void show() {
		System.out.println(super.member1);
		System.out.println(super.member2);
		System.out.println(child_member);
	}
}
public class Day5_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Child child = new Child(123,456,"Hello");
		child.show();
	}

}
