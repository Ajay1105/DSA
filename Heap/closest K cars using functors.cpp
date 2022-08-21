#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class car{
private:
    int id;
    int x;
    int y;
public:
    car(int id,int x,int y){
    this->id=id;
    this->x =x;
    this->y =y;
    }

    int dist(){
    return x*x + y*y;
    }

    void print(){
    cout<<id <<" "<< x << " " << y<< " "<<endl;
    }
};

class carCampatator{
public:
    // Below is a functor here a object is behaving as a function.
    bool operator()(car a,car b){
    return a.dist() > b.dist();
    }
};


int main(){
priority_queue <car,vector<car>,carCampatator> pq;
int x[8] = {3,5,2,7,1,0,6,8};
int y[8] = {0,3,7,6,4,2,2,6};
for(int i=0;i<8;i++){
    car c(i,x[i],y[i]);
    pq.push(c);
}
for(int i=0; i<8;i++){
    car p = pq.top();
    p.print() ;
    pq.pop();
}
  return 0;
}
