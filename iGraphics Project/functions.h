/* this header file includes user define functions   */



#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "Score.h";
void showintro();
void showmenu();
void changemenu();
void showStory();
void showsettings();
void showscore();
void startgame();
void walk();
void showabout();
void blink();
int road,night,building,tree,cc,dd,ee,ff;
int r,g,b;
//
void enemyshowdown();
void enemyshowdown2();
void enemyshowdown3();
void enemyshowdown4();
void enemyshowdown5();
void enemyshowdown6();
void storePassword();
void change();
void initializeValue();
void initializeValueExcept();
void showBarrel();
void soundEffect();
//

///////////////////////SHOWING INTRO/////////////////////////////////////
int j;
void showintro()
{

    iShowImage(0,0,1024,768,i_image[j]);
    iDelayMS(100);
    j++;
    if(j>7)
        j=6;
    iText(420,100,"Press Mouse Button to Continue");
}


////////////////////////SHOWING MENU//////////////////////////////
int u=0;
void showmenu()
{
    iShowImage(0,0,1024,768,m_image[u]);
	 iShowImage(600,490,360,270,menu_head);
    iShowImage(20,590,200,130,button1);
    iShowImage(20,410,200,130,button2);
    iShowImage(20,240,200,130,button3);
    iShowImage(20,70,200,130,button4);
    iShowImage(900,70,100,100,button5);
}

////////////////////////////MENU CHANGE///////////////
void changemenu()
{
    u++;
    if(u>64)
        u=0;
}


///////////////////////// MENU BLINK/////////////////
int pointer=0,blink1=0,blink2 =0,blink3=0,blink4= 0;


void blink()
{
	if(pointer ==1)
        iShowImage(iMouseX-25,iMouseY-30,60,60,mpointer);

    if(blink1 ==1 && gamestat==1 )
    {
        iRotate(90,670,rand()%25);
        iShowImage(50,630,80,80,button1_1);
		iDelayMS(200);
        iUnRotate();

    }
    if(blink2 ==1 && gamestat==1 )
    {
        iRotate(90,490,rand()%25);
        iShowImage(50,420,150,150,button2_1);
		iDelayMS(200);
        iUnRotate();

    }
    if(blink3 ==1 && gamestat==1 )
    {
        iRotate(90,330,rand()%25);
        iShowImage(50,270,100,100,button3_1);
		iDelayMS(200);
        iUnRotate();

    }


}




/////////////////////SHOW STORYLINE/////////////
bool storyMode=true,gameStart=false;
int storyIndex=0;
int delay;
int soundVar=0;
void showStory()
{
	if(soundVar==0)
		{
		PlaySound("Music\\Music 1.wav",NULL,SND_LOOP|SND_ASYNC);
		soundVar=1;
		}
	iShowImage(0,0,1024,768,story[storyIndex]);
      if(storyIndex<7)
		  delay=150;
	   if(storyIndex>6&&storyIndex<15)
		  delay=1500;
	    if(storyIndex>15)
		  delay=350;
	   iDelayMS(delay);
		storyIndex++;
		if(storyIndex>30)
		{
			storyMode=false;
			initializeValue();
			gameStart=true;
		}
}

///////////////////STARTING GAME///////////////
int initialize=0;
int i=0,phase=0,h=9,x=0,moveright_index=4,moveleft_index=1,s=0,y=70,enemyx=700,enemymoveright_index=4,enemymoveleft_index=1;
int playerHeight=180+60,playerWidth=220+60,playerhealth_index=1;
int collisionBarrel=0,collisiondistract=0;
int evidenceCollect=0;
int enemyPhase=0,enemyIndex=1,positionmode=3,caption_index=1,captionX=enemyx+30,enemyhealth=0,ehealth_index=1,enemyCount=1;
int dumpX[1],dumpIndex=0;
int level=1;
int inventoryPhase=1;
bool captionOn=true,defending=false,enemyDeath=false,nextBar=false,inventoryMode=false,bookMode=false;    
int enemy3x=450,enemy3index=1;
int inGameState=0;
int carX=0,carY=0;
bool showSettings=false;
int eCount=1;

