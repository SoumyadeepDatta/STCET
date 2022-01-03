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


void inorder(struct node *root) {
  if (root != NULL) {
    
    inorder(root->left);

    
    printf("%d\t", root->key);

    
    inorder(root->right);
  }
  else
  
  return;
}

void preorder(struct node *root) {
  if (root != NULL) {
    
    printf("%d\t", root->key);
    
    preorder(root->left);

    preorder(root->right);
  }
  else
  return;
}

void postorder(struct node *root) {
  if (root != NULL) {
    
    postorder(root->left);

    postorder(root->right);
    
    printf("%d\t", root->key);
  }
  else
  return;
}



struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int key) {
  
  if (root == NULL) 
  {
  printf("\nNode not found ");
  return root;
  }
  
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    
    struct node *temp = minValueNode(root->right);

    
    root->key = temp->key;

    
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


int main() {
  struct node *root = NULL;
  

  int z,v,c;
  
  while(z)
	{
		printf("\n************************************");
		printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n0.STOP");
		
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
					preorder(root);
					break;
				case 3:
					inorder(root);
					break;
				case 4:
					postorder(root);
					break;
				case 5:
          printf("\nEnter value to be deleted:");
          scanf("%d",&v);
          root = deleteNode(root, v);
          break;
				case 0:
          break;
				default:
					printf("\nInvalid Input!!!");
					
			}
	}
	return 0;
 
}
