

void initWindow()
{ 
  //3 par rangé
  for(int i=0; i<NB_LINES;i++) {
      int y= 25 - (12 *i);
      int numFenetre = i*3;
      fenetres[numFenetre].life = LIFE_FENTRE;
      fenetres[numFenetre].x = 28;
      fenetres[numFenetre].y = y;
      
      fenetres[numFenetre+1].life = LIFE_FENTRE;
      fenetres[numFenetre+1].x = 36;
      fenetres[numFenetre+1].y = y;
      
      fenetres[numFenetre+2].life = LIFE_FENTRE;
      fenetres[numFenetre+2].x = 44;
      fenetres[numFenetre+2].y = y;
  }
      
    //roof Top
    fenetres[NB_FENTRES].life = LIFE_FENTRE * 3;
    fenetres[NB_FENTRES].x = 36;
    fenetres[NB_FENTRES].y = -48;
}

void drawWindow()
{
  
  for(int i=0; i<NB_FENTRES;i++) {
      gb.display.drawBitmap(fenetres[i].x - camX, fenetres[i].y - camY, chooseSprite(fenetres[i].life));
  }
}

void updateWindow()
{
}

const byte * chooseSprite(int life)
{
  if(life<10) {
      return windows10; 
  }
  if(life<50) {
      return windows50; 
  }
  if(life<99) {
      return windows99; 
  }
  
  return windows100;
}
