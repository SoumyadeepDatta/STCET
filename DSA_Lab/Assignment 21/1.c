#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node {
  int key;
  struct node *left, *right;
};


struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *mirror(struct node * root )
{
    
    if(root==NULL)
    {
      return root;
    }
    else
    {
        root->left=mirror(root->left);
        root->right=mirror(root->right);
        struct node *temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}
void inorder(struct node *root) {
  if (root != NULL) 
  {
    
    inorder(root->left);

    
    printf("%d\t", root->key);

    
    inorder(root->right);
  }
  
}

struct node *smallest(struct node *root)
{
  if (root==NULL)
  return root;
  else if(root != NULL && root->left==NULL)
  {
    printf("\n%d",root->key);
    return root;
  }
  else
  {
    root->left=smallest(root->left);
  }
}

void largest( struct node * root )
{
	if ( root !=  NULL )
	{
		while( root->right != NULL )
		{
			root = root->right;
		}
		printf("\n%d",(root->key));
	}
	
} 

int total(struct node *root)
{
  if(root==NULL)
  return 0;
  else
  {
    return total(root->left)+total(root->right)+1;
  }
}
int internal(struct node *root)
{
  if(root==NULL)
  return 0;
  if(root->left==NULL && root->right==NULL)
  return 0;
  else
  {
    return internal(root->left)+internal(root->right)+1;
  }
}
int external(struct node *root)
{
  if(root==NULL)
  return 0;
  if(root->left==NULL && root->right==NULL)
  return 1;
  else
  {
    return external(root->left)+external(root->right);
  }
}
int height(struct node *root)
{
  int lh,rh;
  if(root==NULL)
  return 0;
  else
  {
    lh=height(root->left);
    rh=height(root->right);
    if(lh>rh)
    return lh+1;
    else
    return rh+1;
  }
}
struct node *deleteTree(struct node *root)
{
  if(root==NULL)
  return root;
  
  root->left=deleteTree(root->left);
  root->right=deleteTree(root->right);
  free(root);
  
 
  
}
int main() {
  struct node *root = NULL;
  

  int z,v,c;
  
  while(z)
	{
		printf("\n************************************");
		printf("\n1.Insert\n2.Mirror\n3.Display(Inorder)\n4.Smallest\n5.Largest");
		printf("\n6.Total\n7.Internal\n8.External\n9.Height\n10.Delete entire tree\n0.STOP");
		printf("\n************************************");
		scanf("%d",&z);
		switch(z){
				case 1:
					do{
						printf("\nEnter value:");
						scanf("%d",&v);
						root = insert(root,v) ;
						printf("\nPress 0 to stop. Press other integer to continue.");
						scanf("%d",&c);
					}while(c!=0);
					break;
				case 2:
          mirror(root);
          break;
				case 3:
          inorder(root);
          break;
        case 4:
          smallest(root);
          break;
        case 5:
          largest(root);
          break;
        case 6:
          printf("\n%d",total(root));
          break;
        case 7:
          printf("\n%d",internal(root));
          break;
        case 8:
          printf("\n%d",external(root));
          break;
        case 9:
          printf("\n%d",height(root));
          break;
        case 10:
          root=deleteTree(root);
          root=NULL;
          break;
        case 0:
          break;
				default:
					printf("\nInvalid Input!!!");
					
			}
	}
	return 0;
 
}
