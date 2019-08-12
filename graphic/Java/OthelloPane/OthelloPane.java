package OthelloPane;

import EnumType.OwnerType;
import Owner.Owner;
import javafx.geometry.Pos;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.RowConstraints;
import javafx.util.Duration;

public class OthelloPane extends GridPane 
{ 
    private String backgroundInHex = "#123456";
    private int boardSize;
    private int boxSize;
    private Duration flipDuration;
    private int[][] directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    private Owner[][] owners;
    private Pane[][] boxes;

    public OthelloPane(int boardSize, int boxSize, double flipDuration) {
        super();
        owners = new Owner[boardSize][boardSize];
        boxes = new Pane[boardSize][boardSize];

        this.boardSize = boardSize;
        this.boxSize = boxSize;
        this.flipDuration = Duration.millis(flipDuration);

        for (int i = 0; i < boardSize; i++)
            getRowConstraints().add( new RowConstraints(boxSize));
        for (int i = 0; i < boardSize; i++)
            getColumnConstraints().add( new ColumnConstraints(boxSize));

        for (int i = 0; i < boardSize; i++) 
        {
            for (int j = 0; j < boardSize; j++) 
            {
                Pane box = new Pane();
                Owner owner = new Owner(boxSize, OwnerType.NONE);
                box.setStyle("-fx-background-color: " + backgroundInHex + ";");
                box.getChildren().add(owner);
                setOwner(i, j, owner);
                setBox(i, j, box);
                add(box, j, i);
            }
        }

        int middle = boardSize/2;
        Owner topLeft = owners[middle -1][middle -1];
        Owner topRight = owners[middle -1][middle];
        Owner bottomLeft = owners[middle][middle -1];
        Owner bottomRight = owners[middle][middle];

        topLeft.setType(OwnerType.BLACK);
        bottomRight.setType(OwnerType.BLACK);
        topRight.setType(OwnerType.WHITE);
        bottomLeft.setType(OwnerType.WHITE);

        setGridLinesVisible(true);
        setAlignment(Pos.CENTER);
    }

    public Pane getBox(int row, int column) 
    {
        return boxes[row][column];
    }

    public Owner getOwner(int row, int column) 
    {
        return owners[row][column];
    }

    private void setBox(int row, int column, Pane box) 
    {
        boxes[row][column] = box;
    }
    private void setOwner(int row, int column, Owner owner) 
    {
        owners[row][column] = owner;
    }
}