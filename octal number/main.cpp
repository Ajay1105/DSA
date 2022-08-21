#include <iostream>
#include <string>

using namespace std;

int main()
{   string num;
    bool isOctal = true;
    cout << "Enter number" << endl;
    getline(cin,num);
    for(int i=0;i<num.length();i++){
        if(num.at(i) != '0' && num.at(i) != '1' && num.at(i) != '2' && num.at(i) != '3' && num.at(i) != '4' && num.at(i) != '5' && num.at(i) != '6' && num.at(i) != '7'){
            isOctal = false;
            break;
        }
    }
    isOctal? cout << "It is an octal number"<<endl : cout<< "It is not an octal number"<<endl;
    return 0;
}
