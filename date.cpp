 //�������ܣ���ӡ����,�޸Ŀ�ʼʱ��ͽ���ʱ�䣬���Դ�ӡ�ӿ�ʼʱ�䵽����ʱ�������������


 #include <stdio.h>
 #include <string.h>

 #define BTIME 1900;//��ʼʱ��
 #define ETIME 2016;//����ʱ��

 //1900��1��1��������һ
 //��ά�����0*0��ʼ�ģ������1��ʼ
 FILE *pFile = fopen("date.txt","w");
int lmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month[15][45] = {{0}};
void compMonth(int y);
int getFD(int y);
void printDate();
void printZ();
void printYH(int n);
void printNS(int y);

int main()//�ȿ�ʼһ��Ĵ�ӡ
{
    int i=BTIME;
    int y=ETIME;
    for(; i<=y; i++)
    {
        printNS(i);
        compMonth(i);
        printDate();
    }

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


        for(int i=0; (i<lmonth[m-1] && (a%7+i)<=44); i++)
        {
            month[m-1][a%7 + i+1] = i+1;//������Ҳ�Ǵ�0��ʼ��

        }
        //for(int j=lmonth[m-1]; j<=35; j++)
        //{
         //   month[m-1][a%7 + j] = j-lmonth[m-1] +1;
        //}
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
        printf("\n");
        fprintf(pFile,"\n");
        printYH(ym);
        printZ();
        for(int yd=1; yd<=6; yd++)//��������ÿ���µľ������
        {
            for(int xm=1; xm<=4; xm++)//�·ݵ���������ڵ����Ӧ���ǻ�����ص�
            {
                 for(int xd=1; xd<=7; xd++)
                {
                    if( month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]==0)
                    {
                        printf( "    ");
                        fprintf(pFile,"    ");
                    }
                    else
                    {
                        printf( "%4d", month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]);
                        fprintf( pFile,"%4d", month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]);
                    }
                    //if((yd-1)*7 + xd == 34) printf("\nmonth[%d][%d]:%d\n",(ym-1)*4 + xm - 1,(yd-1)*7 + xd,month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]);
                    //fprintf(pFile, "%4d", month[(ym-1)*4 + xm - 1][(yd-1)*7 + xd]);//�������Ǵ�1��12��λ����,Ҳ���Դ�1��35�����ok,ò��������λҲû��
                }
                if(xm==4)
                {
                    printf("\n");
                    fprintf(pFile,"\n");//û���7��ո�һ�£������س�һ��
                }
                else
                {
                    printf("   ");
                    fprintf(pFile,"   ");//û���7��ո�һ�£������س�һ��
                }
            }
        }
    }

}


 void printZ()
 {
     for(int i=1; i<=4; i++)
     {
         for(int j=0; j<=6; j++)
         {
             switch(j)
             {
             case 0:
                 printf("  ��");
                 fprintf(pFile,"  ��");
                 break;


             case 1:
                 printf("  һ");
                 fprintf(pFile,"  һ");
                 break;


             case 2:
                 printf("  ��");
                 fprintf(pFile,"  ��");
                 break;


             case 3:
                 printf("  ��");
                 fprintf(pFile,"  ��");
                 break;


             case 4:
                 printf("  ��");
                 fprintf(pFile,"  ��");
                 break;


             case 5:
                 printf("  ��");
                 fprintf(pFile,"  ��");
                 break;


             case 6:
                 printf("  ��   ");
                 fprintf(pFile,"  ��   ");
                 break;
             }
         }
         if(i==4)
        {
            printf("\n");
            fprintf(pFile,"\n");
        }
     }
 }
void printYH(int n)//��ӡ�º�
{
    switch(n)
    {
    case 1:
        printf("             һ��                           ����                           ����                           ����\n");
        fprintf(pFile,"             һ��                           ����                           ����                           ����\n");
        break;
    case 2:
        printf("             ����                           ����                           ����                           ����\n");
        fprintf(pFile,"             ����                           ����                           ����                           ����\n");
        break;
    case 3:
        printf("             ����                           ʮ��                          ʮһ��                         ʮ����\n");
        fprintf(pFile,"             ����                           ʮ��                          ʮһ��                         ʮ����\n");
        break;
    }
}
void printNS(int y)//��ӡ����
{
    printf("\n                                                           %d��\n",y);
    fprintf(pFile,"\n                                                           %d��\n",y);
}