//
int bx=1024,flag=0;
int clueCollect=0;
bool clueShow=false;
int clueVar=0;
int bookChapter=4;
//
int background1x=0,background2x=1024,lastBg1x,lastBg2x;
int barrelx=1024,barrelVar=0,barrelVar2=0,lastBarrelx,lastBarrelx2;
int trunkX=3144,trunkVar=0,initializeStop=0;
bool trunkAppeare=false,passwordAppeare=false,stoneAppeare=false;
char passKey[10];
int keyIndex=0;
bool deathScene=true,clueMode=false;
int deadIndex=1;
int clueFlag=0;
void startgame()
{

   
	score=(eCount-1)*10;
   if(level==1)
   {

	if(!gameStart)
	{
	if(name_input)
	{
	showPlayerName();
	}
	if(!name_input)
	{
    if(storyMode)
	{
	showStory();
	}
	}
	}
	
	if(gameStart)
	{
   iShowImage(0,0,1024,768,bgimage1);
   iShowImage(30,700,40,40,heart);
    onScreen_score_and_name();
    iShowImage(75,702,120,40,playerhealth[playerhealth_index]);
	 iShowImage(500,70,200,220,barrel2);
	

    if(flag==1)
        iShowImage(bx,450,400,400,bgimage6);
    
    if(phase==0)
        iShowImage(x,y,playerHeight,playerWidth,ch_image[8]);
    
    if(phase==1)
    {
        iShowImage(x,y,playerHeight,playerWidth,ch_image[i]);
        
    }
    if(phase==2)
    {
        iShowImage(x,y,playerHeight,playerWidth,ch_image[h]);
     
    }
	if(phase==3)
        iShowImage(x,y,playerHeight,playerWidth,ch_image[17]);

    if(phase==4)
    {

        iShowImage(x,y,playerHeight,playerWidth,punch[moveright_index]);
	
       
        
    }
    if(phase==5)
    {
       
        iShowImage(x,y,playerHeight,playerWidth,punch[moveleft_index]);
		
        
    }
    if(phase==6)
    {
      
        iShowImage(x,y,playerHeight,playerWidth,kick[moveleft_index]);
		
       
    }

    if(phase==7)
    {

        iShowImage(x,y,playerHeight,playerWidth,kick[moveright_index]);
	
       
    }
    if(phase==8)
    {
        iShowImage(x,y,playerHeight,playerWidth,gun[moveright_index]);
        
    }
    if(phase==9)
    {
       
        iShowImage(x,y,playerHeight,playerWidth,gun[moveleft_index]);
        
    }
    if(phase==10)
    {
        iShowImage(x,y,playerHeight,playerWidth,jump[moveright_index]);
    }
    if(phase==11)
    {
        iShowImage(x,y,playerHeight,playerWidth,jump[moveleft_index]);
        
    }
	if(phase==12)
	{
		iShowImage(x,y,playerHeight+50,playerWidth+20,defendRight);
	}

    /////////////Enemy///////////////////
	enemyshowdown();
	if(enemyCount>1)
	 iShowImage(dumpX[0],70,190,75,e_death[4]);
	if(enemyCount==2)
	{  
		if(initialize==0)
		{
			enemyx=900,enemymoveright_index=4,enemymoveleft_index=1;
	enemyPhase=0,enemyIndex=1,positionmode=3,enemyhealth=0,ehealth_index=1;
	defending=false,enemyDeath=false;
	    initialize++;
		}
	enemyshowdown();
	}

	///Latest Works...../////////////
	 if(collisionBarrel==0)
	 {
	 iShowImage(800,50,200,220,barrel2);
	 }
	 if(collisionBarrel==1)
	 {
      iShowImage(760,10,340,320,barrel2_1);
	 }
	 if(collisionBarrel==2)
	 {
      iShowImage(830,50,110,90,barrel2_2);
	  PlaySound("Music\\barrel2.wav",NULL,SND_ASYNC);
	  eCount++;
	  collisionBarrel++;
	 }
	  if(collisionBarrel==3)
	  {
	    iShowImage(830,50,110,90,clue1);
		iText(760,40,"Press F to Collect The Evidence");
	  }
	iShowImage(10,10,200,190,barrel3);
	if(collisionBarrel==0)
	{
	if(x>=740)
	{
		x=740;
	}
	}
	if(x>=720)
	{  
		if(collisiondistract==1)
		{
		if(phase==4||phase==6)
		{ 
			collisionBarrel++;
			collisiondistract=0;
		}
		}
	}
	if(x>=740)
	{
	if(evidenceCollect==1)
	{
		iShowBMP2(0,0,"Background\\paper.bmp",0);
		iText(10,10,"Press F To Close");
		inventoryPhase=2;
		collisionBarrel++;
		nextBar=true;
	}
	}
	if(nextBar)
	{
	 iShowImage(940,600,80,50,arrow);
     iSetColor(r,g,b);
	iText(940,560,"NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
	 iSetColor(255,255,255);
	}
    }
	if(x>screenWidth+20)
	{
		level=2;
	}
	}
	if(level==2)
	{
		if(initialize==1)
		{
			initializeValue();
			initialize=2;
		}
		iShowImage(0,0,1024,768,bgimage7);
		 iShowImage(30,700,40,40,heart);
    iShowImage(75,702,120,40,playerhealth[playerhealth_index]);
	onScreen_score_and_name();
	if(flag==1)
        iShowImage(bx,450,400,400,bgimage6);
    
    if(phase==0)
        iShowImage(x,y,playerHeight,playerWidth,ch_image[8]);
    
    if(phase==1)
    {
        iShowImage(x,y,playerHeight,playerWidth,ch_image[i]);
        
    }
    if(phase==2)
    {
        iShowImage(x,y,playerHeight,playerWidth,ch_image[h]);
     
    }
	if(phase==3)
        iShowImage(x,y,playerHeight,playerWidth,ch_image[17]);

    if(phase==4)
    {

        iShowImage(x,y,playerHeight,playerWidth,punch[moveright_index]);
       
        
    }
    if(phase==5)
    {
       
        iShowImage(x,y,playerHeight,playerWidth,punch[moveleft_index]);
        
    }
    if(phase==6)
    {
      
        iShowImage(x,y,playerHeight,playerWidth,kick[moveleft_index]);
       
    }

    if(phase==7)
    {

        iShowImage(x,y,playerHeight,playerWidth,kick[moveright_index]);
       
    }
    if(phase==8)
    {
        iShowImage(x,y,playerHeight,playerWidth,gun[moveright_index]);
        
    }
    if(phase==9)
    {
       
        iShowImage(x,y,playerHeight,playerWidth,gun[moveleft_index]);
        
    }
    if(phase==10)
    {
        iShowImage(x,y,playerHeight,playerWidth,jump[moveright_index]);
    }
    if(phase==11)
    {
        iShowImage(x,y,playerHeight,playerWidth,jump[moveleft_index]);
        
    }
	if(phase==12)
	{
		iShowImage(x,y,playerHeight+50,playerWidth+20,defendRight);
	}
	enemyshowdown2();
	enemyshowdown3();
	if(enemyDeath)
	{  
		if(clueVar==0)
		{
		clueShow=true;
		clueVar++;
		}
		if(clueShow)
		{
			iShowImage(enemyx+40,70,110,90,clue1);
			iShowImage(enemyx+60,70,110,90,key);
			iSetColor(0,0,0);
		iText(enemyx-10,40,"Press F to Collect The Evidence");
		}
		if(evidenceCollect==3)
	{
		iShowImage(0,0,600,560,clue2);
		inventoryPhase=3;
		iText(10,10,"Press F To Close");
		nextBar=true;
	}
	}
	if(nextBar)
	{
	 iShowImage(940,600,80,50,arrow);
     iSetColor(r,g,b);
	iText(940,560,"NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
	 iSetColor(255,255,255);
	}
    
	if(x>screenWidth+20)
	{
		level=3;
		initialize=2;
	}
	//iShowImage(0,0,1024,500,bgimage7_1);
	}
	if(level==3)
	{
		if(initialize==2)
		{
			initializeValue();
			initialize=3;
		}
		iShowImage(0,0,1024,768,bgimage7_2);
	    iShowImage(30,700,40,40,heart);
		iShowImage(75,702,120,40,playerhealth[playerhealth_index]);
		onScreen_score_and_name();
    
	   if(phase==0)
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[8]);
    
    if(phase==1)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[i]);
        
    }
    if(phase==2)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[h]);
     
    }
	if(phase==3)
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[17]);

    if(phase==4)
    {

        iShowImage(x,y-50,playerHeight,playerWidth,punch[moveright_index]);
       
        
    }
    if(phase==5)
    {
       
        iShowImage(x,y-50,playerHeight,playerWidth,punch[moveleft_index]);
        
    }
    if(phase==6)
    {
      
        iShowImage(x,y-50,playerHeight,playerWidth,kick[moveleft_index]);
       
    }

    if(phase==7)
    {

        iShowImage(x,y-50,playerHeight,playerWidth,kick[moveright_index]);
       
    }
    if(phase==8)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,gun[moveright_index]);
        
    }
    if(phase==9)
    {
       
        iShowImage(x,y-50,playerHeight,playerWidth,gun[moveleft_index]);
        
    }
    if(phase==10)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,jump[moveright_index]);
    }
    if(phase==11)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,jump[moveleft_index]);
        
    }
	if(phase==12)
	{
		iShowImage(x,y-50,playerHeight+50,playerWidth+20,defendRight);
	}
	if(x>=600&x<=750)
	{
	if(inGameState==0) 
	iText(650,350,"Press F To Open The CallBooth");
	if(inGameState==1)
	{
		iText(650,350,"Called Car Driver");
		iDelayMS(500);
		inGameState=2;
	}
	if(inGameState==2)
	{
	 if(carX==x)
	 {
	 iShowImage(carX,carY-50,400,230,car);
	 iDelayMS(500);
	 inGameState=3;
	 }
	 else
	 {
	 iText(650,350,"Called Car Driver");
	 iShowImage(carX++,carY-50,400,230,car);
	 }
	 iDelayMS(5);
	}
	if(inGameState==3)
	{
    iShowImage(0,0,1024,768,levelComplete1); 
	}
	}

	}
	if(inGameState==4)
	{
		iShowImage(0,0,1024,768,level1intro);
		if(soundVar==1)
		{
		PlaySound("music\\morning.wav",NULL,SND_LOOP|SND_ASYNC);
		soundVar=2;
		}
	}
	if(level==4)
	{
		 if(initialize==3)
	   {
		   initializeValue();
		   initialize=4;
	   }
		
	iShowImage(background1x,0,1024,768,bgimage9);
	iShowImage(background2x,0,1024,768,bgimage9);
	 iShowImage(30,700,40,40,heart);
	  onScreen_score_and_name();
	 iShowImage(75,702,120,40,playerhealth[playerhealth_index]);
	   if(phase==0)
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,ch_image[8]);
    
    if(phase==1)
    {
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,ch_image[i]);
        
    }
    if(phase==2)
    {
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,ch_image[h]);
     
    }
	if(phase==3)
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,ch_image[17]);

    if(phase==4)
    {

        iShowImage(x,y+15,playerHeight-150,playerWidth-150,punch[moveright_index]);
       
        
    }
    if(phase==5)
    {
       
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,punch[moveleft_index]);
        
    }
    if(phase==6)
    {
      
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,kick[moveleft_index]);
       
    }

    if(phase==7)
    {

        iShowImage(x,y+15,playerHeight-150,playerWidth-150,kick[moveright_index]);
       
    }
    if(phase==8)
    {
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,gun[moveright_index]);
        
    }
    if(phase==9)
    {
       
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,gun[moveleft_index]);
        
    }
    if(phase==10)
    {
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,jump[moveright_index]);
    }
    if(phase==11)
    {
        iShowImage(x,y+15,playerHeight-150,playerWidth-150,jump[moveleft_index]);
        
    }
	if(phase==12)
	{
		iShowImage(x,y+15,playerHeight-100,playerWidth-100,defendRight);
	}
	enemyshowdown5();

	if(enemyDeath)
	{  
		if(clueVar==0)
		{
		clueShow=true;
		clueVar=1;
		}
		if(clueShow)
		{
			iShowImage(enemyx+500,70,40,20,clue1);
			iSetColor(0,0,0);
		iText(enemyx+490,40,"Press F to Collect The Evidence");
		//inGameState=6;
		//initialize=4;
		}
		if(clueFlag==1)
		{
			iShowImage(0,0,600,560,clue3);
			iText(10,10,"Press F to Close");
		}
	}
	}
	if(inGameState==6)
	{
		iShowImage(0,0,1024,768,level2intro);
	}
	if(level==5)
	{
		if(soundVar==2)
		{
		PlaySound("Music\\Music 2.wav", NULL, SND_LOOP | SND_ASYNC);
		soundVar=3;
		}
	   if(initialize==4)
	   {
		   initializeValue();
		   initialize=5;
		   background1x=0,background2x=1024;
	   }
		iShowImage(background1x,0,1024,768,bgimage8);
		iShowImage(background2x,0,1024,768,bgimage8);
		iShowImage(30,700,40,40,heart);
		 onScreen_score_and_name();
		iShowImage(75,702,120,40,playerhealth[playerhealth_index]);
    
	   if(phase==0)
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[8]);
    
    if(phase==1)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[i]);
        
    }
    if(phase==2)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[h]);
     
    }
	if(phase==3)
        iShowImage(x,y-50,playerHeight,playerWidth,ch_image[17]);

    if(phase==4)
    {

        iShowImage(x,y-50,playerHeight,playerWidth,punch[moveright_index]);
       
        
    }
    if(phase==5)
    {
       
        iShowImage(x,y-50,playerHeight,playerWidth,punch[moveleft_index]);
        
    }
    if(phase==6)
    {
      
        iShowImage(x,y-50,playerHeight,playerWidth,kick[moveleft_index]);
       
    }

    if(phase==7)
    {

        iShowImage(x,y-50,playerHeight,playerWidth,kick[moveright_index]);
       
    }
    if(phase==8)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,gun[moveright_index]);
        
    }
    if(phase==9)
    {
       
        iShowImage(x,y-50,playerHeight,playerWidth,gun[moveleft_index]);
        
    }
    if(phase==10)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,jump[moveright_index]);
    }
    if(phase==11)
    {
        iShowImage(x,y-50,playerHeight,playerWidth,jump[moveleft_index]);
        
    }
	if(phase==12)
	{
		iShowImage(x,y-50,playerHeight+50,playerWidth+20,defendRight);
	}
	enemyshowdown4();
	showBarrel();
	if(initialize==6)
	{   
		initializeValueExcept();
		initialize=7;
	}
	if(initialize==7)
	{
		enemyshowdown4();
		if(enemyDeath)
		initialize=8;
	}
	if(initialize==8)
	{   
		initializeValueExcept();
		collisionBarrel=0,collisiondistract=0;
		barrelx=1024;
		initialize=9;
		initializeStop=1;
	}
	if(initialize==9)
	{
	showBarrel();
	enemyshowdown6();
	if(trunkAppeare)
	{
	iShowImage(trunkX,10,100,100,trunk);
	if(x>=trunkX-100&&x<=trunkX)
		iText(trunkX,7,"Press F To Open The Trunk");
	}
	if(passwordAppeare)
	{   iSetColor(76,188,76);
		iShowImage(200,100,800,600,password);
		iText(480,600,"TO OPEN THE VAULT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(520,400,passKey,GLUT_BITMAP_TIMES_ROMAN_24);
		if(strcmp(passKey,"********")==0)
		{
		   iText(520,300,"Vault Unlocked",GLUT_BITMAP_TIMES_ROMAN_24);
		   iDelayMS(2000);
			passwordAppeare=false;
			trunkAppeare=false;
			stoneAppeare=true;
			iSetColor(255,255,255);
		}
		
	}
	if(stoneAppeare)
		{
		iShowImage(trunkX+70,10,100,100,verdant);
		iText(trunkX,7,"Collect The Found Item");
		background1x=0;
		background2x=1024;
		}
	}
	
	/*if(initialize==6)
	{
		initializeValue();
       barrelx=1024,barrelVar=0;
		initialize=7;
	}
	if(initialize==7)
	{
	enemyshowdown4();
	initialize=8;
	}*/
	}
	if(level==6)
	{
		iShowImage(0,0,1024,768,gamecomplete);
	}
	if(level==7)
	{
		iShowImage(0,0,180,200,dead[deadIndex]);
		deadIndex++;
		iDelayMS(70);
		if(deadIndex>4)
			deadIndex=4;
	}
	if(inventoryMode)
	{
		if(!bookMode)
		{
        if(inventoryPhase==1)
		iShowImage(20,20,950,700,inventory[1]);
		if(inventoryPhase==2)
		iShowImage(20,20,950,700,inventory[3]);
		if(inventoryPhase==3)
		iShowImage(20,20,950,700,inventory[4]);
		}
		if(bookMode)
		{
			if(bookChapter==4)
		   iShowImage(20,20,950,700,book1);
		   if(bookChapter==5)
		   iShowImage(20,20,950,700,book2);

		   iShowImage(15,15,80,80,pageBack);
		   iShowImage(850,15,80,80,pageNext);
		   iShowImage(435,5,120,120,close);
		}
		if(clueMode)
		{
			iShowImage(0,0,600,560,clue2);
			iShowImage(435,5,120,120,close);
		}
	}
	if(ehealth_index>6)
		ehealth_index=6;
	if(playerhealth_index>5)
	{
		level=7;
	}
	
}
/////////////////////////SHOWING SETTINGS////////////////////////
int settingVar=1;
bool controlKeyBoard=false;
void showsettings()
{   
	if(settingVar==1)
    iShowImage(0,0,1024,768,settingpic1);
	if(settingVar==2)
    iShowImage(0,0,1024,768,settingpic2);
	if(settingVar==3)
    iShowImage(0,0,1024,768,settingpic3);

    //iShowImage(840,565,80,80,musicbutton);
	if(controlKeyBoard)
	{
    iShowImage(0,0,1024,768,keyboard);
	 iShowImage(435,5,120,120,close);
	showKey();
	}
}

