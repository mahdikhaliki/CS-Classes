import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PanelColors {
    private JFrame frame;
    private JPanel panel;
    private JComboBox colors;

    public PanelColors() {
        frame = new JFrame();
        panel = new JPanel();
        colors = new JComboBox();
        colors.addItem("Blue");
        colors.addItem("Green");
        colors.addItem("Red");

        panel.setLayout(new BorderLayout());
        panel.add(colors, BorderLayout.CENTER);
        panel.setBackground(Color.BLUE);
        colors.addActionListener(new ComboListener());

        frame.setSize(300, 400);
        frame.setTitle("Color");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(panel);
        frame.setVisible(true);
    }

    public class ComboListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String selectedItem = (String) colors.getSelectedItem();

            switch (selectedItem){
                case "Blue": panel.setBackground(Color.BLUE); break;
                case "Green": panel.setBackground(Color.GREEN); break;
                case "Red": panel.setBackground(Color.RED); break;
            }
        }
    }

    public static void main(String[] args) {
        PanelColors colors = new PanelColors();
    }
}
