public class IceCreamCone {
    private double height, radius;

    public IceCreamCone(double height, double radius) {
        this.height = height;
        this.radius = radius;
    }

    public double getSurfaceArea(){
        return Math.PI * radius * Math.sqrt(Math.pow(height, 2) + Math.pow(radius, 2));
    }

    public double getVolume() {
        return Math.PI * Math.pow(radius, 2) * (height / 3);
    }
}
