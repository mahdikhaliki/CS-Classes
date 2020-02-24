import java.util.Scanner;
import java.util.ArrayList;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class P9_4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int input, type;

        String description, date;
        ArrayList<Appointment> apts = new ArrayList<Appointment>();
        DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("M/d/yyyy");

        LocalDate localDate;

        do {
            System.out.print("\n\nChoose from the following options:\n" +
                    "1. Add new appointment\n" +
                    "2. Search for appointments\n" +
                    "3. Quit\n");
            input  = in.nextInt();

            switch (input) {
                case 1:
                    System.out.print("\n\nChoose type of appointment:\n" +
                            "1. One time\n" +
                            "2. Daily\n" +
                            "3. Monthly\n");
                    type = in.nextInt();

                    if (type < 1 || type > 3) {
                        System.out.println("Invalid input");
                        break;
                    }
                    System.out.println("\n\nEnter description of appointment:");
                    description = in.nextLine();                // For some reason the first in.nextLine() does not work
                    description = in.nextLine();

                    System.out.println("Enter a date in format month/day/year:");
                    date = in.nextLine();
                    localDate = LocalDate.parse(date, dateFormat);

                    switch (type) {
                        case 1: apts.add(new Onetime(description, localDate.getYear(), localDate.getMonthValue(),
                                localDate.getDayOfMonth())); break;
                        case 2: apts.add(new Daily(description, localDate.getYear(), localDate.getMonthValue(),
                                localDate.getDayOfMonth())); break;
                        case 3: apts.add(new Monthly(description, localDate.getYear(), localDate.getMonthValue(),
                                localDate.getDayOfMonth())); break;
                    }
                    System.out.println("Appointment successfully added.\n");
                    break;
                case 2:
                    System.out.println("\n\nEnter a date in format month/day/year:");
                    date = in.nextLine();                   // Same as above, the first in.nextLine() does not work
                    date = in.nextLine();
                    localDate = LocalDate.parse(date, dateFormat);

                    System.out.println("You have the following appointments:");
                    int count = 1;
                    for (Appointment apt : apts) {
                        if (apt.occursOn(localDate.getYear(), localDate.getMonthValue(), localDate.getDayOfMonth())) {
                            System.out.println(count++ + ". " + apt.getDescription());
                        }
                    }
                    break;
                case 3: break;
                default: System.out.println("\n\nInvalid input\n");
            }
        } while (input != 3);
    }
}
