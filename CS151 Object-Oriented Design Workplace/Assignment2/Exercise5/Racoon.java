public class Racoon extends Animal {
    private final String NAME = "Racoon";

    public Racoon(String type, String gender, String environment, int age, int speed) {
        this.type = type;
        this.gender = gender;
        this.environment = environment;
        this.age = age;
        this.speed = speed;
    }

    public void scratch() { System.out.println("Scratching"); }

    public String toString() { return NAME+", "+super.toString(); }
}
