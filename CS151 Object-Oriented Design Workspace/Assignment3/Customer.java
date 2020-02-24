public class Customer extends Person {
    private String paymentPreference;

    public Customer() {
        super();
        paymentPreference = "";
    }

    public Customer(String firstName, String lastName) {
        super(firstName, lastName);
        paymentPreference = "";
    }

    public Customer(String firstName, String lastName, Address address) {
        super(firstName, lastName, address);
        paymentPreference = "";
    }

    public void makePayment() {
        System.out.println("Payment Preference: "+paymentPreference);
    }

    public String toString() {
        return "Customer\n"+super.toString();
    }

    public void introduce() {
        System.out.println(toString());
    }

    public void introduce(boolean social) {
        System.out.println(toString());
        if (social) System.out.println("Social: "+getSocial());
    }

    public void setPaymentPreference(String preference) {paymentPreference = preference;}
    public String getPaymentPreference() { return paymentPreference; }
}
