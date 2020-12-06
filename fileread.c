#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h> 

struct restaurantdata { 
    char Allname[50]; // temp struct to keep track of the restaurant name and futher used in userdata.
	int occurence; // how many times a particular restaurant appeared in total 
	
};

struct finalrestaurant { 
    char name[50]; //name of that restaurant
    int ques[5]; // question's impressions
}; //this struct holds the data for each restaurant loaded from test.csv file

struct userdata {
	int userdataques[5]; // the dummy data already loaded from user.cs
	struct restaurantdata recommend[10]; //holds the restaurant data that can be recommended.
	int recommend_number; // tracks the number of total restaurants per user.
}; // this structure holds the data of recorded users not the current user.


struct restaurantdata recommend[96]; //this is the final recommendation list 
struct userdata finaluserdata[96]; //loaded from user.csv
struct finalrestaurant finalrestaurants[96]; //loaded from test.csv
struct restaurantdata restaurant[96]; // temp data for test.csv 
int nextques,recpos=0,usrnum,usercount=0,totalfirstrecommend; //to track the usernumber loaded from user.csv
	


void Probability(int remaining,int total)
{
	float probablity;
	probablity = (float)remaining/total *100;
	printf("%f percent\n",probablity);
};

void removeDuplicates()
{
	int j,i,k;
	for(j=0;j<recpos;j++) //remove duplicates
	{
		for(i=j+1;i<recpos;)
		{
			int result=0;
			result = strcmp(recommend[j].Allname,recommend[i].Allname);
			if(result == 0)
			{	
				for(k = i; k < recpos; k++)
					strcpy(recommend[k].Allname,recommend[k+1].Allname);
				recpos--;
				recommend[j].occurence = recommend[j].occurence+1;
			}
			else
				i++;
		}
	}
};

void PrintStatement(int ContentFiltersize)
{
	int i,j;
	printf("\nProbablity of restaurants by Content Filtering:");
	Probability(ContentFiltersize,96);
	printf("\nProbablity of restaurants by Collaberative Filtering:");
	Probability(recpos,totalfirstrecommend);
	nextques=1;	
	while (nextques!=3)	
	{
		printf("\nChoose an option\n1.Content Filtering\n2.Collaberative Filtering\n3.Proceed to Next Question\n");
		scanf("%d",&nextques);
		if(nextques == 1)
		{		
			printf("\nContent Filtering\n");
			for(i=0;i<ContentFiltersize;i++)
				printf("%s",finalrestaurants[i].name);
		}
		else if(nextques == 2)
		{
			printf("\n\nCollebarative Filtering\n\n");
			if (recpos==0)
			{
				printf("Sorry :(, No Recommendations Found!");
			}
			for(j=0;j<recpos;j++)
				printf("%d.%s ",j+1,recommend[j].Allname);
		}
		else
			break;
		
	} 
}

