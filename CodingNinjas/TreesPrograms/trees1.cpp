#include <iostream>
#include <vector>
#include <queue>
#include "trees.h"
using namespace std;


TreeNode<int>* takelevelwiseinput(){
    int rootData;
    cout << "Enter the root data";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        int numchild = 0, numData;
        cout << "Enter the number of children of " << front->data << ":";
        cin >> numchild;
        for(int i = 0 ; i < numchild ; i++)
        {
            cout << endl;
            cout << "Enter the data of the " << i << " th term : ";
            cin >> numData;
            TreeNode<int>* child = new TreeNode<int>(numData);
            pendingNodes.push(child);
            front -> children.push_back(child);


        }
    }
    return root;
}

int searchEle(TreeNode<int>* root , int key)
{
    
    
    if(root == NULL)
    {
        exit;
    }

    if(root -> data == key)
    {
        cout << "The element is found";
        return 1;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        int flag = searchEle(root -> children[i] , key);
        if(flag == 1)
        {
            exit;
        }

    }

    return 0;

    }

TreeNode<int>*  takeInput(){
    cout << "Enter data : ";
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int> (rootData);

    int n;
    cout << "Enter the no of children of : " << rootData << endl;
    cin >> n;
    for(int i = 0; i < n ; i++){

        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;

}

// calculates the maximum value of a node in the tree

int calc_size(TreeNode<int>* root, int j , int max)

{  
    if(j == -1)
        max = root -> data;
    j++;
    
    int temp = root -> data;
    //cout << "temp  : " << temp;
    
    if( temp > max)
    {
        max = temp;
    }

    //cout << "max1 : " << max << endl;

    // iterated through each child
    for(int i = 0; i < root ->children.size(); i++)
    
    {
        int temp = root -> data;
        if( temp > max)
        {
            max = temp;
        }

        //recursive call where the child becomes the root and we check its children, process repeats untill its a leaf node

        int x = calc_size(root ->children[i], i , max);   

        // keep the value of max in the memory, if one of the children have value greater than parent
        if( x > max)
        {
            max = x;
        }
    }
  //cout << ans;
    return max;
}

//function to find the height of a tree

int height(TreeNode<int>* root ,int max )
{
    // base case when we reach leaf node

    if(root -> children.size() == 0)
    {
        return 1 ;
    }
    
    // iterating through each of the children

    for(int i = 0 ; i < root -> children.size() ; i++)
    {
        //checking the value of each indivisual child of original root 1 by 1 

        int temp_max = 1;

        /* recursive call will go through each branch like if tree is 
           1
           234
           56
           it'll go through 1 2 5
        */

        temp_max = temp_max + height(root -> children[i] , max );
        if( temp_max > max)
        {
            max = temp_max;
        }
        temp_max = 0;
    }

    return max;

}

int countNodes(TreeNode<int>* root , int sum)
{
    //debug statement to help understand the execution of the code
    //cout << "The sum when root is " << root -> data << " is :" << sum << endl;
    if(root -> children.size() == 0)
    return sum+1;
    

    for(int i = 0 ; i < root->children.size(); i++)
    {
        sum = countNodes(root ->children[i] , sum);
        
    }
    
    return sum;
}

void printatK(TreeNode<int>* root , int k)
{
    if(root -> data == NULL)
        return;
    
    if(k == 0)
    {
    cout << root -> data << endl;
    return;
    }

    for ( int i = 0 ; i < root->children.size(); i++)
    {
        printatK(root->children[i] , k-1);
    }
}

void PrintTreeLevelWise(TreeNode<int>* root)
{
    cout << root->data<< endl;
    queue <TreeNode<int>*> Level;
    
    Level.push(root);
    
    while(Level.size() != 0)
    {
        TreeNode<int>* front = Level.front();
        Level.pop();
        
    for(int i = 0 ; i < front->children.size(); i++)
    {
        cout << front -> children[i] -> data;
        Level.push(front -> children[i]);
    }
    cout << endl;
    /*for(int i = 0; i < front->children.size(); i++)
    {
        PrintTreeLevelWise(front->children[i]);
    }*/
    }

}
void printTree(TreeNode<int>* root){
    cout << root-> data << ":";
    for(int i = 0; i < root->children.size(); i++)
    {
        cout<< root-> children[i] -> data << ",";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void preorderTrans(TreeNode<int>* root )
{
    if(root == NULL)
    {
        exit;
    }

    cout << root -> data;

    for (int i = 0 ; i < root->children.size() ; i++)

    {
        preorderTrans(root->children[i]);
    }

}


void postorderTrans(TreeNode<int>* root  )
{
 
    
    if(root == NULL)
    {
        exit;
    }


    for (int i = 0 ; i < root->children.size() ; i++)

    {
        postorderTrans(root->children[i]);

    }
    
    cout << root->data;
   

    

}

int elegreaterthan(TreeNode<int>* root , int x , int sum)
{
    if(root == nullptr)
        exit;

    for(int i = 0 ; i < root -> children.size() ; i++)
        sum = elegreaterthan(root -> children[i], x , sum);
    
    if(root -> data > x )
         return sum+1;

    return sum;
}

int equal(TreeNode<int>* root1, TreeNode<int>* root2 , int f)
{
    if(root1 == nullptr)
        exit;
    if(root1 -> children.size() != root2 -> children.size())
    {
         cout << "Unequal";
            exit;
    }
    for(int i = 0 ; i < root1 -> children.size() ; i++)
    {
        int f = equal(root1 -> children[i] , root2 -> children[i] , f);
        if(f == 0)
        {
            cout << "Unequal";
            exit;
        }
    }

    if(root1 -> data == root2 -> data)
         return 1;
    return 0;

    
}

int next_largest(TreeNode<int>* root, int ele, int curr)
{
    if(root == NULL)
       exit;
    
    int temp = root->data;
   // cout << endl << "Temp :" << temp;
    //cout << "ele :" << ele <<endl;
    for(int i = 0 ; i < root -> children.size(); i++)
    {
        curr = next_largest(root -> children[i], ele , curr);
    }
      if(temp > ele)
    {
        if((temp - ele) < (curr - ele) || (curr - ele <= 0))
            curr = temp;
       
    }

    return curr;
}

int main(){

    // making a tree khud se 

    /*
       TreeNode<int>* root = new TreeNode<int>(1);
       TreeNode<int>* node1 = new TreeNode<int>(2);
       TreeNode<int>* node2 = new TreeNode<int>(3);
       root -> children.push_back(node1);
       root -> children.push_back(node2);
    */

   // calling function to take custom tree input
   // 1 2 2 3 2 4 5 0 0 2 6 7 0 0
    TreeNode<int>* root = takelevelwiseinput();

    cout << "Enter the element whose next largest element you want to find : ";
    int ele;
    cin >> ele;
    int ans = next_largest(root , ele , 0);
    cout << "The next largest element of " << ele << " is " << ans;


/*    //function to check of 2 trees are structurally identical
    TreeNode<int>* root1 = takelevelwiseinput();
    TreeNode<int>* root2 = takelevelwiseinput();

    int f = equal(root1 , root2 , 0);
    if(f == 1)
    {
        cout << "The 2 trees are structurally identical";
    }



    //finding a paticular element
    int key;
    cout << endl <<"Enter an element to be searched" << endl ;
    cin >> key;
    int f = searchEle(root , key);
    cout << f;
    if(f != 1)
       cout << endl << "Element not found" << endl;

    // find number of nodes greater than key
    cout << "Enter an element to check the number of nodes greater than it :";
    int x;
     cin >> x;
    int greaterthan = elegreaterthan(root, x , 0);
    if( greaterthan == 0)
        cout << endl << x << " is the largest element" << endl;
    else 
        cout << "The number of nodes greater than are " << x << " are : " << greaterthan << endl;
    

    

    // Ways to print
    // 1) Level wise print 
    cout << endl <<  "The tree printed level wise is : "  << endl;
    PrintTreeLevelWise(root);

    // 2) PreOrder transversal
    cout << endl <<  "The tree printed  in PreOrder transversal : "  << endl;
    preorderTrans(root);

    // 3) Postorder transversal
    cout << endl <<  "The tree printed  in PostOrder transversal : "  << endl;
    postorderTrans(root);

   //finding the height of the tree and printing
    int h = height(root , root-> data);
    cout << "The height of the tree is : " << h << endl;

    //number of lead nodes
    int c = countNodes(root , 0);
    cout << "The number of leaf nodes are : " << c;;
    printatK(root , 3);

   //number of nodes in tree
    int size = calc_size(root , -1 , root-> data);
    cout << "The number of nodes are: " << size;
*/
    // calling the destructor of the object
   delete root;
}