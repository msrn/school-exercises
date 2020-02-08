import java.util.*;

public class Ambulance extends Consumer implements Runnable {

    private int speed;
    private int ambulanceNum;
    private Random random;
    private Hospital hospital;
    public Ambulance(CircularBuffer cb, int ambulanceNum, int speed, Hospital hospital) {
        super(cb);
        this.ambulanceNum = ambulanceNum;
        this.hospital = hospital;
        this.speed = speed;

        this.random = new Random();
    }

    /** Used to calculate distance between incident and hospital **/
    public double distance(Incident inc) {
        int inX = inc.getPosX();
        int inY = inc.getPosY();
        int hX = hospital.getHospitalX();
        int hY = hospital.getHospitalY();
        double distance = Math.sqrt((inX-hX)*(inX-hX) + (inY-hY)*(inY-hY));

        return distance;

    }
    protected void consume(Object obj) {
        Incident inc = (Incident) obj;

        //Ambulance to sleep for 100ms before starting. Because for some reason Ambulance starts to move before Incident is created.
        try {
            Thread.sleep(100);
        } catch (InterruptedException ie) {
            Thread.currentThread().interrupt();
        }


        double reqTime = (distance(inc)/speed)*1000; //calculate required time to travel distance with given speed. Multiply 1000 to get non decimal result
        long startTime = System.currentTimeMillis(); //start recording execution time

        System.out.println("Ambulance " + ambulanceNum + " moving to incident " + inc.getIncidentNum());
        try {
           Thread.sleep(1000 + Math.abs((int)(reqTime * 10))); //wait for 1000 + reqTime. Multiply by 10 to get little longer time
        } catch (InterruptedException ie) {
            Thread.currentThread().interrupt();
        }

        long siteTime = System.currentTimeMillis() - startTime; // time to get from hospital to site
        System.out.println("Ambulance " + ambulanceNum + " on site " + inc.getIncidentNum() + " (Elapsed time " + siteTime + " ms)");

        double avgSpeed = (distance(inc)/siteTime); //calculate average speed with distance (hospital -> site) and siteTime
        reqTime = (distance(inc)/avgSpeed); //required time to travel distance with the avgSpeed

        System.out.println("Ambulance " + ambulanceNum + " Moving to hospital");
        try {
            Thread.sleep(1000 + Math.abs((int)(reqTime) )); //sleep for reqTime
        } catch (InterruptedException ie) {
            Thread.currentThread().interrupt();
        }


        System.out.println("Ambulance " + ambulanceNum + " transferring patient " + inc.getIncidentNum());
        try {
            Thread.sleep(10000);
        } catch (InterruptedException ie) {
            Thread.currentThread().interrupt();
        }


        long stopTime = System.currentTimeMillis(); //time at the end of the loop
        long totalDuration = stopTime - startTime;
        System.out.println("Ambulance " + ambulanceNum + " Transferred patient (Duration: " + totalDuration +" ms)");


    }


    public void run() {
        Object obj;

        while (true) {
            try {
                if (getNumStored() == 0) {
                    System.out.println(ambulanceNum + " idle");
                }
                    obj = takeObject();
                    consume(obj);

            } catch (InterruptedException ie) {
                break;
            }
        }

    }
}
