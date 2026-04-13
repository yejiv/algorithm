#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int table[60001];
    
    table[0] = 1;
    table[1] = 1;
    
    for(int i = 2; i <= 60000; ++i)
        table[i] = (table[i - 1] + table[i - 2]) % 1000000007;
    
    return table[n];
}
