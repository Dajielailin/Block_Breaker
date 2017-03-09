#include <stdio.h>
#include "conio2.h"
#include "headers.h"
#include<assert.h>
#include<time.h>
#include<stdlib.h>

time_t time1;
int detaTime;
/*¶ÔÐ¡Çò½á¹¹½øÐÐ³õÊ¼»¯*/
Ball example={{18,11},{0,0},0};//¸ÃÐ¡ÇòµÄ³õÊ¼Î»ÖÃÎª(0,0),xºÍy·½Ïò³õÊ¼ËÙ¶ÈÎª£¨0,0£©£¬ËüµÄÐÎ×´ÊÇ×Ö·û¡®0¡¯
Ball *aBll=&example ;          //¶¨ÒåÒ»¸öÖ¸ÕëÊ±£¬Ò»¶¨Òª¸øËü³õÊ¼»¯

/*¶Ô×©¿é½á¹¹½øÐÐ³õÊ¼»¯*/
//µÚÒ»Àà×©¿é,±ê×¼×©
Brick abrick1={{0,1},{10,7},image1};//×©¿éµÄµÈ¼¶Îª01£¬Î»ÖÃÔÚ£¨5,5£©´¦£¬ºóÃæÊý×é´æ´¢µÄÊÇÍ¼ÏñÄÚÈÝ
Brick *aBrick1= &abrick1;
//µÚ¶þÀà×©¿é£¬ÓÀ²»ÏûÊ§×©
Brick abrick2={{0,2},{10,7},image2};//×©¿éµÄµÈ¼¶Îª02£¬Î»ÖÃÔÚ£¨5,5£©´¦£¬ºóÃæÊý×é´æ´¢µÄÊÇÍ¼ÏñÄÚÈÝ
Brick *aBrick2= &abrick2;
//µÚÈýÀà×©¿é£¬ÔöÇ¿×©
Brick abrick3={{0,3},{10,7},image3};//×©¿éµÄµÈ¼¶Îª03£¬Î»ÖÃÔÚ£¨5,5£©´¦£¬ºóÃæÊý×é´æ´¢µÄÊÇÍ¼ÏñÄÚÈÝ
Brick *aBrick3= &abrick3;
int brick3=0;   //ÓÃÀ´¼ÆÊýÐ¡Çò×²µ½µÚÈýÖÖ×©µÄ´ÎÊý
//µÚËÄÀà×©¿é£¬»ÙÃð×©
Brick abrick4={{0,4},{10,10},image4};//×©¿éµÄµÈ¼¶Îª04£¬Î»ÖÃÔÚ£¨5,5£©´¦£¬ºóÃæÊý×é´æ´¢µÄÊÇÍ¼ÏñÄÚ
Brick *aBrick4= &abrick4;

//µÚÎåÀà×©¿é£¬×¨ÃÅÓÃÀ´Çå³ýÒ»¸ö×©¿éµÄÍ¼Ïñ
Brick abrick5={{0,0},{10,10},image5};//×©¿éµÄµÈ¼¶Îª04£¬Î»ÖÃÔÚ£¨5,5£©´¦£¬ºóÃæÊý×é´æ´¢µÄÊÇÍ¼ÏñÄÚÈÝ
Brick *aBrick5= &abrick5;

/*¶¨Òå×óÒÆÖ¸ÁîÎªÊý×Ö¼ü-9
       ÓÒÒÆÖ¸ÁîÎªÊý×Ö¼ü-0
       ÍË³öÓÎÏ·Ö¸Áî-ESC¼ü
*/
int keyboard(void)
{
    int ch=0;       //Ã¿´Îµ÷ÓÃkeyboard()º¯ÊýÊ±¶Ôch³õÊ¼»¯£¬ÈôÃ»ÓÐ³õÊ¼»¯Ð§¹ûÔòÊÇÐ¡ÇòÁ¬Ðø×óÒÆ»òÓÒÒÆ
    if(kbhit())     //¼ì²âµ±Ç°ÊÇ·ñÓÐ¼üÅÌÊäÈë£¬ÈôÓÐÔò·µ»ØÒ»¸ö·Ç0Öµ£¬·ñÔò·µ»Ø0
        ch=getch(); //»ñµÃËù°´ÏÂ¼üÅÌ¶ÔÓ¦µÄASCÂëÖµ
    return ch;
}

