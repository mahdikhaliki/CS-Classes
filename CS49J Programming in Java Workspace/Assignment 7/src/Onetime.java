public class Onetime extends Appointment {

    public Onetime(String description, int year, int month, int day) {
        super(description, year, month, day);
    }

    public boolean occursOn(int year, int month, int day) {
        return this.year == year && this.month == month && this.day == day;
    }
}
