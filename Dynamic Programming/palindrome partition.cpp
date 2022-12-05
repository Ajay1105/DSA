#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string String, int i, int j){
 while(i < j){
 if(String[i] != String[j]) return false;
 i++; j--;
 }  return true;
}

int palPart(string s,int i, int j){
if( i >= j || isPalindrome(s,i,j) )
      return 0;
int res = INT_MAX;
for(int k=i;k<j;k++){
    res = min(res,1+palPart(s,i,k)+palPart(s,k+1,j));
}
return res;
}

int palPart(string str)
{
    int n = str.length();
    int C[n][n];
    bool P[n][n];
    for (int i = 0; i < n; i++) {
        P[i][i] = true;
        C[i][i] = 0;
    }
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
            if (P[i][j] == true)
                C[i][j] = 0;
            else {
                C[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                    C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
            }
        }
    }
    return C[0][n - 1];
}

int main(){
string s= "abbcbbd";
cout << palPart(s,0,s.length()-1) << endl;
cout << palPart(s) << endl;
return 0;
}