//¶¨ÒåÁ½¸öº¯Êý·Ö±ðÀ´¿ØÖÆÐ¡ÇòµÄºá×Ý×ø±ê
void moveBallx(Ball *aBall)//xÖá·½ÏòÁ½¸ö±ß½ç·Ö±ðÎªx=0,x=80
{

    int vel=aBll->b.xvel;
    if(vel==-1) //"9"¼ü±»°´ÏÂ
    {
        if(aBll->a.xcor==0)    //Èç¹ûÐ¡Çò´ïµ½yÖá(x=0)¾Í·´µ¯»ØÈ¥£ºËÙ¶È·´Ïò£¬Î»ÖÃÏòÓÒ¼ÓÒ»
        {
            aBll->a.xcor++;
            aBll->b.xvel=1;
        }
        else
            aBll->a.xcor-- ;

    }
    if(vel==1)  //¡°0¡±¼ü±»°´ÏÂ
    {
        if(aBll->a.xcor==80)    //Èç¹ûÐ¡Çò´ïµ½yÖá(x=0)¾Í·´µ¯»ØÈ¥£ºËÙ¶È·´Ïò£¬Î»ÖÃÏòÓÒ¼ÓÒ»
        {
            aBll->a.xcor--;
            aBll->b.xvel=-1;
        }
        else
            aBll->a.xcor++;
    }
}


void moveBally(Ball *aBall)
{
      int vel=aBll->b.yvel;
     if(aBll->a.ycor >=0 && aBll->a.ycor<=40)    //Èç¹ûÐ¡Çò´ïµ½xÖá(y=0,y=40),Ð¡ÇòÍ£Ö¹ÔË¶¯
        {
            //aBll->a.ycor++;
            if(vel==0) //"9"¼ü±»°´ÏÂ
            {
                aBll->a.ycor--;
            }
            if(vel==1)
            {
                aBll->a.ycor++;
            }
        }

}

void eraseBallx(Ball *aBall)
{
   // gotoxy(aBll->a.xcor,aBll->a.ycor);
    printf("\b \b");    //Ã¿´ÎÒÆ¶¯Ð¡ÇòÇ°ÏÈ°ÑÉÏÒ»¸öÎ»ÖÃµÄ¡®0¡¯É¾µô
}

void displayBallx(Ball *aBall)
{

    gotoxy(aBll->a.xcor,aBll->a.ycor);
    printf("0");
}