int ReadFile(FILE *fp,FILE *fpp,int question)
{	
	int userdatapos=1,count=0,x = 0,a=0,b=0,i=0,j=0,l=0,k=0; // i taking count of total restaurant,a used for temp, x sis used for temp
	char temp[50],userinput[5];
	char ch;
	int pos=1; // for the struct questions
	bool choice=false;
	bool userchoice=false;
	printf("\nHow much you are concerned about the fact that a restaurant should be certified by some COVID-19 certification company?\n");
	printf("Enter your choice\nFor Yes choose 1 else choose 0\n");
	gets(userinput);
	while((ch = fgetc(fp))!=EOF) //reading file 
    {	
    	if(ch == ';')
    	{
			if(choice) //for last question because there is no comma there is semicolon
    		{
    			char *m;
				m=temp;	
				sscanf(m,"%d",&finalrestaurants[pos].ques[j-1]); //typecasting
			}	
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
					pos =count; //pos is basically defining the position of the current restaurant
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
	while((ch = fgetc(fpp))!=EOF) //reading file 
    {	
        if(ch == '/')
        {
            char *s;
			s=temp;
            sscanf(s,"%d",&usrnum);
            x=0;
        }
    	if(ch == ';')
    	{	
			if(userchoice)
    		{
				//printf("%d\n",recpos);
				finaluserdata[userdatapos].recommend_number=j-5;
				//1printf("%d",finaluserdata[userdatapos].recommend_number);
				char *s;
				s=temp;
				strcpy(finaluserdata[userdatapos].recommend[j-6].Allname,s);
				strcpy(recommend[recpos].Allname,finaluserdata[userdatapos].recommend[j-6].Allname);
				recommend[recpos].occurence = 0;
				recpos++;
			}
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
    		if (j==1)
			{
    			char *q;
				q=temp;
				if(*userinput==*q)
				{		
					userchoice = true;
					userdatapos =usercount;
					sscanf(q,"%d",&finaluserdata[usercount].userdataques[j-1]); //typecasting
					usercount++;
					}
					else{
						userchoice = false;
					}
			}
			if(j>5)
			{
				if(userchoice)
				{
					//printf("%d\n",recpos);
					finaluserdata[userdatapos].recommend_number=j-5;
					char *s;
					s=temp;
					strcpy(finaluserdata[userdatapos].recommend[j-6].Allname,s);
					strcpy(recommend[recpos].Allname,finaluserdata[userdatapos].recommend[j-6].Allname);
					recommend[recpos].occurence = 0;
					recpos++;
				}
			}
			if(userchoice)
    		{
    			char *k;
			    k=temp;	
				sscanf(k,"%d",&finaluserdata[userdatapos].userdataques[j-1]); //typecasting
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
	removeDuplicates();
	totalfirstrecommend = recpos;
	PrintStatement(count);
	return count;
};


int InputNum()
{
	int inputnum;
	printf("\nEnter your choice\nFor Yes choose 1 else choose 0\n");
	scanf("%d",&inputnum);
	return inputnum;
};



int SortInput(int finalinput,int size,int quesno) //content filter
{
	int loopcount=0,j;
	while (loopcount<size)
	{
		if (finalinput != finalrestaurants[loopcount].ques[quesno-1])
		{
			size =size-1;
			for(int j=loopcount;j<size;j++)
				finalrestaurants[j]=finalrestaurants[j+1];
		}
		else
			loopcount++;
	}
	return size;
};


int SortRecommendInput(int size,int finalinput,int quesno) //collaberative
{
	int i,loopcount=0,j;
	while (loopcount<size)
	{
		if (finalinput != finaluserdata[loopcount].userdataques[quesno-1])
		{
			size =size-1;
			for(int j=loopcount;j<size;j++)
				finaluserdata[j]=finaluserdata[j+1];
		}
		else
			loopcount++;
	}
	return size;
};


void RecommendationList()
{	
	int i,j;
	recpos=0;
	for(i=0;i<usercount;i++)
	{
		for(j=0;j<finaluserdata[i].recommend_number;j++)
		{
				strcpy(recommend[recpos].Allname,finaluserdata[i].recommend[j].Allname);
				recpos++;
				//printf("%s\n",finaluserdata[i].recommend[j].Allname);
		}
	}
	removeDuplicates();
};

int SortingQuestions(int quesno,int finalinput,int count)
{
	int nextcount;
	int i,j;
	nextcount = SortInput(finalinput,count,quesno); //content
	usercount = SortRecommendInput(usercount,finalinput,quesno); //Collaberative
	RecommendationList();
	PrintStatement(nextcount);
	return nextcount;
};


int NextQuestion(int quesno,int count)
{
	int nextcount;
	int i,j;
	if(quesno == 2)
		printf("\n\nQuestion - 2 :The restaurant must have an option of 'No Contact delivery'?\n");
	if(quesno == 3)
		printf("\n\nQuestion - 3 :Do you want a regular temperature check of the restaurant staff be performed?\n");
	if(quesno == 4)
		printf("\n\nQuestion - 4 :Do you want to reserve your seat with the restaurant beforehand if you want to visit the place\n");
 	if(quesno == 5)
		printf("\n\nQuestion - 5 :Do you want the restaurant to have disposable plates as an option?\n");
	int input;
	input = InputNum();
	nextcount = SortingQuestions(quesno,input,count);
	return nextcount;
};



int main()
{		
	char Restaurant_file[11] ="test.csv";
	char Userdata_file[11] ="user.csv";
	int count;	
	int i,j,quesloop;
	FILE *fp; //file pointer poiting to file
	printf("Welcome to the Restaurant recommendation System\nThis System will help you to get your desired Restaurant\n");
	printf("For Yes Choose 1 and for No Choose 0");
    fp=fopen(Restaurant_file, "r"); //buffer created(file information)
    if(fp == NULL) //empty file
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
	FILE *fpp; //file pointer poiting to file
    fpp=fopen(Userdata_file, "r"); //buffer created(file information)
    if(fpp == NULL) //empty file
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    count = ReadFile(fp,fpp,1);
    fclose(fp);
    for(quesloop=2;quesloop<6;quesloop++)
	{
		count = NextQuestion(quesloop,count);
	}
    return 0;
};
