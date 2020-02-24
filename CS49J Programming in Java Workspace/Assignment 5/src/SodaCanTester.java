import java.util.Scanner;

public class SodaCanTester {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter soda can height: ");
        double height = in.nextDouble();
        System.out.print("Enter soda can diameter: ");
        double diameter = in.nextDouble();

        SodaCan can = new SodaCan(height, diameter);
        System.out.println("Soda can volume = " + can.getVolume());
        System.out.println("Soda can surface Area = " + can.getSurfaceArea());
    }
}
