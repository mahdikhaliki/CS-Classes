public class FullTimeSalaryEmployee extends Employee implements SalaryPay {
    private float salary;

    public FullTimeSalaryEmployee() {
        super();
        salary = 0.0f;
    }

    public FullTimeSalaryEmployee(String firstName, String lastName) {
        super(firstName, lastName);
        salary = 0.0f;
    }

    public FullTimeSalaryEmployee(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
        salary = 0.0f;
    }

    public String toString() {
        return super.toString()+"\nEmployment type: Full-Time Salary Employee";
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
        if(payInfo) System.out.println("Pay: $"+money.format(salary));
    }

    public float computePay(int numWeeks) {
        return (salary/52)*numWeeks;
    }

    public void setSalary(float salary) { this.salary = salary; }
    public float getSalary() { return salary; }
}
