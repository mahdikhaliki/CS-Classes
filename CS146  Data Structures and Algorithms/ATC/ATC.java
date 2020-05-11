import java.util.*;

/**
 * The ATC class simulates the Air Traffic Control process by implementing
 * a priority queue data structure using an underlying heap structure.
 * Airplane objects are stored using maxHeapInsert() in the priority queue
 * and can be accessed or extracted using heapMaximum() or heapExtractMax()
 * respectively. There is a provided heapSort() to return a sorted list
 * of airplane objects based on the approach code (AC).
 *
 * @author Mahdi Khaliki
 */

public class ATC {
    private ArrayList<Airplane> heap;

    /**
     * The ATC constructor initializes an ArrayList which is used to store
     * Airplane objects.
     */
    public ATC() {
        heap = new ArrayList<>();
    }

    /**
     * maxHeapify() is used to maintain the max-heap property. It swaps the array[i] with
     * the largest of its children nodes. This method is called recursively until the root
     * node is larger than it's children.
     *
     * @param (ArrayList<Airplane> array) (ArrayList used to store Airplane objects in a max-heap structure)
     * @param (int i) (The index at which we want to ensure the max-heap property exists)
     * @param (int size) (The size of the array)
     */
    public void maxHeapify(ArrayList<Airplane> array, int i, int size) {
        int l = i*2;
        int r = i*2 + 1;
        int largest = Integer.MIN_VALUE;

        if(l < size && (array.get(l).getApproachCode() > array.get(i).getApproachCode()))
            largest = l;
        else
            largest = i;

        if(r < size && (array.get(r).getApproachCode() > array.get(largest).getApproachCode()))
            largest = r;

        if(largest != i) {
            Collections.swap(array, i, largest);
            maxHeapify(array, largest, size);
        }
    }

    /**
     * buildMaxHeap() uses maxHeapify() to convert an array into a max-heap.
     *
     * @param (ArrayList<Airplane> array) (ArrayList which will be mutated to form a max-heap)
     */
    public void buildMaxHeap(ArrayList<Airplane> array) {
        for(int i = array.size()/2+1; i >= 0; i--)
            maxHeapify(array, i, array.size());
    }

    /**
     * heapSort() clones the heap, and sorts it using buildMaxHeap() and maxHeapify().
     * The objects are sorted in ascending order and then reversed before returning.
     *
     * @return (ArrayList<Airplane> a sorted list based on an airplane's approach code).
     */
    public ArrayList<Airplane> heapSort() {
        ArrayList<Airplane> sorted = (ArrayList<Airplane>) heap.clone();
        int array_size = sorted.size();
        buildMaxHeap(sorted);

        for(int i = sorted.size()-1; i > 0; i--) {
            Collections.swap(sorted, 0, i);
            array_size--;
            maxHeapify(sorted,0, array_size);
        }
        Collections.reverse(sorted);
        return sorted;
    }

    /**
     * Allows the user to insert a new airplane into heap based on its AC while maintaining the
     * max-heap structure.
     *
     * @param (Airplane airplane) (An airplane object which the user wants to insert)
     */
    public void maxHeapInsert(Airplane airplane) {
        heap.add(new Airplane("Temp", Integer.MAX_VALUE, 0));
        heapIncreaseKey(heap.size()-1, airplane);
    }

    /**
     * Allows the user to choose any one of the airplanes stored in the Heap Priority Queue
     * and increase its AC score with its priority in the queue.
     *
     * @param (int i) (The index which we want to increase the approach code)
     * @param (Airplane airplane) (An airplane object which has an updated AC score)
     * @return (boolean returns true if the increase was successful, false if otherwise)
     */
    public boolean heapIncreaseKey(int i, Airplane airplane) {
        if (airplane.getApproachCode() < heap.get(i).getApproachCode()) {
            System.out.println("Error: New key is smaller than the current key");
            return false;
        }

        heap.set(i, airplane);

        while(i > 0 && heap.get(i/2).getApproachCode() < heap.get(i).getApproachCode()) {
            Collections.swap(heap, i, i/2);
            i /= 2;
        }
        return true;
    }

    /**
     * Removes and returns the airplane with the max AC score in the priority queue.
     *
     * @return (Airplane returns the airplane with the max AC score)
     */
    public Airplane heapExtractMax() {
        if(heap.isEmpty()) {
            System.out.println("Error: Heap underflow");
            return new Airplane("Queue is empty", 0, 0);
        }

        Airplane max = heap.get(0);
        int lastIndex = heap.size()-1;
        if(heap.size() == 1) {
            heap.remove(0);
        }
        else {
            heap.set(0, heap.remove(lastIndex));
            maxHeapify(heap, 0, heap.size());
        }
        return max;
    }

    /**
     * Returns the airplane with the max AC score in the priority queue.
     *
     * @return (Airplane returns the airplane with the max AC score)
     */
    public Airplane heapMaximum() { return heap.get(0); }

    /**
     * Retrieves the index of an airplane object based on the flight number. This is used for
     * the UI and the ability for a user to increase an AC score.
     *
     * @param (String flight_number) (The flight number of an airplane we are looking for)
     * @return (int an index of an airplane from the list, -1 if cannot be found in list)
     */
    public int getIndex(String flight_number) {
        for(int i = 0; i < heap.size(); i++)
            if(heap.get(i).getFlightNumber().equals(flight_number)) return i;
        return -1;
    }

    /**
     * Retrieves an airplane object at a given index. This is used for the UI and the ability
     * for a user to increase an AC score.
     *
     * @param (int index) (The index of an airplane in the list)
     * @return (Airplane object at the given index)
     */
    public Airplane getAtIndex(int index) { return heap.get(index); }
}
