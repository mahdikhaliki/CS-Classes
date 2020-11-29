public class Student implements Comparable<Student> {
    private String first_name, last_name;
    private int id;

    public Student(String first, String last, int id) {
        first_name = first;
        last_name = last;
        this.id = id;
    }

    public String getFirst() { return first_name; }
    public String getLast() { return last_name; }
    public int getID() { return id; }

    @Override
    public int compareTo(Student o) {
        String compare = last_name+first_name+String.valueOf(id);
        String o_compare = o.last_name+o.first_name+String.valueOf(o.id);
        return compare.compareTo(o_compare);
    }
}