////////////////////// SHOW SCORE//////////////

void showscore()
{
    iShowImage(0,0,1024,768,scorepic);
	loadFromFile();
	saveScore();
    highScore();
}

/////////////// SHOW ABOUT /////////////////
int ai=0;
void showabout()
{
    iShowImage(0,0,1024,786,aimage[ai]);
	iShowImage(0,0,1024,786,about);
    iDelayMS(250);
    ai++;
    if(ai>42)
        ai=0;


}


void soundEffect()
{	
	if(!(level==5))
	{
	if(!(enemyPhase==2||enemyPhase==3))
	if(phase==4||phase==5||phase==6||phase==7)
	{
		
		PlaySound("Music\\swosh.wav",NULL,SND_ASYNC);
	
	}
	if(phase==8||phase==9)
	{
		PlaySound("Music\\gun.wav",NULL,SND_ASYNC);
	}
	}
}

void playermove()
{  
	
/*	if(phase==4||phase==5||phase==6||phase==7)
	{
		
		//PlaySound("Music\\swosh.wav",NULL,SND_ASYNC);
	
	}
	if(phase==8||phase==9)
	{
		PlaySound("Music\\gun.wav",NULL,SND_ASYNC);
	}*/
   if(level!=4&&level!=5)
   {
	if(phase==1)
	{
	x=x+12;
        i++;
        if(i>8)
            i=0;
        phase=0;
	}

	  if(phase==2)
    {
        x=x-12;
        h++;
        if(h>17)
            h=9;
        phase=3;
    }
	   if(phase==4)
    {
       moveright_index++;
        if(moveright_index>6)
        {
            phase=0;
           moveright_index=4;
        }
	   }
	       if(phase==5)
    {
       moveleft_index++;
        if(moveleft_index>3)
        {
            phase=3;
            moveleft_index=1;
        }
    }
    if(phase==6)
    {
        moveleft_index++;
        if(moveleft_index>3)
        {
            phase=0;
            moveleft_index=1;
        }
    }

    if(phase==7)
    {
       moveright_index++;
        if(moveright_index>6)
        {
            phase=3;
            moveright_index=4;
	}
	}
	 if(phase==8)
    {
       moveright_index++;
        if(moveright_index>6)
        {
            phase=0;
           moveright_index=4;
        }
    }
    if(phase==9)
    {
        moveleft_index++;
        if(moveleft_index>3)
        {
            phase=3;
            moveleft_index=1;
        }
    }
    if(phase==10)
    {
        if(s==0)
        {
            moveright_index++;
            y+=10;
        }
        if(moveright_index>6)
        {
            s=1;
        }
        if(s==1)
        {
            moveright_index--;
            y-=10;
        }
        if(s==1&&moveright_index==4)
        {
            phase=0;
            moveright_index=4;
            s=0;
        }
    }
    if(phase==11)
    {
		if(s==0)
		{
			moveleft_index++;
			y+=10;
		}
		if(moveleft_index>3)
		{   
			s=1;
		}
		if(s==1)
		{
			moveleft_index--;
			y-=10;
		}
		if(s==1&&moveleft_index==1)
		{
			phase=3;
			moveleft_index=1;
			s=0;
		}
	}
	}
    if(level==4||level==5)
	{
		if(phase==1)
	{
		if(level==4)
		{
	background1x=background1x-8;
	background2x=background2x-8;
		}
		
		if(level==5)
		{
	background1x=background1x-16;
	background2x=background2x-16;
	if(trunkAppeare)
	trunkX-=16;
	if(enemyx<x-400)
	barrelx-=16;
		}
        i++;
        if(i>8)
            i=0;
        phase=0;
	if(enemyPhase==6)
		enemyx-=16;
	}

	  if(phase==2)
    {
	   if(level==4)
	   {
       background1x=background1x+8;
	   background2x=background2x+8;
	   }
		
		if(level==5)
	   {
       background1x=background1x+16;
	   background2x=background2x+16;
	   barrelx+=16;
	   if(trunkAppeare)
	   trunkX+=16;
	   }
        h++;
        if(h>17)
            h=9;
        phase=3;
    }
	   if(phase==4)
    {
       moveright_index++;
        if(moveright_index>6)
        {
            phase=0;
           moveright_index=4;
        }
	   }
	       if(phase==5)
    {
       moveleft_index++;
        if(moveleft_index>3)
        {
            phase=3;
            moveleft_index=1;
        }
    }
    if(phase==6)
    {
        moveleft_index++;
        if(moveleft_index>3)
        {
            phase=0;
            moveleft_index=1;
        }
    }

    if(phase==7)
    {
       moveright_index++;
        if(moveright_index>6)
        {
            phase=3;
            moveright_index=4;
	}
	}
	 if(phase==8)
    {
       moveright_index++;
        if(moveright_index>6)
        {
            phase=0;
           moveright_index=4;
        }
    }
    if(phase==9)
    {
        moveleft_index++;
        if(moveleft_index>3)
        {
            phase=3;
            moveleft_index=1;
        }
    }
    if(phase==10)
    {
        if(s==0)
        {
            moveright_index++;
            y+=10;
        }
        if(moveright_index>6)
        {
            s=1;
        }
        if(s==1)
        {
            moveright_index--;
            y-=10;
        }
        if(s==1&&moveright_index==4)
        {
            phase=0;
            moveright_index=4;
            s=0;
        }
    }
    if(phase==11)
    {
		if(s==0)
		{
			moveleft_index++;
			y+=10;
		}
		if(moveleft_index>3)
		{   
			s=1;
		}
		if(s==1)
		{
			moveleft_index--;
			y-=10;
		}
		if(s==1&&moveleft_index==1)
		{
			phase=3;
			moveleft_index=1;
			s=0;
		}
	}
	if(background2x==0)
		{
			background1x=0;
			background2x=1024;
		}
	if(background1x>0)
	{
		if(barrelVar2==0)
		{
		lastBarrelx2=barrelx;
		barrelVar2=1;
		}
		background1x=0;
		background2x=1024;
		//barrelx=800;
		barrelx=lastBarrelx2;
		
	}
	
	}
}

