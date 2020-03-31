import java.util.*;

public class Student implements Cloneable {
    private String firstName, lastName, major, department;
    private int age;
    private float gpa;
    private LinkedList<Course> courses;

    public Student(String firstName, String lastName, int age, float gpa,
        String major, String department) {
            this.firstName = firstName;
            this.lastName = lastName;
            this.major = major;
            this.department = department;
            this.age = age;
            this.gpa = gpa;
    }

    public void addCourse(Course course) { courses.add(course); }

    public void removeCourse(Course course) {
        if
    }


    public void setFirstName(String firstName) { this.firstName = firstName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    public void setMajor(String major) { this.major = major; }
    public void setDepartment(String department) { this.department = department; }
    public void setAge(int age) { this.age = age; }
    public void setGpa(float gpa) { this.gpa = gpa; }
    public void setCourses(LinkedList<Course> courses) { this.courses = courses; }

    public String getFirstName() { return firstName; }
    public String getLastName() { return lastName; }
    public String getMajor() { return major; }
    public String getDepartment() { return department; }
    public int getAge() { return age; }
    public float getGpa() { return gpa; }
    public LinkedList<Course> getCourses() { return courses; }
}

In class Student implement the following methods: addCourse() to add a new course, removeCourse() to remove a course from this student, sortCourses() to print out a sorted list of courses. Method sortCourses() should accept parameters to specify whether the sorting should be ascending or descending and also based on which course attribute to sort the courses. The output should be printed to command line standard output. Save this class and its definition into a file named Student.java.


// private final Course CS151 = new Course("CS151",
//     "Object Oriented Design and Programming", "CS", "6:00PM", "Tue");
// private final Course CS49J = new Course("CS49J",
//     "Programming in Java", "CS", "6:00PM", "Thur");
// private final Course CS154 = new Course("CS154",
//     "Formal Languages", "CS", "4:30PM", "Tue");
// private final Course CS174 = new Course("CS174",
//     "Server Side Programming", "CS", "12:00PM", "Mon");
