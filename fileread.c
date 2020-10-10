#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct restaurant { 
    int num,q1,q2,q3,q,q5; 
    char name[20];
}; 
void ReadFile(FILE *fp,int question);
 // Function which will read the file content
int main()
{		
	char file_name[11] ="test.csv";
	FILE *fp; //file pointer poiting to file
	printf("Welcome to the Restaurant recommendation System\n");
    fp=fopen(file_name, "r"); //buffer created(file information)
    if(fp == NULL) //empty file
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    ReadFile(fp,1);
    fclose(fp);
    return 0;
}
int userinput()
{
	printf("");
}

void ReadFile(FILE *fp,int question)
{
	int x = 0,a,b,i=0,size,j=0; // i taking count of total restaurant,a used for temp, x sis used for temp
	char temp[50],name[1000][1000];
	char userinput;
	char *vartemp;
	char ch;
	printf("Question:1-According to you the restaurant must have a pre booking facility?\nif must then enter 1 else 0\n");
	scanf("%s",&userinput);
	while((ch = fgetc(fp))!=EOF) //reading file 
    {	
    	if(ch == ';')
    	{
    		a=0;
    		j=0;
    		printf("\n");
    		for(a;a<x;a++)
    		{
    			temp[a]=0;	
			}
			x=0;
			i++;
		}
		else if(ch==',')
    	{	
    	if(j == 0)
    	{
    		printf("%s\n",temp);
		}
    	if(j == 1)
    	{
    		printf("ques 1 :%s\n",temp);
    		if(userinput == temp)
    		{
    			printf("in");
			}
		}
    		a=0;
			vartemp = temp;
    		for(a;a<x;a++)
    		{		
       			temp[a]=0;
			}
			j++;
			x=0;
		}
		else{
			temp[x]=ch;
			x++;
		}
	}
};
