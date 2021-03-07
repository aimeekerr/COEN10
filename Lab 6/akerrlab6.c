#include <stdio.h>
int main (void)
{
	int pick;
	int counter;
	int x[]={0,0,0,0,0};
	printf("What would you like to do?\n");
	printf("- Request (1) a leson\n");
	printf("- Cancel (2) a leson\n");
	printf("- List (3) the schedule\n");
	printf("- Quit (9)\n");
	for(;;) //this is a forever loop to keep the program running until the user quits.
	{
	scanf("%d",&pick);
		if(pick==1)//this code will run if the user types in 1
		{
			int i;
			for(i=0;i<5;i++)//this loop is to see which lessons are available
			{
				if(x[i]==0)//if the lesson is open this code will run
				{
					x[i]=i+1;
					counter++;
					printf("\n Your lesson will be at %d! Type 4 to quit!",x[i]);
					break;
				}
				else if(counter==5)//if there are no available lessons this code will run
				{
				printf("No lessons today :( come back tomorrow!");
				break;
				}
			}
			}
		else if(pick==2)//this code will run if the user types in 2
		{
			int time;
			if(counter==0)//this code will run of there are no lessons yet that day
			{
				printf("The schedule is empty");
			}
			else//if there are lessons, this will run the code to let you type in a lesson time to cancel
			{
				printf("Enter the lesson time you wish to cancel.");
				scanf("%d",&time);
				if(time==x[time-1])//this is to cancel the lesson the user types in
				{
					x[time-1]=0;
					printf("Your lesson at %d has been canceled",time);
				}
			}
		}
		else if(pick==3)//this code will run if the user types in 3
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
					if(x[i]==0)//this code will run if the lesson time is free
					{
						printf("%d - Free\n",i+1);
					}
					else//this code will run if the lesson time is taken
					{
						printf("%d - Taken\n",i+1);
					}
				}
			}
		}
		else if(pick==9)//this code will run if the user types in 4
		{
			break;//this quits out of the program
		}
		else//this will run if the user enters anything that isn't 1,2,3,9
		{
			printf("Invalid option, try again.");
		}
	}
}
