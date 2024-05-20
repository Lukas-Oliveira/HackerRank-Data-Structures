#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* insert(struct Node* root, int data);

void post_order(struct Node* root)
{
  if (root != NULL)
  {
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
  }
}

int main()
{
  struct Node* root = NULL;
  int t;
  int data;

  scanf("%d", &t);

  while (t-- > 0)
  {
    scanf("%d", &data);
    root = insert(root, data);
  }

  post_order(root);
  
  return EXIT_SUCCESS;
}

struct Node* insert(struct Node* root, int data)
{
  if (root == NULL)
  {
    struct Node* node =(struct Node*) malloc(sizeof(struct Node));

    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return node;
  }
  else
  {
    struct Node* current;

    if (data <= root->data)
    {
      current = insert(root->left, data);
      root->left = current;
    }
    else
    {
      current = insert(root->right, data);
      root->right = current;
    }

    return root;
  }
}
