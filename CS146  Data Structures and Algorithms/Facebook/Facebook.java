import java.util.Iterator;
import java.util.Random;

/**
 * The Facebook class utilizes chained-hashing to store Person objects. The hashing method of choice
 * is the division method. The table is an array of LinkedLists with a size of 15 but can be changed if needed.
 *
 * @author Mahdi Khaliki
 */

public class Facebook {
    private LinkedList[] users;
    private static final int TABLE_SIZE = 15;

    /**
     * The constructor initialized the table to a new array, iterates and initializes each element
     * to a new LinkedList object.
     */
    public Facebook() {
        users = new LinkedList[TABLE_SIZE];

        for(int i = 0; i < TABLE_SIZE; i++)
            users[i] = new LinkedList();
    }

    /**
     * Adds a new Person to Facebook using the index from hash(). Calls the add()
     * of the LinkedList class at the slot the name is supposed to inserted into.
     *
     * @param (String name) (The name of the Person we want to add to Facebook)
     */
    public void add(String name) {
        int index = hash(name);
        LinkedList slot = users[index];
        slot.add(new Person(name));
    }

    /**
     * Deletes a Person from Facebook using the index from hash(). Calls the remove()
     * of the LinkedList class at the slot the name is supposed to deleted in.
     * Throws PersonNotFoundException if the Person is not a user in Facebook.
     *
     * @param (String name) (The name of the Person we want to delete from Facebook)
     */
    public void delete(String name) throws LinkedList.PersonNotFoundException {
        Person person = findPerson(name);
        int index = hash(name);
        LinkedList slot = users[index];
        slot.remove(person);
    }

    /**
     * Converts the String name to a natural number by taking the ascii code of each character
     * and subtracting ('a'+1) from it. This will yield a number from [1, 26] that is then
     * multiplied by 26^i where i goes from 0 to n-1, n = name.length().
     * Each character is then summed up and the remainder is taken after dividing by TABLE_SIZE.
     *
     * @param (String name) (The name of the Person we want to remove from Facebook)
     */
    public int hash(String name) {
        int natural_number = 0;
        name = name.toLowerCase();

        for(int i = 0; i < name.length(); i++)
            natural_number += (name.charAt(i) - 'a' + 1) * Math.pow(26, i);

        return natural_number % TABLE_SIZE;
    }

    /**
     * Randomly adds friends for each user of Facebook by iterating over each Person in the hashtable
     * and finding a random person to friend. Ensures that the random person is not friends already and
     * that the random person is not the same person that we are trying to friend.
     *
     * Note: This is mainly for simulation purposes.
     */
    public void randomlyAddFriends() {
        Random rand = new Random();

        for(int i = 0; i < TABLE_SIZE; i++) {
            Iterator<Person> iterator = users[i].iterator();
            while(iterator.hasNext()) {
                int numFriends = rand.nextInt(5-1) + 1;
                Person currentPerson = iterator.next();

                for(int k = 0; k < numFriends; k++) {
                    Person randomPerson = findRandomPerson();
                    if(!currentPerson.isFriends(randomPerson) && !currentPerson.equals(randomPerson.getName()))
                        currentPerson.addFriend(randomPerson);
                }
            }
        }
    }

    /**
     * Finds a random Person from the hashtable and returns it.
     *
     * @return (A random person from the hashtable)
     */
    public Person findRandomPerson() {
        Random rand = new Random();
        int table_index = 0;
        int chain_index = 0;

        do {
            table_index = rand.nextInt(TABLE_SIZE - 1) + 1;
            chain_index = users[table_index].size() - 1;
        } while(chain_index <= 0);

        chain_index = rand.nextInt(chain_index) + 1;

        return users[table_index].getAtIndex(chain_index);
    }

    /**
     * Searches the hashtable, using hashing, for a person with the name passed in.
     * Throws PersonNotFoundException if the user is not a Person in Facebook.
     *
     * @return (A random person from the hashtable)
     */
    public Person findPerson(String name) throws LinkedList.PersonNotFoundException {
        int index = hash(name);
        return users[index].find(name);
    }

    /**
     * Friends two Person objects that are passed in.
     *
     * @param (Person person1) (A person object)
     * @param (Person person2) (A person object)
     */
    public void addFriendship(Person person1, Person person2) {
        person1.addFriend(person2);
    }

    /**
     * Unfriends two Person object that are passed in.
     * Throws PersonNotFoundException if one of the Person is not a Facebook user.
     *
     * @param (Person person1) (A person object)
     * @param (Person person2) (A person object)
     */
    public void removeFriendship(Person person1, Person person2) throws LinkedList.PersonNotFoundException {
        person1.removeFriend(person2);
    }

    /**
     * A String representation of all the users in Facebook. Each user is displayed on a new line.
     *
     * @return (A String of all the users in Facebook)
     */
    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();

        for(int i = 0, j = 1; i < TABLE_SIZE; i++) {
            Iterator<Person> iterator = users[i].iterator();
            while (iterator.hasNext())
                string.append((j++)+": "+iterator.next()+"\n");
        }
        return string.toString();
    }

    /**
     * A String representation of all slots and collisions in the hashtable.
     *
     * @return (A String of all the slots and collisions in hashtable)
     */
    public String hashtableToString() {
        StringBuilder string = new StringBuilder();

        for(int i = 0, j = 1; i < TABLE_SIZE; i++) {
            Iterator<Person> iterator = users[i].iterator();
            string.append("["+i+"] : ");
            while (iterator.hasNext())
                string.append(" -> "+iterator.next());
            string.append("\n");
        }
        return string.toString();
    }
}