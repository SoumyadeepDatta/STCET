class Vehicles{
	String company_name;
	int number_of_wheels;
	String number_plate;
	public void drive() {
		System.out.println("Driving...");
	}
}
class Car extends Vehicles{
	String name;
	int number_of_gears;
	public void print_info() {
		System.out.println("Name : "+this.name);
		System.out.println("Company : "+this.company_name);
		System.out.println("Wheels : "+this.number_of_wheels);
		System.out.println("Gears : "+this.number_of_gears);
		System.out.println("Number Plate : "+this.number_plate);
	}
}
public class SingleLevelInheritance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car car = new Car();
		car.name = "Civic";
		car.company_name = "Honda";
		car.number_of_gears = 5;
		car.number_of_wheels = 4;
		car.number_plate = "KXJVN123SBV";
		car.print_info();
		car.drive();
	}
}
