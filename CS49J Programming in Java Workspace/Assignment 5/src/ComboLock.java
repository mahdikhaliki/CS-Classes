public class ComboLock {
    private int combo1, combo2, combo3, dial;
    private boolean turn_right, turn_left, open;

    public ComboLock(int secret1, int secret2, int secret3) {
        if (valid(secret1) && valid(secret2) && valid(secret3)) {
            combo1 = secret1;
            combo2 = secret2;
            combo3 = secret3;
        }
        else {
            System.out.println("Invalid input, combo must be between 0 and 39");
            combo1 = combo2 = combo3 = 0;
        }
        turn_right = turn_left = open = false;
        dial = 0;
    }

    private boolean valid(int secret) {
        return secret >= 0 && secret <= 39;
    }

    public void reset() {
        dial = 0;
        turn_right = turn_left = open = false;
    }

    public void turnRight(int ticks) {
        dial -= ticks;
        while (dial < 0) dial += 40;
        if (!turn_left && dial == combo1) turn_right = true;
        if (turn_left && turn_right && dial == combo3) open = true;
    }

    public void turnLeft(int ticks) {
        dial += ticks;
        while (dial > 39) dial -= 40;
        if (turn_right && dial == combo2) turn_left = true;
    }

    public boolean open() {
        return open;
    }
}
