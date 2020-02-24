import junit.framework.TestCase;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Scanner;

public class P9_5Test extends TestCase {
    protected ArrayList<Appointment> apts;
    protected File file;
    protected Scanner input_file;
    protected PrintWriter output_file;
    protected DateTimeFormatter dateFormat;
    protected LocalDate localDate;

    protected void setUp() throws Exception {
        apts = new ArrayList<Appointment>();
        output_file = new PrintWriter("Appointments.txt");
        file = new File("Appointments.txt");
        input_file = new Scanner(file);
        dateFormat = DateTimeFormatter.ofPattern("M/d/yyyy");

        apts.add(new Onetime("See doctor", 2019, 10, 24));
        apts.add(new Daily("See dentist", 2019, 10, 25));
        apts.add(new Monthly("Oil change", 2019, 10, 26));
    }

    public void testSaveAppointmentToFile() {
        P9_5.saveToFile(apts, output_file);
        output_file.close();

        String line;
        int appt = 0;
        while (input_file.hasNext()) {
            line = input_file.nextLine();
            assertEquals(apts.get(appt).getClass().getName(), line);

            line = input_file.nextLine();
            assertEquals(apts.get(appt).getDescription(), line);

            line = input_file.nextLine();
            assertEquals("10/"+apts.get(appt++).getDay()+"/2019", line);

            if (input_file.hasNext()) input_file.nextLine();
        }
        input_file.close();
    }

    public void testLoadAppointmentFromFile() throws FileNotFoundException {
        input_file = new Scanner(file);
        P9_5.loadFromFile(apts, input_file);

        input_file = new Scanner(file);

        String line;
        int appt = 0;
        while (input_file.hasNext()) {
            line = input_file.nextLine();
            assertEquals(line, apts.get(appt).getClass().getName());

            line = input_file.nextLine();
            assertEquals(line, apts.get(appt).getDescription());

            line = input_file.nextLine();
            assertEquals(line, "10/"+apts.get(appt++).getDay()+"/2019");

            if (input_file.hasNext()) input_file.nextLine();
        }
        input_file.close();
    }

    public void testOccursOn() {
        assertTrue(apts.get(0).occursOn(2019, 10, 24));
        assertFalse(apts.get(0).occursOn(2019, 11, 24));
        assertFalse(apts.get(0).occursOn(2018, 10, 24));
        assertFalse(apts.get(0).occursOn(2019, 10, 25));
        assertFalse(apts.get(0).occursOn(2020, 10, 24));


        assertTrue(apts.get(1).occursOn(2019, 10, 25));
        assertTrue(apts.get(1).occursOn(2019, 10, 26));
        assertTrue(apts.get(1).occursOn(2019, 11, 25));
        assertTrue(apts.get(1).occursOn(2020, 10, 25));
        assertFalse(apts.get(1).occursOn(2019, 10, 24));
        assertFalse(apts.get(1).occursOn(2019, 9, 25));
        assertFalse(apts.get(1).occursOn(2018, 10, 25));

        assertTrue(apts.get(2).occursOn(2019, 10, 26));
        assertTrue(apts.get(2).occursOn(2019, 11, 26));
        assertTrue(apts.get(2).occursOn(2019, 12, 26));
        assertTrue(apts.get(2).occursOn(2020, 1, 26));
        assertFalse(apts.get(2).occursOn(2019, 10, 27));
        assertFalse(apts.get(2).occursOn(2019, 11, 25));
        assertFalse(apts.get(2).occursOn(2018, 10, 26));
    }

    public void testAddAppointment() {
        apts.clear();

        localDate = LocalDate.parse("10/24/2019", dateFormat);
        P9_5.addAppointment(apts, 1, "See doctor", localDate);

        assertEquals("See doctor", apts.get(0).getDescription());
        assertEquals("Onetime", apts.get(0).getClass().getName());
        assertEquals(10, apts.get(0).getMonth());
        assertEquals(24, apts.get(0).getDay());
        assertEquals(2019, apts.get(0).getYear());

        localDate = LocalDate.parse("11/25/2019", dateFormat);
        P9_5.addAppointment(apts, 2, "Optometrist", localDate);

        assertEquals("Optometrist", apts.get(1).getDescription());
        assertEquals("Daily", apts.get(1).getClass().getName());
        assertEquals(11, apts.get(1).getMonth());
        assertEquals(25, apts.get(1).getDay());
        assertEquals(2019, apts.get(1).getYear());

        localDate = LocalDate.parse("1/13/2020", dateFormat);
        P9_5.addAppointment(apts, 3, "Physical therapy", localDate);

        assertEquals("Physical therapy", apts.get(2).getDescription());
        assertEquals("Monthly", apts.get(2).getClass().getName());
        assertEquals(1, apts.get(2).getMonth());
        assertEquals(13, apts.get(2).getDay());
        assertEquals(2020, apts.get(2).getYear());
    }
}