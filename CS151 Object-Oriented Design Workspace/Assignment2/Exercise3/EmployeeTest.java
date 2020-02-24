public class EmployeeTest{
    public static void main(String[] args) {
        Employee joe = new Employee("Joe", "Smith", "5124 Sea Breeze Way Hayward, CA 94543",
                                    "Male", "532-32-4553", 24, 164, "W44321",
                                    "contractor", "1/30/2020", 60);
        Employee lisa = new Employee("Lisa", "Gray", "43397 Cheryl Ann Fremont, CA 94243",
                                    "Female", "745-23-1532", 53, 134, "D11821",
                                    "full time", "3/7/1999", 110000);
        Employee timothy = new Employee("Timothy", "Briggs", "7832 Sams Street Hayward, CA 94544",
                                    "Male", "326-34-9983", 28, 200, "E43521",
                                    "full time", "10/15/2018", 80000);
        Employee george = new Employee("George", "Wallace", "6673 Beach Road Newark, CA 94623",
                                    "Male", "862-23-8963", 45, 158, "W49801",
                                    "part time", "7/30/2005", 20);
        Employee amy = new Employee("Amy", "Student", "51324 Light Way Hayward, CA 94543",
                                    "Female", "325-23-3659", 26, 132, "D33221",
                                    "contractor", "12/20/2019", 45);

        joe.introduce();
        joe.calculatePay(30);
        lisa.introduce();
        lisa.calculatePay(2);
        timothy.introduce();
        timothy.calculatePay(4);
        george.introduce();
        george.calculatePay(25);
        amy.introduce();
        amy.calculatePay(45);
    }
}
