import java.text.DecimalFormat;

public abstract class Employee extends Person {
    private String education;
    private boolean directDeposit;
    protected static final DecimalFormat money = new DecimalFormat("###,###,###,##0.00");

    public Employee() {
        super();
        education = "";
        directDeposit = false;
    }

    public Employee(String firstName, String lastName) {
        super(firstName, lastName);
        education = "";
        directDeposit = false;
    }

    public Employee(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
        education = "";
        directDeposit = false;
    }

    public String toString() {
        return super.toString()+"\nEducation: "+education+
                                "\nDirect Deposit: "+directDeposit;
    }

    public abstract void introduce(boolean social, boolean payInfo);

    public void setEducation(String education) { this.education = education; }
    public void setDirectDeposit(boolean condition) { directDeposit = condition; }

    public String getEducation() { return education; }
    public boolean getDirectDeposit() { return directDeposit; }
}
