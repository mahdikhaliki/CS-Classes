public abstract class Appointment {
    protected String description;
    protected int day, month, year;

    protected Appointment(String description, int year, int month, int day) {
        this.description = description;
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public String getDescription() { return description; }
    public int getYear() { return year; }
    public int getMonth() { return month; }
    public int getDay() { return day; }
    public abstract boolean occursOn(int year, int month, int day);
}

