public class GridManager{

  Cell cells[];

  //Helper for managing all of the cells being displayed
  public GridManager(float unitSizeX, float unitSizeY)
  {
    cells = new Cell[696];
    int i = 0;
    for(int x = 0; x < 24; x++)
    {
      for(int y = 0; y < 29; y++)
      {
        cells[i] = new Cell(x*unitSizeX,y*unitSizeY,unitSizeX,unitSizeY);
        i++;
      }
    }
    for(int q = 0; q < 696; q++)
    {
      cells[q].setState(false);
    }
  }

  public void tick()
  {
    for(int i = 0; i < 696; i++)
    {
      cells[i].tick();
    }
  }

  public void updateGrid(float x, float y)
  {
    for(int i = 0; i < 696; i++)
    {
      if(x > cells[i].getPos(true) && x < cells[i].getPos(true)+cells[i].getUnitSize(true) && y > cells[i].getPos(false) && y < cells[i].getPos(false)+cells[i].getUnitSize(false))
      {
        cells[i].setState(true);
      }
    }
  }

  public Cell getCell(int i)
  {
    return cells[i];
  }
}
