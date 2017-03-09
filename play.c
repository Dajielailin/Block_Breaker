#include <stdio.h>
#include "conio2.h"
#include "headers.h"
#include<assert.h>
#include<time.h>
#include<stdlib.h>

time_t time1;
int detaTime;
/*��С��ṹ���г�ʼ��*/
Ball example={{18,11},{0,0},0};//��С��ĳ�ʼλ��Ϊ(0,0),x��y�����ʼ�ٶ�Ϊ��0,0����������״���ַ���0��
Ball *aBll=&example ;          //����һ��ָ��ʱ��һ��Ҫ������ʼ��

/*��ש��ṹ���г�ʼ��*/
//��һ��ש��,��׼ש
Brick abrick1={{0,1},{10,7},image1};//ש��ĵȼ�Ϊ01��λ���ڣ�5,5��������������洢����ͼ������
Brick *aBrick1= &abrick1;
//�ڶ���ש�飬������ʧש
Brick abrick2={{0,2},{10,7},image2};//ש��ĵȼ�Ϊ02��λ���ڣ�5,5��������������洢����ͼ������
Brick *aBrick2= &abrick2;
//������ש�飬��ǿש
Brick abrick3={{0,3},{10,7},image3};//ש��ĵȼ�Ϊ03��λ���ڣ�5,5��������������洢����ͼ������
Brick *aBrick3= &abrick3;
int brick3=0;   //��������С��ײ��������ש�Ĵ���
//������ש�飬����ש
Brick abrick4={{0,4},{10,10},image4};//ש��ĵȼ�Ϊ04��λ���ڣ�5,5��������������洢����ͼ����
Brick *aBrick4= &abrick4;

//������ש�飬ר���������һ��ש���ͼ��
Brick abrick5={{0,0},{10,10},image5};//ש��ĵȼ�Ϊ04��λ���ڣ�5,5��������������洢����ͼ������
Brick *aBrick5= &abrick5;

/*��������ָ��Ϊ���ּ�-9
       ����ָ��Ϊ���ּ�-0
       �˳���Ϸָ��-ESC��
*/
int keyboard(void)
{
    int ch=0;       //ÿ�ε���keyboard()����ʱ��ch��ʼ������û�г�ʼ��Ч������С���������ƻ�����
    if(kbhit())     //��⵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
        ch=getch(); //��������¼��̶�Ӧ��ASC��ֵ
    return ch;
}

