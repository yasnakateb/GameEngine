package EnumType;
import javafx.scene.paint.Color;

public enum OwnerType 
{
    NONE,
    WHITE,
    BLACK;
    public Color getColor() 
    {
        switch (this) 
        {
            case WHITE: return Color.WHITE;
            case BLACK: return Color.BLACK;
            default: return null;
        }
    }

    @Override
    public String toString() 
    {
        switch (this)
        {
            case WHITE: return "White";
            case BLACK: return "Black";
            default: return "None";
        }
    }
}; 
