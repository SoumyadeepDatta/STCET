//Soumyadeep Datta , Roll 26
import java.util.Scanner;

class Vehicle{
    double speed;
    double mileage;
    int wheels;
    String type;
    public Vehicle(double s, int w, String t){
        this.type = t;
        this.speed = s;
        this.wheels = w;
        this.mileage = 0;
    }
    public void calspeed(double lit,double km){
        this.mileage = (km/lit) ;
    }
    public void displayINFO(){
        System.out.println("Displaying Informations...");
        System.out.println("Speed (Avg) : "+this.speed+" Kmph");
        System.out.println("Wheels : "+this.wheels);
        System.out.println("Type : "+this.type);
        System.out.println("Mileage : "+String.format("%.4f", this.mileage)+" Km/Litre");
        
    }
}
public class a2_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Wheels : ");
        int wh = sc.nextInt();
        System.out.print("Type : ");
        sc.nextLine();
        String type = sc.nextLine();
        System.out.print("Speed (Avg) : ");
        double sp = sc.nextDouble();
        System.out.println();
        System.out.println("Informations for mileage calculation...");
        System.out.print("Fuel (Litre) : ");
        double fuel = sc.nextDouble();
        System.out.print("Distance Driven (Km) : ");
        double dist = sc.nextDouble();
        
        Vehicle car = new Vehicle(sp, wh, type);
        car.calspeed(fuel, dist);
        System.out.println();
        car.displayINFO();

        sc.close();
    }
}
