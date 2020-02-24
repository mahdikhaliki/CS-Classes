import java.util.ArrayList;

public class P18_4 {
    public interface GenericMeasurable<S> {
        Integer getMeasure();
    }

    public static <T extends GenericMeasurable> T max(ArrayList<T> arr) {
        if (arr.size() == 0) return null;
        T max = arr.get(0);
        for (T a : arr)
            if (a.getMeasure() > max.getMeasure())
                max = a;
        return max;
    }

    public static void main(String[] args) {
        ArrayList<GenericMeasurable<Integer>> arr = new ArrayList<>();
        arr.add(new GenericMeasurable() {
            public Integer getMeasure() {
                return new Integer(1);
            }
        });
        arr.add(new GenericMeasurable() {
            public Integer getMeasure() {
                return new Integer(15);
            }
        });
        arr.add(new GenericMeasurable() {
            public Integer getMeasure() {
                return new Integer(3);
            }
        });

        System.out.println("Largest = "+max(arr).getMeasure());
    }
}
