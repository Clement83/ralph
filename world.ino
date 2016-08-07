


void initWord()
{
}

void drawWord()
{
  gb.display.drawLine(0,47 - camY,84,47 - camY);
  int x = 20 - camX;
  gb.display.drawBitmap(x,36 - camY, GroundFloor);
  gb.display.drawBitmap(x,-1 - camY, floors);
  gb.display.drawBitmap(x,-37 - camY, floors);
  if(fenetres[NB_FENTRES].life<30) {
    gb.display.drawBitmap(x,-48 - camY, RoofTop10);
  } else if(fenetres[NB_FENTRES].life<180) {
    gb.display.drawBitmap(x,-48 - camY, RoofTop50);
  } else if(fenetres[NB_FENTRES].life<270) {
    gb.display.drawBitmap(x,-48 - camY, RoofTop99);
  }  else {
    gb.display.drawBitmap(x,-48 - camY, RoofTop100);  
  }
  
  
  
   for(int i=0; i<NB_LINES;i++) {
      int y= 25 - (12 *i);
  }
}

void updateWord()
{
}
