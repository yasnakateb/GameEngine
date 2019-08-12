package Owner;

import EnumType.OwnerType;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class Owner extends Circle 
{
    private OwnerType type = OwnerType.NONE;
    private Owner() {} 
    public Owner(int size, OwnerType type) 
    {
        super();

        int center = size / 2;
        this.type = type;
        setFill(type.getColor());
        
        setCenterX(center);
        setCenterY(center);
        setRadius(center-5);
    }
    public OwnerType getType() { return type; }
    public void setType(OwnerType type) 
    {
        this.type = type;
        setFill(type.getColor());
    }
}