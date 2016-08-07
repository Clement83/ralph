
void initRalph()
{
  ralph.y = 32;
  ralph.x = 2;
  ralph.status = 0;
}

void drawRalph()
{
  switch (ralph.status) 
  {
    case 3: //jump
      gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle);
    case 0 ://idle
      gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle);
      break;
    case 1 ://punch
      if(gb.frameCount%8 > 3){
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, punch);
      } else {
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle);  
      }
      break;
    case 2 ://walk
      if(gb.frameCount%8 >3){
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, walk1);
      } else {
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, walk2);
      }
      break;
    case 4 ://fall
    //NOROT, ROTCCW, ROT180, ROTCW
    //NOFLIP, FLIPH, FLIPV, FLIPVH
      if(gb.frameCount%20 > 14){
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle,NOROT, NOFLIP);  
      } else if(gb.frameCount%20 > 9){
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle,ROTCCW, NOFLIP);  
      }  else if(gb.frameCount%20 > 4){
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle,ROT180, NOFLIP);  
      }  else {
        gb.display.drawBitmap(ralph.x - camX, ralph.y - camY, idle,ROTCW, NOFLIP);  
      } 
      break;
  
  }
}

int indexFenetre;
void updateRalph()
{
   if (ralph.status == 1){
    //if ralph is on window he hurt  
    fenetres[indexFenetre].life -= HIT_RALPH;
    
    if(fenetres[indexFenetre].life<=0) {
        fenetres[indexFenetre].life = 0;
        ralph.status = 0;
        if(indexFenetre == NB_FENTRES) {
          state = S_END_GAME;
        }
    }
  }else if(ralph.status == 4) {
    fallRalph();
  } else {
     for(int i=0; i<NB_FENTRES;i++) {
      if(i == (NB_FENTRES-1)) {
        indexFenetre = i;
        break;
      }
      if(fenetres[i].life<30) {
        if(fenetres[i].life>fenetres[i + 1].life) {
          indexFenetre = i;
        break;
        }
      } else {
        indexFenetre = i;
        break;
      }
    }
    if(fenetres[indexFenetre].life<=0) {
        //go to rooftop
        indexFenetre = NB_FENTRES;
    }
    
    //ralph go to selected window or roof top
    if(ralph.status != 3 && gb.collidePointRect(ralph.x + 7,ralph.y + 7, fenetres[indexFenetre].x, fenetres[indexFenetre].y, 7, 9)){
        ralph.status = 1;
    } else {
      if(ralph.status != 3 && (ralph.x + 4)<fenetres[indexFenetre].x) {
        ralph.status = 2;
          ralph.x++;
      } else if(ralph.status != 3 && (ralph.x + 4)>fenetres[indexFenetre].x){
        ralph.status = 2;
          ralph.x--;
      } else if(roofLevel(ralph.y + 15)>roofLevel(fenetres[indexFenetre].y)){
        ralph.status = 3;
        ralph.y--;
      } else if(roofLevel(ralph.y + 15)<roofLevel(fenetres[indexFenetre].y)) {
        ralph.status = 3;
        ralph.y++;
      } else {
        ralph.status = 0;  
      }
    }
  }
  
}

void updateEndGameRalph()
{
  if(ralph.x<70) {
    ralph.x++;
  } else if(ralph.y<32) {
    ralph.status = 4;
    fallRalph();
  }  else {
    state = S_GAME_OVER;
  }
}

void fallRalph()
{
  if(ralph.y<32) {
    ralph.y++;
  } else {
    ralph.status = 0;
  }
}

int roofLevel(int y)
{
    //47 to 36  ground
    //all 12px is new level
    
    return ((y-47) / 12);
    
}
