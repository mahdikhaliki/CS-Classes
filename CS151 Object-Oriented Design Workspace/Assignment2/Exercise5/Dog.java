public class Dog extends Animal implements Domesticated {
    private final String NAME = "Dog";
    private String domesticatedName, temperament;

    public Dog(String type, String gender, String environment, int age, int speed,
               String domesticatedName, String temperament) {
        this.type = type;
        this.gender = gender;
        this.environment = environment;
        this.age = age;
        this.speed = speed;
        this.domesticatedName = domesticatedName;
        this.temperament = temperament;
    }

    public void bark() { System.out.println("Barking"); }
    public void swim() { System.out.println("Swimming"); }
    public void walk() { System.out.println("Walking"); }
    public void greetHuman() { System.out.println("Greeting human"); }

    public void setDomesticatedName(String name) { this.domesticatedName = name; }
    public void setTemperament(String temperament) { this.temperament = temperament; }

    public String getDomesticatedName() { return domesticatedName; }
    public String getTemperament() { return temperament; }

    public String toString() {
        return NAME+", "+super.toString()+", "+domesticatedName+", "+temperament;
    }
}
