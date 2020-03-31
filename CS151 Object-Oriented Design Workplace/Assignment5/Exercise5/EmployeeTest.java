public class EmployeeTest {
    public static void main(String[] args) {
        Employee john = new Employee("John", "Smith", 101, 35.0f);
        int[] hours = {40, 23, 1, 0, -5, 45};

        for(int i : hours) {
            try {
                System.out.println("\nPay for "+i+" hours: "+john.computePay(i));
            }
            catch(NumberFormatException | TooManyHoursWorkedException e) {
                System.out.println(e);
            }
        }
    }
}
