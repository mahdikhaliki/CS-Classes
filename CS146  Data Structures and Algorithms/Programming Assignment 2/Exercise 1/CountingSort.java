/**
 * The CountingSort class instantiates a given array with explicit values and relative
 * indices which indicate the order of elements that have the same value. The unsorted
 * array is passed into the countSort() which sorts the numbers using counting sort
 * algorithm. Each intermediate step is printed to console.
 *
 * @author Mahdi Khaliki
 */

public class CountingSort {
    private static final int ARRAY_SIZE = 15;

    public static void main(String[] args) {
        Number[] unsortedNums = new Number[ARRAY_SIZE];
        Number[] sortedNums = new Number[ARRAY_SIZE];
        int[] integers = {7, 7, 2, 8, 4, 2, 3, 5, 4, 8, 3, 6, 4, 6, 2};
        int[] relative_index = {1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 3, 2, 3};
        int max_element = 0;

        for(int i = 0; i < ARRAY_SIZE; i++) {
            unsortedNums[i] = new Number(integers[i], relative_index[i]);
            max_element = Math.max(max_element, integers[i]);
        }

        System.out.println("Original array:");
        printArray(unsortedNums);

        countSort(unsortedNums, sortedNums, max_element);

        System.out.println("Sorted array: ");
        printArray(sortedNums);
        System.out.println("The relative indices are also in order which proves " +
                "that counting sort a stable sorting algorithm ");

    }

    /**
     * countSort() uses the counting sort algorithm to sort an array of Numbers. This function
     * only sorts the numbers and not their relative indices so we can prove that counting sort
     * is a stable algorithm.
     *
     * @param (Number[] nums) (An array of numbers that also have their relative indices attached)
     * @param (Number[] sortedArray) (The result of sorting the nums array)
     * @param (int k) (The largest integer in the list)
     */
    public static void countSort(Number[] nums, Number[] sortedArray, int k) {
        int[] C = new int[k+1];

        // Filling in array C with 0's
        for(int i = 0; i <= k; i++) {
            C[i] = 0;
        }

        System.out.println("\nAdding elements to C array");
        for(int i = 0; i < nums.length; i++) {
            C[nums[i].getNumber()] = C[nums[i].getNumber()] + 1;
            System.out.print("C");
            printIntArray(C);
        }

        System.out.println("\nSummation of array C");
        for(int i = 1; i <= k; i++) {
            C[i] = C[i] + C[i-1];
            System.out.print("C");
            printIntArray(C);
        }

        // Inserting the elements into the sortedArray in order using the indices stored in C
        System.out.println("\nInserting element to array B using index at C");
        System.out.print("B");
        printArray(sortedArray);
        System.out.print("C");
        printIntArray(C);
        System.out.println();
        for(int i = nums.length-1; i >= 0; i--) {
            sortedArray[--C[nums[i].getNumber()]] = nums[i];
            System.out.print("B");
            printArray(sortedArray);
            System.out.print("C");
            printIntArray(C);
            System.out.println();
        }
    }

    /**
     * printIntArray() is used to print the array C used in countSort().
     *
     * @param (int[] array) (The array we want to print to console)
     */
    public static void printIntArray(int[] array) {
        System.out.print("["+array[0]);
        for(int i = 1; i < array.length; i++)
            System.out.print(", "+array[i]);
        System.out.println("]");
    }

    /**
     * printArray() is used to print the Number arrays used in countSort() and main().
     *
     * @param (int[] array) (The array we want to print to console)
     */
    public static void printArray(Number[] array) {
        System.out.print("["+array[0]);
        for(int i = 1; i < array.length; i++)
            System.out.print(", "+array[i]);
        System.out.println("]");
    }

    /**
     * The Number class is used to store an integer and it's relative index in a list that may
     * contain multiple of the same elements.
     */
    public static class Number {
        private int number, relative_index;

        public Number(int number, int relative_index) {
            this.number = number;
            this.relative_index = relative_index;
        }

        public int getNumber() { return number; }

        @Override
        public String toString() { return number+"(sub: "+relative_index+")"; }
    }
}
