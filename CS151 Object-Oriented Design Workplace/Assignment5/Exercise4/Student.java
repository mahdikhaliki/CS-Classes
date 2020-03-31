public class Student implements Cloneable {
    private String firstName, lastName, major, department;
    private int age;
    private float gpa;
    private final Course CS151 = new Course("CS151",
        "Object Oriented Design and Programming", "CS", "6:00PM", "Tue");
    private final Course CS49J = new Course("CS49J",
        "Programming in Java", "CS", "6:00PM", "Thur");
    private final Course CS154 = new Course("CS154",
        "Formal Languages", "CS", "4:30PM", "Tue");
    private final Course CS174 = new Course("CS174",
        "Server Side Programming", "CS", "12:00PM", "Mon");

    public Student(String firstName, String lastName, int age, float gpa,
        String major, String department) {
            this.firstName = firstName;
            this.lastName = lastName;
            this.major = major;
            this.department = department;
            this.age = age;
            this.gpa = gpa;
    }

    public void printInfo() {
        System.out.println("Name: "+firstName+' '+lastName+
                           "\nAge: "+age+
                           "\nMajor: "+major+
                           "\nDepartment: "+department+
                           "\nGPA: "+gpa+
                           "\nCourses: ");
        CS151.printInfo();
        CS49J.printInfo();
        CS154.printInfo();
        CS174.printInfo();
    }

    public Object clone() {
        return new Student(firstName, lastName, age, gpa, major, department);
    }

    public void setFirstName(String firstName) { this.firstName = firstName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setMajor(String major) { this.major = major; }
    public void setDepartment(String department) { this.department = department; }
    public void setAge(int age) { this.age = age; }
    public void setGpa(float gpa) { this.gpa = gpa; }

    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public String getMajor() { return major; }
    public String getDepartment() { return department; }
    public int getAge() { return age; }
    public float getGpa() { return gpa; }
}
