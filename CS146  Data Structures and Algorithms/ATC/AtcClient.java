import java.awt.*;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * AtcClient class implements the UI for the Air Traffic Control simulator.
 * The UI is built using Java Swing GUI.
 *
 * @author Mahdi Khaliki
 */

public class AtcClient {
    private static ATC atc;

    public static void main(String[] args) {
        atc = new ATC();

        populatePriorityQueue(atc);

        UserInterface ui = new UserInterface();
    }

    /**
     * Populates the atc object with fake airplane objects using randomly generated
     * characters and numbers
     *
     * @param (ATC atc) (An ATC object to populate)
     */
    public static void populatePriorityQueue(ATC atc) {
        for (int i = 0; i < 30; i++) {
            String flight_number = generateFlightNum();
            int distance = generateDistance();
            int elevation = generateElevation();
            atc.maxHeapInsert(new Airplane(flight_number, distance, elevation));
        }
    }

    /**
     * Inserts an airplane into an ATC object using a provided flight number and
     * a randomly generated distance and elevation.
     *
     * @param (ATC atc) (An ATC object to populate)
     * @param (String flight_num) (An airplane flight number)
     */
    public static void addNewPlane(ATC atc, String flight_num) {
        int distance = generateDistance();
        int elevation = generateElevation();
        atc.maxHeapInsert(new Airplane(flight_num, distance, elevation));
    }

    /**
     * Generates a random flight number.
     *
     * @return (A randomly generated flight number)
     */
    public static String generateFlightNum() {
        StringBuilder flight_num = new StringBuilder();
        Random rand = new Random();

        for (int i = 0; i < 2; i++) {
            char code = (char) (rand.nextInt(90 - 65 + 1) + 65);
            flight_num.append(code);
        }

        int num_of_digits = rand.nextInt(2) + 2;
        for (int i = 0; i < num_of_digits; i++)
            flight_num.append(rand.nextInt(10));

        return flight_num.toString();
    }

    /**
     * Generates a random flight distance between 3,000 to 20,000 meters.
     *
     * @return (A randomly generated flight distance)
     */
    public static int generateDistance() {
        Random rand = new Random();
        return rand.nextInt(20000 - 3000 + 1) + 3000;
    }

    /**
     * Generates a random flight elevation  between 1,000 to 3,000 meters.
     *
     * @return (A randomly generated flight elevation)
     */
    public static int generateElevation() {
        Random rand = new Random();
        return rand.nextInt(3000 - 1000 + 1) + 1000;
    }


    /**
     * UserInterface is a Java Swing GUI that enables an Air Traffic Controller to:
     * 1) Add a new plane to the queue
     * 2) View the sorted list
     * 3) View the first ranked airplane
     * 4) Remove the first ranked airplane from the queue
     * 5) Increase the AC score of an airplane
     *
     * @author Mahdi Khaliki
     */
    static class UserInterface {
        private static final int AREA_ROW = 30;
        private static final int AREA_COLUMN = 35;

        private JPanel main_panel, panel;
        private JFrame frame;

        // Main Menu fields
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        private JLabel banner;
        private JTextArea airplanes_area;
        private JScrollPane scrollPane;
        private JButton add_airplane, view_sorted_list, view_first_ranked, remove_first_ranked, increase_ac_score;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////

        // Sub Menu fields
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        private JLabel flight_num_label, new_flight_AC;
        private JTextField flight_num, new_AC_score;
        private JButton add_airplane_submit, increase_AC_submit;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////

        UserInterface() {
            frame = new JFrame();
            frame.setSize(675, 750);
            frame.setTitle("Air Traffic Control");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            mainMenu("Main Menu");

            frame.setVisible(true);
        }

        public void mainMenu(String banner_message) {
            main_panel = new JPanel();
            main_panel.setLayout(new BorderLayout());
            panel = new JPanel();
            panel.setLayout(new GridLayout(5, 1));
            main_panel.add(panel, BorderLayout.CENTER);

            addBanner(banner_message);
            createButtons();
            addListeners();
            createTextArea();
            addComponentsToPanel();
            frame.add(main_panel);
        }

        public void createButtons() {
            add_airplane = new JButton("Add new airplane to queue");
            view_sorted_list = new JButton("View sorted list");
            view_first_ranked = new JButton("View first ranked airplane");
            remove_first_ranked = new JButton("Remove first ranked airplane");
            increase_ac_score = new JButton("Increase AC score of an airplane");
        }

        public void addComponentsToPanel() {
            main_panel.add(banner, BorderLayout.NORTH);
            panel.add(add_airplane);
            panel.add(view_sorted_list);
            panel.add(view_first_ranked);
            panel.add(remove_first_ranked);
            panel.add(increase_ac_score);
        }
        public void addBanner(String banner_message) {
            banner = new JLabel("", SwingConstants.CENTER);
            banner.setText(banner_message);
            banner.setFont(new Font(null, 0, 30));
        }


