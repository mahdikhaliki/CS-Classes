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

        Collections.swap(myLst, minIndex, maxIndex);
        return myLst;
    }

    public static void table(ArrayList<Integer> myLst) {
        Hashtable<Integer, Integer> ht = new Hashtable<>();
        PriorityQueue<Integer> sortedKeys = new PriorityQueue<>();

        for(Integer integer : myLst) {
            if(ht.containsKey(integer)) {
                int frequency = ht.get(integer) + 1;
                ht.put(integer, frequency);
            }
            else{
                ht.put(integer, 1);
                sortedKeys.add(integer);
            }
        }

        System.out.println("\n[Integer, Frequency]");
        while(sortedKeys.size() > 0) {
            int key = sortedKeys.poll();
            System.out.print("["+key+", "+ht.get(key)+"] ");
        }
        System.out.println();
    }
}
