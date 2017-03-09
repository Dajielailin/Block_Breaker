#define leftmove '1'
#define rightmove '2'
/*定义两个常量分别用来存储砖块的长和宽*/
#define BRIQUE_HEIGHT 3
#define BRIQUE_WIDTH 8
//静态二维数组image用来存储砖块的图像
static char image1[BRIQUE_HEIGHT][BRIQUE_WIDTH]={{'-','-','-','-','-','-','-','-'},{'8','8','8','8','8','8','8','8'},
                                {'-','-','-','-','-','-','-','-'}};
static char image2[BRIQUE_HEIGHT][BRIQUE_WIDTH]={{'M','M','M','M','M','M','M','M'},{'I',' ',' ','X','X',' ',' ','I'},
                                {'M','M','M','M','M','M','M','M'}};
static char image3[BRIQUE_HEIGHT][BRIQUE_WIDTH]={{'*','*','*','*','*','*','*','*'},{'*',' ','*',' ',' ','*',' ','*'},
                                {'*','*','*','*','*','*','*','*'}};
static char image4[BRIQUE_HEIGHT][BRIQUE_WIDTH]={{'-','-','-','-','-','-','-','-'},{'|',' ',' ',' ',' ',' ',' ','|'},
                                {'-','-','-','-','-','-','-','-'}};
static char image5[BRIQUE_HEIGHT][BRIQUE_WIDTH]={{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' ',' '}};
//分别定义小球的position和Speed结构体
typedef struct{
    int xcor;//X方向坐标
    int ycor;
}Position;
typedef struct{
    int xvel;//X方向速度
    int yvel;
}Speed;
typedef struct {
    Position a;
    Speed b;
    char c; //c应该初始化为'0'
}Ball;

//定义Brick结构体，它包含砖块的等级，位置以及图像
typedef struct{
    int bricksTab[3];//定义一个数组，用来存储砖块的等级
    Position p;      //结构体s存储该砖块的位置信息
    char *image;

}Brick;


int keyboard(void );
//定义两个函数分别来控制小球的横纵坐标
void moveBallx(Ball *aBall);//x轴方向两个边界分别为x=0,x=80
void moveBally(Ball *aBall);//y轴方向两个边界分别为y=0,x=40