int scoreFlag=0;

void enemyshowdown()
{
	if(!enemyDeath)
	{
	if(enemyx>=x+30)
		enemyPhase=0;
    printf("%d",enemyPhase);
	if(enemyPhase==0)
    {
        iShowImage(enemyx,70,320,260,e_image[enemyIndex]);

    }
	if(enemyPhase==1)
	{
        iShowImage(enemyx,70,320,260,e_image[1]);
		positionmode=rand()%3+1;
	}
	if(enemyPhase==2)
	{
		 iShowImage(enemyx+70,90,240,200,e_punch[enemymoveleft_index]);
	}
	if(enemyPhase==3)
	{
        iShowImage(enemyx+70,90,240,200,e_kick[enemymoveleft_index]);
	}
	if(enemyPhase==6)
	{
		iShowImage(enemyx,70,190,75,e_death[enemymoveleft_index]);
		enemyDeath=true;
	}
    if(enemyx<=x+30)
    {  
		if(captionOn)
		{
			enemyPhase=1;
			if(caption_index==2)
			captionX=enemyx-180;
			else
			captionX=enemyx+90;
			iDelayMS(200);
			iShowImage(captionX,280,290,285,caption[caption_index]);
			iDelayMS(1000);
			caption_index++;
			if(caption_index>4)
			captionOn=false;
		}
		else
		
		{
		enemyPhase=positionmode;
        if(phase==4||phase==5||phase==6||phase==7||phase==8)
            if(enemyx<=x+2)
            {
                enemyx+=6;
				ehealth_index++;
				if(ehealth_index>6)
					enemyPhase=6;
				if(!(level==5))
				PlaySound("Music\\punch.wav",NULL,SND_ASYNC);
					
            }
			if(!defending)
			{
			if(enemyPhase==2||enemyPhase==3)
            if(enemyx<=x+2)
            {
				playerhealth_index++;
				if(playerhealth_index>5)
				{playerhealth_index=1;
				//level=7;
					//phase=13;
					;}
            }
			}
		}
	}
	}
	if(enemyDeath)
	{ 
		enemyPhase=6;
		if(enemyPhase==6)
	{
		iShowImage(enemyx,70,190,75,e_death[enemymoveleft_index]);
		dumpX[dumpIndex]=enemyx;
		if(dumpIndex<1)
			dumpIndex++;
		if(scoreFlag==0)
		{
			eCount++;
			scoreFlag=1;
		}
	}
		
		enemyCount++;
	}
	iShowImage(enemyx+155,320,100,15,e_health[ehealth_index]);
	
	
	
}

