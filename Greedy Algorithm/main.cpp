#include <bits/stdc++.h>

using namespace std;

// this algo find max activites
//pair->first have starting time of work and pair->second have ending time of work

bool myCmp(pair<int,int> a, pair<int,int> b){
return (a.second < b.second);
}

void maxActivities( pair<int,int> arr[],int n){
sort(arr,arr+n,myCmp);
int act =0;
int res=1;
for(int i=1;i<n;i++){
    if(arr[act].second <= arr[i].first){
      res++;
      act =i;
    }
}
cout << res;
}

int main()
{
    cout << "Hello Greedy Algorithm!" << endl;
    pair<int,int> arr[4];
    arr[0] = make_pair(1,3);
    arr[1] = make_pair(2,4);
    arr[2] = make_pair(3,8);
    arr[3] = make_pair(10,11);
    maxActivities(arr,4);
    return 0;
}
