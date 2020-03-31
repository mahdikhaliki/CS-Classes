public class StudentTest {
    public static void main(String[] args) {
        Student john = new Student("John", "Smith", 20, 3.6f, "Computer Science",
            "School of Computer Science");
        Student johnClone = (Student) john.clone();

        System.out.println();
        john.printInfo();
        System.out.println("\nClone of John Smith:\n");
        johnClone.printInfo();
    }
}
