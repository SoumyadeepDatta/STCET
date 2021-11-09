class Vehicles1{
	String name;
	String company_name;
	int number_of_wheels;
	String number_plate;
	public void drive() {
		System.out.println("Driving...");
	}
}
class Car1 extends Vehicles1{
	int number_of_doors;
	int number_of_gears;
	public void print_car_info() {
		System.out.println("Name : "+this.name);
		System.out.println("Company : "+this.company_name);
		System.out.println("Wheels : "+this.number_of_wheels);
		System.out.println("Doors : "+this.number_of_doors);
		System.out.println("Gears : "+this.number_of_gears);
		System.out.println("Number Plate : "+this.number_plate);
	}
}
class Bike1 extends Vehicles1{
	double top_speed;
	double mileage;
	public void print_bike_info() {
		System.out.println("Name : "+this.name);
		System.out.println("Company : "+this.company_name);
		System.out.println("Wheels : "+this.number_of_wheels);
		System.out.println("Top speed : "+this.top_speed+" kmph");
		System.out.println("Mileage : "+this.mileage+" mpl");
		System.out.println("Number Plate : "+this.number_plate);
	}
}

public class HierarchicalInheritance {

	public static void main(String[] args) {
			// TODO Auto-generated method stub
			System.out.println("Car");
			Car1 car = new Car1();
			car.name = "Civic";
			car.company_name = "Honda";
			car.number_of_doors = 4;
			car.number_of_gears = 5;
			car.number_of_wheels = 4;
			car.number_plate = "KXJVN123SBV";
			car.print_car_info();
			car.drive();
			System.out.println();
			System.out.println("Bike");
			Bike1 bike = new Bike1();
			bike.name = "Pulsar";
			bike.company_name = "Bajaj";
			bike.top_speed = 180;
			bike.mileage = 45;
			bike.number_of_wheels = 2;
			bike.number_plate = "WLKJF45NJKF";
			bike.print_bike_info();
			bike.drive();
		}

}

