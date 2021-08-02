#include <iostream>
#include <string>
using namespace std;

template<typename  v>
 class mapnode {
    string key;
    v value;
    mapnode* next;

    mapnode(string key,v value){
        this->key = key;
        this-> value = value;
        next = NULL;
    }

    ~mapnode(){
        delete next;
    }
};

template<typename v>
class ourmap{
    mapnode<v>** buckets; //an array of pointers 
    int count;
    int numbuckets;

    public:
    ourmap(){
        count = 0;
        numbuckets = 5;
        buckets = new mapnode<v>*[numbuckets];
        for(int i = 0; i < numbuckets ; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
        for(int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete [] buckets; 
    }

  

    private:
    int location(string key){
        int hashkeys = 0;
        int currentLog = 1;
        for(int i = key.length() - 1; i >=0 ; i--)
        {
            hashkeys+= key[i] * currentLog;
            hashkeys = hashkeys % numbuckets;
            currentLog *= 37;
            currentLog = currentLog % 10;
        }

        return hashkeys % numbuckets;
    }

    public:
          int size(){
            return count;
        }
        void insert(string key, v value){
            //create pointer to go through the map
            int bucketIndex = location(key);
            mapnode<v>* head = buckets[bucketIndex];
            while(head != NULL)
            {
                //if we find it update value of node
                if(head-> key == key)
                {
                    head -> value = value;
                    return;
                }
                head = head -> next;
            }
            //if we don't find it 
            head = buckets[bucketIndex];
            mapnode<v>* node = new mapnode<v>(key , value);
            node -> next = head;
            buckets[bucketIndex] = node;
            count++;
        }

        void deleting(string key, v value){
            int bucketIndex = location(key);
            mapnode<v>* head = buckets[bucketIndex];
            mapnode<v>* prev = NULL;
            
            while(head != NULL){
                if(head -> key == key)
                {
                   if(prev = NULL)
                   {
                       buckets[bucketIndex] = head -> next; }
                   else
                    prev -> next = head -> next; 
            v value = head -> value;
            head -> next = NULL;
            delete head;
            count --;
            return value;
            }

            prev = head;
            head = head -> next;
            }

        }
        

        v searchkey(string key){
            int bucketIndex =  location(key);
            mapnode<v>* head = buckets[bucketIndex];
            while(head != NULL)
            {
                if(head->key = key)
                {
                  return head->value;
                }
                head = head -> next;
        }

        return 0;

}
};
