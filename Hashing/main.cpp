#include <iostream>
#include <cstring>

using namespace std;

//template class declared below
template <typename T>
class node
{
public:
    string key;
    T price;
// AS node is templated class node * has no meaning, we need to write node<T> *
    node<T>* next;
    node(string key,T price)
    {
        this->key =key;
        this->price = price;
    }
};

template <typename T>
class hashing
{
    //Below function will give a hash code for each key
    int hashFn(string s)
    {
        int hv=0,p=1;
        for(int i=0; i<s.length(); i++)
        {
            hv+=(s.at(i))*p;
            p*=19;
            hv = hv%11;
        }
        return hv;
    }
    // bucket is node<T> ** type, that is used for pointing array of node<T> * pointers
    node<T> ** bucket;
    int ts; // ts stand for total size of hash table
public:
    // in constructor (hashing), if no value is passed it will consider 11 as ts value. As we are passing 13 in main function is will consider 13.
    hashing(int ts =11)
    {
        this->ts =ts;
        bucket = new node<T>* [ts];
        // initially all node<T>* elements are pointing to null as they don't have elements yet
        for(int i=0; i<ts; i++)
        {
            bucket[i] = NULL;
        }
    }

    void insert(string key,int value)
    {
        int hashValue = hashFn(key);
        node<T>* temp = new node<T>(key,value);
        // making temp pointing NULL as each element in bucket is initially pointing to NULL
        temp->next = bucket[hashValue];
        // now making bucket to point at temp
        bucket[hashValue]=temp;
    }

    void display()
    {
        for(int i=0; i<ts; i++)
        {
            cout<< i << "  ";
            node<T>* temp = bucket[i];
            while(temp != NULL)
            {
                cout<<temp->key <<" "<< temp->price << ", ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    // find function will return full node*, so that we can dereference it in main function and extract required value
    node<T>* find(string key)
    {
        int hashValue = hashFn(key);
        node<T> *temp = bucket[hashValue];
        while(temp != NULL)
        {
            if(temp->key == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

};



int main()
{
    hashing <int>h(13);
    h.insert("apple",100);
    h.insert("mango",80);
    h.insert("banana",60);
    h.insert("kiwi",30);
    h.insert("guava",150);
    h.insert("chhiku", 150);
    h.display();
    node<int> * temp = h.find("apple");
    (temp == NULL)? cout<< "Element not found"<<endl: cout<< "Price of given element is: "<<temp->price<<endl;
    return 0;
}
