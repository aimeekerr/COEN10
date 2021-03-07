#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
	int num1;
	int num2;
	int num3;
	int ans;
	int count=0;
	count=0;
	int i;
	for (i=0;i<10;i++)
	{
		num1=rand()%13;//creating a random number
		num2=rand()%13;//creating a random number
		ans=(num1*num2);//figuring out what the correct answer is and putting it into a variable
		printf("%d x %d = ",num1,num2);//outputting the numbers to multiply
		scanf("%d",&num3);//creating a place to input your answer
		if(num3 == ans)//if loop checking if you got the correct answer
		{
				printf("correct!\n");//outputting "correct" if you got the correct answer
				count++;//adding a count so that you can get your percentage at the end
		}
		else
				printf("nope :(\n");//outputting "wrong" if you got it wrong
	}
	count*=10;//creating a percentage by multiplying your correct answers by 10
	printf("you got %d %% correct!\n",count);//outputting your percentage
}
