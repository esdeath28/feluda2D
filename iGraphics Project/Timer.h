/* This header file contains all iSetTimer function used in game,
in different phase for loading multiple images or codes */



#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

void timer1();
void timer2();
void timer3();
void timer4();
int a=0;
int nm=0;
int timer[5];



//////////Timer For Menu///////////
/*
parameter: no
return type : void
functionalities: this function will render menu background image after 200msec.
                 this is called in iMain.cpp at iDraw function in main menu. 
*/

void timer1()
{
if(gamestat==1&&a==0) 
{
timer[1]=iSetTimer(200,changemenu);
a++;
}
}

/*
//////////////Timer For Character/////////

parameter: no
return type : void
functionalities: this function will render character movement.
enemy movement, called in function.h playermove() function



void timer2()
{   
	if(gamestat=2&&nm==0)
	{
	iSetTimer(200,changeplayer);
	nm++;
	}
}*/



void timer2()
{   
	if(nm==0)
	{
	iSetTimer(100,playermove);
	iSetTimer(100,enemymove);
	iSetTimer(50,change);
	iSetTimer(200,soundEffect);
	nm++;
	}
}

#endif