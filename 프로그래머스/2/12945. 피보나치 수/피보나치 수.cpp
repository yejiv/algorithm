#include <string>
#include <vector>

using namespace std;

static vector<long>table;

void f(int num)
{
    if (num > 2) f(num - 1);
    table.push_back((table[num - 2] + table[num - 1]) % 1234567);
}

int solution(int n) {        
    //table.push_back(0);
    //table.push_back(1);
    //f(n);
    //return table[n] ;
    vector<int> table(n + 1);

    table[0] = 0;
    table[1] = 1;
    
    for(int i = 2; i < n + 1; ++i)
        table[i] = (table[i - 2] + table[i - 1]) % 1234567;
    
    return (table[n]);
}