
class Amazon extends Company{
	public void address() {
		System.out.println("Address : US");
		System.out.println("CEO : Andy Jassy");
	}
}
class Flipkart extends Company{
	public void address() {
		System.out.println("Address : India");
		System.out.println("CEO : Kalyan Krishnamurthy");
	}
}
public class MethodOverriding {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Amazon amazon = new Amazon();
		amazon.address();
		System.out.println();
		Flipkart flipkart = new Flipkart();
		flipkart.address();
		System.out.println();
		Company company = new Company();
		company.address();
	}

}
