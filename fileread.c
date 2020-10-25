#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct restaurantdata { 
    char Allname[50];
};

struct finalrestaurant { 
    char name[50];
    char ques[5];
};

int ReadfirstFile(FILE *fp,int question);
struct restaurantdata restaurant[6];	
struct finalrestaurant finalrestaurants[6];
 // Function which will read the file content
int main()
{		
	char file_Allname[11] ="test.csv";
	struct finalrestaurant s;
	int count;	
	int i;
	FILE *fp; //file pointer poiting to file
	printf("Welcome to the Restaurant recommendation System\n");
    fp=fopen(file_Allname, "r"); //buffer created(file information)
    if(fp == NULL) //empty file
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    count = ReadfirstFile(fp,1);
    for(i=0;i<count;i++)
    {
    	printf("%s",finalrestaurants[i].ques[0]);
	}
    /*ReadFile(fp,2);
    ReadFile(fp,3);
    ReadFile(fp,4);
    ReadFile(fp,5);*/
    fclose(fp);
    return 0;
}

int ReadfirstFile(FILE *fp,int question)
{
	int count=0,x = 0,a=0,b=0,i=0,j=0,l=0,k=0; // i taking count of total restaurant,a used for temp, x sis used for temp
	char temp[50],userinput[5];
	char ch;

	printf("%d",question);
	if(question == 1)
	{
		printf("\nQuestion:1-z\n");
	}
		printf("Enter your choice\nFor Yes choose 1 else choose 0\n");
	gets(userinput);
	while((ch = fgetc(fp))!=EOF) //reading file 
    {	
    	if(ch == ';')
    	{
    		a=0;
    		j=0;
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
    			char *s;
				s=temp;
				strcpy(restaurant[i].Allname,s);
			}
    		else
    		if (j==1){
    			char *p;
				p=temp;
				if(*userinput==*p)
				{					
					strcpy(finalrestaurants[count].name,restaurant[i].Allname);
					finalrestaurants[count].ques[j-1] = *p;
					count++;
				}
			}
			
    		a=0;
    		
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
	float probablity;
	probablity = (float)count/i *100;
	printf("\nProbablity of restaurants:%f percent\n",probablity);
	return count;
};

/*

	else 
	if(question == 2)
	{
		printf("Question:2-According to you the restaurant must have a pre booking facility?\nif must then enter 1 else 0\n");
	}
	else 
	if(question == 3)
	{
		printf("Question:3-According to you the restaurant must have a pre booking facility?\nif must then enter 1 else 0\n");
	}
	else 
	if(question == 4)
	{
		printf("Question:4-According to you the restaurant must have a pre booking facility?\nif must then enter 1 else 0\n");
	}
	else 
	if(question == 5)
	{
		printf("Question:5-According to you the restaurant must have a pre booking facility?\nif must then enter 1 else 0\n");
	}
	
	
char *s;
s=temp;
printf("ques 1 :%s\n",s);
if(*userinput==*s)
{
printf("in");
}
				
				
*/
