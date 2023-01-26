#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED


void takePlayerName();
void showPlayerName();
void highScore();
void saveInFile();
void loadFromFile();


void getKey();
void showKey();
int b_w;  
void onScreen_score_and_name();
void saveScore();
int gamestat=0;
char name[100];               //used to store player name
int nameL;                    //used to store name character in each array cell
char keys[2];
char ch[2];

int score = 0 ;  
char score_string[20];


struct saveScoreFile         
{
	char playerName[100];
	int playerScore;
}ssf[11];

FILE *accessSaveFile;
char tempName[100];
int tempScore;


struct gameSaveFile                   
{
	char playerName[100];
	int score;
	

}slot[1];

FILE *s1;

char holdHighScore[100];		   //this variable is used to hold highscore while converting it to char from int value with itoa() function

int move_save = 0;                

/////////// Name input //////////
bool name_input = true;


void takePlayerName(char key)
{
	if(gamestat==2 && name_input)                           
	{                                        
		  
		if(key == '\r')
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			name_input=false;

		}

		else if(key == '\b')
		{
			
			if(nameL>0)
			{
				PlaySound("music//backspace", NULL, SND_ASYNC);
				nameL--;
				name[nameL] = '\0';               
			}
			if(nameL == 0)
				PlaySound("music//error", NULL, SND_ASYNC);
		}

		else 
		{
			PlaySound("music//button", NULL, SND_ASYNC);
			name[nameL] = key;           
			nameL++;
		}

	}
}

void showPlayerName()
{
	iClear();
	iShowImage(0,0,1024,768,nameinput);
	iSetColor(255,255,255);

	iRectangle(500,560,450,70);
	//iSetColor(0,0,0);
	iText(515,595, name ,GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,255);
}


//keyboard manual input
int punchKey,kickKey,fireKey,defendKey,jumpKey,keyVar=0;
void getKey(char key)
{
	if(key!='\r')
	{
	switch(keyVar)
   {
   case 1:
	punchKey=key;
	break;
   case 2:
   kickKey=key;
   break;
   case 3:
   jumpKey=key;
   break;
   case 4:
   fireKey=key;
   break;
   case 5:
   defendKey=key;
   break;
   }
    }
	keys[0]=key;  
	if(key == '\r')
	{
   
       keyVar++;
	
	}
	
}

