#include <iostream>
#include <string>
using namespace std;

int main() {
    //String Createion
    string str1; 
    //input
    cin >> str1;
     //getline(cin, str1);
    //print
    cout << str1 << endl;

    cout << "Length of string: " << str1.length() << endl;
    cout << "is Empty or not: " << str1.empty() << endl;
    
    //push back, pop back, substr
    str1.push_back('A');
    cout << str1 << endl;
    str1.pop_back();
    cout << str1 << endl;
    cout << str1.substr(0, 6) << endl;
    

    return 0;
}