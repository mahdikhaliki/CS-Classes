import java.util.Scanner;

public class P8_1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter 3 numbers between 0 and 39 for lock combo, for example, 10 15 30: ");
        String input = in.nextLine();
        String[] inputs = input.split(" ");

        if (inputs.length != 3) {
            System.out.println("Invalid amount of arguments entered.");
            System.exit(0);
        }

        ComboLock combo = new ComboLock(Integer.parseInt(inputs[0]),Integer.parseInt(inputs[1]),
                                        Integer.parseInt(inputs[2]));
        do {
            System.out.print("Enter how many ticks to turn to the right: ");
            combo.turnRight(in.nextInt());
            System.out.print("Enter how many ticks to turn to the left: ");
            combo.turnLeft(in.nextInt());
            System.out.print("Enter how many ticks to turn to the right: ");
            combo.turnRight(in.nextInt());
            if (!combo.open()) {
                System.out.println("That's not the right combo, resetting dial to 0.\n");
                combo.reset();
            }
        } while(!combo.open());

        System.out.println("Lock open!");

    }
}
