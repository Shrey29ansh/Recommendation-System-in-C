#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h> 

struct restaurantdata { 
    char Allname[50];
};

struct finalrestaurant { 
    char name[50];
    char ques[5];
};


struct restaurantdata restaurant[6];	
struct finalrestaurant finalrestaurants[];
int nextques;

int main()
{		
	char file_Allname[11] ="test.csv";
	int count;	
	int i,j;
	FILE *fp; //file pointer poiting to file
	printf("Welcome to the Restaurant recommendation System\n");
    fp=fopen(file_Allname, "r"); //buffer created(file information)
    if(fp == NULL) //empty file
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    count = ReadFile(fp,1);
    fclose(fp);
	NextQuestion(2,count);
    return 0;
}

int ReadFile(FILE *fp,int question)
{
	int count=0,x = 0,a=0,b=0,i=0,j=0,l=0,k=0; // i taking count of total restaurant,a used for temp, x sis used for temp
	char temp[50],userinput[5];
	char ch;
	int pos=1; // for the struct questions
	bool choice=false;
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
				strcpy(restaurant[i].Allname,s); // in c langauge strings are stored as array.
			}
    		else
    		if (j==1)
			{
    			char *p;
				p=temp;
				if(*userinput==*p)
				{		
					choice = true;
					pos =count;
					strcpy(finalrestaurants[count].name,restaurant[i].Allname);
					finalrestaurants[count].ques[j-1] = *p;
					count++;
					}
					else{
						choice = false;
					}
			}
			if(choice)
    		{
    			char *m;
				m=temp;	
				finalrestaurants[pos].ques[j-1] = *m;
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
	Probability(count,i);
	printf("Choose an option\n1.Show List of Restaurants\n2.Proceed to Next Question\n");
	scanf("%d",&nextques);
	if(nextques == 1)
	{		
    	for(i=0;i<count;i++)
    	{
    		printf("%s",finalrestaurants[i].name);	
		}
	}
	return count;
};

void Probability(int remaining,int total)
{
	float probablity;
	probablity = (float)remaining/total *100;
	printf("\nProbablity of restaurants:%f percent\n",probablity);
} 

void NextQuestion(int quesno,int count)
{
	int input;
	int i,j;
	if(quesno == 2)
	{
		printf("Question-2");
		input = Input();
		printf("%d",input);		
	}
if(quesno == 3)
	{
		printf("Question-3");
	}
if(quesno == 4)
	{
		printf("Question-4");
	}
 if(quesno == 5)
	{
		printf("Question-5");
	}

	
}

void Input()
{
	int input;
	printf("\nEnter your choice\nFor Yes choose 1 else choose 0\n");
	scanf("%d",&input);
	return input;
}
