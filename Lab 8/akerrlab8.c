#include <stdio.h>
#include <string.h>
void request();
void cancel();
void list();
void names();
void groups();
char array[5][20];
char name[20];
int counter=0;
char phone[5][11];
int size[5];
int x[]={0,0,0,0,0};
int main (void)
{
	printf("What would you like to do?\n");
	printf("- Request (1) a leson\n");
	printf("- Cancel (2) a leson\n");
	printf("- List (3) the schedule\n");
	printf("- Show names (4) starting with a letter\n");
	printf("- Show groups (5) with a number of people\n");
	printf("- Quit (9)\n");
	int pick;
	int i;
	for(i=0;i<5;i++)
	{
		array[i][0]='\0';
	}
	for(;;) //this is a forever loop to keep the program running until the user quits.
	{
	scanf("%d",&pick);
	switch(pick)
	{
		case 1://this code will run if the user types in 1
		{
			request();
			break;
		}
		case 2://this code will run if the user types in 2
		{
			cancel();
			break;
		}
		case 3:///this code will run if the user types in 3
		{
			list();
			break;
		}
		case 4:
		{
			names();
			break;
		}
		case 5:
		{
			groups();
			break;
		}
		case 9://this code will run if the user types in 4
		{
			return 1;//this quits out of the program
		}
		default://this will run if the user enters anything that isn't 1,2,3,9
		{
			printf("Invalid option, try again.");
			break;
		}
	}
	}
}
void request(){
	int flag=0;
	int i;
	char phone1[20];
	int size1;
	if(counter==5)
	{
		printf("No open slots :(\n");
		return;
	}
	else
	{   
		printf("Enter your name!\n");
		scanf("%s",name);
		for(i=0;i<5;i++)
		{
			if(strcmp(array[i],name)==0)
			{
				printf("Name already used\n");
				return;
			}
			else
			{
				flag++;
			}
		}
		printf("Enter the size of your group\n");
		scanf("%d",&size1);
		if(size1>4)
		{
			printf("4 people is the limit\n");
			return;
		}
		else
		{
			flag++;
		}
		printf("Enter your phone number\n");
		scanf("%s", phone1);
		if(strlen(phone1)>11)
		{
			printf("Invalid phone number\n");
			return;
		}
		else
		{
			flag++;
		}
		if(flag!=0)
		{
			strcpy(array[counter],name);
			size[counter]=size1;
			strcpy(phone[counter],phone1);
			counter++;
		}
	}
	printf("your lesson will be at %d for %d people\n",counter,size[counter-1]);
}
void cancel(){
	int i;
	int j;
	int flag=0;
	char name2[20];
	if(counter==0)
	{
		printf("The schedule is empty\n");
	}
	else
	{
		printf("Enter the name of the lesson you wish to cancel\n");
		scanf("%s",name2);
		for(i=0;i<counter;i++)
		{
			if(strcmp(array[i],name2)==0)
			{
				array[i][0]='\0';
				counter--;
				printf("Your lesson has been canceled\n");
				for(j=i+1;j<counter+1;j++)
				{
					strcpy(array[j-1],array[j]);
					printf("%s's lesson is now at %d\n",array[j-1],j);
					strcpy(phone[j-1],phone[j]);
					size[j]=size[j-1];
				}
				array[counter][0]='\0';
				flag++;
				break;
			}
		}
		if(flag==0)
		{
			printf("Not found\n");
		}
	}
}
void list(){
	if(counter==0)//this code will run if there are no lessons yet
	{
		printf("The schedule is empty\n");
	}
	else//this code will run if there are lessons and then output the list
	{
		int i;
	printf("The class times taken today are:\n");
		for(i=0;i<5;i++)//this loop is to check which times are free and which are taken
		{
			if(array[i][0]=='\0')//this code will run if the lesson time is free
			{
				printf("%d - Free\n",i+1);
			}
			else//this code will run if the lesson time is taken
			{
				printf("%d - %s (%s) for %d people\n",i+1,array[i],phone[i],size[i]);
			}
		}
	}
}
void names(){
	char letter;
	int i;
	int flag;
	if(counter==0)
	{
		printf("The schedule is empty\n");
	}
	else
	{
		printf("Enter the first letter of the name that your lesson is under\n");
		scanf(" %c",&letter);
		for(i=0;i<counter;i++)
		{
			if(array[i][0]==letter)
			{
				printf("%s for %d people\n",array[i],size[i]);
				flag++;
			}
		}
		if(flag==0)
		{
			printf("Not found");
		}
	}
}
void groups(){
	int size1;
	int i;
	int flag;
	if(counter==0)
	{
		printf("The schedule is empty\n");
	}
	else
	{
		printf("Enter size of group (1-4)\n");
		scanf("%d",&size1);
		for(i=0;i<5;i++)
		{
			if(size1==size[i])
			{
				printf("%d people for %s\n",size[i],array[i]);
				flag++;
			}
		}
		if(flag==0)
		{
			printf("Not Found\n");
		}
	}
}
