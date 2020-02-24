import java.util.ArrayList;

public class E18_12 {
    public static <T extends Iterable<E>, E> void print(T list) {
        int count = 0;
        for (E e : list) {
            if (count++ != 0)
                System.out.print(", " + e);
            else
                System.out.print(e);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ArrayList<Integer> ints = new ArrayList<>();
        ints.add(1);
        ints.add(3);
        ints.add(4);
        ints.add(5);
        print(ints);
    }
}
