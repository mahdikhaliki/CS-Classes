import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonViewer {
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        JPanel panel = new JPanel();

        JButton button1 = new JButton("Click me!");
        button1.setBounds(0, 0, 50, 20);

        JButton button2 = new JButton("Click me!");
        button2.setBounds(50,0, 50, 20);

        panel.add(button1);
        panel.add(button2);

        frame.add(panel);

        ActionListener listener1 = new ClickerListener();
        button1.addActionListener(listener1);

        ActionListener listener2 = new ClickerListener();
        button2.addActionListener(listener2);

        frame.setSize(500, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static class ClickerListener implements ActionListener {
        public int count;

        @Override
        public void actionPerformed(ActionEvent e) {
            System.out.println("I was clicked "+ ++count +" times!");
        }
    }
}
