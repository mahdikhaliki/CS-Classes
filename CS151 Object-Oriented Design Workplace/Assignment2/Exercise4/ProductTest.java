public class ProductTest {
    public static void main(String[] args){
        Product prod = new Product("BioFreeze", "Frozen ice pack for athletes",
                                   7.99f, 850);
        System.out.println(prod.toString());
    }
}
