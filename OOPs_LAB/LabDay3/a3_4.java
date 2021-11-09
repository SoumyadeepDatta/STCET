import java.util.Scanner;

class Shape{
	double area;
	public void calArea(double r) {
		this.area = Math.PI * Math.pow(r, 2);

	}
	public void calArea(double x, double y) {
		this.area = x*y;
	}
	public void calArea(double a, double b, double c) {
		if(a+b<=c || a+c<=b || b+c<=a) {
			System.out.println("Invalid triangle");
		}
		else {
			double s = (a+b+c)/2;
			this.area = Math.pow(s*(s-a)*(s-b)*(s-c), 0.5);
		}
	}
	public void display() {
		System.out.println("Area : "+String.format("%.2f", this.area));
	}
}

public class a3_4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Shape sh = new Shape();
		System.out.println("1.Circle\n2.Rectangle\n3.Triangle(Scalene)\n4.Exit");
		int choice = sc.nextInt();
		switch (choice) {
		case 1:
			System.out.print("Radius : ");
			double r = sc.nextDouble();
			sh.calArea(r);
			sh.display();
			break;
		case 2:
			System.out.print("Length : ");
			double x_ = sc.nextDouble();
			System.out.print("Breadth : ");
			double y_ = sc.nextDouble();
			sh.calArea(x_,y_);
			sh.display();
			break;
		case 3:
			System.out.print("Side 1 : ");
			double a_ = sc.nextDouble();
			System.out.print("Side 2 : ");
			double b_ = sc.nextDouble();
			System.out.print("Side 3 : ");
			double c_ = sc.nextDouble();
			sh.calArea(a_,b_,c_);
			sh.display();
			break;
		case 4:
			break;
		default:
			System.out.println("Invalid Input");
			break;
		}
		sc.close();
	}

}
