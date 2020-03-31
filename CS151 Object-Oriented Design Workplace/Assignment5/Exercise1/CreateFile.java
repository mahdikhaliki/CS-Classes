import java.io.*;
import java.util.Scanner;

public class CreateFile {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(System.in);
            String input = "";
            PrintWriter output = new PrintWriter("command_line_input.txt");

            System.out.println("Enter text for output file (type @q to quit)");
            while(!input.equals("@q")) {
                input = in.nextLine();
                output.println(input);
            }
            output.close();
        } catch(FileNotFoundException e) {
            System.out.println(e);
        }
    }
}
