#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    FILE *fp,*fp1;
    int choice;
    char name[20],temp[20]={"Temp.txt"},c;
    printf("Press 1 to encrypt:press 2 to Decrypt");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter the filename to Encrypt:");
        scanf("%s",name);
        fp=fopen(name,"r+");
        if(fp==NULL)
        {
            printf("The file %s can't be open",name);
            getch();
            exit(0);

        }
        fp1=fopen(temp,"w+");
        if(fp1==NULL)
        {
            printf("The file temp cant be open");
            getch();
            exit(0);


        }
        c=fgetc(fp);
        while(c!=EOF)
        {
            fputc((c+name[0]),fp1);
            printf("%c",c+name[0]);
            getch();
            c=fgetc(fp);

        }
        fclose(fp);
        fclose(fp1);
        remove(name);
        rename(temp,name);
        printf("The file is Encrypted.");
        getch();
        break;
    case 2:
        printf("Enter the file name to decrypt:");
        scanf("%s",name);
        fp=fopen(name,"r+");
        fp1=fopen(temp,"w+");
        c=fgetc(fp); //gets the next character
        while(c!=EOF)
        {
            fputc(c=name[0],fp1);
            c=fgetc(fp);

        }
        fclose(fp);
        fclose(fp1);
        remove(name);
        rename(temp,name);
        printf("The file is decrypted:");
        getch();

    }
}
