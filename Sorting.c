/*
	Name :- Dishank Gandhi
	PRN :- 1032232071
	Problem Statement :- Write a C program to create a student database using an array of structures. 
	Apply Sorting techniques(Bubble sort ,Insertion Sort, Selection Sort).
*/

#include<stdio.h>

struct student
{
	int PRN;
	char name[50];
	char div;
	int contact_no;
	};
	
void display(int n , struct student *s)
{
	for(int i=0 ; i<n ; i++)
	{
		printf("%s \t %d \t %c \t %d \n", s[i].name , s[i].PRN , s[i].div , s[i].contact_no);
	}
}
	
void bubble_sort(int n , struct student *s)
{	
	struct student temp;
	for(int i=1 ; i<n ; i++)
	{
		for(int j=0 ; j<=n-i-1 ; j++)
		{
			if(s[j].PRN > s[j+1].PRN)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;	
			}
		}
	}
}

void selection_sort(int n , struct student *s)
{
	int index;
	struct student temp;
	
	for(int i=0 ; i<n-1 ; i++)
	{
		index = i;
		for(int j=i+1 ; j<n ; j++)
		{
			if(s[j].PRN < s[index].PRN)
			{
				index = j;
			}
		}
		
		if(index !=i)
		{
			temp = s[i];
			s[i] = s[index];
			s[index] = temp;
		}
	}
}

void insertion_sort(int n , struct student *s)
{
	for(int i=1 ; i<n ; i++)
	{
    	struct student key = s[i];
		int j=i-1;
		
		while(j>=0 && key.PRN < s[j].PRN)
		{
			s[j+1] = s[j];
			j--;
		}
		s[j+1] = key;
	}
}			
	
int main()
{
	int n;
	printf("Enter the number of students : ");
	scanf("%d",&n);
	
	struct student *s;
	for(int i=0 ; i<n ; i++)
	{
		printf("\n");
		printf("Enter %d Student Name : ",i+1);
		scanf(" %s",s[i].name);
		printf("Enter PRN of student : ");
		scanf("%d",&s[i].PRN);
		printf("Enter Division : ");
		scanf(" %c",&s[i].div);
		printf("Enter contact number : ");
		scanf("%d",&s[i].contact_no);
				}

	int choice;
	printf("1)Bubble sort\n2)Selection sort\n3)Insertion sort\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		display(n,s);
		printf("\n");
		bubble_sort(n,s);
		display(n ,s);
		break;
		
		case 2:
		display(n,s);
		printf("\n");
		selection_sort(n,s);
		display(n,s);
		break;
		
		case 3:
		display(n,s);
		printf("\n");
		insertion_sort(n,s);
		display(n,s);
		break;
		
		default:
		printf("Error! Choice not found");
		break;
	}
	
	return 0;
}	