#include <iostream>
#define CHAR_SIZE 128
using namespace std;

class Trie
{
public:
    bool isLeaf;
    Trie* character[CHAR_SIZE];

    Trie()
    {
        this->isLeaf = false;

        for (int i = 0; i < CHAR_SIZE; i++) {
            this->character[i] = nullptr;
        }
    }

    void insert(string);
    bool deletion(Trie*&, string);
    bool search(string);
    bool haveChildren(Trie const*);
};

void Trie::insert(string key)
{
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        if (curr->character[key[i]] == nullptr) {
            curr->character[key[i]] = new Trie();
        }
        curr = curr->character[key[i]];
    }
    curr->isLeaf = true;
}

bool Trie::search(string key)
{
    if (this == nullptr) {
        return false;
    }

    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        curr = curr->character[key[i]];
        if (curr == nullptr) {
            return false;
        }
    }
    return curr->isLeaf;
}

bool Trie::haveChildren(Trie const* curr){
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return true;
    return false;
}

bool Trie::deletion(Trie*& curr, string key){
    if (curr == nullptr) return false;

    if (key.length()){
        if (curr != nullptr &&
            curr->character[key[0]] != nullptr &&
            deletion(curr->character[key[0]], key.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }

    if (key.length() == 0 && curr->isLeaf){
        if (!haveChildren(curr)){
            delete curr;
            curr = nullptr;
            return true;
        }        else {
            curr->isLeaf = false;
            return false;
        }
    }
    return false;
}

int main()
{
    Trie* head = new Trie();

    head->insert("hello");
    cout << head->search("hello") << " ";      // print 1

    head->insert("helloworld");
    cout << head->search("helloworld") << " "; // print 1

    cout << head->search("hell") << " ";      // print 0 (Not found)

    head->insert("hell");
    cout << head->search("hell") << " ";       // print 1

    head->insert("h");
    cout << head->search("h");                 // print 1

    cout << endl;

    head->deletion(head, "hello");
    cout << head->search("hello") << " ";      // print 0

    cout << head->search("helloworld") << " "; // print 1
    cout << head->search("hell");              // print 1

    cout << endl;

    head->deletion(head, "h");
    cout << head->search("h") << " ";          // print 0
    cout << head->search("hell") << " ";       // print 1
    cout << head->search("helloworld");        // print 1

    cout << endl;

    head->deletion(head, "helloworld");
    cout << head->search("helloworld") << " "; // print 0
    cout << head->search("hell") << " ";       // print 1

    head->deletion(head, "hell");
    cout << head->search("hell");              // print 0

    cout << endl;

    if (head == nullptr) {
        cout << "Trie empty!!\n";              // Trie is empty now
    }

    cout << head->search("hell");              // print 0

    return 0;
}




























//#include <iostream>
//
//using namespace std;
//
//struct trie{
//struct trie *children[26];
//bool isEnd;
//trie(){
//isEnd = false;
//for(int i=0;i<26;i++)
//    children[i] = NULL;
//}
//};
//
//void insert(struct trie * head,string key){
//    struct trie * curr  = head;
//for(int i=0;i<key.length();i++){
//    int index = key[i] - 'a';
//    if(curr->children[index] == NULL)
//        curr->children[index] = new struct trie;
//    curr = curr->children[index];
//}
//curr->isEnd = true;
//}
//
//bool search(struct trie * head,string key){
//struct trie * curr  = head;
//for(int i=0;i<key.length();i++){
//    int index = key[i] - 'a';
//    if(curr->children[index] == NULL)
//        return false;
//    curr=curr->children[index];
//}
//return curr->isEnd;
//}
//
//bool isEmpty(struct trie * head){
//for(int i=0;i<26;i++){
//    if(head->children[i] != NULL){
//         return false;
//    }
//}
//return true;
//}
//
//trie * del(struct trie * head,string key,int i){
//if(head == NULL) return NULL;
//
//if(i == key.length()){
//    head->isEnd = false;
//    if(isEmpty(head)){
//        delete(head);
//        head = NULL;
//    }
//    return head;
//}
//
//int index = key[i] - 'a';
//head->children[index] = del(head,key,i+1);
//if(isEmpty(head) && head->isEnd == false){
//        delete(head);
//        head = NULL;
//    }
//    return head;
//}
//
//int main()
//{
//struct trie * t = new trie;
//insert(t,"Ajay");
//isEmpty(t)?cout<< "Found" <<endl: cout << "Not Found" <<endl;
////insert(t,"Engineering");
////search(t,"Ajay")?cout<< "Found" <<endl: cout << "Not Found" <<endl;
////search(t,"past")?cout<< "Found" <<endl: cout << "Not Found" <<endl;
////del(t,"Engineering",0);
////search(t,"Engineering")?cout<< "Found" <<endl: cout << "Not Found" <<endl;
//    return 0;
//}