void enemymove()
{
   if(level==1)
   {
	if(enemyPhase==0)
	 {
        enemyx=enemyx-10;
        enemyIndex++;
        if(enemyIndex>8)
            enemyIndex=1;
	 } 
	 if(enemyPhase==2)
	 {
		  enemymoveleft_index++;
        if(enemymoveleft_index>7)
        {
            enemymoveleft_index=1;
			positionmode=rand()%3+1;
        }

	 }
    if(enemyPhase==3)
	{
		 enemymoveleft_index++;
        if(enemymoveleft_index>7)
        {
           positionmode=rand()%3+1;
			printf("%d",enemyPhase);
            enemymoveleft_index=1;
        }
	
	}

	if(enemyPhase==4)
	{
		//kick right

	}
	if(enemyPhase==5)
	{
		//move right

	}
	if(enemyPhase==5)
	{
		// punch right

	}
	if(enemyPhase==6)
	{
		enemymoveleft_index++;
        if(enemymoveleft_index>4)
        { 
            enemymoveleft_index=4;
			enemyDeath=true;
        }
	}
   }
  if(level==2)
  {
  if(enemyPhase==0)
	 {
        enemyx=enemyx-10;
        enemyIndex++;
        if(enemyIndex>9)
            enemyIndex=1;
	 } 
	 if(enemyPhase==2)
	 {
		  enemymoveleft_index++;
        if(enemymoveleft_index>3)
        {
            enemymoveleft_index=1;
			positionmode=rand()%3+1;
        }

	 }
    if(enemyPhase==3)
	{
		 enemymoveleft_index++;
        if(enemymoveleft_index>3)
        {
           positionmode=rand()%3+1;
			printf("%d",enemyPhase);
            enemymoveleft_index=1;
        }
	
	}

	if(enemyPhase==4)
	{
		//kick right

	}
	if(enemyPhase==5)
	{
		//move right

	}
	if(enemyPhase==5)
	{
		// punch right

	}
	if(enemyPhase==6)
	{
		enemymoveleft_index++;
        if(enemymoveleft_index>4)
        {
            enemymoveleft_index=4;
			enemyDeath=true;
        }
	}
	enemy3index++;
	enemy3x+=20;
	if(enemy3index>5)
		enemy3index=1;
	if(enemyDeath)
	{
     iShowImage(830,50,110,90,clue1);
	 iText(760,40,"Press F to Collect The Evidence");
	}
  }
   if(level==4)
   {
	if(enemyPhase==0)
	 {
        enemyx=enemyx-10;
        enemyIndex++;
        if(enemyIndex>8)
            enemyIndex=1;
	 } 
	 if(enemyPhase==2)
	 {
		  enemymoveleft_index++;
        if(enemymoveleft_index>7)
        {
            enemymoveleft_index=1;
			positionmode=rand()%3+1;
        }

	 }
    if(enemyPhase==3)
	{
		 enemymoveleft_index++;
        if(enemymoveleft_index>7)
        {
           positionmode=rand()%3+1;
			printf("%d",enemyPhase);
            enemymoveleft_index=1;
        }
	
	}

	if(enemyPhase==4)
	{
		//kick right

	}
	if(enemyPhase==5)
	{
		//move right

	}
	if(enemyPhase==5)
	{
		// punch right

	}
	if(enemyPhase==6)
	{
		enemymoveleft_index++;
        if(enemymoveleft_index>4)
        { 
            enemymoveleft_index=4;
			enemyDeath=true;
        }
	}
   }
  if(level==5)
   {
  if(enemyPhase==0)
	 {
        enemyx=enemyx-10;
        enemyIndex++;
        if(enemyIndex>9)
            enemyIndex=1;
	 } 
	 if(enemyPhase==2)
	 {
		  enemymoveleft_index++;
        if(enemymoveleft_index>3)
        {
            enemymoveleft_index=1;
			positionmode=rand()%3+1;
        }

	 }
    if(enemyPhase==3)
	{
		 enemymoveleft_index++;
        if(enemymoveleft_index>3)
        {
           positionmode=rand()%3+1;
			printf("%d",enemyPhase);
            enemymoveleft_index=1;
        }
	
	}

	if(enemyPhase==4)
	{
		//kick right

	}
	if(enemyPhase==5)
	{
		//move right

	}
	if(enemyPhase==5)
	{
		// punch right

	}
	if(enemyPhase==6)
	{
		enemymoveleft_index++;
        if(enemymoveleft_index>4)
        {
            enemymoveleft_index=4;
			enemyDeath=true;
        }
	}
	enemy3index++;
	enemy3x+=20;
	if(enemy3index>5)
		enemy3index=1;
  }
}

