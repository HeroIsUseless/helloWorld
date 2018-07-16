//main�ǰ�Ԥװ�õ�������ӡ����

#include <stdio.h>
#include <string.h>
#define BTIME 1900;
#define ETIME 2016;
//1900��1��1��������һ
//��ά�����0*0��ʼ�ģ������1��ʼ
FILE *pFile = fopen("date.out","w");
int lmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month[12][40] = {{0}};
void compMonth(int y);
int getFD(int y);
void printDate();
void printZ();

int main()//�ȿ�ʼһ��Ĵ�ӡ
{
    int y = ETIME;
    compMonth(y);
    printDate();
    fclose(pFile);
    return 0;
}

void compMonth(int y)
{
    if( (y%100 != 0) && (y%4==0) || (y%400 == 0))
    {
        lmonth[1] = 29;
    }
    else
    {
        lmonth[1] = 28;
    }
    int a = getFD(y);
    for(int m=1; m<=12; m++)
    {
        memset(month[m-1],0,sizeof(month[m-1]));
        for(int i=0; (i<lmonth[m-1] && (a%7+i)<35); i++)
        {
            month[m-1][a%7 + i] = i+1;//������Ҳ�Ǵ�0��ʼ��
        }
        a+=lmonth[m-1];
    }
}

int getFD(int y)
{
    int d = 0;
    for(int i=1990; i<y; i++)
    {
        if( (y%100 != 0) && (y%4 == 0) || (y%400 == 0))
        {
            d+=366;
        }
        else
        {
            d+=365;
        }
    }
    return (d+1)%7;
}
void printDate()
{
    for(int ym=1; ym<=3; ym++)//��������12���µ����
    {
        printZ();
        for(int yd=1; yd<=5; yd++)//��������ÿ���µľ������
        {
            for(int xm=1; xm<=4; xm++)//�·ݵ���������ڵ����Ӧ���ǻ�����ص�
            {
                 for(int xd=1; xd<=7; xd++)
                {
                    printf( "%4d", month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]);
                    fprintf(pFile, "%4d", month[(ym-1)*4 + xm][(yd-1)*7 + xd]);//�������Ǵ�1��12��λ����,Ҳ���Դ�1��35�����ok,ò��������λҲû��
                }
                if(xm==4)
                {
                    printf("\n");
                    fprintf(pFile,"\n");//û���7��ո�һ�£������س�һ��
                }
                else
                {
                    printf("   ");
                    fprintf(pFile,"    ");//û���7��ո�һ�£������س�һ��
                }
            }
        }
    }


    for(int i=0; i<12; i++)
    {
        printf("%d ",month[i][35]);
    }

}

void printZ()
{
    printf("\n");
    for(int i=1; i<=4; i++)
    {
        for(int j=0; j<=6; j++)
        {
            switch(j)
            {
            case 0:
                printf("  ��");
                break;

            case 1:
                printf("  һ");
                break;

            case 2:
                printf("  ��");
                break;

            case 3:
                printf("  ��");
                break;

            case 4:
                printf("  ��");
                break;

            case 5:
                printf("  ��");
                break;

            case 6:
                printf("  ��   ");
                break;
            }
        }
        if(i==4) printf("\n");
    }
}






















