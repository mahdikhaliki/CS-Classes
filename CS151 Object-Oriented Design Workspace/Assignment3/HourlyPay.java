public interface HourlyPay {
    public static final float OVERTIME_RATE = 1.5f;

    public float computePay(float numHours);
}
