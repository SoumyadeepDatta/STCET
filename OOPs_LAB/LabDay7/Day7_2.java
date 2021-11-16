abstract class Bank{
	public String bank_name;
	private String branch_name;
	private String IFSC_code;
	public Bank(String branch,String ifsc){
		this.branch_name = branch;
		this.IFSC_code = ifsc;
	}
	public void Display() {
		System.out.println(bank_name+"\n"+branch_name+"\nIFSC Code : "+IFSC_code+"\n");
	}
	// Formula is same for all banks
	public double formula(double p,double r,double t) {
		t=1; // t (time duration) is taken as 1 for simplicity
		return (double)(p*r*t)/100;
	}
	public abstract double getROI(double fd);
}
// roi is final so that it dosen't gets modified mistakenly
class SBI extends Bank{
	final double roi=6;
	public SBI(String branch, String ifsc) {
		super(branch, ifsc);
		this.bank_name = "SBI";
	}
	public double getROI(double fd) {
		return formula(fd, roi, 1);
	}
}
class PNB extends Bank{
	final double roi=7;
	public PNB(String branch, String ifsc) {
		super(branch, ifsc);
		this.bank_name = "PNB";
	}
	public double getROI(double fd) {
		return formula(fd, roi, 1);
	}
}
class AXIS extends Bank{
	final double roi=8;
	public AXIS(String branch, String ifsc) {
		super(branch, ifsc);
		this.bank_name = "AXIS";
	}
	public double getROI(double fd) {
		return formula(fd, roi, 1);
	}
}
class HDFC extends Bank{
	final double roi=9;
	public HDFC(String branch, String ifsc) {
		super(branch, ifsc);
		this.bank_name = "HDFC";
	}
	public double getROI(double fd) {
		return formula(fd, roi, 1);
	}
}
// Create a class to compare within an array
class Compare{
	String name;
	double amount;
	public Compare(String name, double amount) {
		// TODO Auto-generated constructor stub
		this.name = name;
		this.amount = amount;
	}
}
public class Day7_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double fd = 50000;
		SBI b1 = new SBI("Kolkata Main Branch", "SBIN0000001");
		PNB b2 = new PNB("Bamunari Distt Hooghly Wb", "PUNB0320100");
		AXIS b3 = new AXIS("Central Avenue, Kolkata", "UTIB0000870");
		HDFC b4 = new HDFC("Ajay Nagar", "HDFC0009304");
		b1.Display();
		b2.Display();
		b3.Display();
		b4.Display();
		double max=0;
		int max_index=0;
		// Creating an array to compare all of them
		Compare[] banks = {new Compare(b1.bank_name, b1.getROI(fd)),new Compare(b2.bank_name, b2.getROI(fd)),new Compare(b3.bank_name, b3.getROI(fd)),new Compare(b4.bank_name, b4.getROI(fd)),};
		for(int i=0;i<banks.length;i++) {
			if(banks[i].amount>max) {
				max = banks[i].amount;
				max_index = i;
			}
		}
		System.out.println("For amount "+fd+" ...");
		System.out.println("Maximum amount (Interest) is "+banks[max_index].amount+" for "+banks[max_index].name+" Bank");
		System.out.println("So you should choose "+banks[max_index].name+" Bank");
	}

}
