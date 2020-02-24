import java.util.HashMap;
import java.util.Map;

public class Card {
    private String notation;
    private static Map<Character, String> ranks, suits;

    public  Card() {
        notation = "";
        ranks = new HashMap<>();
        suits = new HashMap<>();
        ranks.put('A', "Ace");
        ranks.put('K', "King");
        ranks.put('Q', "Queen");
        ranks.put('J', "Jack");
        suits.put('D', "Diamonds");
        suits.put('H', "Hearts");
        suits.put('S', "Spades");
        suits.put('C', "Clubs");
    }

    public  Card(String note) {
        this();
        notation = note.toUpperCase();
    }

    public String getDescription() {
        int notationLen = notation.length();

        if (notationLen < 2 || notationLen > 3) return "Unknown";

        if (notationLen == 3) {
            if (notation.charAt(0) != '1' && notation.charAt(1) != '0') {
                return "Unknown";
            }
            else {
                if (suits.containsKey(notation.charAt(2))) {
                    return "10 of " + suits.get(notation.charAt(2));
                }
            }
        }
        else {
            char firstChar = notation.charAt(0), secondChar = notation.charAt(1);
            if (ranks.containsKey(firstChar) || (firstChar >= 50 && firstChar <= 57)) {
                if (suits.containsKey(secondChar))
                    return Character.isDigit(firstChar) ? firstChar + " of " + suits.get(secondChar)
                            : ranks.get(firstChar) + " of " + suits.get(secondChar);
            }
        }
        return "Unknown";
    }
}