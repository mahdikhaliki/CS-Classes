import java.util.Iterator;

/**
 * The LinkedList class is a data structure that uses chaining to form a list.
 * In this case a double-ly linked list is implemented where each Node contains
 * the previous and next Node.
 *
 * @author Mahdi Khaliki
 */

public class LinkedList implements Iterable<Person> {
    private Node head;
    private int size;

    /**
     * The LinkedList constructor initializes the head to a null pointer and the size to 0.
     */
    public LinkedList() {
        head = null;
        size = 0;
    }

    /**
     * Adds a Person object to the head of the linked list.
     *
     * @param (Person person) (A Person object that needs to be added to the linked list)
     */
    public void add(Person person) {
        Node node = new Node(person, null, head);
        head = node;
        if(head.next != null)
            head.next.previous = head;
        size++;
    }

    /**
     * Traverses the list and removes the Person object from the list. Throws a PersonNotFoundException
     * if the person object does not exist in the table.
     *
     * @param (Person person) (The person object that needs to be removed from the list)
     */
    public void remove(Person person) throws PersonNotFoundException {
        Node traverse = head;

        while (traverse != null && !traverse.val.equals(person.getName()))
            traverse = traverse.next;

        if (traverse == null)
            throw new PersonNotFoundException("Could not find friend in list");

        if (traverse.previous == null)
            head = traverse.next;
        else
            traverse.previous.next = traverse.next;

        if (traverse.next != null)
            traverse.next.previous = traverse.previous;
        size--;
    }

    /**
     * Traverses the list till it reaches the given index then returns the Person object at that index.
     *
     * @return (A Person object at the given index in the linked list)
     */
    public Person getAtIndex(int index) {
        if (index >= size) throw new IndexOutOfBoundsException();

        Node traverse = head;
        for (int i = 0; i < index; i++)
            traverse = traverse.next;

        return traverse.val;
    }

    /**
     * Getter for size of the list.
     *
     * @return (An int for the size of the list)
     */
    public int size() {
        return size;
    }

    /**
     * Traverses the list to find a user that matches the name passed in. Throws a PersonNotFoundException
     * if the user does not exist in the list.
     *
     * @param (String name) (The name of the person which we want to find in the list)
     * @return (A Person object that matches the name passed in.)
     */
    public Person find(String name) throws PersonNotFoundException {
        Node traverse = head;

        while (traverse != null && !traverse.val.equals(name))
            traverse = traverse.next;

        if (traverse == null)
            throw new PersonNotFoundException("Could not find "+name+" in list");

        return traverse.val;
    }

    /**
     * Traverses the list and checks if the user exists in the list.
     *
     * @@return (Returns true if the person exists in the list, false otherwise)
     */
    public boolean contains(Person person) {
        Node traverse = head;

        while (traverse != null && !traverse.val.equals(person.getName()))
            traverse = traverse.next;

        return traverse == null ? false : true;
    }

    /**
     * Goes through the linked list and forms a String representing all the Person objects in the list.
     * Each Person object is written on a new line.
     *
     * @return (String containing all the elements in the linked list)
     */
    public String toString() {
        Node traverse = head;
        StringBuilder persons = new StringBuilder();

        while (traverse != null) {
            persons.append(traverse.val+"\n");
            traverse = traverse.next;
        }
        return persons.toString().trim();
    }

    /**
     * An iterator for the linked list.
     *
     * @return (An Iterator object for the given list)
     */
    @Override
    public Iterator<Person> iterator() {
        return new LinkedListIterator(this);
    }

    /**
     * The PersonNotFoundException signifies that a person was not found in the linked list.
     */
    class PersonNotFoundException extends Exception {
        public PersonNotFoundException(String error) {
            super(error);
        }
    }

    /**
     * The Node class contains a val (Person object), previous, and next Nodes.
     */
    class Node {
        public Person val;
        public Node previous, next;

        /**
         * The Node constructor initializes a node with the parameters passed in.
         */
        public Node(Person val, Node previous, Node next) {
            this.val = val;
            this.previous = previous;
            this.next = next;
        }
    }

    /**
     * An iterator class that is used for the LinkedList class.
     */
    class LinkedListIterator implements Iterator<Person> {
        Node current;

        /**
         * The LinkedListIterator initializes the current Node to the head of the list that is passed in.
         *
         * @param (LinkedList list) (The list in which the iterator will use)
         */
        public LinkedListIterator(LinkedList list) {
            current = list.head;
        }

        /**
         * Checks to see if the list has another element.
         *
         * @return (Returns true if there is an object to return, false otherwise)
         */
        public boolean hasNext() {
            return current != null;
        }

        /**
         * Returns the next object in the list.
         *
         * @return (The next object in the list)
         */
        public Person next() {
            Person data = current.val;
            current = current.next;
            return data;
        }
    }
}