class Counter{
	static int count=0;
	public Counter() {
		count++;
		System.out.println(count);
	}
}
public class Day6_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Counter c1 = new Counter();
		Counter c2 = new Counter();
		Counter c3 = new Counter();
		Counter c4 = new Counter();
		// all of the above four objects of class Counter shares the same memory location for the static member variable count rather than creating new references for every objects 
	}

}
