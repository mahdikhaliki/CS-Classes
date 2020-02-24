public class Monthly extends Appointment {

    public Monthly(String description, int year, int month, int day) {
        super(description, year, month, day);
    }

    public boolean occursOn(int year, int month, int day) {
        if (year > this.year && day == this.day) return true;
        else if (year == this.year && month >= this.month && day == this.day) return true;
        return false;
    }
}
