//#include <iostream>
//#include <vector>
//#include <queue>
//#include <functional>
//
//using namespace std;
//
//int main()
//{
//    //min heap
//    priority_queue <int, vector<int>, greater<int>> pqMin;
//    //max heap
//    priority_queue <int, vector<int>> pqMax;
//    pqMax.push(0);pqMin.push(0);
//    pqMax.pop();pqMin.pop();
//    int median =0, n;
//    cout<< "pqMax: "<<pqMax.top()<< "  pqMin: " <<pqMin.top()<<endl;
//    while(cin>>n)
//    {
//        int diff = pqMax.size() - pqMin.size();
//        if(diff==0)
//        {
//            median = (pqMax.top()+ pqMin.top())/2;
//cout<< "median till now is: "<< median<<endl;
//        }
//        else if(diff==1)
//        {
//            median = pqMax.top();
//cout<< "median till now is: "<< median<<endl;
//        }
//        else if(diff==-1)
//        {
//            median = pqMin.top();
//cout<< "median till now is: "<< median<<endl;
//        }
//        if(n==-1)
//        {
//            cout<<"Median is: " <<median;
//            break;
//        }
//        else if(n>=pqMin.top())
//        {
//            pqMin.push(n);
//            cout<<n<<"pushed in pqMin"<<endl;
//        }
//        else
//        {
//            pqMax.push(n);
//            cout<<n<<"pushed in pqMax"<<endl;
//        }
//
//        if(diff == 2)
//        {
//            int k=pqMax.top();
//            pqMax.pop();
//            pqMin.push(k);
//        }
//        else if(diff == -2)
//        {
//            int k = pqMax.top();
//            pqMax.pop();
//            pqMax.push(k);
//        }
//    }
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
priority_queue <int, vector<int>, greater<int>> pqMin;
priority_queue <int, vector<int>> pqMax;

void insert(int n)
{

    if(pqMax.size() == pqMin.size())
    {
        if(pqMax.size() == 0)
        {
            pqMax.push(n);
        }
        if(n>pqMin.top())
        {
            pqMin.push(n);
        }
        else
        {
            pqMax.push(n);
        }
    }
    else
    {
        if(pqMax.size()>pqMin.size())
        {
            if(n>pqMax.top())
            {
                pqMin.push(n);
            }
            else
            {
                int temp = pqMax.top();
                pqMax.pop();
                pqMin.push(temp);
                pqMax.push(n);
            }
        }
        else
        {
            if(n<pqMin.top())
            {
                pqMax.push(n);
            }
            else
            {
                int temp = pqMin.top();
                pqMin.pop();
                pqMax.push(temp);
                pqMin.push(n);
            }
        }
    }
}

void median()
{
    if(pqMax.size()==pqMin.size())
    {
        cout<< "Median is: "<< (pqMax.top() +pqMin.top())/2 <<endl;
    }
    else if (pqMax.size()>pqMin.size())
    {
        cout<< "Median is: " << pqMax.top()<<endl;
    }
    else
    {
        cout<< "Median is: "<< pqMin.top() <<endl;
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==-1)
        {
            break;
        }
        insert(n);
        median();
    }

    return 0;
}
