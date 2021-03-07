#include <stdio.h>
#include <string.h>
int main (void)
{
	char array[5][20];
	int pick;
	char name[20];
	char name2[20];
	int counter=0;
	int x[]={0,0,0,0,0};
	printf("What would you like to do?\n");
	printf("- Request (1) a leson\n");
	printf("- Cancel (2) a leson\n");
	printf("- List (3) the schedule\n");
	printf("- Show names (4) starting with a letter\n");
	printf("- Quit (9)\n");
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
			if(counter==5)
			{
				printf("No open slots :(");
				break;
			}
			else
			{
				printf("Enter your name!");
				scanf("%s",name);
				strcpy(array[counter],name);
				counter++;
			}
			printf("your lesson will be at %d",counter);
			break;
		}
		case 2://this code will run if the user types in 2
		{
			int i;
			int j;
			int flag=0;
			if(counter==0)
			{
				printf("The schedule is empty");
			}
			else
			{
				printf("Enter the name of the lesson you wish to cancel.");
				scanf("%s",name2);
				for(i=0;i<counter;i++)
				{
					if(strcmp(array[i],name2)==0)
					{
						array[i][0]='\0';
						counter--;
						for(j=i+1;j<5;j++)
						{
							strcpy(array[j-1],array[j]);
						}
							printf("your lesson has been canceled");
							array[counter][0]='\0';
							flag++;
							break;
					}
				}
				if(flag==0)
				{
					printf("Not found");
				}
			}
			break;
		}
		case 3:///this code will run if the user types in 3
		{
			if(counter==0)//this code will run if there are no lessons yet
			{
				printf("The schedule is empty");
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
						printf("%d - %s\n",i+1,array[i]);
					}
				}
			}
			break;
		}
		case 4:
		{
			char letter;
			int i;
			int flag;
			if(counter==0)
			{
				printf("The schedule is empty");
			}
			else
			{
				printf("Enter the first letter of the name that your lesson is under");
				scanf(" %c",&letter);
				for(i=0;i<counter;i++)
				{
					if(array[i][0]==letter)
					{
						printf("%s\n",array[i]);
						flag++;
					}
				}
				if(flag==0)
				{
					printf("Not found");
				}
			}
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
