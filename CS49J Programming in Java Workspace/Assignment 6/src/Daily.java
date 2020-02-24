public class Daily extends Appointment {

    public Daily(String description, int year, int month, int day) {
        super(description, year, month, day);
    }

    public boolean occursOn(int year, int month, int day) {
        if (year > super.year) return true;
        else if (year == super.year && month >= super.month && day >= super.day) return true;
        return false;
    }
}