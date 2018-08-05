#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t;t=x;x=y;y=t;}

void selsort(int[]); //选择排序
void insort(int[]); //插入排序
void bubsort(int[]); //冒泡排序

int main(void)
{
	int number[MAX]={0};
	int i;

	srand(time(NULL));

	printf("排序前：");
	for(i=0;i<MAX;i++)
	{
		number[i]=rand()%100; //随机生成10个100以内的自然数
		printf("%d ",number[i]);
	}

	printf("\n请选择排序方式：\n1.选择排序\n2.插入排序\n3.冒泡排序\n");
	
	scanf("%d",&i);

	switch(i)
	{
	case 1:
		selsort(number);break;
	case 2:
		insort(number);break;
	case 3:
		bubsort(number);break;
	default:
		printf("选项错误\n");
	}

	return 0;
}

void selsort(int number[])
{
	int i,j,k,m;

	for(i=0;i<MAX-1;i++)
	{
		m=i;
		for(j=i+1;j<MAX;j++)
			if(number[j]<number[m])
				m=j; //与当前元素相比，找到最小元素的下标

		if(i!=m)
			SWAP(number[i],number[m]) //使当前元素成为最小元素 从小到大

		printf("第 %d 次排序：",i+1);
		for(k=0;k<MAX;k++)
			printf("%d ",number[k]);
		printf("\n");
	}
}

void insort(int number[])
{
	int i,j,k,tmp;

	for(j=1;j<MAX;j++) //从第2个元素开始
	{
		tmp=number[j];
		i=j-1;
		while(tmp<number[i]) //当前元素与之前所有元素(逆序)比较，如果当前元素小于之前元素，之前元素就依次后移；否则退出循环
		{
			number[i+1]=number[i];
			i--;
			if(i==-1)
				break;
		}
		number[i+1]=tmp; //把当前元素按序放进前一部分(有序)

		printf("第 %d 次排序：",j);
		for(k=0;k<MAX;k++)
			printf("%d ",number[k]);
		printf("\n");
	}
}

void bubsort(int number[])
{
	int i,j,k,flag=1;

	for(i=0;i<MAX-1&&flag==1;i++)
	{
		flag=0; //flag控制是否结束本次循环
		for(j=0;j<MAX-i-1;j++) //后面的元素是有序的，当前元素number[j]都是与后一元素(均属于前面无序部分)比较
		{
			if(number[j+1]<number[j])
			{
				SWAP(number[j+1],number[j]);
				flag=1; //flag值的变化只代表是否发生交换，最后几次排序如果没有交换任何元素则提前终止
			}
		}

		printf("第 %d 次排序：",i+1);
		for(k=0;k<MAX;k++)
			printf("%d ",number[k]);
		printf("\n");
	}
}


