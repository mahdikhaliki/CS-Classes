import javax.swing.*;
import java.awt.*;

public class OlympicRingComponent extends JComponent {
    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g;
        final int DIAMETER = 60;

        OlympicRing r1 = new OlympicRing(0, 0, DIAMETER, Color.BLUE);
        OlympicRing r2 = new OlympicRing(DIAMETER, 0, DIAMETER, Color.BLACK);
        OlympicRing r3 = new OlympicRing(DIAMETER*2, 0, DIAMETER, Color.RED);
        OlympicRing r4 = new OlympicRing(DIAMETER/2, DIAMETER/2, DIAMETER, Color.YELLOW);
        OlympicRing r5 = new OlympicRing(DIAMETER/2+DIAMETER, DIAMETER/2, DIAMETER, Color.GREEN);

        r1.draw(g2);
        r2.draw(g2);
        r3.draw(g2);
        r4.draw(g2);
        r5.draw(g2);
    }
}
