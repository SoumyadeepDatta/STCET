/**
 * Day11_1
 * @author Soumyadeep Datta
 */
/**
 * Counter
 * It is a class to demonstrate the working of a simple counter
 * Has a shared resource 'count' for threads t1 & t2
 * up() method is a critical section for the program w.r.t t1 & t2
 * It is used to demonstrate thread synchronization in Java
 */
class Counter {

    private int count;  // Member variable is made private
    /**
     * up() 
     * It increments the count by 1. i.e. count = count + 1
     * t1 has loop which runs 1000 times
     * t2 has loop which runs 1000 times
     * So, as a result of both of these count value should be 2000 at the end
     * But, we would not be getting count value as 2000 in some cases, after t1 & t2 finish executing
     * Reason: In some case suppose, count value is 1998
     * Consider the following :
     * In the last iteration of the for loop of t1 & t2
     * t1 tries to get the value of count which is 1998 & increment the count by 1 which is 1999
     * t2 tries to get the value of count before t1 finishes incrementing, which is still 1998
     * t2 now increments 1998 by 1, which is 1999
     * So, result = 1999, which is not obtained as expected (2000)
     * 
     * That's why the up() method is made synchronized
     * That means t2 can't access the variable count until t1 finishes executing the method, and vice-versa
     * So, the expected result (2000) is obtained
     */
    public synchronized void up() {
        this.count++;
    }
    /**
     * To reset the count value to 0
     */
    public void reset() {
        this.count = 0;
    }
    /**
     * To access private member count
     * @return 
     */
    public int peek() {
        return this.count;
    }
}
public class Day11_1 {

    public static void main(String[] args) throws Exception{
        Counter c = new Counter();
        /**
         * Threads t1 & t2 are created using anonymous class which implements the run() method of the interface Runnable
         */
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 1; i <= 1000; i++) {
                    try {
                        /**
                         * Pausing t1 for 2 ms to demonstarate the atomic operation (incrementing the shared variable 'count')
                         */
                        Thread.currentThread().sleep(2);     
                    } catch (InterruptedException e) {}
                    c.up(); // incrementing the count by 1
                }
            }
        });
        
        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 1; i <= 1000; i++) {
                    try {
                        /**
                         * Pausing t2 for 2 ms to demonstarate the atomic operation (incrementing the shared variable 'count')
                         */
                        Thread.currentThread().sleep(2);     
                    } catch (InterruptedException e) {}
                    c.up(); // incrementing the count by 1
                }
            }
        });

        /**
         * Calling the start() method for both the threads t1 & t2, to execute the run() method
         */
        t1.start();
        t2.start();
        /**
         * Pausing the Main Thread until t1 & t2 finishes executing
         */
        t1.join();
        t2.join();
        /**
         * Main Thread prints the count value at the end
         */
        System.out.println("Count : " + c.peek());
    }
}