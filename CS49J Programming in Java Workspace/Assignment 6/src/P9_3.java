import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class P9_3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String date;
        DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("M/d/yyyy");

        Appointment apts[] = new Appointment[3];
        apts[0] = new Monthly("Doctors", 2019, 10, 1);
        apts[1] = new Daily("Dentist", 2019, 10, 4);
        apts[2] = new Onetime("Physical therapist", 2019, 10, 1);

        System.out.println("\n\nEnter a date in format month/day/year:");
        date = in.nextLine();
        LocalDate localDate = LocalDate.parse(date, dateFormat);

        System.out.println("\nYou have the following appointments:");
        int count = 1;
        for (Appointment apt : apts) {
            if (apt.occursOn(localDate.getYear(), localDate.getMonthValue(), localDate.getDayOfMonth())) {
                System.out.println(count++ + ". " + apt.getDescription());
            }
        }
    }
}
