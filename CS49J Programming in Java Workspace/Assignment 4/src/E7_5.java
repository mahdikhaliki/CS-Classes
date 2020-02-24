import java.util.Scanner;

public class E7_5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a string of integers: ");
        String entries = in.nextLine();

        if (entries.length() == 0) System.exit(0);          // If user does not enter a number, exit program

        String numbers[] = entries.split(" ");
        int alternating_sum = Integer.parseInt(numbers[0]);
        System.out.print(alternating_sum);

        for (int i = 1; i < numbers.length; i++) {
            if (i % 2 == 0) {
                System.out.print(" + ");
                alternating_sum += Integer.parseInt(numbers[i]);
            }
            else {
                System.out.print(" - ");
                alternating_sum -= Integer.parseInt(numbers[i]);
            }
            System.out.print(numbers[i]);
        }
        System.out.println(" = " + alternating_sum);
    }
}