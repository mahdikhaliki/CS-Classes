import java.util.Iterator;

/**
 * The Person class represents a facebook user with a name and a list of friends.
 * Also implements the Comparable interface for comparing two Person objects in the BST.
 *
 * @author Mahdi Khaliki
 */

public class Person implements Comparable<Person> {
    private String name;
    private LinkedList friends;

    /**
     * The Person constructor assigns the name and initializes a LinkedList of friends.
     *
     * @param (String name) (The name of the user)
     */
    public Person(String name) {
        this.name = name;
        friends = new LinkedList();
    }

    /**
     * Adds a friend to this person's friend list and friend's list of this person.
     * So it adds both individuals to each other's friends list.
     *
     * @param (Person friend) (The Person object which we want to friend)
     */
    public void addFriend(Person friend) {
        friends.add(friend);
        friend.friends.add(this);
    }

    /**
     * Removes a friend from this person's friend list and friend's list of this person.
     * So it removes both individuals from each others friends list.
     * Throws a PersonNotFoundException if the friend object is not a friend of this user
     *
     * @param (Person friend) (The Person object which we want to unfriend)
     */
    public void removeFriend(Person friend) throws LinkedList.PersonNotFoundException {
        friends.remove(friend);
        friend.friends.remove(this);
    }

    /**
     * Checks if two persons are friends.
     *
     * @param (Person person) (The Person object which we want to check)
     * @return (True if the two are friends, false otherwise)
     */
    public boolean isFriends(Person person) {
        return friends.contains(person);
    }

    /**
     * Returns a String representation of the friends list. Refer to LinkedList toString()
     * for formatting.
     *
     * @return (A String of the people in the friends list)
     */
    public String getFriends() {
        return friends.toString();
    }

    /**
     * Creates a BST object and adds each friend to the BST. Then calls the inorderString() of the
     * BST class to return a sorted order string of this Person's friends.
     *
     * @return (A sorted String of the people in the friends list)
     */
    public String stringOfSortedFriends() {
        BST bst = new BST();
        Iterator<Person> iterator = friends.iterator();
        while(iterator.hasNext())
            bst.add(iterator.next());

        return bst.inorderString();
    }

    /**
     * Returns a string representation of the Person.
     *
     * @return (The name of the user)
     */
    @Override
    public String toString() {
        return name;
    }

    /**
     * Checks if this person has the same name as the one passed in.
     *
     * @param (String name) (The name we want to compare with)
     * @return (True if the names match, false otherwise)
     */
    @Override
    public boolean equals(Object name) {
        String other = (String) name;

        return this.name.equals(other) ? true : false;
    }

    /**
     * Getter for name attribute.
     *
     * @return (The name of this Person)
     */
    public String getName() { return name; }

    /**
     * Compares two person objects based on their name attributes.
     * returns < 0 if this Person is alphabetically before the person object passed in.
     * returns 0 if this Person is alphabetically equal the person object.
     * returns > 0 if this Person is alphabetically after the person object.
     *
     * @return (A number representing the comparison outlined above)
     */
    @Override
    public int compareTo(Person person) {
        return this.name.compareTo(person.name);
    }
}

