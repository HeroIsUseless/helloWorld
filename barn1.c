/*
ID:22920179
LANG:C
TASK:barn1
*/
#include <stdio.h>
#include <stdlib.h>
//��Ϊ���ľ����ܽ��շ���һ�����
//�����ǵ�һ���Ƿ���ţ��ڶ��Ƿ����ճ��ȣ����ճ���������Ϻ�
//��Ϊ��m��ľ�壬������m-1���գ���m-1��ǰ�÷��䣬�������
//ǰ�÷����ֱ�Ӽ��Ϳ�����
int main()
{
    int i, j, k, t, m, s, c;//ľ��������Ŀ��ţ���������ţ����Ŀ
    int a[200][2];//ţ����ţ��ı��+һ����ǣ���ʾ��ţ����ţ�ﳤ��
    FILE *pFile1 = fopen("barn1.in", "r");
    FILE *pFile2 = fopen("barn1.out", "w");
    fscanf(pFile1,"%d %d %d", &m, &s, &c);
    printf("%d %d %d\n", m, s, c);
    for(i=0; i<c; i++)
    {
        fscanf(pFile1,"%d", &a[i][0]);
    }

    for(i=0; i<c; i++)//ţ���Ŵ�С������һ��
    {
        k = i;
        for(j=i; j<c; j++)
        {
            if(a[k][0] > a[j][0])
                k = j;
        }
        t=a[i][0]; a[i][0]=a[k][0]; a[k][0]=t;
    }
    for(i=0; i<c-1; i++)
    {
        a[i][1] = a[i+1][0] - a[i][0] -1;
    }
    a[c-1][1] = 0;

    s = s-(a[0][0]-1)-(s-a[c-1][0]-1)-1;

    for(i=0; i<c; i++)//�ÿշ��䳤��������һ��
    {
        k = i;
        for(j=i; j<c; j++)
        {
            if(a[k][1] < a[j][1])
                k = j;
        }
        t=a[i][0]; a[i][0]=a[k][0]; a[k][0]=t;
        t=a[i][1]; a[i][1]=a[k][1]; a[k][1]=t;
    }

    if(m>c) m=c;
    for(i=0; i<m-1; i++)
    {
        s -= a[i][1];
    }
    fprintf(pFile2,"%d\n", s);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

