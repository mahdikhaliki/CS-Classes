import java.util.Scanner;

public class P6_5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter an integer: ");
        int integerInput = in.nextInt();

        PrimeGenerator prime = new PrimeGenerator(integerInput);
        int output = prime.nextPrime();
        while (output != 0) {
            System.out.print(output + " ");
            output = prime.nextPrime();
        }
    }
}