
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	struct node* LC;	// left child
	int info;
	struct node* RC;	// right child
} *root = NULL;

void inorder_traversal(struct node *ptr);
void preorder_traversal(struct node *ptr);
void postorder_traversal(struct node *ptr);
struct node* search(int item);
struct node* searchParent(int item);
struct node* inorder_successor(struct node* ptr);
void insert(int item);
void deletion(int item);
int height(struct node *ptr);

void inorder_traversal(struct node *ptr)
{
	
}

void preorder_traversal(struct node *ptr)
{
	}

void postorder_traversal(struct node *ptr)
{
	}

struct node* search(int item)		// returns position where node is found
{
	struct node* ptr = root;
}

void insert(int item)			// inserts node at corrrect position
{
	
}

struct node* inorder_successor(struct node* ptr)
{
}

void deletion(int item)	
{
}

int main()
{
	int code;
	
	do
	{
		printf("\n1. Insert element\n");
		printf("2. Search element\n");
		printf("3. Delete element\n");
		printf("4. Height of tree\n");
		printf("5. Traversal\n");
		printf("6. Exit program\n");
		scanf("%d", &code);		// input choice here

		int num;
		switch(code)
		{
			case 1: printf("Input element to insert: "); scanf("%d", &num);
							insert(num); break;
			
			case 2: printf("Input element to search: "); scanf("%d", &num);
							
							break;
				 
			case 3: printf("Input element to delete: "); scanf("%d", &num);
							deletion(num); break;
				 
			case 4: printf("Height of tree %d\n", height(root)); break;

			case 5: printf("Inorder sequence: "); inorder_traversal(root); printf("\n");
							printf("Preorder sequence: "); preorder_traversal(root); printf("\n");
							printf("Postorder sequence: "); postorder_traversal(root); printf("\n");
							break;
			
			case 6: printf("Exiting program on user input\n"); break;
			
			default:printf("Wrong code inputted\n");
		}
	}while(code != 6);

	return 0;
}
