#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int value;
    struct node* left;
    struct node* right;
};
struct node* root;
struct node* insert(struct node* root1, int data)
{
    if(root1==NULL)
    {   root1 = new node;
        root1->value = data;
        root1->left = NULL;
        root1->right = NULL;
    }
    else if(data < root1->value){
        root1->left = insert(root1->left, data);
    }
    else {root1->right = insert(root1->right, data);
    }
    return root1;
}
void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        cout<<r->value;
        inOrder(r->right);
    }
}
void preOrder(struct node* r)
{
    if(r!=NULL){
        cout<<r->value;
        preOrder(r->left);
        preOrder(r->right);
    }
}
void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        cout<<r->value;

    }
}
struct node * minValueNode(struct node* node)
{   struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node* deleteNode(struct node* root2, int key)
{
    if (root2 == NULL)
        return root2;
    if (key < root2->value)
        root2->left = deleteNode(root2->left, key);
    else if (key > root2->value)
        root2->right = deleteNode(root2->right,key);
    else
    {
        if (root2->left == NULL)
        {
            struct node *temp = root2->right;
            free(root2);
            return temp;
        }
        else if (root2->right == NULL)
        {
            struct node *temp = root2->left;
            free(root2);
            return temp;
        }
        struct node* temp = minValueNode(root2->right);
        root2->value = temp->value;
        root2->right = deleteNode(root2->right, temp->value);
    }
    return root2;
}
int main()
{
    root = NULL;
    int n,i,v;

    while(1)
        {cout<<"\n 1 Enter element";
    cout<<"\n 2 In Order";
    cout<<"\n 3 Pre Order";
    cout<<"\n 4 Post Order";

    cout<<"\n 6 Exit";
            cout<<"\n Enter Choice"<<endl;
         cin>>i;
        switch(i)
    {case 1:
        cout<<"Enter element";
        cin>>v;
        root = insert(root, v);
        break;
     case 2:
        cout<<"Inorder Traversal: ";
        inOrder(root);
        cout<<endl;
        break;
     case 3:
        cout<<"Preorder Traversal: ";
        preOrder(root);
        cout<<endl;
        break;
     case 4:
        cout<<"Postorder Traversal: ";
        postOrder(root);
        cout<<endl;
        break;
     case 5:
        cout<<"Enter element to delete";
        cin>>n;
        deleteNode(root,n);
        break;
     case 6:
        exit(0);
    }
        }
   return 0;
}
