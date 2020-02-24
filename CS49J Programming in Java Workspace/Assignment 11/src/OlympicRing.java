import java.awt.*;
import java.awt.geom.Ellipse2D;

public class OlympicRing  {
    private int x, y, diameter;
    private Color color;

    public OlympicRing(int x, int y, int diameter, Color color) {
        this.x = x;
        this.y = y;
        this.diameter = diameter;
        this.color = color;
    }

    public void draw(Graphics2D g2) {
        Ellipse2D.Double ring = new Ellipse2D.Double(x, y, diameter, diameter);
        g2.setColor(color);
        g2.draw(ring);
    }
}
