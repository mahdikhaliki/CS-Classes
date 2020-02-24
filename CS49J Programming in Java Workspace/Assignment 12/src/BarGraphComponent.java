import javax.swing.*;
import java.awt.*;

public class BarGraphComponent extends JComponent {
    Rectangle rect;

    BarGraphComponent(int x, int y, int width, int height) {
        rect = new Rectangle(x, y, width, height);
    }

    protected void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.BLUE);
        g2.fill(rect);
        g2.draw(rect);
    }

    public Dimension getPreferredSize() {
        return new Dimension(100, 20);
    }
}
