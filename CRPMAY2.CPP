#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void main()
{
FILE *fp1,*fp;
int choice;
char name[20],tmp[20]={"tmp.txt"},text[500],c;


lable1: printf("\n 1.press 1 to encrypt \n 2.press 2 to decrypt \n press 3 to exit \n 4. enter 4 to create a file \n enter your choice: ");
scanf("%d",&choice);

switch(choice)
	{
	 case 1:
		printf("\n ener the filename:\t");
		scanf("%s",name);
		fp=fopen(name,"r+");
		if(fp==NULL)
			{
			printf("\n the file cannot be opened.");

			}
		else
			{


			c=fgetc(fp);
			printf("\n the cipher text are:\n");
			while(c!=EOF)
				{
				 fputc(c+name[0],fp);
				 printf("%c",c+name[0]);

				}

			}
		fclose(fp);
		fclose(fp1);
		break;
	 case 2:
		printf("\n enter the filename to decrypt:");
		scanf("%s",name);
		fp=fopen(name,"r+");
		fp1=fopen(name,"w+");
		c=fgetc(fp);
		while(c!=EOF)
			{
			fputc(c-name[0],fp1);
			c=fgetc(fp);
			}
		fclose(fp);
		fclose(fp1);
		remove(name);
		rename(tmp,name);
		printf("\n the file is decrypted:");
		fp=fopen(name,"r");
		c=fgetc(fp);
		while(c!=EOF)
			{
			fputc(c-name[0],fp1);
			c=fgetc(fp);
			}
		fclose(fp);
		break;
	case 3:
		printf("\n you chose to exit.\n press 'enter'.");
		getch();
		exit(0);
		break;
	case 4:
		fp=fopen(name,"w+");
		printf("\n enter your text:\n");
		scanf("%s",text);
		int i=0;
		while(c!='\0')
			{
			c=text[i];
			fputc(c,fp);
			i++;
			}
		break;

	default:
		printf("\n default exit.");
		getch();
		break;
	}
	goto lable1;
	getch();

}
