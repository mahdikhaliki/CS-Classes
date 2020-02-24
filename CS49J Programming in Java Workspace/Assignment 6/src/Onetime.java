public class Onetime extends Appointment {

    public Onetime(String description, int year, int month, int day) {
        super(description, year, month, day);
    }

    public boolean occursOn(int year, int month, int day) {
        return super.year == year && super.month == month && super.day == day;
    }
}
