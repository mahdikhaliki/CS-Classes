public class E9_13 {
    public static void main(String[] args) {
        BetterRectangle rect = new BetterRectangle(5, 6, 0, 0);
        BetterRectangle rect2 = new BetterRectangle(11, 34, 0, 0);

        System.out.println("Perimeter of a 5x6 rectangle = " + rect.getPerimeter());
        System.out.println("Area of a 5x6 rectangle = " + rect.getArea());

        System.out.println("\nPerimeter of a 11x34 rectangle = " + rect2.getPerimeter());
        System.out.println("Area of a 11x34 rectangle = " + rect2.getArea());
    }
}
