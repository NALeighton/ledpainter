public class Cell{

  private float xPos;
  private float yPos;
  private float unitSizeX;
  private float unitSizeY;
  private boolean active;
  private boolean changed;
  private int life;

  //Square displayed on the screen is a cell
  public Cell(float xPos, float yPos, float unitSizeX, float unitSizeY)
  {
    this.xPos = xPos;
    this.yPos = yPos;
    this.unitSizeX = unitSizeX;
    this.unitSizeY = unitSizeY;
    active = false;
    changed = false;
    life = 0;
  }

  public int getLife()
  {
    return life;
  }

  public void tick()
  {
    if(life == 0 && active == false) return;
    else
    {
      life --;
      if(life == 0)
      {
        setState(false);
      }
    }
  }

  public void setState(boolean state)
  {
    active = state;
    changed = true;
    if (active)life = 20;
    else
    {
      life = 0;
      changed = true;
    }
  }

  public void setChanged(boolean state)
  {
    changed = state;
  }
  public boolean getChanged()
  {
    return changed;
  }

  public boolean getState()
  {
    return active;
  }

  //boolean x is used to determin which axis you are questing the size of. True = X, False = Y

  public float getUnitSize(boolean x)
  {
    if(x)
    {
      return unitSizeX;
    }
    else
    {
      return unitSizeY;
    }
  }

  public float getPos(boolean x)
  {
    if(x)
    {
      return xPos;
    }
    else
    {
      return yPos;
    }
  }
}
