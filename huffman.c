// huffman coding
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define COUNT 5

struct node
{
char symbol;
float probab;
struct node* leftchild;
struct node* rightchild;
struct node* father;
};

typedef struct node node;
//node* queue;

node* createnode(char symbol,float probab);  // creates node
node* insertnode(node* queue,node* newnode); //returns pointer to new ascending arranged queue
node* createAscenQueue();   //min 3 inputs
node* createTree(node* queue);
void printqueue(node* queue);
// following 2 optional functions
void print2DUtil(node *root, int space);
void print2D(node *root);
//----------------MAIN-----------------------------------------------------
int main()
{
//int a;
//scanf("%d",&a);

node* queue=createAscenQueue();
printf("\nsym=%c\n",(queue->symbol));

node* tree = createTree(queue);


//print2D(tree);
//printf("%f %f %f",tree->probab,tree->rightchild->probab,tree->leftchild->probab);
//printf("\ntest=%d",a);
//free();
return 0;
}
//---------------------------------------------------------------------------------
node* createnode(char symbol,float probab)
{
node* temp = (node*)malloc(sizeof(node));
temp->symbol=symbol;
temp->probab=probab;
return temp;
}

node* insertnode(node* queue,node* newnode)
{
node* temp=queue;
// case where new probab is least change head of queue
if((temp->probab) >= (newnode->probab))
	   {
			newnode->rightchild=queue;
			queue->father = newnode;
			queue=newnode;
			printf("\n%f 1 %f\n",newnode->probab,temp->probab);
			return queue;
	   }

while((temp->rightchild)!=NULL)
   {
	   if((temp->probab) >= (newnode->probab))
	   {


		    newnode->father = temp->father;
		    (temp->father->rightchild) = newnode;
		    newnode->rightchild = temp;
		    temp->father = newnode;
		    printf("\n%f 2 %f\n",newnode->probab,temp->probab);
			return queue;

	   }
	 temp=(temp->rightchild);
   }

if((temp->probab) >= (newnode->probab))
       {


		    newnode->father = temp->father;
		    (temp->father->rightchild) = newnode;
		    newnode->rightchild = temp;
		    temp->father = newnode;
		    printf("\n%f 2 %f\n",newnode->probab,temp->probab);
			return queue;

	   }

temp->rightchild = newnode;
newnode->father = temp;
printf("\n%f 3 %f\n",temp->probab,newnode->probab);
return queue;

}

node* createAscenQueue()
{
    int i,size;
    float probab;
    char symbol;
    node* temp;
    node* queue;

printf("\nenter no of elements\n");
scanf("%d",&size);

for(i=0;i<size;i++)
  {
     getchar();
     printf("\nenter symbol: ");
     scanf("%c",&symbol);

     printf("\nenter probsb: ");
     scanf("%f",&probab);

      temp = createnode(symbol,probab);
      if (i==0)
      {
          queue=temp;
          continue;
      }
      queue=insertnode(queue,temp);
  }
  temp=queue;
  for(i=0;i<size;i++)
  {
     printf("  %f",temp->probab);
     temp=temp->rightchild;
  }
return queue;
}

node* createTree(node* queue)
{
    node* temp;
 do
 {
    temp =createnode('x',0);
    temp->rightchild = queue;
    temp->leftchild = queue->rightchild;
    temp->probab = (temp->rightchild->probab) + (temp->leftchild->probab);
    queue = queue->rightchild->rightchild;
    queue = insertnode(queue,temp);
    printqueue(queue);
 }
 while((queue->rightchild->rightchild) != NULL);

temp =createnode('x',0);
    temp->rightchild = queue;
    temp->leftchild = queue->rightchild;
    temp->probab = (temp->rightchild->probab) + (temp->leftchild->probab);

return temp;
}

void printqueue(node* queue)
{
	node* temp = queue;
while(temp->rightchild != NULL)
	{
	printf("%f  ",temp->probab);
	temp=temp->rightchild;
	}
	printf("%f \n",temp->probab);
}
// following 2 optional functions
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->rightchild, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%f\n", root->probab);

    // Process left child
    print2DUtil(root->leftchild, space);
}

// Wrapper over print2DUtil()
void print2D(node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
