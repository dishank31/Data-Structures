/*
	Name :- Dishank Gandhi
	PRN :- 1032232071
	Problem Statement :- Implement binary tree and perform following operations: Creation of binary tree and traversal recursive.
*/

#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

struct treenode
{
	char data[15];
	struct treenode *left;
	struct treenode *right;
};

struct treenode* stack [STACK_SIZE];
int top = -1;

int isempty()
{
	return top == -1;
}

void push(struct treenode *node)
{
	if(top == STACK_SIZE - 1)
	{
		printf("Stack Overflow!");
		return;
	}
	stack[++top] = node;
}

struct treenode *pop()
{
	if(isempty())
	{
		printf("Stack underflow\n");
		return NULL;
	}
	struct treenode *node = stack[top--];
	return node;
}

void create_tree(struct treenode *temp)
{
	char ch;
	
	printf("Do you want to add data in left node of %s (y/n) : ", temp -> data);
	scanf(" %c",&ch);
	if(ch == 'y' || ch == 'Y')
	{
		struct treenode *curr = (struct treenode * ) malloc(sizeof (struct treenode));
		printf("Enter data : ");
		scanf(" %s" , curr->data);
		curr -> left = NULL;
		curr -> right = NULL;
		temp -> left = curr;
		create_tree(curr);
	}
	
	printf("Do you want to add data in right node of %s (y/n) : ", temp -> data);
	scanf(" %c", &ch);
	if(ch =='y' || ch == 'Y')
	{
		struct treenode *curr = (struct treenode * ) malloc(sizeof (struct treenode));
		printf("Enter data : ");
		scanf(" %s" , curr->data);
		curr -> left = NULL;
		curr -> right = NULL;
		temp -> right = curr;
		create_tree(curr);
	}
}

void create_nr(struct treenode *root)
{
	struct treenode *temp;
	int flag;
	char ch;

	do
	{
		temp = root;
		flag = 0;
		struct treenode *curr = (struct treenode *) malloc (sizeof (struct treenode));	

		while(flag==0)
		{
			printf("where do you want to add data in left(L) or right node(R) : ");
			scanf(" %c" , &ch);

			if(ch=='L' || ch=='l')
			{
				if(temp -> left == NULL)
				{
					temp -> left = curr;
					flag = 1;
				}
				temp = temp -> left;
			}

			else
			{
				if(ch =='R' || ch == 'r')
				{
					if(temp -> right == NULL)
					{
						temp -> right = curr;
						flag = 1;
					}
					temp = temp -> right;
				}
			}
		}

		printf("Do you want to create more nodes (Y/N) : ");
		scanf(" %c" , &ch);
	} while (ch == 'Y' || ch == 'y');
}

void inorder_r(struct treenode *temp)
{
	if(temp!= NULL)
	{
		inorder_r(temp -> left);
		printf(" %s" , temp->data);
		inorder_r(temp -> right);
	}
}

void inorder_nr(struct treenode *root)
{
	struct treenode *temp = root;
	while(1)
	{
		while(temp != NULL)
		{
			push(temp);
			temp = temp -> left;
		}
		
		if(isempty())
		{
			break;
		}
		
		temp = pop();
		printf(" %s" , temp -> data);
		temp = temp -> right;
	}
}

void preorder(struct treenode *temp)
{
	if(temp!= NULL)
	{
		printf(" %s" , temp->data);	
		preorder(temp -> left);
		preorder(temp -> right);
	}
}

void preorder_nr(struct treenode *root)
{
	struct treenode *temp = root;
	while(1)
	{
		while(temp != NULL)
		{
			printf(" %s" , temp -> data);
			push(temp);
			temp = temp -> left;
		}
		
		if(isempty())
		{
			break;
		}
		
		temp = pop();
		temp = temp -> right;
	}
}

void postorder(struct treenode *temp)
{
	if(temp!= NULL)
	{
		postorder(temp -> left);
		postorder(temp -> right);
		printf(" %s" , temp->data);
	}
}
	
void postorder_nr(struct treenode *root)
{
	struct treenode *temp = root;
	while(1)
	{
		while(temp != NULL)
		{
			push(temp);
			temp = temp -> left;
		}

		if(stack[top] -> right == NULL)
		{
			temp = pop();
			printf(" %s" , temp -> data);
		}

		 while(!isempty() && stack[top]->right == temp)
        {
            temp = pop();
            printf(" %s", temp->data);
        }
        if (isempty())
        {
            break;
        }
        temp = stack[top]->right;
    }
}
	

int main()
{
	struct treenode *root = (struct treenode *) malloc(sizeof (struct treenode));
	printf("Enter the data for root : ");
	scanf(" %s", root->data);
	root -> left = NULL;
	root -> right = NULL;
	create_tree(root);
	
	int choice , t = 1;

	while(t==1)
	{	
		printf("Enter operation to be performed : \n\t1)Create using recursive \n\t2)Create non recursively \n\t3)Print Inorder \n\t4)Print Preorder \n\t5)Print Postorder \n\t6)Print Non Recusrive Inorder \n\t7)Print Non Recusrive Preorder \n\t8)Print Non Recusrive Postorder \n\t9)Exit!");
		scanf(" %d", &choice);
	
		switch(choice)
		{
			case 1:
			create_tree(root);
			printf("\n");
			break;

			case 2:
			create_nr(root);
			printf("\n");
			break;

			case 3:
			inorder_r(root);
			printf("\n");
			break;
		
			case 4:
			preorder(root);
			printf("\n");
			break;
		
			case 5:
			postorder(root);
			printf("\n");
			break;
		
			case 6:
			inorder_nr(root);
			printf("\n");
			break;

			case 7:
			preorder_nr(root);
			printf("\n");
			break;

			case 8:
			postorder_nr(root);
			printf("\n");
			break;

			case 9:
			printf("See you in the next assignment");
			t++;
			break;

		default:
			printf("Error! Choice not found");
			break;
		}
	}
	return 0;
}