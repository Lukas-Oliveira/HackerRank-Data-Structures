/**
 * Link: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* insert(struct node* root, int data)
{
  if (root == NULL)
  {
    struct node* node =(struct node*) malloc(sizeof(struct node));

    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return node;
  }
  else
  {
    struct node* current;

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

int get_height(struct node* root)
{
  if (root == NULL)
    return -1;
  else
  {
    int left_height  = get_height(root->left);
    int right_height = get_height(root->right);

    if (left_height > right_height)
      return (left_height + 1);
    else
      return (right_height + 1);
  }
}

int main()
{
  struct node* root = NULL;
  int t;
  int data;

  scanf("%d", &t);

  while (t-- > 0)
  {
    scanf("%d", &data);
    root = insert(root, data);
  }

  printf("%d\n", get_height(root));
  
  return EXIT_SUCCESS;
}