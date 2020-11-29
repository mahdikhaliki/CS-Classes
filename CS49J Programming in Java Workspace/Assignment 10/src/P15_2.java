import java.util.*;

public class P15_2 {
    public static void main(String[] args) {
        SortedMap<Student, String> grades = new TreeMap<>();
        SortedMap<Integer, List<String>> students  = new TreeMap<>();

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
                case 1: addStudent(grades, students, in); break;
                case 2: removeStudent(grades, students, in); break;
                case 3: modifyGrade(grades, students, in); break;
                case 4: printAllGrades(grades); break;
                default:
            }
        } while(input != 5);
    }

    public static void addStudent(Map grades, Map students, Scanner in) {
        String first, last, grade;
        int id;

        System.out.println("\n\nEnter student's first name: ");
        first = in.nextLine();
        System.out.println("Enter student's last name: ");
        last = in.nextLine();
        System.out.println("Enter student's ID: ");
        id = in.nextInt();
        in.nextLine();
        System.out.println("Enter grade: ");
        grade = in.nextLine();

        List<String> list = new LinkedList<>();
        list.add(first);
        list.add(last);
        students.put(id, list);
        grades.put(new Student(first, last, id), grade);
        System.out.println("Successfully added "+first+" "+last);
    }

    public static void removeStudent(Map grades, Map<Integer, List<String>> students, Scanner in) {
        int id;

        System.out.println("\n\nEnter student ID to remove:");
        id = in.nextInt();
        in.nextLine();
        List<String> list = students.get(id);
        if (list != null && grades.remove(new Student(list.get(0), list.get(1), id)) != null) {
            System.out.println("Successfully removed " + list.get(0)+" "+list.get(1));
        }
        else System.out.println("Student with ID: "+id+" does not exist");
    }

    public static void modifyGrade(Map grades, Map<Integer, List<String>> students, Scanner in) {
        String grade;
        int id;

        System.out.println("\n\nEnter student ID: ");
        id = in.nextInt();
        in.nextLine();

        List<String> list = students.get(id);
        Student student = null;
        if (list != null)
            student = new Student(list.get(0), list.get(1), id);

        if (student != null && grades.containsKey(student)) {
            System.out.println("Enter new grade: ");
            grade = in.nextLine();
            grades.replace(student, grade);
            System.out.println("Grade successfully updated for "+list.get(0)+" "+list.get(1));
        }
        else System.out.println("Student with ID: "+id+" does not exist");
    }

    public static void printAllGrades(Map<Student, String> grades) {
        System.out.println("\n");
        for (Student key : grades.keySet())
            System.out.println(key.getFirst()+" "+key.getLast() + " id: " + key.getID() + ": "
                    +grades.get(key));
    }
}