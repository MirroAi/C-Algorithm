#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t;t=x;x=y;y=t;}

void quicksort(int[],int,int);

int main(void)
{
	int number[MAX]={0};
	int i;
	srand(time(NULL));
	printf("����ǰ��");
	for(i=0;i<MAX;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}

	quicksort(number,0,MAX-1);
	printf("\n�����");
	for(i=0;i<MAX;i++)
		printf("%d ",number[i]);

	printf("\n");
	return 0;
}

void quicksort(int number[],int left,int right)
{
	int i,j,s;
	if(left<right)
	{
		s=number[(left+right)/2]; //���±�
		i=left-1;
		j=right+1;

		while(1)
		{
			while(number[++i]<s); //���������ұ����ģ��õ��±�i
			while(number[--j]>s); //���������ұ���С�ģ��õ��±�j
			if(i>=j)
				break; //��������±귢���˽��棬˵������С�ͱ�����Ԫ���Ѿ��ֳ���������
			SWAP(number[i],number[j]); //û��������ͽ���Ԫ�أ�ʹ����С������ߣ����������ұ�
		}

		quicksort(number,left,i-1); //�Ա���С�Ĳ��ֵ�Ԫ�ؿ�������
		quicksort(number,j+1,right); //�Ա����Ĳ��ֵ�Ԫ�ؿ������� 
	}
}