package login;


import EnumType.OwnerType;
import OthelloPane.OthelloPane;
import login.othelloMain;
import Owner.Owner;
import javafx.application.Application; 
import static javafx.application.Application.launch; 
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets; 
import javafx.geometry.Pos; 
import javafx.scene.Scene; 
import javafx.scene.control.Button; 
import javafx.scene.control.CheckBox;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.PasswordField; 
import javafx.scene.control.RadioButton;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.layout.GridPane; 
import javafx.scene.text.Text; 
import javafx.scene.control.TextField; 
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;  
import static login.othelloMain.BOARD_SIZE;
import static login.othelloMain.BOX_SIZE;
import static login.othelloMain.FLIP_DURATION;
import static login.othelloMain.othelloPane;
import static login.othelloMain.setupClickListeners;
         
public class Login extends Application
{ 
  @Override 
  public void start(Stage stage) 
  {
       
    //Creating a Grid Pane 
    GridPane loginpass = new GridPane();    
    GridPane profileGrid = new GridPane();  
    GridPane homeGrid = new GridPane();
    GridPane OthelloGrid = new GridPane();
    GridPane diffcultGrid = new GridPane();
    
    //othelloGrid properties
    OthelloGrid.setMinSize(500, 500); 
    OthelloGrid.setPadding(new Insets(10, 10, 10, 10)); 
    OthelloGrid.setVgap(10); 
    OthelloGrid.setHgap(0);       
    OthelloGrid.setAlignment(Pos.CENTER); 
    
    //loginpass propertise
    loginpass.setMinSize(400, 200); 
    loginpass.setPadding(new Insets(10, 10, 10, 10)); 
    loginpass.setVgap(5); 
    loginpass.setHgap(5);       
    loginpass.setAlignment(Pos.CENTER); 
    
    //profileGrid
    profileGrid.setMinSize(500, 300); 
    profileGrid.setPadding(new Insets(10, 10, 10, 10));  
    profileGrid.setVgap(5); 
    profileGrid.setHgap(5);       
    profileGrid.setAlignment(Pos.CENTER); 

    //homeGrid propertise
    homeGrid.setMinSize(400, 200); 
    homeGrid.setPadding(new Insets(10, 10, 10, 10)); 
    homeGrid.setVgap(5); 
    homeGrid.setHgap(5); 
    homeGrid.setAlignment(Pos.CENTER); 
      
    //diffcultGrid properties
    diffcultGrid.setMinSize(400, 400); 
    diffcultGrid.setPadding(new Insets(10, 10, 10, 10)); 
    diffcultGrid.setVgap(5); 
    diffcultGrid.setHgap(5);       
    diffcultGrid.setAlignment(Pos.CENTER); 
    
    //Creating a scene object 
    Scene loginScene = new Scene(loginpass); 
    Scene profileScene = new Scene(profileGrid); 
    BorderPane layout = new BorderPane();
    Scene home = new Scene (layout,400,300);
    Scene othelloscene = new Scene(OthelloGrid);
    Scene diffcultscene = new Scene(diffcultGrid);
    
    //Setting title to the Stage 
    stage.setTitle("Login"); 
       
    //Adding scene to the stage 
    stage.setScene(loginScene);
    
    //Displaying the contents of the stage 
    stage.show();  
    
    //Label for user 
    Text emailtextsgn = new Text("Email"); 
    
    //Text field for user 
    TextField emailfieldsgn = new TextField();
    
    //Label for pass 
    Text passname = new Text("Password"); 
    
    //Text field for pass 
    PasswordField passText = new PasswordField();
    
    //Label for name 
    Text nameLabel = new Text("Frist Name"); 
    
    //Text field for name 
    TextField nameText = new TextField(); 
     
    Text Lastname = new Text("Last Name"); 
    
    //Text field for last 
    TextField Lasttext = new TextField(); 
    
    //Label for date of birth 
    Text dobLabel = new Text("Date of birth"); 
    
    //date picker to choose date 
    DatePicker datePicker = new DatePicker(); 
     
    //Label for gender
    Text genderLabel = new Text("Gender"); 
    
    //Toggle group of radio buttons       
    ToggleGroup groupGender = new ToggleGroup(); 
    RadioButton maleRadio = new RadioButton("male"); 
    maleRadio.setToggleGroup(groupGender); 
    RadioButton femaleRadio = new RadioButton("female"); 
    femaleRadio.setToggleGroup(groupGender);  
          
    //Label for location 
    Text locationLabel = new Text("Location"); 
    
    //Choice box for location 
    ChoiceBox locationchoiceBox = new ChoiceBox(); 
    locationchoiceBox.getItems().addAll
       ("Iran", "USA", "UK", "France", "German"); 
     
    //Label for register 
    Button buttonRegister = new Button("Register");  
    
    //Creating Buttons 
    Button bcksgn = new Button("Back"); 
    Button clsgn = new Button("Clear"); 
     
    //Arranging all the nodes in the grid 
    profileGrid.add(emailtextsgn, 0, 0); 
    profileGrid.add(emailfieldsgn, 1, 0);
    
    profileGrid.add(passname, 0, 1); 
    profileGrid.add(passText, 1, 1);
    
    profileGrid.add(nameLabel, 0, 2); 
    profileGrid.add(nameText, 1, 2); 
    
    profileGrid.add(Lastname, 0, 3); 
    profileGrid.add(Lasttext, 1, 3); 
    
    profileGrid.add(dobLabel, 0, 4);       
    profileGrid.add(datePicker, 1, 4); 
    
    profileGrid.add(genderLabel, 0, 5); 
    profileGrid.add(maleRadio, 1, 5);       
    profileGrid.add(femaleRadio, 2, 5);  
     
    profileGrid.add(locationLabel, 0, 8); 
    profileGrid.add(locationchoiceBox, 1, 8);    
     
    profileGrid.add(buttonRegister, 2, 9);      
    profileGrid.add(clsgn , 3, 9);
    profileGrid.add(bcksgn , 4, 9);
    
    //Back Button
    bcksgn.setOnAction(e -> 
    {
      stage.setScene(loginScene);
      stage.setTitle("Login"); 
    });

    //Clear Button
    clsgn.setOnAction(e ->{
        emailfieldsgn.clear();
        passText.clear();
        nameText.clear();
        Lasttext.clear();
        datePicker.getEditor().clear();
        maleRadio.setSelected(false);
        femaleRadio.setSelected(false);
        locationchoiceBox.getSelectionModel().clearSelection();
    });
      
    //Styling nodes   
    buttonRegister.setStyle(
       "-fx-background-color: darkslateblue; -fx-text-fill: white;");
    clsgn.setStyle(
            "-fx-background-color: darkslateblue; -fx-text-fill: white;");
    emailtextsgn.setStyle("-fx-font: normal bold 15px 'serif' "); 
    passname.setStyle("-fx-font: normal bold 15px 'serif' "); 
    Lastname.setStyle("-fx-font: normal bold 15px 'serif' "); 
    nameLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
    dobLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
    genderLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
    locationLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
     
   
    profileGrid.setStyle("-fx-background-color: BEIGE;");       
    
    Text emailTextlogin = new Text("Email");       
    Text passTextlogin = new Text("Password"); 
    TextField emailFieldlogin = new TextField();       
    PasswordField passFiledlogin = new PasswordField();  
    Text newuser = new Text("New user?");
    Button signup = new Button("Sign up");
    Button bsubmit = new Button("Submit"); 
    Button cllogin = new Button("Clear");  
    Text Message = new Text();
  
    loginpass.add(emailTextlogin, 0, 0); 
    loginpass.add(emailFieldlogin, 1, 0);
    loginpass.add(passTextlogin, 0, 1);       
    loginpass.add(passFiledlogin, 1, 1);
    loginpass.add(Message,1,2);
    loginpass.add(newuser,0,4);
    loginpass.add(signup,1,4);
    loginpass.add(bsubmit, 0, 5); 
    loginpass.add(cllogin, 1, 5); 
    
    
    cllogin.setOnAction(e ->{
      emailFieldlogin.clear();
      passFiledlogin.clear();
    });
      
      
    bsubmit.setOnAction(e->{
      Message.setFill(Color.RED);

      String email = emailFieldlogin.getText();
      String password = passFiledlogin.getText();
      if(email.equals(""))
      {
          Message.setText("Please enter the email");
      }
      else if(password.equals(""))
      {
          Message.setText("Please enter the password");
      }
      else
      {
        stage.setScene(home);
        stage.setTitle("Home"); 
      }
    });

        
    bsubmit.setStyle("-fx-background-color: darkslateblue; -fx-text-fill: white;"); 
    cllogin.setStyle("-fx-background-color: darkslateblue; -fx-text-fill: white;"); 
     
    emailTextlogin.setStyle("-fx-font: normal bold 20px 'serif' "); 
    passTextlogin.setStyle("-fx-font: normal bold 20px 'serif' ");  
    loginpass.setStyle("-fx-background-color: BEIGE;"); 
    

    signup.setOnAction(e -> {stage.setScene(profileScene);stage.setTitle("Sign Up"); });
       
    Button oth = new Button("Othello");
    oth.setOnAction(e-> {stage.setScene(diffcultscene);stage.setTitle("Difficulty"); });
    Button tic = new Button("Tic Tac Teo");

    tic.setOnAction((ActionEvent e) -> {
      Text soon = new Text("Coming Soon...");
      soon.setStyle("-fx-font: normal bold 25px 'serif'; ");
      soon.setFill(Color.RED);
      GridPane coming = new GridPane();
      coming.setMinSize(250, 150);
      coming.setPadding(new Insets(20, 20, 20, 20));
      coming.setAlignment(Pos.CENTER);
      coming.setStyle("-fx-background-color: BEIGE;");
      coming.add(soon,0,0);
      Scene come = new Scene(coming);
      Stage stage1 = new Stage();
      stage1.setTitle("Tic Tac Teo");
      stage1.setScene(come);
      stage1.show();
    });
  
    Menu fileMenu = new Menu("Menu");

    fileMenu.getItems().add(new MenuItem("Game options"));
    fileMenu.getItems().add(new MenuItem("Show profile"));
    fileMenu.getItems().add(new MenuItem("Set Difficulty"));
    fileMenu.getItems().add(new SeparatorMenuItem());
    fileMenu.getItems().add(new MenuItem("Setting"));
    fileMenu.getItems().add(new MenuItem("Exit"));
    
    MenuItem paste = new MenuItem ("Paste");
    paste.setOnAction(e->System.out.println("Pasting some crap"));
    paste.setDisable(true);
    
    MenuBar menuBar = new MenuBar();
    menuBar.getMenus().addAll(fileMenu);

    layout.setTop(menuBar);
    homeGrid.add(oth, 0, 3);
    homeGrid.add(tic, 0, 4);
    Button sgnout = new Button("Sign Out");
    sgnout.setOnAction(e->{stage.setScene(loginScene);stage.setTitle("Login");});
    homeGrid.add(sgnout,0,7);
    layout.setCenter(homeGrid);
    Text difficulty = new Text("Choose Diffculty of Game:"); 
    ToggleGroup diff = new ToggleGroup(); 
    RadioButton hard = new RadioButton("Hard"); 
    hard.setToggleGroup(diff); 
    RadioButton medium = new RadioButton("Medium"); 
    medium.setToggleGroup(diff);  
    RadioButton easy = new RadioButton("easy"); 
    easy.setToggleGroup(diff);
    
    Button con = new Button("Continue");
    Button cancel = new Button("Cancel");
    
    diffcultGrid.add(difficulty, 1,0);
    diffcultGrid.add(hard,1,2);
    diffcultGrid.add(medium,1,3);
    diffcultGrid.add(easy,1,4);
    diffcultGrid.add(con,1,8);
    diffcultGrid.add(cancel,2,8);

    con.setOnAction(e->{stage.setScene(othelloscene);stage.setTitle("Othello"); });
    cancel.setOnAction(e->{stage.setScene(home);stage.setTitle("Home");});
    othelloPane = new OthelloPane(BOARD_SIZE, BOX_SIZE, FLIP_DURATION);
     
    TitleLabel ownerTurnLabel;
    ownerTurnLabel = new TitleLabel(0, true);
    OthelloGrid.add(ownerTurnLabel, 0, 0);
    setupClickListeners();
    OthelloGrid.add(othelloPane, 0, 1);

    Button backoth = new Button("Back");
    backoth.setOnAction(e->{stage.setScene(home);stage.setTitle("Home");});
    
    Button help = new Button("Help");
    help.setOnAction(e->{});
    OthelloGrid.add(backoth,1,2);
    OthelloGrid.add(help,0,2);
   }      
   public static void main(String args[])
   { 
      launch(args); 
   } 
}
