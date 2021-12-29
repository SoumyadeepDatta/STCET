import java.util.Scanner;

/**
 * @author Soumyadeep Datta
 * MyThread
 * A sample thread to run
 * Created using extending the Thread class
 */
class MyThread extends Thread{
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            /**
             * Prints Hello along with System time (in ms) to check Thread.sleep(500)
             */
            System.out.println("Hello "+System.currentTimeMillis()+" ms");
            try { Thread.sleep(500);} catch (Exception e) {}
        }
    }
    
}

public class Day11_2 {
    public static void main(String[] args) throws Exception{
        Thread t = new MyThread();  // creating a thread object of MyThread
        /**
         * Display default name of the thread
         */
        System.out.println("Default thread name : "+t.getName());
        
        System.out.print("Enter new thread name : ");
        /**
         * Take user I/P to change name of the thread
         */
        Scanner sc = new Scanner(System.in);
        String t_name = sc.nextLine();
        sc.close();
        /**
         * Change the thread name
         */
        t.setName(t_name);
        System.out.println("New thread name : "+t.getName());   // display the changed name of the thread
        /**
         * Calling start() method of thread t to execute run()
         */
        t.start();
        /**
         * Check wether thread t is alive or not (returns true if alive else returns false)
         * Here t is alive because it has not finished its execution yet
         */
        System.out.println("Alive : "+t.isAlive());
        /**
         * Waits for t to join the Main thread (basically waits until t finishes its execution)
         */
        t.join();
        /**
         * Now t is not alive, because it has finished its execution
         */
        System.out.println("Alive : "+t.isAlive());
    }
}
