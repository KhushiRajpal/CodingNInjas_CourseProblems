#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, int> ourmap;

    //insert
    pair<string,int> p("abc" , 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    //display
    cout << ourmap["abc"] << endl;

   
   
    //check if present
    cout << ourmap["ghee"] << endl;

     if(ourmap.count("ghee") > 0)
    {
        cout << "ghee is present";
    }

    ourmap.erase("ghee");
   
   cout << ourmap.size() << endl;
    


}