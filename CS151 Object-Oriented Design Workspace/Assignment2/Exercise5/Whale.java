public class Whale extends Animal {
    private final String NAME = "Whale";

    public Whale(String type, String gender, String environment, int age, int speed) {
        this.type = type;
        this.gender = gender;
        this.environment = environment;
        this.age = age;
        this.speed = speed;
    }

    public void swim() { System.out.println("Swimming"); }

    public String toString() { return NAME+", "+super.toString(); }
}
