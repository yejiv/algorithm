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
    table.push_back(0);
    table.push_back(1);
    f(n);
    return table[n] ;
}