class Sedan extends Car{
	int number_of_doors;
	String type;
	double hp;
	public void print_info() {
		System.out.println("Name : "+this.name);
		System.out.println("Company : "+this.company_name);
		System.out.println("Wheels : "+this.number_of_wheels);
		System.out.println("Gears : "+this.number_of_gears);
		System.out.println("Number Plate : "+this.number_plate);
		System.out.println("Doors : "+this.number_of_doors);
		System.out.println("Type : "+this.type);
		System.out.println("Power : "+this.hp+" hp");
		
	}
}

public class MultiLevelInheritance {

	public static void main(String[] args) {
			// TODO Auto-generated method stub
			Sedan sedan = new Sedan();
			sedan.name="Corolla";
			sedan.company_name="Toyota";
			sedan.number_of_wheels=4;
			sedan.number_of_gears=5;
			sedan.number_plate="KJENW234NJF";
			sedan.number_of_doors=4;
			sedan.type="Compact";
			sedan.hp=288.94;
			
			sedan.print_info();
			sedan.drive();
		}

}

