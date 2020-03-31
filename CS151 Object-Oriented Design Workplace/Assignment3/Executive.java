public class Executive extends Employee {
    private float yearlyBonus, salary;

    public Executive() {
        super();
        yearlyBonus = salary = 0.0f;
    }

    public Executive(String firstName, String lastName) {
        super(firstName, lastName);
        yearlyBonus = salary = 0.0f;
    }

    public Executive(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
        yearlyBonus = salary = 0.0f;
    }

    public String toString() {
        return super.toString()+"\nEmployment type: Executive";
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
        if(payInfo) System.out.println("Pay: $"+money.format(yearlyBonus+salary));
    }

    public float computePay() { return yearlyBonus+salary; }

    public void setYearlyBonus(float bonus) { yearlyBonus = bonus; }
    public void setSalary(float salary) { this.salary = salary; }
    public float getYearlyBonus() { return yearlyBonus; }
    public float getSalary() { return salary; }

}
