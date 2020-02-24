import java.util.*;

public class E15_4 {
    public static void main(String[] args) {
        SortedMap<String, String> grades = new TreeMap<>();
        Scanner in = new Scanner(System.in);
        int input;
        do {
            do {
                System.out.println("\n\nSelect from one of the options below:\n" +
                        "1. Add student\n2. Remove student\n3. Modify grade\n4. Print all grades\n5. Quit");
                input = in.nextInt();
                in.nextLine();
                if (input < 1 || input > 5) System.out.print("\n\nInvalid option");
            } while (input < 1 || input > 5);

            switch (input) {
                case 1: addStudent(grades, in); break;
                case 2: removeStudent(grades, in); break;
                case 3: modifyGrade(grades, in); break;
                case 4: printAllGrades(grades); break;
                default:
            }
        } while(input != 5);
    }

    public static void addStudent(Map grades, Scanner in) {
        String name, grade;

        System.out.println("\n\nEnter student name: ");
        name = in.nextLine();
        System.out.println("Enter grade: ");
        grade = in.nextLine();
        grades.put(name, grade);
        System.out.println("Successfully added "+name);
    }

    public static void removeStudent(Map grades, Scanner in) {
        String name;

        System.out.println("\n\nEnter student name to remove:");
        name = in.nextLine();

        if (grades.remove(name) != null)
            System.out.println("Successfully removed " + name);
        else System.out.println(name+" does not exist");
    }

    public static void modifyGrade(Map grades, Scanner in) {
        String name, grade;

        System.out.println("\n\nEnter student name: ");
        name = in.nextLine();
        if (grades.containsKey(name)) {
            System.out.println("Enter new grade: ");
            grade = in.nextLine();
            grades.replace(name, grade);
        }
        else System.out.println(name+" does not exist");
    }

    public static void printAllGrades(Map grades) {
        System.out.println("\n");
        for (Object key : grades.keySet())
            System.out.println(key+": "+grades.get(key));
    }
}
