import java.awt.Rectangle;

public class BetterRectangle extends Rectangle {

    public BetterRectangle(int width, int height, int x, int y) {
        super();
        super.setLocation(x, y);
        super.setSize(width, height);
    }

    public int getPerimeter() {
        return 2 * (super.height + super.width);
    }

    public int getArea() {
        return super.height * super.width;
    }
}
