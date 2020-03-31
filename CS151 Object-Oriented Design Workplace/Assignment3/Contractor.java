public class Contractor extends Employee implements HourlyPay {
    private float hourlyRate;

    public Contractor() {
        super();
        hourlyRate = 0.0f;
    }

    public Contractor(String firstName, String lastName) {
        super(firstName, lastName);
        hourlyRate = 0.0f;
    }

    public Contractor(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
        hourlyRate = 0.0f;
    }

    public String toString() {
        return super.toString()+"\nEmployment type: Contractor";
    }

    public void introduce() {
        System.out.println(toString());
    }

    public void introduce(boolean social) {
        System.out.println(toString());
        if(social) System.out.println("Social: "+getSocial());
    }

    public void introduce(boolean social, boolean payInfo) {
        System.out.println(toString());
        if(social) System.out.println("Social: "+getSocial());
        if(payInfo) System.out.println("Pay: $"+money.format(hourlyRate)+" /hr");
    }

    public float computePay(float numHours) {
        if(numHours < 40)  return hourlyRate * numHours;
        else return (hourlyRate*40f)+(hourlyRate*OVERTIME_RATE)*(numHours-40f);
    }

    public void setHourlyRate(float hourlyRate) { this.hourlyRate = hourlyRate; }
    public float getHourlyRate() { return hourlyRate; }
}
