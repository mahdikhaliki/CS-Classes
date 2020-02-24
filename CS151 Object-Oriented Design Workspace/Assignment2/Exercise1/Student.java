import java.util.*;

public class Student {
    private String firstName, lastName, major, department;
    private int age;
    private float gpa;

    private Course courses;

    public Student() {
        firstName = lastName = major = department = "";
        age = 0;
        gpa = 0.0f;
        courses = new Course();
    }

    public Student(String firstName, String lastName, int age, float gpa,
                   String major, String department) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.gpa = gpa;
        this.major = major;
        this.department = department;
        courses = new Course();
    }

    public void setFirstName(String firstName) { this.firstName = firstName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setAge(int age) { this.age = age; }
    public void setGpa(float gpa) { this.gpa = gpa; }
    public void setMajor(String major) { this.major = major; }
    public void setDepartment(String department) { this.department = department; }

    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public int getAge() { return age; }
    public float getGpa() { return gpa; }
    public String getMajor() { return major; }
    public String getDepartment() { return department; }

    public void addCourse(String course, String time, String days) {
        courses.addCourse(course, time, days);
    }

    public void printSchedule() {
        courses.printSchedule();
    }

    public void printStudentInfo() {
        System.out.println('\n'+firstName+' '+lastName+", "+age+", "+gpa+", "+
                            major+", "+department);
    }

    class Course {
        ArrayList<String> courses;

        public Course() { courses = new ArrayList<String>(); }

        public void addCourse(String course, String time, String days) {
            courses.add(course+' '+time+' '+days);
        }

        public void printSchedule() {
            System.out.println('\n'+firstName+' '+lastName+"\'s Schedule:");
            for (String course : courses)
                System.out.println(course);
        }
    }
}
