#include<stdio.h>
#include<string.h>

void main()
{
	FILE *f1,*f2; //f1 refers IA32 file and f2 refers IA64 code file
	char ch;
	char s[50];	
	int i;
	f1=fopen("IA_32.asm","r");
	if(f1==NULL)
		printf("Source File Does not exist");
	f2=fopen("IA_64.asm","w");
	
	while((ch=fgetc(f1))!=EOF)
	{
		i=0;
		strcpy(s,"\0");

		while(ch!=' '&&ch!='\n')
		{
	
			s[i++]=ch;
			ch=fgetc(f1);
		}

		if(ch==' '||ch=='\n')
		{
			s[i]='\0';
		}
		if(strcmp(s,"pushl")==0)
			strcpy(s,"pushq");
		if(strcmp(s,"subl")==0)
			strcpy(s,"subq");
		if(strcmp(s,"%ebp")==0)
			strcpy(s,"%rbp");
		if(strcmp(s,"%esp,")==0)
			strcpy(s,"%rsp,");
		if(strcmp(s,"%esp")==0)
			strcpy(s,"%rsp");
		if(strcmp(s,"5")==0)
			strcpy(s,"6");

		if(strcmp(s,"8")==0)
			strcpy(s,"16");
		if(strcmp(s,"5,")==0)
			strcpy(s,"6,");
		if(strcmp(s,"-8")==0)
			strcpy(s,"-16");
		if(strcmp(s,"4,")==0)
			strcpy(s,"7");
		if(strcmp(s,"4")==0)
			strcpy(s,"5");
		
		fputs(s,f2);
		if(ch==' '||ch=='\n')
		{
			fputc(ch,f2);
		}
		
	}
	fclose(f1);
	fclose(f2);
	printf("\n Traslation of IA32 to IA64 done successfully\n");
}

	
