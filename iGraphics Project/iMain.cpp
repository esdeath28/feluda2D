#define screenHeight 1024
#define screenWidth 768
#include "allheader.h"  // This header file includes all header file like "iGraphics.h","bitmap_loader.h", "pictures.h",....etc



void iDraw()
{

    iClear();
    /* gamestat is called  different phase in game. It is called by iMouse function,
      clicking inside a parameter will cause the mode to change according to the players desire  */

    if(gamestat==0)
    {  
        showintro();   //in functions.h , Shows intro images.
		
    }
    if(gamestat==1)
    {
        showmenu();   // in functions.h, show menu images & buttons.
        blink();      // in functions.h, show upper layer icon called by iPassiveMouse,when mouse pointer in desire range
        timer1();     // in Timer.h, called iSetTimer for rendering background image

    }
    if(gamestat==2)
    {
        startgame();  // in functions.h, starting game,player,movement....etc
        timer2();     // in Timer.h,
    }
    if(gamestat==3)
    {
        showscore();  // in functions.h, show high score
    }
    if(gamestat==4)
    {
        showsettings(); // in functions.h, show control instructions
    }
    if(gamestat==5)
    {
        showabout();    // in functions.h, show project members descripions
    }


}

/* iPassiveMouse is taking value from mouse pointer iMouseX,iMouseY continuously
    and return this value to blink function in function.h,for blink menu icon.   */

