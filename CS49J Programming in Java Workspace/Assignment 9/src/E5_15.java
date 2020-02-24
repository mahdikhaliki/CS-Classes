import java.io.File;
import java.io.IOException;
import java.util.*;

public class E5_15 {
    public static void main(String[] args) throws IOException {
        Map<Integer, String> indexIdent = new HashMap<Integer, String>();
        Map<String, Set<String>> identLine = new HashMap<String, Set<String>>();

        Scanner in = new Scanner(new File("test.java"));
        String identifier = "", line;

        int index = 0;
        while (in.hasNext()) {
            line = in.nextLine();

            Scanner inLine = new Scanner(line);
            inLine.useDelimiter("[^A-Za-z0-9_]+");

            while (inLine.hasNext()) {
                Set<String> set = new HashSet<String>();
                identifier = inLine.next();

                if (identLine.containsKey(identifier)) {
                    identLine.get(identifier).add(line);
                }
                else {
                    indexIdent.put(index++, identifier);
                    set.add(line);
                    identLine.put(identifier, set);
                }
            }
        }

        for (int i = 0; i < identLine.size(); i++) {
            identifier = indexIdent.get(i);
            System.out.println(i + ": " + identifier + " occurs in:");
            for (String str : identLine.get(identifier))
                System.out.println(str);
            System.out.println();
        }
    }
}
