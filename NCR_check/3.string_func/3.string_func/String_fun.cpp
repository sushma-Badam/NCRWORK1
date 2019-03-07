#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void reverse(char *s1,char *s2)
{
	int length = strlen(s1);
	int i = 0,j=0;
	for (i = (length - 1); i >= 0; i--)
	{
		*(s2 + j) = *(s1 + i);
		j++;
	}
	*(s2+j)= '\0';
}
void str_copy(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (*(s1+i)!='\0')
	{
		*(s2 + j) = *(s1 + i);
		i++;
		j++;
	}
	*(s2 + j) = '\0';
}
void str_cat(char *s1, char *s2)
{
	int length = strlen(s2);
	int l = strlen(s1);
	int i = 0;
	s1 = (char*)realloc(s1, 40);
	while (*(s2 + i) != '\0')
	{
		*(s1+l) = *(s2 + i);
		l++;
		i++;
	}
	*(s1 + l) = '\0';
}
void str_compare(char *s1, char *s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int i=0;
	if (l1>l2)
		printf("cannot compare as string1 greater than string2");
	else if(l1<l2)
		printf("cannot compare as string2 greater than string1");
	else
	{
		while (*(s1 + i) != '\0')
		{
			if (*(s1 + i) == *(s2 + i))
				i++;
			else
			{
				printf("two strings are of same length but not equal");
				return;
			}
		}
		printf("%s and %s :strings are equal", s1, s2);
	}
}
int main()
{
	char *string1 = (char*)malloc(MAX);
	char *string2 = (char*)malloc(MAX);
	int choice = 0;
	while (1)
	{
		printf("\n\nEnter \n 0:EXIT \n 1.Reverse \n 2.Copy \n 3.Concatnate \n 4.Comparison : \n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:printf("\nEnter string to be reversed :\n");
			getchar();
			scanf_s("%[^\n]s", string1, MAX);
			reverse(string1, string2);
			printf("Reversed string :%s ", string2);
			break;
		case 2:printf("\nEnter string to be copied :\n");
			getchar();
			scanf_s("%[^\n]s", string1, MAX);
			str_copy(string1, string2);
			printf("Copied string :%s", string2);
			break;
		case 3:printf("\nEnter first string :\n");
			getchar();
			scanf_s("%[^\n]s", string1, MAX);
			printf("Enter second string :\n");
			getchar();
			scanf_s("%[^\n]s", string2, MAX);
			str_cat(string1, string2);
			printf("\n Concatnated string :%s", string1);
			break;
		case 4:printf("\nEnter first string :\n");
			getchar();
			scanf_s("%[^\n]s", string1, MAX);
			printf("Enter second string :\n");
			getchar();
			scanf_s("%[^\n]s", string2, MAX);
			str_compare(string1, string2);
			break;
		case 0:
			free(string1);
			free(string2);
			getchar();
			return 0;
		default:
			printf("\nINVALID CHOICE \n");
		}
	}

	return 0;
}