public class Monthly extends Appointment {

    public Monthly(String description, int year, int month, int day) {
        super(description, year, month, day);
    }

    public boolean occursOn(int year, int month, int day) {
        if (year > super.year && day == super.day) return true;
        else if (year == super.year && month >= super.month && day == super.day) return true;
        return false;
    }
}
