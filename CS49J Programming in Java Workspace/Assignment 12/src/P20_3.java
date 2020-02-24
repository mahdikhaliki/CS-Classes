import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

public class P20_3 {
    private static final int FIELD_WIDTH = 20;
    private static final int AREA_ROW = 35;
    private static final int AREA_COLUMN = 35;

    private double balance;

    private JPanel  main_panel, panel1, panel2;
    private JFrame frame;

    private JLabel initial_amount_label, interest_rate_label, num_years_label;
    private JTextField initial_amount, interest_rate, num_years;
    private JButton calculate;
    private JTextArea resultArea;
    private JScrollPane scrollPane;

    P20_3() {

        main_panel = new JPanel();
        main_panel.setLayout(new BorderLayout());

        panel1 = new JPanel();
        panel1.setLayout(new GridLayout(4, 2));

        panel2 = new JPanel();
        main_panel.add(panel1, BorderLayout.NORTH);
        main_panel.add(panel2, BorderLayout.SOUTH);

        frame = new JFrame();
        frame.setTitle("Savings Account");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        createLabels();
        createTextFields();
        createButton();
        createTextArea();
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

    public void createTextArea() {
        resultArea = new JTextArea(AREA_ROW, AREA_COLUMN);
        resultArea.setEditable(false);
        scrollPane = new JScrollPane(resultArea);
    }

    public void addComponentsToPanel() {
        panel1.add(initial_amount_label);
        panel1.add(initial_amount);
        panel1.add(interest_rate_label);
        panel1.add(interest_rate);
        panel1.add(num_years_label);
        panel1.add(num_years);
        panel1.add(calculate);
        panel2.add(scrollPane);
    }

    public class CalculateButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            resultArea.setText("");
            DecimalFormat money = new DecimalFormat("###,###,###,##0.00");

            balance = Double.parseDouble(initial_amount.getText());
            double rate = Double.parseDouble(interest_rate.getText());
            int years = Integer.parseInt(num_years.getText());

            if (years > 0) {
                for (int i = 0; i < years; i++) {
                    balance *= (1+(rate/100));
                    resultArea.append("Year "+ (i+1) +" : $"+ money.format(balance)+'\n');
                }
            }
            else resultArea.append("$"+money.format(balance)+'\n');
        }
    }

    public static void main(String[] args) {
        P20_3 p = new P20_3();
    }
}

