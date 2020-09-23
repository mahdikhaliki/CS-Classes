import java.util.Random;

/**
 * The RadixSort class generates 30 random 5-digit hex numbers. The numbers are
 * represented using a String. radixSort() is used to sort the 30 hex numbers
 * using the least significant digit approach.
 *
 * @author Mahdi Khaliki
 */

public class RadixSort {
    private static final int ARRAY_SIZE = 30;

    public static void main(String[] args) {
        String[] hexadecimals = new String[ARRAY_SIZE];

        for(int i = 0; i < ARRAY_SIZE; i++)
            hexadecimals[i] = hexGenerator();

        System.out.println("Original array: ");
        printList(hexadecimals);

        radixSort(hexadecimals, 5);
        System.out.println("Sorted array: ");
        printList(hexadecimals);
    }

    /**
     * radixSort() is used to sort an array of hexadecimal numbers and tt uses the least
     * significant digit approach. It uses counting sort as its sorting algorithm to sort
     * the digits.
     *
     * @param (String[] hexadecimal) (An array of hexadecimal numbers)
     * @param (int digits) (The number of digits in each hexadecimal number)
     */
    public static void radixSort(String[] hexadecimals, int digits) {
        String[] B = new String[hexadecimals.length];

        // Starting from the least significant digit
        for (int i = digits-1; i >= 0; i--) {

            // Using counting sort to sort each digit
            int[] C = new int[16];
            for (int j = 0; j < hexadecimals.length; j++){
                char digit = hexadecimals[j].charAt(i);
                if(Character.isDigit(digit))
                    C[hexadecimals[j].charAt(i)-'0']++;
                else
                    C[hexadecimals[j].charAt(i)-'a'+10]++;
            }

            for (int j = 1; j < 16; j++)
                C[j] += C[j-1];

            for (int j = hexadecimals.length-1; j >= 0; j--) {
                char digit = hexadecimals[j].charAt(i);
                if(Character.isDigit(digit))
                    B[--C[hexadecimals[j].charAt(i)-'0']] = hexadecimals[j];
                else
                    B[--C[hexadecimals[j].charAt(i)-'a'+10]] = hexadecimals[j];
            }

            // Copying the sorted array to the hexadecimals array
            for (int j = 0; j < hexadecimals.length; j++)
                hexadecimals[j] = B[j];
        }
    }

    /**
     * printList() is used to print the hexadecimals array.
     *
     * @param (String[] array) (The array we want to print to console)
     */
    public static void printList(String[] array) {
        System.out.print("["+array[0]);
        for(int i = 1; i < array.length; i++)
            System.out.print(", "+array[i]);
        System.out.println("]");
    }

    /**
     * hexGenerator() generates random 5-digit hexadecimal numbers
     *
     * @return (A 5-digit hexadecimal number)
     */
    public static String hexGenerator() {
        Random rand = new Random();
        StringBuilder hex = new StringBuilder();

        for(int i = 0; i < 5; i++) {
            int digit = rand.nextInt(16);

            // Ensure there is no 4 digit numbers
            if(i == 0 && digit == 0)
                digit = rand.nextInt(15)+1;

            if(digit > 9)
                hex.append(Integer.toHexString(digit));
            else
                hex.append(digit);
        }
        return hex.toString();
    }
}
