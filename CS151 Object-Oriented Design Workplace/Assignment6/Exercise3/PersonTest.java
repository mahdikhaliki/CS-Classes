import java.util.*;

public class PersonTest {
    public static void main(String[] args) {
        ArrayList<Person> persons = new ArrayList<>();
        persons.add(new Person("Joe", "Smith", 40));
        persons.add(new Person("Amy", "Gold", 32));
        persons.add(new Person("Tony", "Stork", 21));
        persons.add(new Person("Sean", "Irish", 24));
        persons.add(new Person("Tina", "Brock", 28));
        persons.add(new Person("Lenny", "Hep", 18));

        printList(persons);
        System.out.println("\n\nSorting by age in ascending order.\n");
        persons.sort(Comparator.comparingInt(Person::getAge));
        printList(persons);
        System.out.println("\n\nSorting by age in decending order.\n");
        Collections.reverse(persons);
        printList(persons);

        System.out.println("\n\nSorting by first name in ascending order.\n");
        persons.sort(Comparator.comparing(Person::getFirstName));
        printList(persons);
        System.out.println("\n\nSorting by first name in decending order.\n");
        Collections.reverse(persons);
        printList(persons);

        Comparator<Person> compareByLastLen = new Comparator<Person>() {
            @Override
            public int compare(Person p1, Person p2) {
                return p1.getLastName().length() - p2.getLastName().length();
            }
        };

        System.out.println("\n\nSorting by length of last name in ascending order.\n");
        Collections.sort(persons, compareByLastLen);
        printList(persons);
        System.out.println("\n\nSorting by length of last name in decending order.\n");
        Collections.reverse(persons);
        printList(persons);

    }

    public static void printList(List<Person> list) {
        for(Person person : list) System.out.println(person);
    }
}
