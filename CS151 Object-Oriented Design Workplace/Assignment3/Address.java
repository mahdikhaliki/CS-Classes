public class Address {
    private int streetNum, zip;
    private String streetName, city, state;

    public Address() {
        streetNum = zip = 0;
        streetName = city = state = "";
    }

    public Address(int streetNum, String streetName, String city,
                   String state, int zip) {
        this.streetNum = streetNum;
        this.streetName = streetName;
        this.city = city;
        this.state = state;
        this.zip = zip;
    }

    public String toString() {
        if (streetName.length() == 0) return "";
        return streetNum+" "+streetName+' '+city+", "+state+' '+zip;
    }

    public void setStreetNumber(int streetNum) { this.streetNum = streetNum; }
    public void setStreetName(String streetName) { this.streetName = streetName; }
    public void setCity(String city) { this.city = city; }
    public void setState(String state) { this.state = state; }
    public void setZip(int zip) { this.zip = zip; }

    public int getStreetNumber() { return streetNum; }
    public String getStreetName() { return streetName; }
    public String getCity() { return city; }
    public String getState() { return state; }
    public int getZip() { return zip; }
}
