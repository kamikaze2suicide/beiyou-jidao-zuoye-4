#include<stdio.h>
#include<stdlib.h>
void copyFilechuzhushi(char * sourceFileName, char * destFileName)
{
	char ch1,ch2,chTemp,s[1000];
	FILE * sourcefPtr,*destfPtr;
	
	if((sourcefPtr=fopen(sourceFileName,"r"))==NULL)
		printf("can't open the source file\n");
	else if((destfPtr=fopen(destFileName,"w"))==NULL)
		printf("can't open the dest file\n");
	else
	{
		ch1=fgetc(sourcefPtr);//��Դ�ļ���ȡһ��du�ַ�
		while(!feof(sourcefPtr))
		{//����zhi������
			if('/' == ch1)
			{
				ch2 = ch1;
				ch1 = fgetc(sourcefPtr);
				if ('/' == ch1 || '*' == ch1)
				{
					fseek(sourcefPtr,-2,SEEK_CUR);
					fgets(s,sizeof(s),sourcefPtr);
					ch1=fgetc(sourcefPtr);
					puts(s);//��ӡע�ͣ��Ա����???
				}
				else
				{
					fputc(ch2,destfPtr);
				}
			}
			else
			{
				fputc(ch1,destfPtr); //���ַ�д��Ŀ���ļ�
				ch1=fgetc(sourcefPtr);
			}
		}
		fclose(sourcefPtr);
		fclose(destfPtr);
	}
}

int main()
{
	copyFilechuzhushi("1.c","2.c");
	system("pause");
	return 0;
}
