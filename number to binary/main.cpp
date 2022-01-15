#include <iostream>

using namespace std;

int power(int n){int result=1;
for(int i=0;i<n;i++){
    result*=2;
} return result;
}

int main()
{
    cout << "Hello world! This is code to convert number to binary(4 bit)" << endl;
    cout << "Enter a number: ";
    int n;
    cin>>n;
   if(n>15){cout<<"You can't enter more than '15' as it is code for 4 bit!!!" ;exit;}
    for(int i=3;i>=0;i--){
        if(n>=power(i)){
           cout<<1;
            n-=power(i);
           }else{
           cout<<0;}}
    return 0;
}
