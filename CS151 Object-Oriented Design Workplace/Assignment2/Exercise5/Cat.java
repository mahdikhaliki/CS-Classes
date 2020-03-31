public class Cat extends Animal implements Domesticated {
    private final String NAME = "Cat";
    private String domesticatedName, temperament;

    public Cat(String type, String gender, String environment, int age, int speed,
               String domesticatedName, String temperament) {
        this.type = type;
        this.gender = gender;
        this.environment = environment;
        this.age = age;
        this.speed = speed;
        this.domesticatedName = domesticatedName;
        this.temperament = temperament;
    }

    public void scratch() { System.out.println("Scratching"); }
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
