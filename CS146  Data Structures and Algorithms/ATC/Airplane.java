/**
 * The Airplane class contains fields that describe a flight's
 * designation and current location in the airspace.
 *
 * @author Mahdi Khaliki
 */

public class Airplane implements Cloneable {
    private String flight_number;
    private int distance, elevation, approach_code;

    /**
     * The Airplane constructor calculates the approach code using the equations provided:
     * Approach Code (AC) = 15000 meters –(Direct Distance to runway in meter + Elevation in meter)/2
     *
     * @param (String flight_number) (A given designation to a flight)
     * @param (int distance) (Direct Distance to runway in meter)
     * @param (int size) (Elevation in meter)
     */
    public Airplane(String flight_number, int distance, int elevation) {
        this.flight_number = flight_number;
        this.distance = distance;
        this.elevation = elevation;
        approach_code = 15000 - (distance + elevation)/2;
    }

    /**
     * Manually overwrites an approach code
     *
     * @param (int approach_code) (An approach code to an airport)
     */
    public void setApproachCode(int approach_code) { this.approach_code = approach_code; }

    /**
     * Returns the approach code of an Airplane object.
     *
     * @return (int approach code of an airplane)
     */
    public int getApproachCode() {
        return approach_code;
    }

    /**
     * Returns the flight number of an Airplane object.
     *
     * @return (String flight number of an airplane)
     */
    public String getFlightNumber() { return flight_number; };

    /**
     * Overrides the toString() for printing of output.
     *
     * @return (String an airplane's description)
     */
    @Override
    public String toString() {
        return "("+flight_number+", "+"D: "+distance+" meters, H: "+elevation+
                " meters) - AC: "+getApproachCode();
    }

    /**
     * Overrides the clone() to use in heapIncreaseKey().
     *
     * @return (A clone of an airplane)
     */
    @Override
    public Object clone() {
        Airplane plane = new Airplane(flight_number, distance, elevation);
        plane.setApproachCode(approach_code);
        return plane;
    }
}
