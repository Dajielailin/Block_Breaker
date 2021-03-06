#include <stdio.h>
#include "conio2.h"
#include "headers.h"
#include<assert.h>
#include<time.h>
#include<stdlib.h>

time_t time1;
int detaTime;
/*对小球结构进行初始化*/
Ball example={{18,11},{0,0},0};//该小球的初始位置为(0,0),x和y方向初始速度为（0,0），它的形状是字符‘0’
Ball *aBll=&example ;          //定义一个指针时，一定要给它初始化

/*对砖块结构进行初始化*/
//第一类砖块,标准砖
Brick abrick1={{0,1},{10,7},image1};//砖块的等级为01，位置在（5,5）处，后面数组存储的是图像内容
Brick *aBrick1= &abrick1;
//第二类砖块，永不消失砖
Brick abrick2={{0,2},{10,7},image2};//砖块的等级为02，位置在（5,5）处，后面数组存储的是图像内容
Brick *aBrick2= &abrick2;
//第三类砖块，增强砖
Brick abrick3={{0,3},{10,7},image3};//砖块的等级为03，位置在（5,5）处，后面数组存储的是图像内容
Brick *aBrick3= &abrick3;
int brick3=0;   //用来计数小球撞到第三种砖的次数
//第四类砖块，毁灭砖
Brick abrick4={{0,4},{10,10},image4};//砖块的等级为04，位置在（5,5）处，后面数组存储的是图像内
Brick *aBrick4= &abrick4;

//第五类砖块，专门用来清除一个砖块的图像
Brick abrick5={{0,0},{10,10},image5};//砖块的等级为04，位置在（5,5）处，后面数组存储的是图像内容
Brick *aBrick5= &abrick5;

/*定义左移指令为数字键-9
       右移指令为数字键-0
       退出游戏指令-ESC键
*/
int keyboard(void)
{
    int ch=0;       //每次调用keyboard()函数时对ch初始化，若没有初始化效果则是小球连续左移或右移
    if(kbhit())     //检测当前是否有键盘输入，若有则返回一个非0值，否则返回0
        ch=getch(); //获得所按下键盘对应的ASC码值
    return ch;
}

//定义两个函数分别来控制小球的横纵坐标
void moveBallx(Ball *aBall)//x轴方向两个边界分别为x=0,x=80
{

    int vel=aBll->b.xvel;
    if(vel==-1) //"9"键被按下
    {
        if(aBll->a.xcor==0)    //如果小球达到y轴(x=0)就反弹回去：速度反向，位置向右加一
        {
            aBll->a.xcor++;
            aBll->b.xvel=1;
        }
        else
            aBll->a.xcor-- ;

    }
    if(vel==1)  //“0”键被按下
    {
        if(aBll->a.xcor==80)    //如果小球达到y轴(x=0)就反弹回去：速度反向，位置向右加一
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
     if(aBll->a.ycor >=0 && aBll->a.ycor<=40)    //如果小球达到x轴(y=0,y=40),小球停止运动
        {
            //aBll->a.ycor++;
            if(vel==0) //"9"键被按下
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
    printf("\b \b");    //每次移动小球前先把上一个位置的‘0’删掉
}

void displayBallx(Ball *aBall)
{

    gotoxy(aBll->a.xcor,aBll->a.ycor);
    printf("0");
}

/*显示砖块图像函数*/
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
//游戏界面初始化，放砖块
void init()
{
    int i;
    //放第一类砖块
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
    //放第二类砖块
    aBrick2->p.xcor = 19; //(输出结果中, x和y都是从1开始的)
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
    //放第三类砖块
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
    //放第四类砖块
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
//判断当前位置上小球和砖块有没有发生了碰撞；若有则返回num，四种砖块分别对应的num值为1,2,3,4,如没撞到砖块，则返回0
int boolIsColliding(Ball *aBall)
{
    int i;
    int num=0;  //初始时默认没撞到砖块
    int x= aBll->a.xcor;
    int y= aBll->a.ycor;
    //判断小球是不是撞到了第一块砖，有num返回1，第一种砖一碰就消失
    if(y==30 )
    {
        for(i=1;i<7;i++)
        {
            if( x>9*i && x<9*i+9)
            {
                aBrick5->p.xcor = 10+9*(i-1);
                aBrick5->p.ycor = 31;
                displayBrick(aBrick5);
                num=1;  //撞到标准型砖块
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
                num=1;  //撞到标准型砖块
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
                num=1;  //撞到标准型砖块
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
                num=1;  //撞到标准型砖块
            }
        }
    }
    //判断小球是不是撞到了第二种砖，有num返回2，第二种砖永不消失
    if(y==7 || y==4 || y==33 || y==36)
    {
            if( (x>18 && x<27) || (x>45 && x<54))
                num=2;
    }
    //判断小球是不是撞到了第三种砖，有num返回3，第二种砖碰两次消失
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
                num=3;  //撞到标准型砖块
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
                num=3;  //撞到标准型砖块
                brick3++;
            }
        }
    }
    //判断小球是不是撞到了第四种砖，有num返回4，第二种砖为毁灭性
    if(y==9 || y==13 || y==27 || y==32)
    {
            if( (x>9 && x<18) || (x>54 && x<63))
                num=4;
    }

    return num;
}
int main()
{
    int i,j;   //由i,j精确定义一个计数器，计数器每一个循环用时大概1秒
    int score=0;
    int life=3; //初始时玩家共有3条生命
    displayBallx(aBll);
    int ydir=1;
 //   aBll->b.yvel= ydir;    //刚开始小球在y方向向下运动
    init();     //初始化游戏界面
    time1 = time(NULL); //每次进入主函数就记录当时时间
    int gotime=1;       //如果没有按下ESC键，游戏一直进行,即gotime一直为1
    while(gotime)            //定义一个无限循环来检测时间进程
    {
        //先检测用户是否有按键输入
        if(life==0)
        {
            printf("\nGame is over!");
            exit(EXIT_FAILURE);
        }

        int ch=keyboard();
        switch(ch)
            {
            case 27: //如果按下键，退出主循环游戏
                gotime=0;
            case 57: //如果按下数字9键，x方向速度为-1
                aBll->b.xvel=-1;
                moveBallx(aBll);
                break;
            case 48: //如果按下0键，x方向速度为1
                aBll->b.xvel=1;
                moveBallx(aBll);
                break;
            default:
                break;
            }
        displayBallx(aBll);
        //定义一个计数器，用来测量时间，大约为1秒
        for(i=0;i<3000;i++)
            for(j=0;j<50000;j++);
        i=0;    //计数器清0

     //计数器清零后，先擦除原小球，再在新位置显示小球
        eraseBallx(aBll);// 先在原坐标处消除小球，然后再对坐标操作


        switch(boolIsColliding(aBll))
            {
            case 0: //如果没撞到砖块
                break;
            case 1: //撞到标准砖块
                score++;
                break;
            case 2: //撞到永不消失砖块
               // score++;
                if(ydir==1)
                    ydir=0;
                else
                    ydir=1;
                break;
            case 3: //撞到增强砖
                score++;
                if(brick3<3)
                {
                    if(ydir==1)
                        ydir=0;
                    else
                        ydir=1;
                }
                break;
            case 4: //撞到毁灭型砖块
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

