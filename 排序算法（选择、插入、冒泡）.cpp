#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x,y) {int t;t=x;x=y;y=t;}

void selsort(int[]); //ѡ������
void insort(int[]); //��������
void bubsort(int[]); //ð������

int main(void)
{
	int number[MAX]={0};
	int i;

	srand(time(NULL));

	printf("����ǰ��");
	for(i=0;i<MAX;i++)
	{
		number[i]=rand()%100; //�������10��100���ڵ���Ȼ��
		printf("%d ",number[i]);
	}

	printf("\n��ѡ������ʽ��\n1.ѡ������\n2.��������\n3.ð������\n");
	
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
		printf("ѡ�����\n");
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
				m=j; //�뵱ǰԪ����ȣ��ҵ���СԪ�ص��±�

		if(i!=m)
			SWAP(number[i],number[m]) //ʹ��ǰԪ�س�Ϊ��СԪ�� ��С����

		printf("�� %d ������",i+1);
		for(k=0;k<MAX;k++)
			printf("%d ",number[k]);
		printf("\n");
	}
}

void insort(int number[])
{
	int i,j,k,tmp;

	for(j=1;j<MAX;j++) //�ӵ�2��Ԫ�ؿ�ʼ
	{
		tmp=number[j];
		i=j-1;
		while(tmp<number[i]) //��ǰԪ����֮ǰ����Ԫ��(����)�Ƚϣ������ǰԪ��С��֮ǰԪ�أ�֮ǰԪ�ؾ����κ��ƣ������˳�ѭ��
		{
			number[i+1]=number[i];
			i--;
			if(i==-1)
				break;
		}
		number[i+1]=tmp; //�ѵ�ǰԪ�ذ���Ž�ǰһ����(����)

		printf("�� %d ������",j);
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
		flag=0; //flag�����Ƿ��������ѭ��
		for(j=0;j<MAX-i-1;j++) //�����Ԫ��������ģ���ǰԪ��number[j]�������һԪ��(������ǰ�����򲿷�)�Ƚ�
		{
			if(number[j+1]<number[j])
			{
				SWAP(number[j+1],number[j]);
				flag=1; //flagֵ�ı仯ֻ�����Ƿ�����������󼸴��������û�н����κ�Ԫ������ǰ��ֹ
			}
		}

		printf("�� %d ������",i+1);
		for(k=0;k<MAX;k++)
			printf("%d ",number[k]);
		printf("\n");
	}
}


