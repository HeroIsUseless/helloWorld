/*
ID:22920179
LANG:C
TASK:milk
*/
#include <stdio.h>
//�ö�ά���飬��������
int n, m;//ţ��������ũ����Ŀ
int a[5000][2];//����+����

int main()
{
    int i,j,t,k, max=0, money=0;
    int l[5000];
    FILE *pFile1 = fopen("milk.in", "r");
    FILE *pFile2 = fopen("milk.out", "w");
    fscanf(pFile1,"%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        fscanf(pFile1, "%d %d", &a[i][0], &a[i][1]);
    }

    for(i=0; i<m; i++)//��������
    {
        k = i;
        for(j=i; j<m; j++)
        {
            if(a[k][0] > a[j][0])
                k = j;
        }
        t=a[k][0]; a[k][0]=a[i][0]; a[i][0]=t;
        t=a[k][1]; a[k][1]=a[i][1]; a[i][1]=t;
    }
    for(i=0; i<m; i++)
    {
        if(max+a[i][1]>=n)
            break;
        else
            max += a[i][1];
    }//��ʱ��maxû�г�����i����
    for(j=0; j<i; j++)
    {
        money += a[j][0]*a[j][1];
    }
    money += (n-max)*a[i][0];
    fprintf(pFile2,"%d\n", money);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

