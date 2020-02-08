import java.util.concurrent.atomic.AtomicInteger;

public class Incident  {

    private int posX;
    private int posY;
    private int incidentNum;

    Incident(int posX, int posY, int incidentNum) {
        this.posX = posX;
        this.posY = posY;
        this.incidentNum = incidentNum;
    }

    public synchronized int getPosX() {
        return posX;
    }

    public synchronized int getPosY() {
        return posY;
    }

    public synchronized int getIncidentNum() {
        return incidentNum;
    }

    @Override
    public synchronized String toString() {
        return "Incident{" +
                "posX=" + posX +
                ", posY=" + posY +
                ", incidentNum=" + incidentNum +
                '}';
    }
}
