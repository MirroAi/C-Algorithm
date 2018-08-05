#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t;t=x,x=y;y=t;}

void quicksort(int[],int,int);
int bisearch(int[],int);

int main(void)
{
	int number[MAX]={0};
	int i,find;
	srand(time(NULL));

	for(i=0;i<MAX;i++)
		number[i]=rand()%100;

	quicksort(number,0,MAX-1);

	printf("���У�");
	for(i=0;i<MAX;i++)
		printf("%d ",number[i]);

	printf("\n����Ѱ�Ҷ���");
	scanf("%d",&find);

	if((i=bisearch(number,find))>=0)
		printf("�ҵ����������� %d",i);
	else
		printf("�Ҳ���ָ����");

	printf("\n");

	return 0;
}

int bisearch(int number[],int find)
{
	int low,mid,upper;

	low=0;
	upper=MAX-1;

	while(low<=upper)
	{
		mid=(low+upper)/2;
		if(number[mid]<find)
			low=mid+1;
		else if(number[mid]>find)
			upper=mid-1;
		else
			return mid;
	}

	return -1;
}

void quicksort(int number[],int left,int right)
{
	int i,j,s;

	if(left<right)
	{
		s=number[(left+right)/2];
		i=left-1;
		j=right+1;

		while(1)
		{
			while(number[++i]<s); //Ϊ��ʡ�£��Ű�i��left-1����Ȼ�������Ҫд��while(number[i]<s){i++;}
			while(number[--j]>s);
			if(i>=j)
				break;
			SWAP(number[i],number[j]);
		}

		quicksort(number,left,i-1);
		quicksort(number,j+1,right);
	}
}

