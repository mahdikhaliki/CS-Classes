import java.util.Scanner;
import java.util.ArrayList;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.File;

public class P9_5 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        int input, type;
        String date;
        ArrayList<Appointment> apts = new ArrayList<Appointment>();

        DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("M/d/yyyy");
        LocalDate localDate;

        System.out.print("Enter text file to load appointments from: ");
        String input_f = in.nextLine();
        File file = new File(input_f);

        while (!file.exists()) {
            System.out.print("FILE NOT FOUND\nEnter text file to load appointments from: ");
            input_f = in.nextLine();
            file = new File(input_f);
        }
        Scanner input_file = new Scanner(file);

        loadFromFile(apts, input_file);
        input_file.close();

        do {
            System.out.print("\n\nChoose from the following options:\n" +
                    "1. Add new appointment\n" +
                    "2. Search for appointments\n" +
                    "3. Quit\n");
            input  = in.nextInt();

            switch (input) {
                case 1:
                    String description;

                    System.out.print("\n\nChoose type of appointment:\n" +
                            "1. Onetime\n" +
                            "2. Daily\n" +
                            "3. Monthly\n");
                    type = in.nextInt();

                    if (type < 1 || type > 3) {
                        System.out.println("Invalid input");
                        break;
                    }
                    System.out.println("\n\nEnter description of appointment:");
                    in.nextLine();                // For some reason the first in.nextLine() does not work
                    description = in.nextLine();

                    System.out.println("Enter a date in format month/day/year:");
                    localDate = LocalDate.parse(in.nextLine(), dateFormat);

                    addAppointment(apts, type, description, localDate);
                    break;
                case 2:
                    System.out.println("\n\nEnter a date in format month/day/year:");
                    date = in.next();
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

        System.out.println("\n\nEnter text file to save appointments to: ");
        String output_f = in.next();
        PrintWriter output_file = new PrintWriter(output_f);

        saveToFile(apts, output_file);
        output_file.close();
    }

    public static void addAppointment(ArrayList<Appointment> apts, int type, String description, LocalDate localDate) {
        switch (type) {
            case 1: apts.add(new Onetime(description, localDate.getYear(), localDate.getMonthValue(),
                    localDate.getDayOfMonth())); break;
            case 2: apts.add(new Daily(description, localDate.getYear(), localDate.getMonthValue(),
                    localDate.getDayOfMonth())); break;
            case 3: apts.add(new Monthly(description, localDate.getYear(), localDate.getMonthValue(),
                    localDate.getDayOfMonth())); break;
        }
        System.out.println("Appointment successfully added.\n");
    }

    public static void loadFromFile(ArrayList<Appointment> apts, Scanner input_file) {
        DateTimeFormatter dateFormat = DateTimeFormatter.ofPattern("M/d/yyyy");
        LocalDate localDate;

        while (input_file.hasNext()) {
            String type = input_file.nextLine();
            String description = input_file.nextLine();
            String date = input_file.nextLine();
            localDate = LocalDate.parse(date, dateFormat);

            switch(type.toUpperCase().charAt(0)) {
                case 'O':
                    apts.add(new Onetime(description, localDate.getYear(), localDate.getMonthValue(),
                            localDate.getDayOfMonth())); break;
                case 'D':
                    apts.add(new Daily(description, localDate.getYear(), localDate.getMonthValue(),
                            localDate.getDayOfMonth())); break;
                case 'M':
                    apts.add(new Monthly(description, localDate.getYear(), localDate.getMonthValue(),
                            localDate.getDayOfMonth())); break;
                default:
                    System.out.println("Incorrectly formatted file");
            }
            if (input_file.hasNext()) input_file.nextLine();
        }
    }

    public static void saveToFile(ArrayList<Appointment> apts, PrintWriter output_file) {
        for (int i = 0; i < apts.size(); i++) {
            String type = apts.get(i).getClass().getName();
            output_file.println(type);
            output_file.println(apts.get(i).getDescription());
            output_file.println(apts.get(i).getMonth()+"/"+apts.get(i).getDay()+"/"+apts.get(i).getYear());

            if (i != apts.size() - 1) output_file.println();
        }
    }
}
