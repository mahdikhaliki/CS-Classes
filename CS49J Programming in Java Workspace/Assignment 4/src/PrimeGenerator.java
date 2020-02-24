public class PrimeGenerator {
    private int user_input;
    private static int current_prime;

    public PrimeGenerator() {
        user_input = 0;
        current_prime = 0;

    }
    public PrimeGenerator(int input) {
        user_input = input;
        current_prime = 0;
    }

    public int nextPrime() {
        while (!is_prime(++current_prime));
        return current_prime > user_input ? 0 : current_prime;
    }

    private boolean is_prime(int num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0) return false;

        for (int i = 3; i < num / 2; i += 2)
            if (num % i == 0) return false;
        return true;
    }
}