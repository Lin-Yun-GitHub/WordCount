#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
	FILE *fp;
	int CharCount=0;
	int WordCount=0;
	char ch;
	
	//CharCount
	if((fp=fopen("F:\\LY\\WordCount\\input.txt","r"))==NULL)
	{
		printf("There is not file\n");
		exit(0);
	}
	if(strcmp("-c",argv[1])==0)
	{
		ch=fgetc(fp);
		while(ch!=EOF)
		{
			CharCount++;
			ch=fgetc(fp);
		}
		printf("×Ö·ûÊý£º%d\n",CharCount);
	}
	fclose(fp);
	
	//WordCount
	fp=fopen("F:\\LY\\WordCount\\input.txt","r");
	if(strcmp("-w",argv[1])==0)
	{
		ch=fgetc(fp);
		while(ch!=EOF)
		{
			while(ch==' '||ch==',')
			{
				ch=fgetc(fp);
			}
			while((ch>'A' && ch<'Z')||(ch>'a' && ch<'z'))
			{
				ch=fgetc(fp);
			}
			if(ch==' '||ch==','||ch==EOF)
			{
				WordCount++;
			}	
			ch=fgetc(fp);
		}
		printf("µ¥´ÊÊý£º%d\n",WordCount);
	}
	fclose(fp);
	return 0;
}