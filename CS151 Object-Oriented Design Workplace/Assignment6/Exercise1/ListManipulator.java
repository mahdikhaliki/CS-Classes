import java.util.*;

public class ListManipulator {

    public static ArrayList<Integer> sort(ArrayList<Integer> myLst, Boolean ascending) {
        Collections.sort(myLst);
        if(!ascending) Collections.reverse(myLst);
        return myLst;
    }

    public static ArrayList<Integer> swapLargestSmallest(ArrayList<Integer> myLst) {
        if(myLst.isEmpty()) return myLst;

        int minIndex = 0, maxIndex = 0;

        for(int i = 1; i < myLst.size(); i++) {
            if(myLst.get(i) < myLst.get(minIndex)) minIndex = i;
            if(myLst.get(i) > myLst.get(maxIndex)) maxIndex = i;
        }

        int temp = myLst.get(minIndex);
        myLst.set(minIndex, myLst.get(maxIndex));
        myLst.set(maxIndex, temp);

        return myLst;
    }

    public static void table(ArrayList<Integer> myLst) {
        
    }


    Accepts an array list of integers, creates a table of unique values and the number of times each value occurs, sorts this table, and outputs it to command line.


    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        Random rand = new Random();

        for(int i = 0; i < 15; i++)
            arr.add(rand.nextInt(100));

        // sort(arr, true);
        // System.out.println(arr);
        // sort(arr, false);
        // System.out.println(arr);

        System.out.println(arr);
        swapLargestSmallest(arr);
        System.out.println(arr);
    }
}
