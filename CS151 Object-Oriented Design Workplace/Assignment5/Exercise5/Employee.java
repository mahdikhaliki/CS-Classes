public class Employee {
    private String firstName, lastName;
    private float hourlyPay;
    private int id;

    public Employee(String firstName, String lastName, int id, float hourlyPay) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
        this.hourlyPay = hourlyPay;
    }

    public float computePay(int numHours)
        throws TooManyHoursWorkedException, NumberFormatException{
        if(numHours < 0)
            throw new NumberFormatException("Number of hours cannot be less than 0");
        else if(numHours > 40)
            throw new TooManyHoursWorkedException("Number of hours is over 40");

        return hourlyPay * numHours;
    }

    public void setFirstName(String firstName) { this.firstName = firstName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setId(int id) { this.id = id; }
    public void setHourlyPay(float hourlyPay) { this.hourlyPay = hourlyPay; }

    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public int getId() { return id; }
    public float getHourlyPay() { return hourlyPay; }
}
