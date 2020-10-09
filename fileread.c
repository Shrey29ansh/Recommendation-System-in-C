#include<stdio.h>
#include<stdlib.h>
int main()
{	
	char temp[1000],name[1000][1000];
	int x = 0,a=0,b=0,i=0,size;
	char ch, file_name[25];
	FILE *fp; //file pointer poiting to file
	printf("Enter fil name\n"); 
    gets(file_name); //getting name of file
    fp=fopen(file_name, "r"); //buffer created(file information)
    if(fp == NULL) //empty file
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    printf("the file:%s\n",file_name);
    while((ch = fgetc(fp))!=EOF) //reading file 
    {
    	if(ch==',')
    	{	
    	a=0;
    		printf("%s\n",temp);
    		for(a;a<x;a++)
    		{
    			temp[a]=0;
    			
			}
			x=0;
		}
		else if(ch == ';')
    	{
    		a=0;
    		printf("\n");
    		for(a;a<x;a++)
    		{
    			temp[a]=0;
    			
			}
			x=0;
		}
		else{
			temp[x]=ch;
			x++;
		}
	}
    fclose(fp);
    return 0;
}
