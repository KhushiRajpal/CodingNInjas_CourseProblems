#include <vector>

class PriorityMax{
    std::vector<int> v;

  /*  Priority(){

    }*/

    bool isEmpty(){
        if(v.size() == 0)
            return true;

        return false;
    }

    int Sizeof()
    {
        return v.size();
    }

    int getmin(){
        if(v.size() == 0)
            return -1;
        return v[0];
    }

void insert(int ele)
{
    //insert in last place , if its more than the parent , swap karo
    v.push_back(ele);
    
    int childInd = v.size() - 1;
    while(childInd >= 0)
    {
    int parentInd = (childInd - 1)/2;
    if(v[parentInd] > v[childInd])
    {
        int temp = v[parentInd];
        v[parentInd] = v[childInd];
        v[childInd] = temp;
    }
    else
        return;
    childInd = parentInd;    
}
}

int deleteEle(int x)
{
    int ans = v[0];
    v[0] = x;
    v.pop_back();
    int LchildInd = 1;
    int RchildInd = 2;
    int parentInd = 0;
    while(parentInd < v.size())
    {
    int maxInd = parentInd;

    if((LchildInd < v.size() ) && (v[LchildInd] > v[parentInd]))
        maxInd = LchildInd;
    
    if((RchildInd < v.size() ) && (v[RchildInd] > v[parentInd]))
        maxInd = RchildInd;

    int temp = v[maxInd];
    v[maxInd] = v[parentInd];
    v[parentInd] = temp;

    parentInd = maxInd;
    LchildInd = parentInd*2 + 1;
    RchildInd = parentInd*2 + 2;
    }
}

    
    




    }

}

