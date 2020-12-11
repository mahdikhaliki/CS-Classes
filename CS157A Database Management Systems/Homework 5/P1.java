import java.util.HashSet;
import java.util.Scanner;

public class P1 {
    static Scanner in = new Scanner(System.in);
    static HashSet<String> customerAccs;

    public static void main(String[] argv) {
        if (argv.length < 1) {
            System.out.println("Need database properties filename");
        }
        else {
            BankingSystem.init(argv[0]);
            String input = "";

            while (!input.equals("3")) {
                printScreen1();
                input = in.nextLine();
                if (input.equals("1")) {
                    newCustomerScreen();
                } else if (input.equals("2")) {
                    customerLogin();
                } else if (!input.equals("3")) {
                    System.out.println("Invalid Input. Try Again");
                }
            }
        }
    }

    public static void printScreen1() {
        System.out.println("\n\nWelcome to the Self Services Banking System! – Main Menu");
        System.out.println("1.\tNew Customer\n" +
                "2.\tCustomer Login\n" +
                "3.\tExit");
    }

    public static void newCustomerScreen() {
        System.out.println("\nNew Customer Sign Up");

        System.out.print("Enter Name: ");
        String name = in.nextLine();

        System.out.print("Enter Gender (Type M or F): ");
        String gender = in.nextLine();

        System.out.print("Enter Age: ");
        String age = in.nextLine();

        System.out.print("Enter Pin: ");
        String pin = in.nextLine();

        Integer id = BankingSystem.newCustomer(name, gender, age, pin);

        if (id != null) {
            System.out.println("\nYour customer ID is: " + id);
            customerAccs = new HashSet<>();
            printScreen3(id.toString());
        }
        else {
            System.out.println("\n1.\tTry again\n" +
                    "2.\tExit");
            String input = in.nextLine();

            if (input.equals("1"))
                newCustomerScreen();
        }
    }

    public static void customerLogin() {
        System.out.println("\nCustomer Login");

        System.out.print("Enter ID: ");
        String id = in.nextLine();

        System.out.print("Enter Pin: ");
        String pin = in.nextLine();

        if (id.equals("0") && pin.equals("0")) {
            printScreen4();
            return;
        }

        customerAccs = BankingSystem.login(id, pin);

        if (customerAccs != null) {
            printScreen3(id);
        }
        else {
            System.out.println("Incorrect credentials");
            if(tryAgain())
                customerLogin();
        }
    }

    public static void printScreen3(String id) {
        System.out.println("\nCustomer Main Menu");
        System.out.println("1.\tOpen Account\n" +
                "2.\tClose Account\n" +
                "3.\tDeposit\n" +
                "4.\tWithdraw\n" +
                "5.\tTransfer\n" +
                "6.\tAccount Summary\n" +
                "7.\tExit");
        String input = in.nextLine();

        if (input.equals("1")) {
            openAccount(id);
        } else if (input.equals("2")) {
            closeAccount();
        } else if (input.equals("3")) {
            deposit();
        } else if (input.equals("4")) {
            withdraw();
        } else if (input.equals("5")) {
            transfer();
        } else if (input.equals("6")) {
            BankingSystem.accountSummary(id);
        } else if (!input.equals("7")) {
            System.out.println("Invalid Input. Try Again");
        } else {
            return;
        }

        printScreen3(id);
    }

    public static void openAccount(String currentCustomer) {
        System.out.print("\nEnter Customer ID: ");
        String id = in.nextLine();

        System.out.print("Enter Account Type (S for Saving or C for Checking): ");
        String type = in.nextLine();

        System.out.print("Enter Initial deposit Amount: ");
        String amount = in.nextLine();

        Integer accNumber = BankingSystem.openAccount(id, type, amount);

        if (accNumber != null) {
            System.out.println("\nYour account number is: " + accNumber);
            if(currentCustomer.equals(id))
                customerAccs.add(accNumber.toString());
        } else if (tryAgain()) {
            openAccount(currentCustomer);
        }
    }

    public static void closeAccount() {
        System.out.print("Enter account number you wish to close: ");
        String accNumber = in.nextLine();

        if(!customerAccs.contains(accNumber)) {
            System.out.println("This account does not belong to you");
            if(tryAgain())
                closeAccount();
            return;
        }

        if (!BankingSystem.closeAccount(accNumber)) {
            if (tryAgain())
                closeAccount();
            return;
        }

        customerAccs.remove(accNumber);
    }

    public static void deposit() {
        System.out.print("Enter account number: ");
        String accNumber = in.nextLine();

        System.out.print("Enter deposit amount: ");
        String amount = in.nextLine();

        if (!BankingSystem.deposit(accNumber, amount))
            if (tryAgain())
                deposit();
    }

    public static void withdraw() {
        System.out.print("Enter account number: ");
        String accNumber = in.nextLine();

        if(!customerAccs.contains(accNumber)) {
            System.out.println("This account does not belong to you");
            if(tryAgain())
                withdraw();
            return;
        }

        System.out.print("Enter withdraw amount: ");
        String amount = in.nextLine();

        if (!BankingSystem.withdraw(accNumber, amount))
            if (tryAgain())
                withdraw();
    }

    public static void transfer() {
        System.out.print("Enter source account number: ");
        String srcAccNumber = in.nextLine();

        if(!customerAccs.contains(srcAccNumber)) {
            System.out.println("This account does not belong to you");
            if(tryAgain())
                transfer();
            return;
        }

        System.out.print("Enter destination account number: ");
        String destAccNumber = in.nextLine();

        System.out.print("Enter transfer amount: ");
        String amount = in.nextLine();

        if (!BankingSystem.transfer(srcAccNumber, destAccNumber, amount))
            if (tryAgain())
                transfer();
    }

    public static void printScreen4() {
        System.out.println("\nAdministrator Main Menu");
        System.out.println("1.\tAccount Summary for a Customer\n" +
                "2.\tReport A :: Customer Information with Total Balance in Decreasing Order\n" +
                "3.\tReport B :: Find the Average Total Balance Between Age Groups\n" +
                "4.\tExit");
        String input = in.nextLine();

        if (input.equals("1")) {
            System.out.print("Enter customer id: ");
            input = in.nextLine();

            BankingSystem.accountSummary(input);
        } else if (input.equals("2")) {
            BankingSystem.reportA();
        } else if (input.equals("3")) {
            System.out.print("Enter min age: ");
            String min = in.nextLine();

            System.out.print("Enter max age: ");
            String max = in.nextLine();

            BankingSystem.reportB(min, max);
        } else if (input.equals("4")) {
            return;
        }
        printScreen4();
    }

    public static boolean tryAgain() {
        System.out.println("\n1.\tTry again\n" +
                "2.\tExit");
        String input = in.nextLine();
        return input.equals("1") ? true : false;
    }
}