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



struct finalrestaurant finalrestaurants[10];
struct restaurantdata restaurant[10];	
int nextques;

void Probability(int remaining,int total)
{
	float probablity;
	probablity = (float)remaining/total *100;
	printf("\nProbablity of restaurants:%f percent\n",probablity);
};

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
    		for(a=0;a<x;a++)
    		{
    			temp[a]=0;	
			}
			x=0;
			j=0;
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
					sscanf(p,"%d",&finalrestaurants[count].ques[j-1]); //typecasting
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
				sscanf(m,"%d",&finalrestaurants[pos].ques[j-1]); //typecasting
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

int InputNum()
{
	int inputnum;
	printf("\nEnter your choice\nFor Yes choose 1 else choose 0\n");
	scanf("%d",&inputnum);
	return inputnum;
};

int NextQuestion(int quesno,int count)
{
	int nextcount;

	int i,j;
	if(quesno == 2)
	{
		int input;
		printf("\nQuestion-2");
		input = InputNum();
		nextcount = SortingQuestions(quesno,input,count);
		
	}
	if(quesno == 3)
	{
			int input;
		printf("\nQuestion-3");
		input = InputNum();
		nextcount = SortingQuestions(quesno,input,count);
;
	}
	if(quesno == 4)
	{
			int input;
		printf("\nQuestion-4");
		input = InputNum();
		nextcount = SortingQuestions(quesno,input,count);
		
	}
 	if(quesno == 5)
	{
		int input;
		printf("\nQuestion-5");
		input = InputNum();
		nextcount = SortingQuestions(quesno,input,count);

	}
		return nextcount;
};



int SortingQuestions(int quesno,int finalinput,int count)
{
	int nextcount=0;
	int loop;
	int i,j;
	nextcount= count;
	for(loop = 0; loop<count;loop++)
	{
		if(loop != count-1)
		{
			//printf("%d",finalrestaurants[loop].ques[quesno-1]);
			if(finalinput != finalrestaurants[loop].ques[quesno-1])
			{
					nextcount--;
					strcpy(finalrestaurants[loop].name,finalrestaurants[loop+1].name);
					for(i=0;i<5;i++)
					{
						finalrestaurants[loop].ques[i]=finalrestaurants[loop+1].ques[i];
					}
			}
			
		}	
		else
		{
			if(finalinput != finalrestaurants[loop].ques[quesno-1])
			{
				nextcount--;
				for(i=0;i<5;i++)
					{
						finalrestaurants[loop+1].ques[i]=finalrestaurants[loop].ques[i];
					}
				
			}
		}
	}
	for(i=0;i<nextcount;i++)
    	{
    		printf("%s",finalrestaurants[i].name);	
		}
	return nextcount;
};
int main()
{		
	char file_Allname[11] ="test.csv";
	int count;	
	int i,j,quesloop;
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
    for(quesloop=2;quesloop<6;quesloop++)
	{
		count = NextQuestion(quesloop,count);

	}
    return 0;
};