/*ÏÔÊ¾×©¿éÍ¼Ïñº¯Êý*/
void displayBrick(Brick *aBrick)
{
    int i,j;
    for(i=0;i<BRIQUE_HEIGHT;i++)
    {
        gotoxy(aBrick->p.xcor,aBrick->p.ycor++);
        for(j=0;j<BRIQUE_WIDTH;j++)
            putchar(aBrick->image[i* BRIQUE_WIDTH+ j]);

    }

}
//ÓÎÏ·½çÃæ³õÊ¼»¯£¬·Å×©¿é
void init()
{
    int i;
    //·ÅµÚÒ»Àà×©¿é
    for(i=0;i<6;i++)
    {
        displayBrick(aBrick1);
        aBrick1->p.xcor += 9;
        aBrick1->p.ycor -= 3;
    }
    i=0;
    aBrick1->p.xcor = 10;
    aBrick1->p.ycor = 31;
    for(i=0;i<6;i++)
    {
        displayBrick(aBrick1);
        aBrick1->p.xcor += 9;
        aBrick1->p.ycor -= 3;
    }
    aBrick1->p.xcor = 28;
    aBrick1->p.ycor = 1;
    displayBrick(aBrick1);
    aBrick1->p.xcor = 37;
    aBrick1->p.ycor = 1;
    displayBrick(aBrick1);
    aBrick1->p.xcor = 28;
    aBrick1->p.ycor = 37;
    displayBrick(aBrick1);
    aBrick1->p.xcor = 37;
    aBrick1->p.ycor = 37;
    displayBrick(aBrick1);
    //·ÅµÚ¶þÀà×©¿é
    aBrick2->p.xcor = 19; //(Êä³ö½á¹ûÖÐ, xºÍy¶¼ÊÇ´Ó1¿ªÊ¼µÄ)
    aBrick2->p.ycor = 1;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 19;
    aBrick2->p.ycor = 4;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 46;
    aBrick2->p.ycor = 1;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 46;
    aBrick2->p.ycor = 4;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 19;
    aBrick2->p.ycor = 34;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 19;
    aBrick2->p.ycor = 37;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 46;
    aBrick2->p.ycor = 34;
    displayBrick(aBrick2);
    aBrick2->p.xcor = 46;
    aBrick2->p.ycor = 37;
    displayBrick(aBrick2);
    //·ÅµÚÈýÀà×©¿é
    aBrick3->p.xcor = 28;
    aBrick3->p.ycor = 4;
    displayBrick(aBrick3);
    aBrick3->p.xcor = 37;
    aBrick3->p.ycor = 4;
    displayBrick(aBrick3);
    aBrick3->p.xcor = 28;
    aBrick3->p.ycor = 34;
    displayBrick(aBrick3);
    aBrick3->p.xcor = 37;
    aBrick3->p.ycor = 34;
    displayBrick(aBrick3);
    //·ÅµÚËÄÀà×©¿é
    displayBrick(aBrick4);
    aBrick4->p.xcor = 55;
    aBrick4->p.ycor = 10;
    displayBrick(aBrick4);
    aBrick4->p.xcor = 10;
    aBrick4->p.ycor = 28;
    displayBrick(aBrick4);
    aBrick4->p.xcor = 55;
    aBrick4->p.ycor = 28;
    displayBrick(aBrick4);

}
//ÅÐ¶Ïµ±Ç°Î»ÖÃÉÏÐ¡ÇòºÍ×©¿éÓÐÃ»ÓÐ·¢ÉúÁËÅö×²£»ÈôÓÐÔò·µ»Ønum£¬ËÄÖÖ×©¿é·Ö±ð¶ÔÓ¦µÄnumÖµÎª1,2,3,4,ÈçÃ»×²µ½×©¿é£¬Ôò·µ»Ø0
int boolIsColliding(Ball *aBall)
{
    int i;
    int num=0;  //³õÊ¼Ê±Ä¬ÈÏÃ»×²µ½×©¿é
    int x= aBll->a.xcor;
    int y= aBll->a.ycor;
    //ÅÐ¶ÏÐ¡ÇòÊÇ²»ÊÇ×²µ½ÁËµÚÒ»¿é×©£¬ÓÐnum·µ»Ø1£¬µÚÒ»ÖÖ×©Ò»Åö¾ÍÏûÊ§
    if(y==30 )
    {
        for(i=1;i<7;i++)
        {
            if( x>9*i && x<9*i+9)
            {
                aBrick5->p.xcor = 10+9*(i-1);
                aBrick5->p.ycor = 31;
                displayBrick(aBrick5);
                num=1;  //×²µ½±ê×¼ÐÍ×©¿é
            }
        }
    }
    else if(y==10)
    {
        for(i=1;i<7;i++)
        {
            if( x>9*i && x<9*i+9)
            {
                aBrick5->p.xcor = 10+9*(i-1);
                aBrick5->p.ycor = 7;
                displayBrick(aBrick5);
                num=1;  //×²µ½±ê×¼ÐÍ×©¿é
            }
        }
    }
    else if(y==4)
    {
         for(i=0;i<2;i++)
        {
            if( x>27+9*i && x<9*i+36)
            {
                aBrick5->p.xcor = 28+9*i;
                aBrick5->p.ycor = 1;
                displayBrick(aBrick5);
                num=1;  //×²µ½±ê×¼ÐÍ×©¿é
            }
        }
    }
     else if(y==36)
    {
         for(i=0;i<2;i++)
        {
            if( x>27+9*i && x<9*i+36)
            {
                aBrick5->p.xcor = 28+9*i;
                aBrick5->p.ycor = 37;
                displayBrick(aBrick5);
                num=1;  //×²µ½±ê×¼ÐÍ×©¿é
            }
        }
    }
    //ÅÐ¶ÏÐ¡ÇòÊÇ²»ÊÇ×²µ½ÁËµÚ¶þÖÖ×©£¬ÓÐnum·µ»Ø2£¬µÚ¶þÖÖ×©ÓÀ²»ÏûÊ§
    if(y==7 || y==4 || y==33 || y==36)
    {
            if( (x>18 && x<27) || (x>45 && x<54))
                num=2;
    }
    //ÅÐ¶ÏÐ¡ÇòÊÇ²»ÊÇ×²µ½ÁËµÚÈýÖÖ×©£¬ÓÐnum·µ»Ø3£¬µÚ¶þÖÖ×©ÅöÁ½´ÎÏûÊ§
    if(y==33)
    {
        for(i=0;i<2;i++)
        {
            if( x>(27+9*i) && (x<9*i+36))
            {
                if(brick3>1)
                {
                    aBrick5->p.xcor = 28+9*i;
                aBrick5->p.ycor = 34;
                displayBrick(aBrick5);
                }
                num=3;  //×²µ½±ê×¼ÐÍ×©¿é
                brick3++;
            }
        }
    }
    else if(y==7)
    {
        for(i=0;i<2;i++)
        {
            if( x>(27+9*i) && (x<9*i+36))
            {
                if(brick3>1)
                {
                    aBrick5->p.xcor = 28+9*i;
                    aBrick5->p.ycor = 4;
                    displayBrick(aBrick5);
                }
                num=3;  //×²µ½±ê×¼ÐÍ×©¿é
                brick3++;
            }
        }
    }
    //ÅÐ¶ÏÐ¡ÇòÊÇ²»ÊÇ×²µ½ÁËµÚËÄÖÖ×©£¬ÓÐnum·µ»Ø4£¬µÚ¶þÖÖ×©Îª»ÙÃðÐÔ
    if(y==9 || y==13 || y==27 || y==32)
    {
            if( (x>9 && x<18) || (x>54 && x<63))
                num=4;
    }

    return num;
}
int main()
{
    int i,j;   //ÓÉi,j¾«È·¶¨ÒåÒ»¸ö¼ÆÊýÆ÷£¬¼ÆÊýÆ÷Ã¿Ò»¸öÑ­»·ÓÃÊ±´ó¸Å1Ãë
    int score=0;
    int life=3; //³õÊ¼Ê±Íæ¼Ò¹²ÓÐ3ÌõÉúÃü
    displayBallx(aBll);
    int ydir=1;
 //   aBll->b.yvel= ydir;    //¸Õ¿ªÊ¼Ð¡ÇòÔÚy·½ÏòÏòÏÂÔË¶¯
    init();     //³õÊ¼»¯ÓÎÏ·½çÃæ
    time1 = time(NULL); //Ã¿´Î½øÈëÖ÷º¯Êý¾Í¼ÇÂ¼µ±Ê±Ê±¼ä
    int gotime=1;       //Èç¹ûÃ»ÓÐ°´ÏÂESC¼ü£¬ÓÎÏ·Ò»Ö±½øÐÐ,¼´gotimeÒ»Ö±Îª1
    while(gotime)            //¶¨ÒåÒ»¸öÎÞÏÞÑ­»·À´¼ì²âÊ±¼ä½ø³Ì
    {
        //ÏÈ¼ì²âÓÃ»§ÊÇ·ñÓÐ°´¼üÊäÈë
        if(life==0)
        {
            printf("\nGame is over!");
            exit(EXIT_FAILURE);
        }

        int ch=keyboard();
        switch(ch)
            {
            case 27: //Èç¹û°´ÏÂ¼ü£¬ÍË³öÖ÷Ñ­»·ÓÎÏ·
                gotime=0;
            case 57: //Èç¹û°´ÏÂÊý×Ö9¼ü£¬x·½ÏòËÙ¶ÈÎª-1
                aBll->b.xvel=-1;
                moveBallx(aBll);
                break;
            case 48: //Èç¹û°´ÏÂ0¼ü£¬x·½ÏòËÙ¶ÈÎª1
                aBll->b.xvel=1;
                moveBallx(aBll);
                break;
            default:
                break;
            }
        displayBallx(aBll);
        //¶¨ÒåÒ»¸ö¼ÆÊýÆ÷£¬ÓÃÀ´²âÁ¿Ê±¼ä£¬´óÔ¼Îª1Ãë
        for(i=0;i<3000;i++)
            for(j=0;j<50000;j++);
        i=0;    //¼ÆÊýÆ÷Çå0

     //¼ÆÊýÆ÷ÇåÁãºó£¬ÏÈ²Á³ýÔ­Ð¡Çò£¬ÔÙÔÚÐÂÎ»ÖÃÏÔÊ¾Ð¡Çò
        eraseBallx(aBll);// ÏÈÔÚÔ­×ø±ê´¦Ïû³ýÐ¡Çò£¬È»ºóÔÙ¶Ô×ø±ê²Ù×÷


        switch(boolIsColliding(aBll))
            {
            case 0: //Èç¹ûÃ»×²µ½×©¿é
                break;
            case 1: //×²µ½±ê×¼×©¿é
                score++;
                break;
            case 2: //×²µ½ÓÀ²»ÏûÊ§×©¿é
               // score++;
                if(ydir==1)
                    ydir=0;
                else
                    ydir=1;
                break;
            case 3: //×²µ½ÔöÇ¿×©
                score++;
                if(brick3<3)
                {
                    if(ydir==1)
                        ydir=0;
                    else
                        ydir=1;
                }
                break;
            case 4: //×²µ½»ÙÃðÐÍ×©¿é
                life--;
                if(ydir==1)
                    ydir=0;
                else
                    ydir=1;

                break;
            default:
                break;
            }
        aBll->b.yvel= ydir;
        moveBally(aBll);

    }
    // detaTime = difftime(time(NULL),time1);
    // printf("%d\n",detaTime);
    printf("\n\nThe total score is :%d",score/2);
    return EXIT_SUCCESS;
}

