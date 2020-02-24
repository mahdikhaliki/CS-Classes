import java.util.Scanner;

public class E4_17 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter the first time: ");
        int firstValue = in.nextInt();
        System.out.println("Please enter the second time: ");
        int secondValue = in.nextInt();

        while (firstValue > 2359 || firstValue < 0 || secondValue > 2359 || secondValue < 0) {
            System.out.println("\nTime entered is not valid!");
            System.out.println("Please enter the first time: ");
            firstValue = in.nextInt();
            System.out.println("Please enter the second time: ");
            secondValue = in.nextInt();
        }

        if (secondValue >= firstValue) {
            int difference = secondValue - firstValue;
            int hours = difference / 100;
            int minutes = hours >= 1 ? difference % (hours * 100) : difference;
            if ((firstValue / 10) % 10 >= (secondValue / 10) % 10 && minutes > 40)
                minutes -= 40;
            System.out.println(hours + " hour(s) " + minutes + " minute(s)");
        } else {
            int difference = 2360 - firstValue + secondValue;
            if (2360 - firstValue == 60) difference -= 60;
            int hours = difference / 100;
            int minutes = hours >= 1 ? difference % (hours * 100) : difference;
            if (minutes >= 60) {
                minutes -= 60;
                hours++;
            }
            System.out.println(hours + " hour(s) " + minutes + " minute(s)\n");
        }
    }
}