import java.text.DecimalFormat;

public class Employee extends Person{
    private String id, status, startDate;
    private float hourlyRate, yearlySalary;
    private static DecimalFormat money = new DecimalFormat("###,###,###,##0.00");

    public Employee(String firstName, String lastName, String address, String gender,
                  String social, int age, float weight, String id, String status,
                  String startDate, float compensation) {
        super(firstName, lastName, address, gender, social, age, weight);
        this.id = id;
        this.status = status;
        this.startDate = startDate;
        if(status.equals("full time")) yearlySalary = compensation;
        else hourlyRate = compensation;
    }

    public void setId(String id) { this.id = id; }
    public void setStatus(String status) { this.status = status; }
    public void setDate(String startDate) { this.startDate = startDate; }
    public void setHourlyRate(float hourlyRate) { this.hourlyRate = hourlyRate; }
    public void setyearlySalary(float yearlySalary) { this.yearlySalary = yearlySalary; }

    public String getId() { return id; }
    public String getStatus() { return status; }
    public String getDate() { return startDate; }
    public float getHourlyRate() { return hourlyRate; }
    public float getyearlySalary() { return yearlySalary; }

    public void introduce() {
        super.introduce();
        System.out.println("ID: "+id+
                           "\nStatus: "+status+
                           "\nStart Date: "+startDate);
        if(status.equals("full time"))
            System.out.println("Yearly Salary: $"+money.format(yearlySalary));
        else
            System.out.println("Hourly Rate: $"+money.format(hourlyRate));
    }

    public void calculatePay(float num) {
        if(status.equals("full time"))
            System.out.println("Pay: $"+money.format(yearlySalary/52 * num));
        else
            System.out.println("Pay: $"+money.format(num * hourlyRate));
    }
}
