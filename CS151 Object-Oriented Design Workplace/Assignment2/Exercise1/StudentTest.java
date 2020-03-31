public class StudentTest {
    public static void main(String[] args) {
        Student s1 = new Student("John", "Smith", 20, 3.6f,
                    "Computer Science", "School of Computer Science");

        System.out.println(s1.getFirstName()+' '+s1.getLastName()+", "+s1.getAge()
                           +", "+s1.getGpa()+", "+s1.getMajor()+", "+s1.getDepartment());

        s1.addCourse("CS151", "6:00PM-7:15PM", "TuTh");
        s1.printSchedule();

        s1.setAge(21);
        s1.setGpa(3.68f);
        s1.addCourse("CS174", "3:00PM-4:15PM", "TuTh");
        s1.printStudentInfo();
        s1.printSchedule();
    }
}
