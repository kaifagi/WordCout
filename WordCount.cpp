#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define maxsize 1000



int count(char a[2],FILE* fp)
{
	char ch;
	int k=0;
	int word=0;
	int i=0;
	int sum_zifu=0;
	int sum_danci=0;
	int b[maxsize][2];//ǰ���[]�д����k+1�У�[]��0�洢�ַ�����[]�д洢������
	fscanf(fp,"%c",&ch);
	while(!feof(fp))
	{
		if(ch=='\n')
		{
			b[k][0]+=1;
			word=0;
			k++;
		
		}
		else if(ch==' '||ch=='\t')
		{
			b[k][0]+=1;
			word=0;
		}
		else
		{
			b[k][0]+=1;
			if(!isalpha(ch))//isaplha()�����ж�ch�Ƿ�Ϊ��ĸ
			{
				word=0;
			}
			else if(word==0)//��һ���ַ�������ĸ������ַ�����ĸ
			{
				b[k][1]+=1;
				word=1;
			}
		}
		fscanf(fp,"%c",&ch);
	}
	fclose(fp);
	for(i=0;i<k+1;i++)
	{
		sum_zifu+=b[k][0];
		sum_danci+=b[k][1];

	}
	if(strcmp(a,"-c")==0)
		return sum_zifu;
	if(strcmp(a,"-w")==0)
		return sum_danci;
	return 0;
}
int main()
{
	int shu=0;
	int a[maxsize][2]={0};
	char fileName[100];
	char c[2];
	FILE* fp=NULL;
	scanf("%s %s",c,fileName);
	getchar();
	fp=fopen(fileName,"r");
/*	if(fp == NULL)
	{
		return 0;

	}*/
	shu=count(c,fp);
	if(strcmp(c,"-c")==0)
		printf("�ַ����� %d\n",shu);
	if(strcmp(c,"-w")==0)
		printf("�������� %d\n",shu-2);
	return 0;
}
