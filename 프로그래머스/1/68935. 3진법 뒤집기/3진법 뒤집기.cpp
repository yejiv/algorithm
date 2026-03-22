#include <string>
#include <vector>
#include <cmath>

using namespace std;


int solution(int n) {
    int         answer = 0, size = 0;
    vector<int> mod;
    
    while(n > 0)
    {
        mod.push_back(n % 3);
        n /= 3;
    }
    
    size = mod.size();
    for(int i = 0; i < size; ++i)
        answer += mod[size - i - 1] * pow(3, i);

    
    return answer;
}