void initializeValue()
{
 
 i=0,phase=0,h=9,x=0,moveright_index=4,moveleft_index=1,s=0,y=70,enemyx=700,enemymoveright_index=4,enemymoveleft_index=1;
 playerHeight=180+60,playerWidth=220+60,playerhealth_index=1;
 collisionBarrel=0,collisiondistract=0;
 evidenceCollect=0;
 inventoryMode=0;
 enemyPhase=0,enemyIndex=1,positionmode=3,caption_index=1,captionX=enemyx+30,enemyhealth=0,ehealth_index=1,enemyCount=1;
 dumpX[1],dumpIndex=0;
 enemyDeath=false;
  clueCollect=0;
 clueShow=false;
 clueVar=0;
}
void initializeValueExcept()
{
	enemyx=700,enemymoveright_index=4,enemymoveleft_index=1;
 playerHeight=180+60,playerWidth=220+60,playerhealth_index=1;
 evidenceCollect=0;
 inventoryMode=0;
 enemyPhase=0,enemyIndex=1,positionmode=3,caption_index=1,captionX=enemyx+30,enemyhealth=0,ehealth_index=1,enemyCount=1;
 dumpX[1],dumpIndex=0;
 enemyDeath=false;
  clueCollect=0;
 clueShow=false;
 clueVar=0;

}
void enemyshowdown2()
{
	if(!enemyDeath)
	{
	if(enemyx>=x+30)
		enemyPhase=0;
    printf("%d",enemyPhase);
	if(enemyPhase==0)
    {
        iShowImage(enemyx,70,325,265,e2_image[enemyIndex]);

    }
	if(enemyPhase==1)
	{
        iShowImage(enemyx,70,325,265,e2_image[9]);
		positionmode=rand()%3+1;
	}
	if(enemyPhase==2)
	{
		 iShowImage(enemyx,70,330,260,e2_punch[enemymoveleft_index]);
	}
	if(enemyPhase==3)
	{
        iShowImage(enemyx,70,330,260,e2_kick[enemymoveleft_index]);
	}
	if(enemyPhase==6)
	{
		iShowImage(enemyx,70,330,260,e2_death[enemymoveleft_index]);
		enemyDeath=true;
	}
    if(enemyx<=x+30)
    {  
		if(captionOn)
		{
			enemyPhase=1;
			if(caption_index==2)
			captionX=enemyx-180;
			else
			captionX=enemyx+90;
			iDelayMS(200);
			iShowImage(captionX,300,240,220,caption[caption_index]);
			iDelayMS(1000);
			caption_index++;
			if(caption_index>4)
			captionOn=false;
		}
		else
		
		{
		enemyPhase=positionmode;
        if(phase==4||phase==5||phase==6||phase==7||phase==8)
            if(enemyx<=x+2)
            {
                enemyx+=6;
				ehealth_index++;
				if(ehealth_index>6)
					enemyPhase=6;
				if(!(level==5))
				PlaySound("Music\\punch.wav",NULL,SND_ASYNC);
					
            }
			if(!defending)
			{
			if(enemyPhase==2||enemyPhase==3)
            if(enemyx<=x+2)
            {
				playerhealth_index++;
				if(playerhealth_index>5)
				{playerhealth_index=1;
				 //level=7;
					//phase=13;
					;}
            }
			}
		}
	}
	}
	if(enemyDeath)
	{ 
		enemyPhase=6;
		if(enemyPhase==6)
	{
		iShowImage(enemyx,70,330,260,e2_death[enemymoveleft_index]);
		dumpX[dumpIndex]=enemyx;
		if(dumpIndex<1)
			dumpIndex++;
		if(scoreFlag==1)
		{
			eCount++;
			scoreFlag=2;
		}
	}
		
		enemyCount++;
	}
	iShowImage(enemyx+155,320,100,15,e_health[ehealth_index]);
		
}

