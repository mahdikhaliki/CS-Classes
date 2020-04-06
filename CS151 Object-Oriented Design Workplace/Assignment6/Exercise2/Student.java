import java.util.*;

public class Student {
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
            courses = new LinkedList<Course>();
    }

    public void addCourse(Course course) { courses.add(course); }

    public void removeCourse(String courseName) {
        Iterator itr = courses.iterator();
        while (itr.hasNext())
        {
            Course course = (Course)itr.next();
            if(course.getName().equals(courseName)){
                itr.remove();
                return;
            }
        }
        System.out.println("Course to remove was not found.");
    }

    public void sortCourses(boolean ascending, String attribute) {
        switch(attribute.toLowerCase()) {
            case "description":
                courses.sort(Comparator.comparing(Course::getDescription));
                break;
            case "department":
                courses.sort(Comparator.comparing(Course::getDepartment));
                break;
            case "start time":
                courses.sort(Comparator.comparing(Course::getStartTime));
                break;
            case "weekday":
                courses.sort(Comparator.comparing(Course::getWeekday));
                break;
            default:
                courses.sort(Comparator.comparing(Course::getName));
                break;
        }

        if(!ascending) Collections.reverse(courses);
        System.out.println("-----------------------------------------------"+
                           "\nCourses have been sorted based on "+attribute);

       for(Course course : courses)
           course.printInfo();
    }

    public void printInfo() {
        System.out.println("-----------------------------------------------"+
                           "\n"+firstName+" "+lastName+
                           "\n"+major+
                           "\n"+department+
                           "\n"+age+
                           "\n"+gpa);

        for(Course course : courses)
            course.printInfo();
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
