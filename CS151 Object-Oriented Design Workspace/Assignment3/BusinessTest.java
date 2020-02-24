public class BusinessTest{
    public static void main(String[] args) {
        Executive executive = new Executive("Mahdi", "Khaliki",
            new Address(980, "Cheryl Circle", "Hayward", "CA", 94544));
        Executive executive2 = new Executive("Frank", "Stevenson");

        FullTimeSalaryEmployee fullSalary = new FullTimeSalaryEmployee("Eddie", "Anderson",
            new Address(6720, "Ball Road", "Fremont", "CA", 94324));
        FullTimeSalaryEmployee fullSalary2 = new FullTimeSalaryEmployee("Jason", "Lee");

        FullTimeHourlyEmployee fullHourly = new FullTimeHourlyEmployee("Lisa", "Weisman",
            new Address(2081, "Kings Lane", "Milpitas", "CA", 94523));
        FullTimeHourlyEmployee fullHourly2 = new FullTimeHourlyEmployee("George", "Wu");

        PartTimeHourlyEmployee partTime = new PartTimeHourlyEmployee("Alison", "Rhodes",
            new Address(2322, "Straight Road", "Fremont", "CA", 94545));
        PartTimeHourlyEmployee partTime2 = new PartTimeHourlyEmployee("Jeff", "Wei");

        Contractor contractor = new Contractor("Sam", "Green",
            new Address(11222, "Business Lane", "Santa Clara", "CA", 94555));
        Contractor contractor2 = new Contractor("Christian", "Winn");

        Customer customer = new Customer("Ben", "Wheeler",
            new Address(98532, "Skyport Drive", "Santa Clara", "CA", 94555));
        Customer customer2 = new Customer("Monica", "Rivero");

        System.out.println();
        executive.setId(199203);
        executive.setAge(22);
        executive.setSocial("098-76-5432");
        executive.setEducation("B.S. Computer Science, SJSU");
        executive.setAccommodations("Coffee in the morning");
        executive.setSalary(250000.00f);
        executive.setYearlyBonus(55000.00f);
        executive.introduce(true, true);
        System.out.println("calculatePay(): "+executive.computePay()+"\n");

        executive2.setId(199903);
        executive2.setAge(58);
        executive2.setSocial("123-45-6789");
        executive2.setEducation("MBA, SJSU");
        executive2.setAccommodations("Driver to work");
        executive2.setSalary(225000.00f);
        executive2.setYearlyBonus(55000.00f);
        executive2.introduce(true);
        System.out.println("calculatePay(): "+executive2.computePay()+"\n");

        fullSalary.setId(223903);
        fullSalary.setAge(28);
        fullSalary.setSocial("098-76-5432");
        fullSalary.setEducation("B.S. Computer Science, SJSU");
        fullSalary.setSalary(115000.00f);
        fullSalary.introduce(true, true);
        System.out.println("calculatePay(2): "+fullSalary.computePay(2)+"\n");

        fullSalary2.setId(113983);
        fullSalary2.setAge(43);
        fullSalary2.setSocial("123-45-6789");
        fullSalary2.setEducation("B.S. Computer Science, SJSU");
        fullSalary2.setSalary(135000.00f);
        fullSalary2.introduce();
        System.out.println("calculatePay(4): "+fullSalary2.computePay(4)+"\n");

        fullHourly.setId(23403);
        fullHourly.setAge(32);
        fullHourly.setSocial("098-76-5432");
        fullHourly.setEducation("B.S. Computer Science, SJSU");
        fullHourly.setHourlyRate(45.00f);
        fullHourly.introduce(true, true);
        System.out.println("calculatePay(40.0): "+fullHourly.computePay(40.0f)+"\n");

        fullHourly2.setId(543289);
        fullHourly2.setAge(22);
        fullHourly2.setSocial("123-45-6789");
        fullHourly2.setEducation("B.S. Computer Science, SJSU");
        fullHourly2.setHourlyRate(38.00f);
        fullHourly2.introduce(true);
        System.out.println("calculatePay(45.5): "+fullHourly2.computePay(45.5f)+"\n");

        partTime.setId(345890);
        partTime.setAge(54);
        partTime.setSocial("098-76-5432");
        partTime.setEducation("B.S. Computer Science, SJSU");
        partTime.setHourlyRate(46.00f);
        partTime.introduce(true, true);
        System.out.println("calculatePay(41.0): "+partTime.computePay(41.0f)+"\n");

        partTime2.setId(867519);
        partTime2.setAge(41);
        partTime2.setSocial("123-45-6789");
        partTime2.setEducation("B.S. Software Engineering, SJSU");
        partTime2.setHourlyRate(42.00f);
        partTime2.introduce(true, true);
        System.out.println("calculatePay(25.0): "+partTime2.computePay(25.0f)+"\n");

        contractor.setId(102983);
        contractor.setAge(33);
        contractor.setSocial("098-76-5432");
        contractor.setEducation("B.S. Computer Science, SJSU");
        contractor.setHourlyRate(43.00f);
        contractor.introduce(true, true);
        System.out.println("calculatePay(33.3): "+contractor.computePay(33.30f)+"\n");

        contractor2.setId(38758);
        contractor2.setAge(48);
        contractor2.setSocial("123-45-6789");
        contractor2.setEducation("B.A. Computer Science, UCB");
        contractor2.setHourlyRate(56.00f);
        contractor2.introduce(true, true);
        System.out.println("calculatePay(42.0): "+contractor2.computePay(42.0f)+"\n");

        customer.setId(183);
        customer.setAge(33);
        customer.setPaymentPreference("Credit ****-****-****-3490");
        customer.setSocial("098-76-5432");
        customer.introduce();
        customer.makePayment();
        System.out.println();

        customer2.setId(758);
        customer2.setAge(48);
        customer2.setPaymentPreference("Debit ****-****-****-6602");
        customer2.setSocial("123-45-6789");
        customer2.introduce(true);
        customer.makePayment();
        System.out.println();
    }
}
