import java.util.Scanner;

public class E5_19 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String userInput = "";
        while(true) {
            System.out.println("\nEnter the card notation (type Q to end program): ");
            userInput = in.nextLine();
            if (userInput.compareToIgnoreCase("Q") == 0)
                break;
            Card card = new Card(userInput);
            System.out.println(card.getDescription());
        }
    }
}
