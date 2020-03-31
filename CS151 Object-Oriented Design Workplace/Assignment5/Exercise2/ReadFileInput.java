import java.io.*;
import java.util.Scanner;

public class ReadFileInput{
    public static void main(String[] args) {
        try {
             Scanner in = new Scanner(new File("quote.txt"));
             while(in.hasNext())
                System.out.println(in.nextLine());
             in.close();
        } catch(FileNotFoundException e) {
            System.out.println(e);
        }
    }
}
