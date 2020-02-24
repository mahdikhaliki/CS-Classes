import java.text.DecimalFormat;
import java.util.Scanner;

public class E5_18 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter income: ");
        double income = in.nextDouble();
        double taxes = calculateTaxes(income);

        DecimalFormat money = new DecimalFormat("###,###,###,##0.00");
        System.out.println("Taxes owed for $"+ money.format(income) + ": $" + money.format(taxes));
    }

    public static double calculateTaxes(double income) {
        double taxes = 0.0;
        if (income > 0 && income <= 50000) {
            taxes = income * .01;
        } else if (income > 50000 && income <= 75000) {
            taxes = 50000 * .01;
            taxes += (income - 50000) * .02;
        } else if (income > 75000 && income <= 100000) {
            taxes = 50000 * .01;
            taxes += 25000 * .02;
            taxes += (income - 75000) * .03;
        } else if (income > 100000 && income <= 250000) {
            taxes = 50000 * .01;
            taxes += 25000 * .02;
            taxes += 25000 * .03;
            taxes += (income - 100000) * .04;
        } else if (income > 250000 && income <= 500000) {
            taxes = 50000 * .01;
            taxes += 25000 * .02;
            taxes += 25000 * .03;
            taxes += 150000 * .04;
            taxes += (income - 250000) * .05;
        } else if (income > 500000) {
            taxes = 50000 * .01;
            taxes += 25000 * .02;
            taxes += 25000 * .03;
            taxes += 150000 * .04;
            taxes += 250000 * .05;
            taxes += (income - 500000) * .06;
        }
        return taxes;
    }
}
