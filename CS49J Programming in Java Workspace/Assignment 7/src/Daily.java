public class Daily extends Appointment {

    public Daily(String description, int year, int month, int day) {
        super(description, year, month, day);
    }

    public boolean occursOn(int year, int month, int day) {
        if (year > this.year) return true;
        else if (year == this.year) {
           if (month == this.month && day >= this.day) return true;
           else if (month > this.month) return true;
        }
        return false;
    }
}
