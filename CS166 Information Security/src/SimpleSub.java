import java.util.ArrayList;
import java.util.HashMap;

public class SimpleSub {
    public static void main(String[] args) {
        String cipher = "PBFPVYFBQXZTYFPBFEQJHDXXQVAPTPQJKTOYQWIPBVWLXTOXBTFXQWAXBVCXQWAXFQJVWLEQNTOZQGGQLFXQWAKVWLXQ" +
                "WAEBIPBFXFQVXGTVJVWLBTPQWAEBFPBFHCVLXBQUFEVWLXGDPEQVPQGVPPBFTIXPFHXZHVFAGFOTHFEFBQUFTDHZBQPOTHXTYFTO" +
                "DXQHFTDPTOGHFQPBQWAQJJTODXQHFOQPWTBDHHIXQVAPBFZQHCFWPFHPBFIPBQWKFABVYYDZBOTHPBQPQJTQOTOGHFQAPBFEQJHD" +
                "XXQVAVXEBQPEFZBVFOJIWFFACFCCFHQWAUVWFLQHGFXVAFXQHFUFHILTTAVWAFFAWTEVOITDHFHFQAITIXPFHXAFQHEFZQWGFLVW" +
                "PTOFFA";
        cipher = cipher.toUpperCase();
        HashMap<Character, Integer> frequency = new HashMap<>();
        char[] rankings = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'C', 'U', 'M', 'W', 'F',
                'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'};

        // Getting the frequency of each letter in the cipher
        for (int i = 0; i < cipher.length(); i++) {
            char c = cipher.charAt(i);
            if(!Character.isAlphabetic(c)) continue;

            if (frequency.containsKey(c)) {
                int count = frequency.get(c) + 1;
                frequency.put(c, count);
            } else {
                frequency.put(c, 1);
            }
        }

        // Ranking each character based on its frequency
        ArrayList<Character> cipherRanking = new ArrayList<>();
        for (int i = 0; i < frequency.size(); i++) {
            char max = cipher.charAt(0);
            for (Character c : frequency.keySet()) {
                if (frequency.get(c) > frequency.get(max)) {
                    max = c;
                }
            }
            frequency.put(max, -1);
            cipherRanking.add(i, max);
        }

        // Rewriting the String using the statistics of English letters from rankings[]
        StringBuilder plainText = new StringBuilder();
        for(int i = 0; i < cipher.length(); i++) {
            char c = cipher.charAt(i);
            if(Character.isAlphabetic(c))
                plainText.append(rankings[cipherRanking.indexOf(c)]);
            else
                plainText.append(c);
        }

        System.out.println(plainText);
    }
}
