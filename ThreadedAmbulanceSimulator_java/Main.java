import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {


    private static IncidentGenerator incidents = null;
    private static Ambulance ambulance;
    private static Thread ambulanceThread;
    private static Thread incidentThread;
    private static CircularBuffer buffer = null;
    private static Hospital hospital;
    private static Random random;
    private static Scanner sc;
    public static void main(String[] argv) {
        sc = new Scanner(System.in);
        random = new Random();
        List<Ambulance> ambulanceList = new ArrayList<>();

        System.out.print("How many ambulances? > ");
        int ambulanceCount = Integer.parseInt(sc.nextLine());

        try {
            buffer = new CircularBuffer(4);
        } catch (IllegalArgumentException iae) {
            System.out.println("Invalid");
            iae.printStackTrace();

            System.exit(-1);
        }


        int incRnd = random.nextInt(100 + 1 - 20) + 20;
        //create incidents with randomly generated maxLocx and maxLocY
        incidents = new IncidentGenerator(buffer, incRnd, incRnd);
        //create hospital and randomly generate position with the max value of incidents maxLocX and maxLocY
        hospital = new Hospital(random.nextInt(incidents.getMaxLocX() + 1 - 20) + 20, random.nextInt(incidents.getMaxLocY() + 1 - 20) + 20);

        //generate user given amount of  ambulance objects and store them to a list. And randomly generated speed value. hospital object also given as a argument.
        for (int i = 0; i < ambulanceCount; i++) {
            ambulanceList.add(new Ambulance(buffer, i + 1, random.nextInt(200 + 1 - 20) + 20, hospital));
        }


        incidentThread = new Thread(incidents);
        incidentThread.start();

        //iterate ambulance object list and create new threads, and then start them.
        for (int i = 0; i < ambulanceList.size(); i++) {
            ambulanceThread = new Thread(ambulanceList.get(i));
            ambulanceThread.start();
        }



    }
}