void showKey()
{   
	iSetColor(0,0,0);
	/*iSetColor(b_w,b_w,b_w);
	 b_w++;
	if(b_w>180)
	 b_w=0;*/
	switch(keyVar)
   {
   case 0:
	   {
	  iText(300,600,"PRESS ENTER TO CHANGE THE KEYS",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,550,"DEFAULT KEYS ARE",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,500,"MOVE LEFT",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(500,500,"LEFT BUTTON",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,450,"MOVE RIGHT",GLUT_BITMAP_TIMES_ROMAN_24);
 	  iText(500,450,"RIGHT BUTTON",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,400,"PUNCH",GLUT_BITMAP_TIMES_ROMAN_24);
      iText(500,400,"Z",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,350,"KICK",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(500,350,"Q",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,300,"JUMP",GLUT_BITMAP_TIMES_ROMAN_24);
      iText(500,300,"H",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,250,"FIRE",GLUT_BITMAP_TIMES_ROMAN_24);
      iText(500,250,"X",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,200,"DEFEND",GLUT_BITMAP_TIMES_ROMAN_24);
      iText(500,200,"D",GLUT_BITMAP_TIMES_ROMAN_24);

	   }
	  break;
   case 1:
	   {
     iText(300,500,"PUNCH",GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(600,500,keys,GLUT_BITMAP_TIMES_ROMAN_24);
	 break;
	   }
   case 2:
	   {
	iText(300,500,"KICK",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600,500,keys,GLUT_BITMAP_TIMES_ROMAN_24);
     break;
	   }
   case 3:
    {
	iText(300,500,"JUMP",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600,500,keys,GLUT_BITMAP_TIMES_ROMAN_24);
     break;
    }
   case 4:
 {
    iText(300,500,"FIRE",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600,500,keys,GLUT_BITMAP_TIMES_ROMAN_24);
     break;
	   }
   case 5:
 {
	iText(300,500,"DEFEND",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600,500,keys,GLUT_BITMAP_TIMES_ROMAN_24);
     break;
	   }
   default:
	   {
		   printf("%d %d %d %d",kickKey,punchKey,jumpKey,defendKey);
	  iText(300,600,"YOU HAVE CHOOSEN",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,550,"THE KEYS ARE",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,500,"MOVE LEFT",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(500,500,"LEFT BUTTON",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,450,"MOVE RIGHT",GLUT_BITMAP_TIMES_ROMAN_24);
 	  iText(500,450,"RIGHT BUTTON",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,400,"PUNCH",GLUT_BITMAP_TIMES_ROMAN_24);
	  ch[0]=punchKey;
      iText(500,400,ch,GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,350,"KICK",GLUT_BITMAP_TIMES_ROMAN_24);
	   ch[0]=kickKey;
	   printf("%d %c",kickKey,ch[0]);
	  iText(500,350,ch,GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,300,"JUMP",GLUT_BITMAP_TIMES_ROMAN_24);
	   ch[0]=jumpKey;
	   printf("%d %c",jumpKey,ch[0]);
      iText(500,300,ch,GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,250,"FIRE",GLUT_BITMAP_TIMES_ROMAN_24);
	   ch[0]=fireKey;
	    printf("%c",ch[0]);
      iText(500,250,ch,GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(300,200,"DEFEND",GLUT_BITMAP_TIMES_ROMAN_24);
	   ch[0]=defendKey;
      iText(500,200,ch,GLUT_BITMAP_TIMES_ROMAN_24);

	   }
  
   }
	
}
void onScreen_score_and_name()
{
	iSetColor(255 , 0 , 0);
	iText(900, 740, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);

	itoa(score , score_string , 10);
	iText(970, 740, score_string, GLUT_BITMAP_TIMES_ROMAN_24);

	//iText(400 , 560 , "Name:", GLUT_BITMAP_TIMES_ROMAN_24);

	//iText(400 , 530 , name , GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,255);

}



void saveScore()
{
	accessSaveFile = fopen("High Score.txt","r");

	for(int i = 0 ; i < 10 ; i ++)
	{
		fscanf(accessSaveFile , "%s %d" , &ssf[i].playerName  , &ssf[i].playerScore);
	}

	fclose(accessSaveFile);

	for (int i = 0 ; i<10 ; i++)
		for(int j = 10 ; j>i ; j--)
		{
			if( ssf[j].playerScore > ssf[j-1].playerScore )
			{
				tempScore = ssf[j-1].playerScore;
				ssf[j-1].playerScore = ssf[j].playerScore;
				ssf[j].playerScore = tempScore;

				strcpy( tempName , ssf[j-1].playerName);
				strcpy( ssf[j-1].playerName , ssf[j].playerName);
				strcpy( ssf[j].playerName , tempName);
			}
		}
		

	accessSaveFile = fopen("High Score.txt", "w");

	for(int i = 0; i<10 ; i++)
	{
		fprintf(accessSaveFile , "%s\t%d\r\n" , ssf[i].playerName  , ssf[i].playerScore);
	}

	fclose(accessSaveFile);


}

void highScore()
{

	iSetColor(251,160,38);

	iText(435,520, "Name ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(650,520, "Score ",GLUT_BITMAP_TIMES_ROMAN_24);

	accessSaveFile = fopen("High Score.txt","r");

	for(int i = 0 ; i < 10 ; i ++)
	{
		fscanf(accessSaveFile , "%s %d" , &ssf[i].playerName  , &ssf[i].playerScore);
	}


	fclose(accessSaveFile);

	iSetColor(225,220,30);

	iText( 440 , 450  , "1. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 410  , "2. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 370  , "3. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 330  , "4. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 290  , "5. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 250  , "6. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 210  , "7. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 170  , "8. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 130  , "9. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 430 , 90  , "10. " , GLUT_BITMAP_TIMES_ROMAN_24 );

	iSetColor(53,204,236);

	for(int i = 0 ; i < 10 ; i++)
	{
		
		

		iText( 470 , 450 - i *40 , ssf[i].playerName , GLUT_BITMAP_TIMES_ROMAN_24 );

		itoa(ssf[i].playerScore , holdHighScore , 10);
		iText( 650 , 450 - i *40 , holdHighScore , GLUT_BITMAP_TIMES_ROMAN_24 );

	}
	
}


void saveInFile()
{
	strcpy(slot[0].playerName , name);
	slot[0].score = score ; 


	

		s1 = fopen("slot 1.txt", "w");

		fprintf(s1 , "%s\t%d" , slot[0].playerName , slot[0].score );
		
	
		fclose(s1);

	

	
}


void loadFromFile()
{

	
		s1 = fopen("slot 1.txt", "r");
		for(int i=0;i<10;i++)
		{
		fscanf(s1 , "%s %d" , &slot[0].playerName  , &slot[0].score );
		strcpy(ssf[i].playerName , slot[0].playerName);
		ssf[i].playerScore = slot[0].score;
	
		}
		fclose(s1);
	
}



#endif // SCORE_H_INCLUDED
