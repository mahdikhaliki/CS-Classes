import javafx.util.Pair;

public class P18_1 {
    public interface Measurable {
        double getMeasure();
    }

    public static class DoubleValue implements Measurable {
        private double a;

        public DoubleValue(double value) { a = value; }

        public double getMeasure() { return a; }
    }

    public static <E extends Measurable> Pair<E, E> minMax(E[] arr) {
        if (arr.length == 0) return null;

        E min = arr[0];
        E max = arr[0];

        for (int i = 0; i < arr.length; i++) {
            if (arr[i].getMeasure() < min.getMeasure()) {
                min = arr[i];
            }
            if (arr[i].getMeasure() > max.getMeasure()) {
                max = arr[i];
            }
        }
        return new Pair<>(min, max);
    }

    public static void main(String[] args) {
        DoubleValue[] list = new DoubleValue[4];

        list[0] = new DoubleValue(10);
        list[1] = new DoubleValue(0);
        list[2] = new DoubleValue(1);
        list[3] = new DoubleValue(6);

        Pair<DoubleValue, DoubleValue> p = minMax(list);
        System.out.println("Min = "+p.getKey().getMeasure()+"\nMax = "+p.getValue().getMeasure());
    }
}
