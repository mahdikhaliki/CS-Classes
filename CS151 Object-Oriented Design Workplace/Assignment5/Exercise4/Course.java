public class Course {
    private String name, description, department, startTime, weekday;

    public Course(String name, String description, String department,
                  String startTime, String weekday) {
          this.name = name;
          this.description = description;
          this.department = department;
          this.startTime = startTime;
          this.weekday = weekday;
    }

    public void printInfo() {
        System.out.println("\nCourse name: "+name+
                           "\nDescription: "+description+
                           "\nDepartment: "+department+
                           "\nStart time: "+startTime+
                           "\nWeekday: "+weekday+'\n');
    }

    public void setName(String name) { this.name = name; }
    public void setDescription(String description) { this.description = description; }
    public void setDepartment(String department) { this.department = department; }
    public void setStartTime(String startTime) { this.startTime = startTime; }
    public void setWeekday(String weekday) { this.weekday = weekday; }

    public String getName() { return name; }
    public String getDescription() { return description; }
    public String getDepartment() { return department; }
    public String getStartTime() { return startTime; }
    public String getWeekday() { return weekday; }
}
