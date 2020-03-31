import java.util.Scanner;
import java.util.InputMismatchException;

public class IntToHex {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int input = 0;

        try {
            System.out.print("Enter integer: ");
            input = in.nextInt();
            System.out.println("Hex: "+Integer.toHexString(input));
        } catch(InputMismatchException e) {
            System.out.println("Input is not of integer type");
        }
    }
}
