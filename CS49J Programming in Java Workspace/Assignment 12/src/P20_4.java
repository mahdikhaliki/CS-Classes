import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class P20_4 {
    private static final int FIELD_WIDTH = 20;

    private double balance;

    private JPanel  main_panel, panel1, panel2, panel3, panel4;
    private JFrame frame;

    private JLabel initial_amount_label, interest_rate_label, num_years_label;
    private JTextField initial_amount, interest_rate, num_years;
    private JButton calculate;

    P20_4() {
        main_panel = new JPanel();
        main_panel.setLayout(new BorderLayout());

        panel1 = new JPanel();
        panel1.setLayout(new GridLayout(4, 2));

        panel2 = new JPanel();
        panel2.setLayout(new BorderLayout());
        panel3 = new JPanel();
        panel3.setLayout(new BorderLayout());
        panel2.add(panel3, BorderLayout.NORTH);
        panel4 = new JPanel();
        panel2.add(panel4, BorderLayout.SOUTH);

        main_panel.add(panel1, BorderLayout.NORTH);
        main_panel.add(panel2, BorderLayout.SOUTH);

        frame = new JFrame();
        frame.setTitle("Savings Account");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        createLabels();
        createTextFields();
        createButton();
        addComponentsToPanel();
        calculate.addActionListener(new CalculateButtonListener());

        frame.add(main_panel);
        frame.pack();
        frame.setVisible(true);
    }

    public void createLabels() {
        initial_amount_label = new JLabel("Initial amount: ");
        interest_rate_label = new JLabel("Annual interest rate: ");
        num_years_label = new JLabel("Number of years: ");
    }

    public void createTextFields() {
        initial_amount = new JTextField(FIELD_WIDTH);
        interest_rate = new JTextField(FIELD_WIDTH);
        num_years = new JTextField(FIELD_WIDTH);
    }

    public void createButton() { calculate = new JButton("Calculate"); }

    public void addComponentsToPanel() {
        panel1.add(initial_amount_label);
        panel1.add(initial_amount);
        panel1.add(interest_rate_label);
        panel1.add(interest_rate);
        panel1.add(num_years_label);
        panel1.add(num_years);
        panel1.add(calculate);
    }

    public class CalculateButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            panel2.revalidate();
            panel2.repaint();
            balance = Double.parseDouble(initial_amount.getText());
            double rate = Double.parseDouble(interest_rate.getText());
            int years = Integer.parseInt(num_years.getText());
            panel4.setLayout(new GridLayout(years, 1));

            panel3.add(new JTextField("Dollars"), BorderLayout.NORTH);
            panel3.add(new JTextField("0\t10\t100\t1,000\t10,000\t100,000\t1,000,000\t10,000,000+"), BorderLayout.SOUTH);

            for (int i = 0; i < years; i++) {
                int tens = 0;
                balance *= (1+(rate/100));
                int temp = (int) balance;
                while (temp > 0) {
                    temp /= 10;
                    tens++;
                }
                int width = 100*(tens-1)+((int)balance/(10*(tens-1)));
                System.out.println(width);
                panel4.add(new BarGraphComponent(5, 2, width , 10));
            }

            panel2.revalidate();
            panel2.repaint();
            frame.pack();
        }
    }

    public static void main(String[] args) {
        P20_4 p = new P20_4();
    }
}