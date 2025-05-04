/*
    Name :- Dishank Gandhi
    PRN :- 1032232071
    Batch :- F1
    Problem Statement :- Queues are frequently used in computer programming, and a typical example is the creation of a
                         job queue by an operating system. If the operating system does not use priorities, then the jobs
                         are processed in the order they enter the system. Write a program for simulating job queue. Write
                         functions to add job and delete job from queue.
*/

#include<stdio.h>

int r=-1,f=-1;

int is_full(int n)
{
    if(r==n-1) return 1;
    else return 0;
}

int is_empty()
{
    if (r==f) return 1;
    else return 0;
}

void add(int arr[],int n)
{
    if (is_full(n)) printf("\nQueue is full!! First delete an element");
    
    else
    {
        int elem;
        printf("\nEnter the element to be added in queue: ");
        scanf(" %d",&elem);
        r++;
        arr[r]=elem;
        printf("\n");
    }
}

void del(int arr[])
{
    if (is_empty(arr)) printf("\nQueue is empty!! Add some elements");
    
    else
    {
        f++;
        printf("\nDeleted the following element from the queue: %d\n",arr[f]);
    }
}

void display(int arr[],int n)
{
    if(is_empty(arr)) printf("\nQueue is empty!!\n");
    
    else
    {
        printf("\nQueue is:\n");
        for(int i=f+1;i<=r;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n,choice,t=0;
    printf("Enter the length of the job queue: ");
    scanf(" %d",&n);
    
    int queue[n];
    printf("\nJob Queue created");
    
    while(t==0)
    {
        printf("\nEnter the operation to be done:\n\t1.Add a job\n\t2.Delete a job\n\t3.Display the job queue\n\t4.Exit");
        scanf(" %d",&choice);

    switch(choice)
    {
        case 1:
            add(queue,n);
            break;
        
        case 2:
            del(queue);
            break;
        
        case 3:
            display(queue,n);
            break;
        
        case 4:
            t++;
            break;
        
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;    
}