void enemyshowdown3()
{
	iShowImage(enemy3x,70,400,265,e3_run[enemy3index]);
}

void enemyshowdown4()
{
if(!enemyDeath)
	{
	if(enemyx>=x-10)
		enemyPhase=0;
    printf("%d",enemyPhase);
	if(enemyPhase==0)
    {
        iShowImage(enemyx,35,325,265,e2_image[enemyIndex]);

    }
	if(enemyPhase==1)
	{
        iShowImage(enemyx,35,325,265,e2_image[9]);
		positionmode=rand()%3+1;
	}
	if(enemyPhase==2)
	{
		 iShowImage(enemyx,35,330,260,e2_punch[enemymoveleft_index]);
	}
	if(enemyPhase==3)
	{
        iShowImage(enemyx,35,330,260,e2_kick[enemymoveleft_index]);
	}
	if(enemyPhase==6)
	{
		iShowImage(enemyx,35,330,260,e2_death[enemymoveleft_index]);
		enemyDeath=true;
	}
    if(enemyx<=x-10)
    {  
		if(captionOn)
		{
			enemyPhase=1;
			if(caption_index==2)
			captionX=enemyx-180;
			else
			captionX=enemyx+90;
			iDelayMS(200);
			iShowImage(captionX,270,260,260,caption[caption_index]);
			iDelayMS(1000);
			caption_index++;
			if(caption_index>4)
			captionOn=false;
		}
		else
		
		{
		enemyPhase=positionmode;
        if(phase==4||phase==5||phase==6||phase==7||phase==8)
            if(enemyx<=x+10)
            {
                enemyx+=6;
				ehealth_index++;
				if(ehealth_index>6)
					enemyPhase=6;
				if(!(level==5))
				PlaySound("Music\\punch.wav",NULL,SND_ASYNC);
					
            }
			if(!defending)
			{
			if(enemyPhase==2||enemyPhase==3)
            if(enemyx<=x-10)
            {
				playerhealth_index++;
				if(playerhealth_index>5)
				{playerhealth_index=1;
					//phase=13;
					;}
            }
			}
		}
	}
	}
	if(enemyDeath)
	{ 
		enemyPhase=6;
		if(enemyPhase==6)
	{
		iShowImage(enemyx,35,330,260,e2_death[enemymoveleft_index]);
		dumpX[dumpIndex]=enemyx;
		if(dumpIndex<1)
			dumpIndex++;
		if(scoreFlag==3)
		{
			eCount++;
			scoreFlag=4;
		}
	}
	enemyCount++;	
		
	}
	iShowImage(enemyx+150,300,100,15,e_health[ehealth_index]);
		
}

