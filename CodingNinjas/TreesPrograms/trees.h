#include <vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode(){
        //destructor of object at node x won't be called untill its children are already destroyed
        for(int i = 0 ; i < children.size(); i++)
        {
            delete children[i];
        }
    }



    
};