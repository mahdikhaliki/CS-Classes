public class Person {
    private String firstName, lastName, address, gender, social;
    private int age;
    private float weight;

    public Person(String firstName, String lastName, String address, String gender,
                  String social, int age, float weight) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.address = address;
        this.gender = gender;
        this.social = social;
        this.age = age;
        this.weight = weight;
    }

    public void setFirstName(String firstName) { this.firstName = firstName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setAddress(String address) { this.address = address; }
    public void setGender(String gender) { this.gender = gender; }
    public void setSocial(String socialSecurity) { this.social = social; }
    public void setAge(int age) { this.age = age; }
    public void setWeight(float weight) { this.weight = weight; }

    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public String getAddress() { return address; }
    public String getGender() { return gender; }
    public String getSocial() { return social; }
    public int getAge() { return age; }
    public float getWeight() { return weight; }

    public String toString() {
        return firstName+' '+lastName+", "+address;
    }

    public void introduce() {
        System.out.println("\nName: "+firstName+' '+lastName+
                           "\nGender: "+gender+
                           "\nAge: "+age+
                           "\nWeight: "+weight+" lbs"+
                           "\nSocial Security Number: "+social+
                           "\nAddress: "+address);
    }
}
