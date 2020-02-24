import junit.framework.TestCase;

public class E5_18Test extends TestCase {
    public void testCalculateTaxes() {
        double income = 0;
        double taxes = E5_18.calculateTaxes(income);
        double expectedTaxes = 0.0;

        assertEquals(expectedTaxes, taxes);

        income = 500000;
        taxes = E5_18.calculateTaxes(income);
        expectedTaxes = 20250.0;

        assertEquals(expectedTaxes, taxes);

        income = 110503.34;
        taxes = E5_18.calculateTaxes(income);
        expectedTaxes = 2170.1336;

        assertEquals(expectedTaxes, taxes);
    }
}