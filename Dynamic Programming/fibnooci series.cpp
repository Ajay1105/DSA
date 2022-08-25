#include <iostream>

using namespace std;

int memory[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int fiboonaci(int n){
if(memory[n] == -1){
        int res;
    if(n==0 || n == 1){
        res=n;
    }
    else{
      res = fiboonaci(n-1)+fiboonaci(n-2);
    }
        memory[n] =res;
}
return memory[n];
}

int main()
{

    cout << fiboonaci(8);
    return 0;
}
