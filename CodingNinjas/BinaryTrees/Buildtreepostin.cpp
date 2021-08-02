#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include <algorithm>
using namespace std;

void  takeInput(int* a , int len)

{
    cout << "Enter the elements :";
    for(int i = 0; i < len; i++)
    {
        cin >> a[i];
    }

}

BinaryTreeNode<int>* build(int* pre , int* in , int instart , int inend , int prestart, int preend)
{
    if(instart > inend)
        return NULL;

    int rootData = pre[prestart];
    int ris , rie , lis , lie;
    int rps , rpe , lps , lpe ;
    auto itr = find(in, arr + n, rootData);
    int pos = -1;
    if (itr != end(arr))
        pos = distance(arr, itr) ;

    //finding out the value of all 8 variables

    lis = instart;
    lie = pos - 1;
    lps = prestart+1;
    lpe = lie - lis + lps ;

    ris = pos + 1;
    rie = inend;
    rpe = preend;
    rps = lpe + 1;

    root -> left = build(pre, in , lis , lie , lps , lpe);
    root -> right = build(pre , in, lps , lpe , rps, rpe);
    
    return root;
}

BinaryTreesNode<int>* buildmain(int* in, int* pre, int size){
    return build(in, pre, 0, size - 1, 0 , size -1);
}


int main()
{
    int length;
    cout << "Enter the length of the preorder tranversal of tree";
    cin >> length;
    int  pre[length];
    int in[length];
    
    cout << "Enter the Preorder transversal";
    takeInput(pre, length);

    cout << "Enter the Inorder transversal";
    takeInput(in, length);
    
}