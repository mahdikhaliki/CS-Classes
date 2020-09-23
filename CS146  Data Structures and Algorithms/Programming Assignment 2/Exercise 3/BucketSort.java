import java.util.Iterator;
import java.util.LinkedList;

/**
 * The BucketSort class uses the bucketSort() to sort an array of Numbers that
 * contains an integer and it's relative index in an array. We want to see if
 * bucket sort is a stable algorithm. If the sorting result is in order both
 * in terms of its integer and relative indices then the sort is stable.
 *
 * @author Mahdi Khaliki
 */

public class BucketSort {
    private static final int ARRAY_SIZE = 15;

    public static void main(String[] args) {
        Number[] nums = new Number[ARRAY_SIZE];
        int[] integers = {7, 7, 2, 8, 4, 2, 3, 5, 4, 8, 3, 6, 4, 6, 2};
        int[] relative_index = {1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 3, 2, 3};

        for(int i = 0; i < ARRAY_SIZE; i++)
            nums[i] = new Number(integers[i], relative_index[i]);

        System.out.println("Original array:");
        printArray(nums);

        bucketSort(nums);

        System.out.println("Sorted array: ");
        printArray(nums);
        System.out.println("The relative indices are also in order which proves " +
                "that bucket sort a stable sorting algorithm when using an intermediate stable sort");
    }

    /**
     * bucketSort() uses the following equation for determining bucket indices:
     *      value*number_of_elements / (max_array_value+1)
     * Insertion sort is used to sort each bucket which is a linked list.
     *
     * @param (Number[] nums) (An array of numbers that also have their relative indices attached)
     */
    public static void bucketSort(Number[] nums) {
        int max_element = max(nums);
        int n = nums.length;
        LinkedList<Number>[] B = new LinkedList[n];

        // Initializing each bucket to a new LinkedList
        for(int i = 0; i < n; i++)
            B[i] = new LinkedList<>();

        // Inserting the elements into their respective bucket
        for(int i = 0; i < n; i++) {
            int index = (n * nums[i].getNumber()) / (max_element+1);
            B[index].add(nums[i]);
        }

        // Using insertion sort to sort each bucket
        for(int i = 0; i < B.length; i++)
            if(!B[i].isEmpty())
                insertionSort(B[i]);

        // Copying each bucket back to the original array
        int index = 0;
        for(int i = 0; i < B.length; i++)
            if(!B[i].isEmpty())
                for(Iterator<Number> t = B[i].iterator(); t.hasNext();)
                    nums[index++] = t.next();
    }

    /**
     * Finds the maximum element in an array of Numbers
     *
     * @param (Number[] nums) (An array of numbers that also have their relative indices attached)
     * @return (The integer value of the largest element in the list)
     */
    public static int max(Number[] nums) {
        int max = nums[0].getNumber();
        for(Number num : nums)
            max = Math.max(max, num.getNumber());
        return max;
    }

    /**
     * Uses insertion sort algorithm to sort a linked list.
     *
     * @param (LinkedList<Number> list) (A linked list of Numbers)
     */
    public static void insertionSort(LinkedList<Number> list) {
        for(int j = 1; j < list.size(); j++) {
            Number key = list.get(j);
            int i = j-1;

            while(i >= 0 && list.get(i).getNumber() > key.getNumber()) {
                list.set(i+1, list.get(i));
                i--;
            }
            list.set(i+1, key);
        }
    }

    /**
     * printArray() is used to print the Numbers array.
     *
     * @param (Number[] array) (The array we want to print to console)
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
