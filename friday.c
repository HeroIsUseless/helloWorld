#include <stdio.h>
//�������n�꣬�������13����ÿ�����ڵĴ�����
/*ͨ�������꣬�Ϳ���֪���ж��ٸ�13����
�ӵ�һ��13�տ�ʼ���ж����ǵڼ���
�õڼ����ж������ڼ�������������
���

 */
int get13DayWeek(int m);
int getYearDay(int n);
int getMonthDay(int n);
 int main()
 {
     int n,i,j,weekday[7] = 0;
     FILE* pFile1 = fopen("friday.in","r");
     FILE* pFile2 = fopen("friday.out","w");

     fscanf(pFile1,"%d",&n);
     m = 12*n;
     for(i=0; i<m; i++)
     {
         for(j=0; j<7; j++)
         {
             if(j+1 == get13DayWeek(i))
                weekday[i]++;
         }
     }
     for(i=0; i<7; i++)
     {
         fprintf(pFile2,"%d ",weekday[i]);
     }
     fclose(pFile1);fclose(pFile2);
     return 0;
 }
int get13DayWeek(int m)//����ڼ���13�գ��������ڼ�
 {//�ó������������������������
     int n;
     if(m%12 != 0)
         n = getYearDay(m/12) + getMonthDay(m%12, m/12+1);
     else
         n = getYearDay(m/12-1) + getMonthDay(12, m/12);
     n = n%7 + 1;
    return n;
 }
 int getYearDay(int n)
 {
     int i,a=0;
     for(i=0; i<n; i++)
        if(((1990+n)%100!=0&&(1990+n)/4==0)||((1990+n)%400==0))
            a+=366;
        else
            a+=365;
     return a;
 }
 int getMonthDay(int m, int n)
 {
     int month[20];
     month[1]=31;
     month[2]=29;
     month[3]=31;
     month[4]=30;
     month[5]=31;
     month[6]=30;
     month[7]=31;
     month[8]=31;
     month[9]=30;
     month[10]=31;
     month[11]=30;
     month[12]=31;
     if(((1990+n)%100!=0&&(1990+n)/4==0)||((1990+n)%400==0))

        else

     return 0;
 }






