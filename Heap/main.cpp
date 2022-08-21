#include <iostream>
#include <vector>
using namespace std;

class heap{
private:
    vector <int> v;

    // heapify function - rearrange to make a min heap again
    void heapify(int index){
    int leftIndex = index*2;
    int rightIndex = (index*2)+1;

    // first assume index is minimum, then compare it with left and then with right one by one
    int min = index;
    // leftIndex<v.size() checks whether let node exist or not
    if(leftIndex<v.size() && v[leftIndex]<v[index]){
        min = leftIndex;
    }
    if(rightIndex<v.size() && v[rightIndex]<v[index]){
        min = rightIndex;
    }
    // if index is not minimum then swap it with min element
    if(min != index){
        swap(v[index],v[min]);
        // recursively call function again
        heapify(min);
    }
    }

public:
    heap(){
      // Blocking 0th index of vector
      v.push_back(-1);
    }

    void push (int num){
    // push element at last index
    v.push_back(num);
    int index = v.size()-1;
    // find it's parent index
    int parent = index/2;
    // as it is min heap if parent is larger than child swap it
    while(index>1 && v[index]< v[parent]){
        swap(v[index],v[parent]);
        index = parent;
        parent = index/2;
    }
    }

    void display(){
        cout<<v.size()<<endl;
    for(int i=1;i<v.size();i++){
        cout<< v[i] <<endl;
    }
    }

    void pop(){
    // in min heap only smallest/largest element can be removed
    // as smallest element is at index 1, swap it can bring it to lowest index and pop it
    swap(v[1],v[v.size()-1]);
    v.pop_back();
    heapify(1);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    heap first;
    first.push(2);
    first.push(75);
    first.push(8);
    first.push(5);
    first.push(25);
    first.push(70);
    first.display();
    first.pop();
    cout<<endl<<endl;
    first.display();
    return 0;
}
