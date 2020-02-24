import java.util.Scanner;

public class E4_22 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter ice cream cone height: ");
        double height = in.nextDouble();
        System.out.print("Enter ice cream cone radius: ");
        double radius = in.nextDouble();

        IceCreamCone ice = new IceCreamCone(height, radius);
        System.out.println("Ice cream cone volume = " + ice.getVolume());
        System.out.println("Ice cream cone surface area = " + ice.getSurfaceArea());
    }
}
