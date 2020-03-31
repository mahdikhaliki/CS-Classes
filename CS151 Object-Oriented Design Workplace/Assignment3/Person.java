public abstract class Person {
    private String firstName, lastName, accommodations, social;
    private int age, id;
    private Address address;

    public Person() {
        firstName = lastName = accommodations = social = "";
        age = id = 0;
        address = new Address();
    }

    public Person(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
        accommodations = social = "";
        age = id = 0;
        address = new Address();
    }

    public Person(String firstName, String lastName, Address address) {
        this.firstName = firstName;
        this.lastName = lastName;
        accommodations = social = "";
        age = id = 0;
        this.address = address;
    }

    public String toString() {
        return firstName+' '+lastName+
               "\nage: "+age+
               "\nID: "+id+
               "\nAddress: "+address.toString()+
               "\nAccommodations: "+accommodations;
    }

    public abstract void introduce();
    public abstract void introduce(boolean social);

    public void setFirstName(String firstName) { this.firstName = firstName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setId(int id) { this.id = id; }
    public void setSocial(String socialSecurity) { social = socialSecurity; }
    public void setAge(int age) { this.age = age; }
    public void setAddress(Address address) { this.address = address; }
    public void setAccommodations(String accommodations) {
        this.accommodations = accommodations;
    }

    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public int getId() { return id; }
    public String getSocial() { return social; }
    public int getAge() { return age; }
    public Address getAddress() { return address; }
    public String getAccommodations() { return accommodations; }
}
