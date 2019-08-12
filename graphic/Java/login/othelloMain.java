package login;

import EnumType.OwnerType;
import OthelloPane.OthelloPane;
import Owner.Owner;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import static login.othelloMain.othelloPane;


public class othelloMain {
    
    static final String BOARD_GAME_NAME = "Othello";
    static final int BOARD_SIZE = 8;
    static final int BOX_SIZE = 40;
    static final int FLIP_DURATION = 500;

    static int blackOwnerPoints = 0;
    static int whiteOwnerPoints = 0;

    static final OwnerType startingOwner = OwnerType.BLACK;

    static OwnerType currentTurn = startingOwner;
 
    static OthelloPane othelloPane;

    public static void setupClickListeners() 
    { 
        for (int row = 0; row < BOARD_SIZE; row++) 
        {
            for (int column = 0; column < BOARD_SIZE; column++) 
            {
                final Owner currentOwner = othelloPane.getOwner(row, column);
                final int f_row = row;
                final int f_column = column;
                othelloPane.getBox(f_row, f_column).setOnMouseClicked(event -> {
                System.out.println("on box with the row: "+f_row +" column: "+ f_column);
                    
                if(f_row == 4 && f_column == 3)
                {
                    GridPane errorGrid = new GridPane();
                    errorGrid.setMinSize(250, 150);
                    errorGrid.setPadding(new Insets(20, 20, 20, 20));
                    errorGrid.setAlignment(Pos.CENTER);
                    errorGrid.setStyle("-fx-background-color: BEIGE;");
                    Scene errorscen = new Scene(errorGrid);
                    Stage stage1 = new Stage();
                    stage1.setTitle("Tic Tac Teo");
                    stage1.setScene(errorscen);
                    stage1.show();
                    Text error = new Text("Invalid move!!!!");
                    error.setStyle("-fx-font: normal bold 25px 'serif'; ");
                    error.setFill(Color.RED);
                    
                    Button ok = new Button("OK");
                    ok.setOnAction(e->stage1.close());
                    errorGrid.add(error,0,0);
                    errorGrid.add(ok,1,5);
                }
                });
            }
        }
    }
}


class TitleLabel extends Label 
{ 
    final int padding = 30;
    private TitleLabel() {}
    public TitleLabel(int fontSize, boolean bold) 
    {
        setFont(new Font(30));
        setMaxWidth(Double.MAX_VALUE);
        setAlignment(Pos.CENTER);
        setPadding(new Insets(30,0,30,0));

        if (bold) setStyle("-fx-font-weight: bold");
    }
} 