//�������������ֱ�������С��ĺ�������
void moveBallx(Ball *aBall)//x�᷽�������߽�ֱ�Ϊx=0,x=80
{

    int vel=aBll->b.xvel;
    if(vel==-1) //"9"��������
    {
        if(aBll->a.xcor==0)    //���С��ﵽy��(x=0)�ͷ�����ȥ���ٶȷ���λ�����Ҽ�һ
        {
            aBll->a.xcor++;
            aBll->b.xvel=1;
        }
        else
            aBll->a.xcor-- ;

    }
    if(vel==1)  //��0����������
    {
        if(aBll->a.xcor==80)    //���С��ﵽy��(x=0)�ͷ�����ȥ���ٶȷ���λ�����Ҽ�һ
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
     if(aBll->a.ycor >=0 && aBll->a.ycor<=40)    //���С��ﵽx��(y=0,y=40),С��ֹͣ�˶�
        {
            //aBll->a.ycor++;
            if(vel==0) //"9"��������
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
    printf("\b \b");    //ÿ���ƶ�С��ǰ�Ȱ���һ��λ�õġ�0��ɾ��
}

void displayBallx(Ball *aBall)
{

    gotoxy(aBll->a.xcor,aBll->a.ycor);
    printf("0");
}

/*��ʾש��ͼ����*/
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
//��Ϸ�����ʼ������ש��
void init()
{
    int i;
    //�ŵ�һ��ש��
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
    //�ŵڶ���ש��
    aBrick2->p.xcor = 19; //(��������, x��y���Ǵ�1��ʼ��)
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
    //�ŵ�����ש��
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
    //�ŵ�����ש��
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
//�жϵ�ǰλ����С���ש����û�з�������ײ�������򷵻�num������ש��ֱ��Ӧ��numֵΪ1,2,3,4,��ûײ��ש�飬�򷵻�0
int boolIsColliding(Ball *aBall)
{
    int i;
    int num=0;  //��ʼʱĬ��ûײ��ש��
    int x= aBll->a.xcor;
    int y= aBll->a.ycor;
    //�ж�С���ǲ���ײ���˵�һ��ש����num����1����һ��שһ������ʧ
    if(y==30 )
    {
        for(i=1;i<7;i++)
        {
            if( x>9*i && x<9*i+9)
            {
                aBrick5->p.xcor = 10+9*(i-1);
                aBrick5->p.ycor = 31;
                displayBrick(aBrick5);
                num=1;  //ײ����׼��ש��
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
                num=1;  //ײ����׼��ש��
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
                num=1;  //ײ����׼��ש��
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
                num=1;  //ײ����׼��ש��
            }
        }
    }
    //�ж�С���ǲ���ײ���˵ڶ���ש����num����2���ڶ���ש������ʧ
    if(y==7 || y==4 || y==33 || y==36)
    {
            if( (x>18 && x<27) || (x>45 && x<54))
                num=2;
    }
    //�ж�С���ǲ���ײ���˵�����ש����num����3���ڶ���ש��������ʧ
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
                num=3;  //ײ����׼��ש��
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
                num=3;  //ײ����׼��ש��
                brick3++;
            }
        }
    }
    //�ж�С���ǲ���ײ���˵�����ש����num����4���ڶ���שΪ������
    if(y==9 || y==13 || y==27 || y==32)
    {
            if( (x>9 && x<18) || (x>54 && x<63))
                num=4;
    }

    return num;
}
int main()
{
    int i,j;   //��i,j��ȷ����һ����������������ÿһ��ѭ����ʱ���1��
    int score=0;
    int life=3; //��ʼʱ��ҹ���3������
    displayBallx(aBll);
    int ydir=1;
 //   aBll->b.yvel= ydir;    //�տ�ʼС����y���������˶�
    init();     //��ʼ����Ϸ����
    time1 = time(NULL); //ÿ�ν����������ͼ�¼��ʱʱ��
    int gotime=1;       //���û�а���ESC������Ϸһֱ����,��gotimeһֱΪ1
    while(gotime)            //����һ������ѭ�������ʱ�����
    {
        //�ȼ���û��Ƿ��а�������
        if(life==0)
        {
            printf("\nGame is over!");
            exit(EXIT_FAILURE);
        }

        int ch=keyboard();
        switch(ch)
            {
            case 27: //������������˳���ѭ����Ϸ
                gotime=0;
            case 57: //�����������9����x�����ٶ�Ϊ-1
                aBll->b.xvel=-1;
                moveBallx(aBll);
                break;
            case 48: //�������0����x�����ٶ�Ϊ1
                aBll->b.xvel=1;
                moveBallx(aBll);
                break;
            default:
                break;
            }
        displayBallx(aBll);
        //����һ������������������ʱ�䣬��ԼΪ1��
        for(i=0;i<3000;i++)
            for(j=0;j<50000;j++);
        i=0;    //��������0

     //������������Ȳ���ԭС��������λ����ʾС��
        eraseBallx(aBll);// ����ԭ���괦����С��Ȼ���ٶ��������


        switch(boolIsColliding(aBll))
            {
            case 0: //���ûײ��ש��
                break;
            case 1: //ײ����׼ש��
                score++;
                break;
            case 2: //ײ��������ʧש��
               // score++;
                if(ydir==1)
                    ydir=0;
                else
                    ydir=1;
                break;
            case 3: //ײ����ǿש
                score++;
                if(brick3<3)
                {
                    if(ydir==1)
                        ydir=0;
                    else
                        ydir=1;
                }
                break;
            case 4: //ײ��������ש��
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