void enemyshowdown5()
{
	if(!enemyDeath)
	{
	if(enemyx>=x-10)
		enemyPhase=0;
    printf("%d",enemyPhase);
	if(enemyPhase==0)
    {
        iShowImage(enemyx,70,150,130,e_image[enemyIndex]);

    }
	if(enemyPhase==1)
	{
        iShowImage(enemyx,70,150,150,e_image[1]);
		positionmode=rand()%3+1;
	}
	if(enemyPhase==2)
	{
		 iShowImage(enemyx+30,100,100,80,e_punch[enemymoveleft_index]);
	}
	if(enemyPhase==3)
	{
        iShowImage(enemyx+30,100,100,80,e_kick[enemymoveleft_index]);
	}
	if(enemyPhase==6)
	{
		iShowImage(enemyx,100,80,35,e_death[enemymoveleft_index]);
		enemyDeath=true;
	}
       if(enemyx<=x-10)
    {  
		if(captionOn)
		{
			enemyPhase=1;
			if(caption_index==2)
			captionX=enemyx-180;
			else
			captionX=enemyx+90;
			iDelayMS(200);
			iShowImage(captionX,270,260,260,caption[caption_index]);
			iDelayMS(1000);
			caption_index++;
			if(caption_index>4)
			captionOn=false;
		}
		else
		
		{
		enemyPhase=positionmode;
        if(phase==4||phase==5||phase==6||phase==7||phase==8)
            if(enemyx<=x+2)
            {
                enemyx+=6;
				ehealth_index++;
				if(ehealth_index>6)
					enemyPhase=6;
				if(!(level==5))
					PlaySound("Music\\punch.wav",NULL,SND_ASYNC);
            }
			if(!defending)
			{
			if(enemyPhase==2||enemyPhase==3)
           if(enemyx<=x+10)
            {
				playerhealth_index++;
				if(playerhealth_index>5)
				{playerhealth_index=1;
					//phase=13;
					;}
            }
			}
		}
	}
	}
	if(enemyDeath)
	{ 
		enemyPhase=6;
		if(enemyPhase==6)
	{
		iShowImage(enemyx,100,80,35,e_death[enemymoveleft_index]);
		dumpX[dumpIndex]=enemyx;
		if(dumpIndex<1)
			dumpIndex++;
		if(scoreFlag==2)
		{
			eCount++;
			scoreFlag=3;
		}
	}
		enemyCount++;
		
	}
	iShowImage(enemyx+60,190,50,10,e_health[ehealth_index]);
	
	
	
}


void enemyshowdown6()
{
if(!enemyDeath)
	{
	if(enemyx>=x-10)
		enemyPhase=0;
    printf("%d",enemyPhase);
	if(enemyPhase==0)
    {
        iShowImage(enemyx,35,325,265,e3_image[enemyIndex]);

    }
	if(enemyPhase==1)
	{
        iShowImage(enemyx,35,325,265,e3_image[9]);
		positionmode=rand()%3+1;
	}
	if(enemyPhase==2)
	{
		 iShowImage(enemyx,35,330,260,e3_punch[enemymoveleft_index]);
	}
	if(enemyPhase==3)
	{
        iShowImage(enemyx,35,330,260,e3_kick[enemymoveleft_index]);
	}
	if(enemyPhase==6)
	{
		iShowImage(enemyx,35,330,260,e3_death[enemymoveleft_index]);
		enemyDeath=true;
	}
    if(enemyx<=x-10)
    {  
		if(captionOn)
		{
			enemyPhase=1;
			if(caption_index==2)
			captionX=enemyx-180;
			else
			captionX=enemyx+90;
			iDelayMS(200);
			iShowImage(captionX,270,260,260,caption[caption_index]);
			iDelayMS(1000);
			caption_index++;
			if(caption_index>4)
			captionOn=false;
		}
		else
		
		{
		enemyPhase=positionmode;
        if(phase==4||phase==5||phase==6||phase==7||phase==8)
            if(enemyx<=x+10)
            {
                enemyx+=6;
				ehealth_index++;
				if(ehealth_index>6)
					enemyPhase=6;
				 if(!(level==5))
					PlaySound("Music\\punch.wav",NULL,SND_ASYNC);
            }
			if(!defending)
			{
			if(enemyPhase==2||enemyPhase==3)
            if(enemyx<=x-10)
            {
				playerhealth_index++;
				if(playerhealth_index>5)
				{playerhealth_index=1;
					//phase=13;
					;}
            }
			}
		}
	}
	}
	if(enemyDeath)
	{ 
		enemyPhase=6;
		if(enemyPhase==6)
	{
		iShowImage(enemyx,35,330,260,e3_death[enemymoveleft_index]);
		dumpX[dumpIndex]=enemyx;
		if(dumpIndex<1)
			dumpIndex++;
		if(scoreFlag==4)
		{
			eCount++;
			scoreFlag=5;
		}
	}
		if(trunkVar==0)
		{
		trunkAppeare=true;
		trunkVar=1;
		}
		enemyCount++;
	}
	iShowImage(enemyx+150,300,100,15,e_health[ehealth_index]);
		
}


void showBarrel()
{

	if(enemyx<x-400)
	{
	 if(collisionBarrel==0)
	 {
	 iShowImage(barrelx,10,200,220,barrel2);
	 }
	 if(collisionBarrel==1)
	 {
      iShowImage(barrelx-50,-50,340,320,barrel2_1);
	 }
	 if(collisionBarrel==2)
	 {
      iShowImage(barrelx,20,210,90,barrel2_2);
	  collisionBarrel++;
	  if(initializeStop==0)
	  {
	  if(initialize!=7||initialize!=9||initialize!=8)
	  initialize=6;
	  }
	 }
	}
	if(collisionBarrel==0)
	{
	if(x>=barrelx-64)
	{
		if(barrelVar==0)
		{
	   lastBg1x=background1x;
	   lastBg2x=background2x;
	   lastBarrelx=barrelx;
	   barrelVar=1;
		}
		background1x=lastBg1x;
		background2x=lastBg2x;
		barrelx=lastBarrelx;
	}
	}
	if(x>=barrelx-64)
	{  
		if(collisiondistract==1)
		{
		if(phase==4||phase==6)
		{ 
			collisionBarrel++;
			collisiondistract=0;
		}
		}
	}

}

void storePassword(char key)
{
	passKey[keyIndex]=key;
	keyIndex++;
}
#endif
