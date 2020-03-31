public abstract class Animal {
    protected String type, gender, environment;
    protected int age, speed;

    public void move() { System.out.println("Moving"); }
    public void sound() { System.out.println("Making sound"); }
    public void eat() { System.out.println("eating"); }
    public void sleep() { System.out.println("Sleeping"); }

    public String toString() {
        return type+", "+gender+", "+environment+", "+age+", "+speed+" miles/hr";
    }

    public void setType(String type) { this.type = type; }
    public void setGender(String gender) { this.gender = gender; }
    public void setEnvironment(String environment) { this.environment = environment; }
    public void setAge(int age) { this.age = age; }
    public void setSpeed(int speed) { this.speed = speed; }

    public String getType() { return type; }
    public String getGender() { return gender; }
    public String getEnvironment() { return environment; }
    public int getAge() { return age; }
    public int getSpeed() { return speed; }
}
