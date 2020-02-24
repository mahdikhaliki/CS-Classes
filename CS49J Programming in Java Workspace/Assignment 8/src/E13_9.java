public class E13_9 {
    public static void main(String[] args) {
        System.out.println("text = Mississippi, str = sip, index = "
                + indexOf("Mississippi", "sip"));
        System.out.println("text = Mississippi, str = M, index = "
                + indexOf("Mississippi", "M"));
        System.out.println("text = Mississippi, str = ippi, index = "
                + indexOf("Mississippi", "ippi"));
        System.out.println("text = Mississippi, str = ssiss, index = "
                + indexOf("Mississippi", "ssiss"));
        System.out.println("text = Mississippi, str = Mississippi, index = "
                + indexOf("Mississippi", "Mississippi"));

        System.out.println("text = Mississippi, str = Tennessee, index = "
                + indexOf("Mississippi", "Tennessee"));
        System.out.println("text = Mississippi, str = m, index = "
                + indexOf("Mississippi", "m"));
        System.out.println("text = Mississippi, str = sss, index = "
                + indexOf("Mississippi", "sss"));
        System.out.println("text = Mississippi, str = xy, index = "
                + indexOf("Mississippi", "xy"));
    }

    public static int indexOf(String text, String str) {
        return indexOfHelper(text, str, 0, 0);
    }

    public static int indexOfHelper(String text, String str, int index, int compareIndex) {
        if (str.length() <= compareIndex) return index - str.length();
        if (text.length() == 0) return -1;
        if (text.charAt(0) == str.charAt(compareIndex))
            return indexOfHelper(text.substring(1), str, index + 1, ++compareIndex);
        else if (text.charAt(0) != str.charAt(compareIndex) && compareIndex > 0)
            return indexOfHelper(text, str, index, 0);
        else
            return indexOfHelper(text.substring(1), str, index + 1, 0);
    }
}