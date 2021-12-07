/**
 * Day10_1
 */
class MyException extends Exception{
    private String PIN;
    MyException(String pin){
        this.PIN = pin;
    }
    @Override                       
    public String toString(){       // overriding the toString() method of Throwable class
        return "MyException["+PIN+"] exceeds length";
    }
}
public class Day10_1 {
    public static void generatePIN(String s) throws MyException{
        System.out.println("Generating...");
        if(s.length()>4){
            throw new MyException(s);
        }
        System.out.println(s+"\nDONE");
    }
    public static void main(String[] args) {
        try {
            generatePIN("23425");
        } catch (MyException e) {
            System.out.println(e);
        }
    }
}