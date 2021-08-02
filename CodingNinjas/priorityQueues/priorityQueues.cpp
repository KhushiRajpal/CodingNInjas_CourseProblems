#include <vector>

class Priority{
    std::vector<int> v;

    Priority(){

    }

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

    //insert and delete

   void  insert(int ele){
      
       v.push_back(ele);
       int x  = v.size() - 1;
       while( x > 0)
       {
           int parent = (x - 1)/2;
           if(v[x] > v [parent])
           {
               int temp = v[parent];
               v[parent] = v[x];
               v[x] = temp;
           }
           else 
               break;
           x = parent;
       }
     

    }

    void deleteEle(int ele){
        if(v.size() == 0)
            return;
        
        //find element in tree and swap with last one
      
        int ans = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();

        //now rearrange the tree : element c
          int parentInd = 0;
            int LchildInd = 1;
            int RchildInd = 2;
        
        while(parentInd < v.size())
        {
            if(LchildInd < v.size())
            {
                if(v[parentInd] > v[LchildInd]) 
                {
                    if((RchildInd < v.size()) && (v[RchildInd] > v[LchildInd]))
                        {
                                //swap parentInd with leftchild
                                int temp = v[parentInd];
                                v[parentInd] = v[LchildInd];
                                v[LchildInd] = temp;    
                                parentInd = LchildInd;   
                        }
                }

                else if((RchildInd < v.size()) && (v[RchildInd] > v[LchildInd]))
                    {
                        //swap parent with rightchild
                                int temp = v[parentInd];
                                v[parentInd] = v[RchildInd];
                                v[RchildInd] = temp;
                                parentInd = RchildInd;

                    }
                else
                    break;
            }
            LchildInd = parentInd*2 + 1;
            LchildInd = parentInd*2 + 2;
        
            

        }

    }



};