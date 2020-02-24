public class AnimalTest {
    public static void main(String[] args) {
        Dog dog = new Dog("Canidae", "Male", "Home", 3, 15, "Charles", "Happy pupper");
        Cat cat = new Cat("Felidae", "Female", "Home", 8, 17, "Maxi", "Grump");
        Racoon racoon = new Racoon("Procyonidae", "Male", "Forest", 2, 6);
        Whale whale = new Whale("Cetaceans", "Male", "Ocean", 65, 26);

        System.out.println(dog.toString());
        dog.move();
        dog.sound();
        dog.eat();
        dog.sleep();
        dog.bark();
        dog.swim();
        System.out.println();

        System.out.println(cat.toString());
        cat.move();
        cat.sound();
        cat.eat();
        cat.sleep();
        cat.scratch();
        System.out.println();

        System.out.println(racoon.toString());
        racoon.move();
        racoon.sound();
        racoon.eat();
        racoon.sleep();
        racoon.scratch();
        System.out.println();

        System.out.println(whale.toString());
        whale.move();
        whale.sound();
        whale.eat();
        whale.sleep();
        whale.swim();
    }
}
