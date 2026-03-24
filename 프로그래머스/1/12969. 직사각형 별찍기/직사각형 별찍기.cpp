#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    string star = "";
    
    cin >> a >> b;
    
    for(int i = 0; i < a; ++i)
        star += '*';
    
    for(int i = 0; i < b; ++i)
        cout << star << endl;
    
    return 0;
}