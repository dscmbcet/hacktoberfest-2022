#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node*left, *right;
};
//create a node
struct node *newNode(int item){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}

//inorder traversal
void inorder(struct node *root){
    if(root!=NULL){
        //TRAVERSE LEFT
        inorder(root->left);
        
        //traverse root
        printf("%d -> ", root->key);
        
        //traverse right
        inorder(root->right);
    }
}

//insert a node
struct node *insert(struct node *node, int key){
    //return a new node if the tree is empty
    if(node==NULL) return newNode(key);
    
    //traverse to the right place and insert the node
    if(key<node->key)
    node->left =insert(node->left,key);
    
    else
    node->right =insert(node-> right, key);
    
    return node;
}

//find the inorder successor
struct node *minValueNode(struct node *node){
    struct node *current =node;
    
    //find the leftmost leaf
    while(current &&current->left!=NULL)
        current =current->left;
        
    return current;
}

//deleting a node
struct node *deleteNode(struct node *root, int key){
    //return if the tree is empty
    if(root==NULL) return root;
    //find the node to be deleted
    if(key<root->key) root->left=deleteNode(root->left, key);
    else if(key>root->key)
        root->right=deleteNode(root->right,key);
        
    else{
        //if the node is with only one child or no child
        if(root->left ==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right ==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        
        //if the node has two children
        struct node *temp=minValueNode(root->right);
        
        //place the inorder successor in position of the node to be deleted
        root->key=temp->key;
        
        //delete the inorder successor
        root->right =deleteNode(root->right, temp->key);
    }
    return root;
}

int main(){
    struct node *root=NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    // root = insert(root, 9);
    
    printf("Inorder traversal: ");
    inorder(root);
    
    printf("\nAfter deleting 10\n");
    root=deleteNode(root,10);
    printf("Inorder traversal: ");
    inorder(root);
    
    return 0;
}