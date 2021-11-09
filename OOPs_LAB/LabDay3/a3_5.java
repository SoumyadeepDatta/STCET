import java.util.Scanner;

class Sum{
	double s;
	public Sum() {
		System.out.println("Bucket is empty");
	}
	public Sum(double a, double b) {
		this.s = a+b;
	}
	public Sum(double a, double b, double c) {
		this.s = a+b+c;
	}
	
}

public class a3_5 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); 
		System.out.println("Default Constructor :");
		Sum sum1 = new Sum();
		System.out.println("Sum : "+sum1.s);
		System.out.println("***************************************");
		System.out.println("Constructor Overloading (2 parameters) :");
		double s2_1 = sc.nextDouble();
		double s2_2 = sc.nextDouble();
		Sum sum2 = new Sum(s2_1,s2_2);
		System.out.println("Sum : "+sum2.s);
		System.out.println("***************************************");
		System.out.println("Constructor Overloading (3 parameters) :");
		double s3_1 = sc.nextDouble();
		double s3_2 = sc.nextDouble();
		double s3_3 = sc.nextDouble();
		Sum sum3 = new Sum(s3_1,s3_2,s3_3);
		System.out.println("Sum : "+sum3.s);
		System.out.println("***************************************");
		sc.close();
	}

}