void iPassiveMouse(int mx, int my)
{   
	

    if (mx >= 0 && mx <= 1000 && my >= 0 && my <= 736)
    {
        pointer =1;    // change mouse pointer icon

    }
    if(mx>=20&&mx<=220&&my>=590&&my<=760)

        blink1 = 1;    // change icon at start game bar
    else
        blink1 =0;     // remain same start game bar

    if(mx>=20&&mx<=220&&my>=410&&my<=540)
        blink2 = 1;    // change icon at settings bar
    else
        blink2 = 0;    // remain same settings bar

    if(mx>=20&&mx<=220&&my>=240&&my<=370)
        blink3 = 1;    // change icon at score bar
    else
        blink3 =0;     // remain same score bar
    
	if(mx>=107&&mx<=330&&my>=490&&my<=550)
	{
		settingVar=2;  // in functions.h, defines settings phase
	}
	else settingVar=1;

	if(mx>=80&&mx<=730&&my>=310&&my<=346)
	{
		settingVar=3;   // in functions.h, defines settings phase
	}
	
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n", mx, my);
    //place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(gamestat==0)                       // At this range it will call menu function, when intro function is actived
        {
            gamestat=1;
        }
        if(mx>=20&&mx<=220&&my>=590&&my<=760)  // At this range it will call start game function, when main menu is actived
        {
            if(gamestat==1)
                gamestat=2;
        }
        if(mx>=20&&mx<=220&&my>=240&&my<=370)  // At this range it will call Score function, when main menu is actived
        {
            if(gamestat==1)
                gamestat=3;
        }
        if(mx>=20&&mx<=220&&my>=410&&my<=540)  // At this range it will call Setting function, when main menu is actived
        {
            if(gamestat==1)
                gamestat=4;
			showSettings=true;
        }

        if(mx>=20&&mx<=220&&my>=70&&my<=130)   // At this range it will  close game , when main menu is actived
        {
            exit(0);
        }
		if(gamestat==4)
		{
		if(mx>=80&&mx<=730&&my>=310&&my<=346)
		{
           controlKeyBoard=true;               // in functions.h, user can select keyboard key settings
		}
		if(mx>=415&&mx<=535&&my>=5&&my<=125)
		   {  
			controlKeyBoard=false;
			keyVar=0;
		   }
		}
		
		if(inventoryMode)                      // show players collection of clue
		{
            if(mx>=600&&mx<=660&&my>=524&&my<=622)
			  bookMode=true;
	          if(bookMode)
			  {
			   if(mx>=15&&mx<=92&&my>=15&&my<=88)
			    bookChapter=4;

               if(mx>=850&&mx<=895&&my>=15&&my<=88)
			     bookChapter=5;
			   if(mx>=415&&mx<=535&&my>=5&&my<=125)
			     bookMode=false;
			  }
			  if(mx>=800&&mx<=850&&my>=524&&my<=622)
			  clueMode=true;
	          if(clueMode)
			  {
			   if(mx>=415&&mx<=535&&my>=5&&my<=125)
			     clueMode=false;
			  }
		}
		if(inGameState==6)
		{
		level=5;
		initializeValue();
		enemyCount++;
		inGameState++;
		}
		if(inGameState==4)
		{
		level=4;
		enemyCount++;
		initializeValue();
		inGameState++;
		}
		if(inGameState==3)
	{
		if(mx>=900&&mx<=1024&&my>=50&&my<=100)
		{
			inGameState++;
		}
	}
    }

    if(mx>=900&&mx<=1000&&my>=70&&my<=170)     // At this range it will call about function, when main menu is actived
    {
        if(gamestat==1)
            gamestat=5;
    }


    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
    /* phase lies in functions.h at startgame(). which defines different state for character */
	if(key == 27)
    {
        gamestat =1;          // call back to  menu function
	}
	if(gameStart)
	{
	if (key == 'z')
    {
        if(phase==0)       // characters right standing position
        {
            phase=4;       // characters right punch position
			collisiondistract=1;
        }
        if(phase==3)       // characters left standing position
        {
            phase=5;       // characters left punch position
        }
    }

    if (key == 'q')
    {
        if(phase==0)        //characters right standing position
        {
            phase=6;        //characters right kick position
			collisiondistract=1;
        }
        if(phase==3)        //characters left standing position
        {
            phase=7;        //characters left kick position
        }
    }
    if (key == 'x')
    {
        if(phase==0)         //characters right standing position
        {
            phase=8;         //characters right gun shoot position
        }
        if(phase==3)         //characters left standing position
        {
            phase=9;         // characters left gun shoot position
        }
    }
    if (key == 'h')
    {
        if(phase==0)         //characters right standing position
        {
            phase=10;        //characters right jump position
        }
        if(phase==3)         //characters left standing position
        {
            phase=11;        //characters left jump position
        }
    }

    if(key == 'b')
    {
        enemyPhase=3;
		//iSetTimer(100,change);
    }

    

	 if(key == 'f')            // players clue collection mode will open
	 {
		  if(level==4)
		  {
			if(clueFlag==1)
			{
			inGameState=6;
		    initialize=4;
			}
			  if(clueShow)
			{
			if(clueFlag==0)
			  clueFlag=1;
			}
		  }
		 if(evidenceCollect==1)
		 {
			 evidenceCollect=0;
		 }
	 if(collisionBarrel==3)
	 {
     evidenceCollect=1;
	 }
	 //if(x>enemyx+30&&x<enemyx+80)
	 {
	    if(evidenceCollect==3)
		 {
			 evidenceCollect=0;
		 }

		 if(clueShow)
	 {
		 clueShow=false;
		 evidenceCollect=3;
	 }
		 if(trunkAppeare)
		 {
			 if(x>=trunkX-100&&x<=trunkX)
			 {
			 trunkAppeare=false;
			 passwordAppeare=true;
			 }
		 }
	 }
	 if(stoneAppeare)
	 {
		 stoneAppeare=false;
		 level=6;
	 }
	 if(level==3)
		 inGameState=1;
	 }
	 if(key == 'd')
	 {
		 defending=true;
		 phase=12;
	 }
	  if(key == 'i')
	 {
		 if(inventoryMode)
		 inventoryMode=false;
		 else
		 inventoryMode=true;
		
	 }
	  if(key!='f')
	  {
	  if(passwordAppeare)
	  {
      if(key == '\b')
	  {
        keyIndex--;
		passKey[keyIndex]='\0';
		  
		
	  }
	  storePassword(key);
	  }
	  }
	}

	if(!gameStart)         
	{
	 
		takePlayerName(key);     // in score.h, takeing player's name
		if(showSettings)
		getKey(key);
		
 }

}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_RIGHT)
    {
        phase=1;              //characters right walk
    }
    if (key == GLUT_KEY_LEFT)
    {
        phase=2;              //characters left walk
    }
	getKey(key);

}

int musicON=1;
void changemusic()
{
    musicON=0;
    PlaySound(0,0,0);
}

//
void change()
{
 r=rand()%255;
 g=rand()%255;
 b=rand()%255;

}
//
void callMusic()
{
	PlaySound("music\\Intro 1.wav",NULL,SND_LOOP|SND_ASYNC);
}
int main()
{
    //place your own initialization codes here.
   // iSetTimer(60000,changemusic);
    PlaySound("music\\Intro 1.wav",NULL,SND_LOOP|SND_ASYNC);
    iInitialize(screenHeight,screenWidth, "Feluda:The Game");
    load_all_image();
    iStart(); // it will start drawing

    return 0;
}

