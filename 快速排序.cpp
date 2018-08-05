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
	printf("排序前：");
	for(i=0;i<MAX;i++)
	{
		number[i]=rand()%100;
		printf("%d ",number[i]);
	}

	quicksort(number,0,MAX-1);
	printf("\n排序后：");
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
		s=number[(left+right)/2]; //轴下标
		i=left-1;
		j=right+1;

		while(1)
		{
			while(number[++i]<s); //从左往右找比轴大的，得到下标i
			while(number[--j]>s); //从右往左找比轴小的，得到下标j
			if(i>=j)
				break; //如果两个下标发生了交叉，说明比轴小和比轴大的元素已经分成了两部分
			SWAP(number[i],number[j]); //没发生交叉就交换元素，使比轴小的在左边，比轴大的在右边
		}

		quicksort(number,left,i-1); //对比轴小的部分的元素快速排序
		quicksort(number,j+1,right); //对比轴大的部分的元素快速排序 
	}
}