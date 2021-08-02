#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter data: "<< endl;
    cin >> rootData;
    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* node1 = takeInput();
    BinaryTreeNode<int>* node2 = takeInput();
    root->left = node1;
    root->right = node2;

    return root;
}

BinaryTreeNode<int>* takeInputLevelwise()
{
    int rootData;
    cout << "Enter root data";
    cin >> rootData;
    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << front -> data << " : " << endl;
        int leftChild;
        cin >> leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front -> left = child;
            pendingNodes.push(child);
        }
        cout << "Enter the right child of " << front -> data << " : " << endl;
        int rightChild;
        cin >> rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            front -> right = child;
            pendingNodes.push(child);
        }
        
    }
    return root;
}

void printrange(BinaryTreeNode<int>* &root, int min , int max)
{
    if(root == NULL)
        return;

    if((min <= root->data)&& (root->data <= max))
        cout << root -> data;
    
    if((root->left) && (root -> data >= max))
        printrange(root -> left, min, max);

    else if((root->right) && (root->data <= min))
        printrange(root->right , min, max);

    else
    {
         if(root->left)
            printrange(root -> left, min, max);

        if(root->right)
            printrange(root->right , min, max);
    }       
        
}


void printTree(BinaryTreeNode<int> * root)
{
    if(root == NULL)
        return;

    cout << root->data << ":";

    if(root -> left != NULL)
        cout << "L" << root ->left ->data;

    if(root -> right != NULL)
        cout << "R" << root -> right -> data;
    
    cout << endl;

    printTree(root->left);
    printTree(root -> right);
    }


BinaryTreeNode<int>* searchele(BinaryTreeNode<int>* &root , int key)
{
    if(root == NULL)
        return NULL;

    else if(root -> data == key)
        return root;

    else if((root -> left) && (key < root->data))
        searchele(root -> left , key);
    

    else
        searchele(root -> right, key);

}


void PrintTreeLevelWise(BinaryTreeNode<int> * root )
{
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pending ;
    pending.push(root);
    
    while(pending.size() != 0)
    {
        BinaryTreeNode<int>* front = pending.front();
        cout << front -> data << ": ";
        if(front == nullptr)
        {
            if(front == NULL ){
                if(pending.size() != 0 )
                    pending.push(NULL);
            }
        }

        pending.pop();
        if(front -> left != NULL)
        {
            if(front->left->data != -1)
            {
                BinaryTreeNode<int>* child = front -> left ;
                cout << "L" << front -> left -> data;
                pending.push(child);
            }
        }
      
        if(front -> left != NULL)
        {
            if(front->right->data != -1)
            {
                BinaryTreeNode<int>* child = front -> right;
                cout << "R" << front -> right -> data << endl;
                pending.push(child);
            }
        }
    }
} 

//find a node 
//height of binary tree 
//mirror

int numNode(BinaryTreeNode<int>* root)
{
    if(root == NULL)
       return 0;
    return 1 + numNode(root-> left) + numNode(root->right);
}

int findNode(BinaryTreeNode<int>* root, int key)
{
    if(root-> data == key)
        cout << "The key is found ";
        return 1;
        
    
    if(root == NULL)
       return 0;
    
    if(root -> left != NULL)
        if(findNode(root -> left , key) == 1)
           exit;

    if(root -> right != NULL)
        if(findNode(root -> right , key))
           exit;
    return 0;
}

int  findheight(BinaryTreeNode<int>* root , int k , int m)
{
  
    if(k > m)
       m = k;
    if(root == NULL)
        return 0;

    if(root -> left != NULL)
    {
       int x = findheight(root -> left, k+1 , m);
       if(x > m)
           m = x;
    }
    if(root -> right != NULL)
    {
         int x = findheight(root -> left, k+1 , m);
       if(x > m)
           m = x;
    }
    return m;
}

/*bool mirror(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2, bool check)
{
    if(root1 == NULL || root2 == NULL)
    return false ;

    if(root1  == root2)
    {
        if(root1 -> left == root2 -> right)
        {
            if(root1 -> right == root2 -> left)
            {
                if(mirror(root1 -> left, root2-> right))
                    

            }
        }
    }
}*/


void inorder(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return ;
    }

    inorder(root-> left);
    cout << root-> data;
    inorder(root->right);
}

void postorder(BinaryTreeNode<int> * root)
{
    if(root == NULL)
        return ;

    if(root -> left != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
    }

    cout << root -> data;
    
  
}


// 4 2 6 1 3 -1 -1 -1 -1 5 7 -1 -1 -1 -1
int main()
{

    //dynamically creating a tree 

    BinaryTreeNode<int>* root = takeInputLevelwise();
    int min = 3;
    int max = 7;
    printrange(root, min , max);


 /*   int key = 45;

    BinaryTreeNode<int>* pos = searchele(root , key);
    if(pos != NULL)
         cout << pos -> data << " was found.";

    else
        cout << "Element was not found.";

    //statically creating a tree

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root-> left = node1;
    root->right = node2;

   PrintTreeLevelWise(root);
   postorder(root);

   // number of nodes 

   cout << "The number of nodes in the tree are : " << numNode(root) << endl;

   cout << "Enter a node to check whether present : " << endl;
   int key ;
   cin >> key;
   int ch = findNode(root , key);
   if(ch == 0)
       cout << "The node is not present" <<endl;
       
   int h = findheight(root , 0 , 0);
   cout << "Height : " << h;

   //find a node
   */
  
    delete root;
}