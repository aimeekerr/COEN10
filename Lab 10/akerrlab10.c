#include <stdio.h>
#include <string.h>
#include <ctype.h>
char words[10][10];
int length[10];
int counter=0;
void input();
void reverse();
void upper();
void other();
int main (void)
{
	printf("Enter up to 10 words!\n");
	input();
	reverse();
	upper();
	other();
}
void input(){
	int i;
	int j;
	int a;
	char word[10];
	for (i=0;i<10;i++)
	{
		if(scanf("%s",word)<1)
		{
			break;
		}
		else
		{
			for(a=0;a<counter;a++)
			{
				if(strcmp(words[a],word)>0)
				{
					break;
				}
			}
			for(j=counter-1;j>=a;j--)
			{
				strcpy(words[j+1],words[j]);
			}
			strcpy(words[a],word);
			counter++;
		}
	}
	printf("Your words are:\n");
	for(i=0;i<counter;i++)
	{
		if(words[i][0]=='\0')
		{
			printf("\n");
			return;
		}
		else
		{
			printf("-");
			printf("%s\n",words[i]);
		}
	}
}
void reverse(){
	int i;
	int j;
	char temp[10];
	for(i=0,j=counter-1;i<j;i++,j--)
	{
			strcpy(temp,words[i]);
			strcpy(words[i],words[j]);
			strcpy(words[j],temp);
	}
	printf("Your words reversed are:\n");
	for(i=0;i<counter;i++)
	{
		if(words[i][0]=='\0')
		{
			printf("\n");
			return;
		}
		else
		{
			printf("-");
			printf("%s\n",words[i]);
		}
	}
}

void upper(){
	int i;
	int counter1=0;
	char *p;
	for(i=0;i<counter;i++)
	{
		counter1=0;
		p=words[i];
		while(*p!='\0')
		{
			if(islower(*p))
			{
				*p=toupper(*p);
			}
			p++;
			counter1++;
		}
		length[i]=counter1;
	}
	printf("Your words uppercase are:\n");
	for(i=0;i<counter;i++)
	{
		if(words[i][0]=='\0')
		{
			printf("\n");
			return;
		}
		else
		{
			printf("-");
			printf("%s\n",words[i]);
		}
	}

}
void other(){
	int i;
	char shortest[10];
	char longest[10];
	int shortest1=length[0];
	int longest1=length[0];
	int avg=0;
	printf("The words that don't start with letters are:\n");
	for(i=1;i<counter;i++)
	{
		if(length[i]>longest1)
			longest1=i;
		if(length[i]<shortest1)
			shortest1=i;
		avg=avg+length[i];
		if(!isalpha(words[i][0]))
		{
			printf("%s\n",words[i]);
		}
	}
	avg=avg/counter;
	strcpy(longest,words[longest1]);
	strcpy(shortest,words[shortest1]);
	printf("The longest word is: %s (%d)\n",longest,length[longest1]);
	printf("The shortest word is: %s (%d)\n",shortest,length[shortest1]);
	printf("The average length of the words is %d\n",avg);
}
