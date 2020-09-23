import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * The GUI class instantiates a Facebook object and adds users from a file. It contains all the GUI for
 * Facebook.
 *
 * @author Mahdi Khaliki
 */

public class GUI extends Application {
    private Facebook facebook;
    private static final int SPACING = 10;

    @Override
    public void start(Stage stage) throws FileNotFoundException {
        Scanner inputFile = new Scanner(new File("names.txt"));
        facebook = new Facebook();

        while(inputFile.hasNext())
            facebook.add(inputFile.next());

        facebook.randomlyAddFriends();

        VBox inputFields = new VBox();
        inputFields.setSpacing(SPACING);
        inputFields.setPadding(new Insets(10, 20, 10, 20));

        Label users = new Label("Facebook user's:");
        users.setAlignment(Pos.BASELINE_LEFT);
        TextArea textArea = new TextArea();
        textArea.setMinHeight(400);
        textArea.setEditable(false);
        textArea.setText(facebook.toString());

        HBox display = new HBox();
        display.setSpacing(SPACING);
        Button printUsers = new Button("Display all facebook users");
        printUsers.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                textArea.setText(facebook.toString());
                users.setText("Facebook user's:");
                users.setStyle("-fx-text-fill: black");
            }
        });

        Button showCollisions = new Button("Show Collisions in hashtable");
        showCollisions.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                textArea.setText(facebook.hashtableToString());
                users.setText("Hash table and collisions:");
                users.setStyle("-fx-text-fill: black");
            }
        });

        display.getChildren().addAll(printUsers, showCollisions);

        HBox add = new HBox();
        add.setSpacing(SPACING);
        TextField addUser = new TextField();
        addUser.setPromptText("Enter user's name");
        Button addUserButton = new Button("Add User");
        addUserButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String name = addUser.getText();
                facebook.add(name);
                users.setText(name+" has been added");
                users.setStyle("-fx-text-fill: green");
                textArea.setText(facebook.toString());
                addUser.clear();
            }
        });
        add.getChildren().addAll(addUser, addUserButton);

        HBox delete = new HBox();
        delete.setSpacing(SPACING);
        TextField deleteUser = new TextField();
        deleteUser.setPromptText("Enter user's name");
        Button deleteUserButton = new Button("Delete User");
        deleteUserButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String name = deleteUser.getText();
                try {
                    facebook.delete(name);
                    users.setText(name+" has been deleted ");
                    users.setStyle("-fx-text-fill: green");
                    textArea.setText(facebook.toString());
                    deleteUser.clear();
                } catch(LinkedList.PersonNotFoundException e) {
                    users.setText("The person entered is not a facebook user");
                    users.setStyle("-fx-text-fill: red");
                }
            }
        });
        delete.getChildren().addAll(deleteUser, deleteUserButton);

        HBox friendUnfriend = new HBox();
        friendUnfriend.setSpacing(SPACING);
        TextField person1Field = new TextField();
        person1Field.setPromptText("Enter a user's name");
        TextField person2Field = new TextField();
        person2Field.setPromptText("Enter a user's name");
        Button friend = new Button("Friend");
        friend.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    Person person1 = facebook.findPerson(person1Field.getText());
                    Person person2 = facebook.findPerson(person2Field.getText());
                    facebook.addFriendship(person1, person2);

                    users.setText(person1+" and "+person2+" are now friends");
                    users.setStyle("-fx-text-fill: green");
                    person1Field.clear();
                    person2Field.clear();
                    textArea.clear();
                } catch (LinkedList.PersonNotFoundException e) {
                    textArea.setText("One of the persons entered is not a facebook user");
                    users.setStyle("-fx-text-fill: red");
                }
            }
        });
        Button unfriend = new Button("Unfriend");
        unfriend.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    Person person1 = facebook.findPerson(person1Field.getText());
                    Person person2 = facebook.findPerson(person2Field.getText());
                    facebook.removeFriendship(person1, person2);

                    users.setText(person1+" and "+person2+" are no longer friends");
                    users.setStyle("-fx-text-fill: green");
                    person1Field.clear();
                    person2Field.clear();
                    textArea.clear();
                } catch (LinkedList.PersonNotFoundException e) {
                    textArea.setText("Cannot unfriend "+person1Field+" and "+person2Field+" since they're not friends");
                    users.setStyle("-fx-text-fill: red");
                }
            }
        });
        friendUnfriend.getChildren().addAll(person1Field, person2Field, friend, unfriend);

        HBox friendshipStatus = new HBox();
        friendshipStatus.setSpacing(SPACING);
        friendshipStatus.setAlignment(Pos.CENTER_LEFT);
        Label friendshipStatusLabel = new Label("Enter two names to check friendship status:");
        TextField statusPerson1 = new TextField();
        statusPerson1.setPromptText("Name");
        TextField statusPerson2 = new TextField();
        statusPerson2.setPromptText("Name");
        Button statusSubmit = new Button("Check");
        statusSubmit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    Person person1 = facebook.findPerson(statusPerson1.getText());
                    Person person2 = facebook.findPerson(statusPerson2.getText());
                    if(person1.isFriends(person2))
                        textArea.setText("Yes! "+person1+" and "+person2+" are friends");
                    else
                        textArea.setText("No, "+person1+" and "+person2+" are not friends");

                    users.setText("Friendship status:");
                    users.setStyle("-fx-text-fill: black");
                    statusPerson1.clear();
                    statusPerson2.clear();
                } catch (LinkedList.PersonNotFoundException e) {
                    users.setText("One of the persons entered is not a facebook user");
                    users.setStyle("-fx-text-fill: red");
                }
            }
        });
        friendshipStatus.getChildren().addAll(friendshipStatusLabel, statusPerson1, statusPerson2, statusSubmit);

        HBox printFriends = new HBox();
        printFriends.setSpacing(SPACING);
        printFriends.setAlignment(Pos.CENTER_LEFT);
        Label printFriendsLabel = new Label("Enter a user's name to print their friends");
        TextField printFriendsField = new TextField();
        printFriendsField.setPromptText("Name");
        Button printSubmit = new Button("Print");
        printSubmit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    String person = printFriendsField.getText();
                    textArea.setText(facebook.findPerson(person).getFriends());
                    users.setText(person+"'s friends: ");
                    users.setStyle("-fx-text-fill: black");
                    printFriendsField.clear();
                } catch (LinkedList.PersonNotFoundException e) {
                    textArea.setText("The person entered is not a facebook user");
                    users.setStyle("-fx-text-fill: red");
                }
            }
        });
        Button sortedPrintSubmit = new Button("Print in sorted order");
        sortedPrintSubmit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    String person = printFriendsField.getText();
                    textArea.setText(facebook.findPerson(person).stringOfSortedFriends());
                    users.setText(person+"'s friends in sorted order: ");
                    users.setStyle("-fx-text-fill: black");
                    printFriendsField.clear();
                } catch (LinkedList.PersonNotFoundException e) {
                    textArea.setText("The person entered is not a facebook user");
                    users.setStyle("-fx-text-fill: red");
                }
            }
        });
        printFriends.getChildren().addAll(printFriendsLabel, printFriendsField, printSubmit, sortedPrintSubmit);

        inputFields.getChildren().addAll(display, add, delete, friendUnfriend, friendshipStatus,
                printFriends, users, textArea);

        Scene scene = new Scene(inputFields);
        stage.setScene(scene);
        stage.setX(100);
        stage.setY(0);
        stage.setMinHeight(600);
        stage.setMinWidth(450);
        stage.setTitle("Facebook");
        stage.show();
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}