        public void addListeners() {
            add_airplane.addActionListener(new AddAirplaneButtonListener());
            view_sorted_list.addActionListener(new ViewSortedListButtonListener());
            view_first_ranked.addActionListener(new ViewFirstRankedButtonListener());
            remove_first_ranked.addActionListener(new RemoveFirstRankedButtonListener());
            increase_ac_score.addActionListener(new IncreaseAcScoreButtonListener());
        }

        public void createTextArea() {
            airplanes_area = new JTextArea(AREA_ROW, AREA_COLUMN);
            airplanes_area.setEditable(false);
            scrollPane = new JScrollPane(airplanes_area);
        }

        public class AddAirplaneButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                panel = new JPanel();
                flight_num_label = new JLabel("Enter a Flight Number to add: ");
                flight_num = new JTextField(20);
                add_airplane_submit = new JButton("Submit");
                add_airplane_submit.addActionListener(new AddPlaneSubmitButtonListener());
                panel.add(flight_num_label);
                panel.add(flight_num);
                panel.add(add_airplane_submit);
                frame.add(panel);
                frame.revalidate();
            }
        }

        /**
         * After the user clicks submit, the flight is added to the queue with the given
         * flight number and randomly generated distance and elevation.
         */
        public class AddPlaneSubmitButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                addNewPlane(atc, flight_num.getText());
                frame.getContentPane().removeAll();
                mainMenu("New plane added to queue");
                frame.revalidate();
            }
        }

        /**
         * If user selects to sort list then heapSort() is called using the
         * atc object which returns a sorted list of airplane objects based on AC.
         */
        public class ViewSortedListButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                banner.setText("");
                airplanes_area.setText("");
                main_panel.add(scrollPane, BorderLayout.SOUTH);
                frame.revalidate();

                ArrayList<Airplane> planes = atc.heapSort();
                for(int i = 1; i <= planes.size(); i++) {
                    airplanes_area.append(i+". "+planes.get(i-1).toString()+"\n");
                }
            }
        }

        /**
         * If user selects to view first ranked airplane the heapMaximum() is called
         * which returns an airplane object. The airplane object is then outputted
         * to the user but is not removed from the list.
         */
        public class ViewFirstRankedButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                banner.setText("");
                airplanes_area.setText("");
                main_panel.add(scrollPane, BorderLayout.SOUTH);
                frame.revalidate();

                airplanes_area.append("First ranked airplane in queue:\n");
                airplanes_area.append(atc.heapMaximum().toString());
            }
        }

        /**
         * If user selects to remove the first ranked airplane the heapExtractMax()
         * is called which returns an airplane object. The airplane object is then
         * outputted to the user and removed from the list.
         */
        public class RemoveFirstRankedButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                banner.setText("");
                airplanes_area.setText("");
                main_panel.add(scrollPane, BorderLayout.SOUTH);
                frame.revalidate();

                airplanes_area.append("The following first ranked airplane in queue has been removed:\n");
                airplanes_area.append(atc.heapExtractMax().toString());
            }
        }

        public class IncreaseAcScoreButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                panel = new JPanel();
                flight_num_label = new JLabel("Enter a Flight Number to increase AC: ");
                new_flight_AC = new JLabel("Enter new AC to increase to: ");
                flight_num = new JTextField(20);
                new_AC_score = new JTextField(20);
                increase_AC_submit = new JButton("Submit");
                increase_AC_submit.addActionListener(new IncreaseAcScoreSubmitButtonListener());
                panel.add(flight_num_label);
                panel.add(flight_num);
                panel.add(new_flight_AC);
                panel.add(new_AC_score);
                panel.add(increase_AC_submit);
                frame.add(panel);
                frame.revalidate();
            }
        }

        /**
         * If user selects to increase an airplane object's AC score the
         * user will be asked to provide the flight number in which they
         * want to change and the new approach code. The airplane object is then
         * updated to the new approach code using heapIncreaseKey().
         */
        public class IncreaseAcScoreSubmitButtonListener implements ActionListener {
            public void actionPerformed(ActionEvent e) {
                int index = atc.getIndex(flight_num.getText());
                int new_AC = -1;
                String banner_message = "";

                if(index == -1) {
                    banner_message = "No matching flight in queue";
                }
                else {
                    Airplane plane = (Airplane) atc.getAtIndex(index).clone();
                    new_AC = Integer.parseInt(new_AC_score.getText());
                    plane.setApproachCode(new_AC);
                    if(!atc.heapIncreaseKey(index, plane))
                        banner_message = "Error: New AC is smaller than the current AC";
                    else
                        banner_message = "AC has been updated to new value";
                }
                frame.getContentPane().removeAll();
                mainMenu(banner_message);
                frame.revalidate();
            }
        }
    }
}
