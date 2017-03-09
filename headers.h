#define leftmove '1'
#define rightmove '2'
/*�������������ֱ������洢ש��ĳ��Ϳ�*/
#define BRIQUE_HEIGHT 3
#define BRIQUE_WIDTH 8
//��̬��ά����image�����洢ש���ͼ��
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
//�ֱ���С���position��Speed�ṹ��
typedef struct{
    int xcor;//X��������
    int ycor;
}Position;
typedef struct{
    int xvel;//X�����ٶ�
    int yvel;
}Speed;
typedef struct {
    Position a;
    Speed b;
    char c; //cӦ�ó�ʼ��Ϊ'0'
}Ball;

//����Brick�ṹ�壬������ש��ĵȼ���λ���Լ�ͼ��
typedef struct{
    int bricksTab[3];//����һ�����飬�����洢ש��ĵȼ�
    Position p;      //�ṹ��s�洢��ש���λ����Ϣ
    char *image;

}Brick;


int keyboard(void );
//�������������ֱ�������С��ĺ�������
void moveBallx(Ball *aBall);//x�᷽�������߽�ֱ�Ϊx=0,x=80
void moveBally(Ball *aBall);//y�᷽�������߽�ֱ�Ϊy=0,x=40

