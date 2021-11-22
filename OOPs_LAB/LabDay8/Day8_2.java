/**
MethodHiding
 */
class Parent {
    public static void showInfo(){
        System.out.println("This is parent");
    }
}
/**
* Child extends Parent 
 */
class Child extends Parent {
    public static void showInfo(){
        System.out.println("This is child");
    }
}

public class Day8_2 {
    public static void main(String[] args) {
        // When a method is overriden & both are static, then we say mehtod in the super class is hidden by the method in the sub class
        Child.showInfo();
        Child child = new Child();
        child.showInfo();
        
        // It is considered as compile time polymorphism
        Parent parent = new Child();
        parent.showInfo();
    }
}
