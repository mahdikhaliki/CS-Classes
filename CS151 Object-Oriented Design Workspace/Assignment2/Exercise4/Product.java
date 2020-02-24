public final class Product {
    private final String name, description;
    private final float price;
    private final int maxQuantity;

    public Product(String name, String description, float price, int maxQuantity) {
        this.name = name;
        this.description = description;
        this.price = price;
        this.maxQuantity = maxQuantity;
    }

    public String getName() { return name; }
    public String getDescription() { return description; }
    public float getPrice() { return price; }
    public int getMaxQuantity() { return maxQuantity; }

    public String toString(){
        return name+", "+description+", "+price+", "+maxQuantity;
    }
}
