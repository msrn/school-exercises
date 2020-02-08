import java.util.*;


public class IncidentGenerator extends Producer implements Runnable {

    private int maxLocX;
    private int maxLocY;
    private Random random;
    private int incidentNum;

    public IncidentGenerator(CircularBuffer cb, int maxLocX, int maxLocY) {
        super(cb);
        this.maxLocX = maxLocX;
        this.maxLocY = maxLocY;
        this.random = new Random();

    }



    protected Object produce() {
        Object obj;
        try {
            Thread.sleep(1000 + Math.abs(random.nextInt(1000)));
        } catch (InterruptedException ie) {
            ;
        }

        incidentNum++;

        //generate incident locations within 0,maxLoc range.
        int genX = random.nextInt(maxLocX + 1);
        int genY = random.nextInt(maxLocY + 1);
        obj = new Incident(genX, genY, incidentNum);
        return obj;
    }


    public void run() {
        Incident inc;

                while (true) {
                    try {
                        inc = (Incident) produce();
                        putObject(inc);
                        System.out.println("\t Incident " + inc.getIncidentNum() + " reported at: " + inc.getPosX() + ":" + inc.getPosY());
                    } catch (InterruptedException ie) {
                        break;
            }

        }

    }

    public int getMaxLocX() {
        return maxLocX;
    }

    public int getMaxLocY() {
        return maxLocY;
    }
}
