#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    
    vector<int> answer;
    int backupN(n), backupM(m), mod;
    
    if (n < m)
    {
        int tmp = n;
        n = m;
        m = tmp;
    }

    while(mod = n % m)
    {
        n = m;
        m = mod;
    }
    
    answer.push_back(m); 
    answer.push_back(backupN * backupM / m); 

    return answer;
}