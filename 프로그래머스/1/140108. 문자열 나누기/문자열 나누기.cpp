#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char target;
    int dup[2] = {0, 0};
    
    for(auto & alpha : s)
    {
        if (dup[0] == 0)
            target = alpha;
        
        (alpha == target) ? ++dup[0] : ++dup[1];
        
        if (dup[0] == dup[1])
        {
            dup[0] = dup[1] = 0;
            ++ answer;
        }
    }
    
    if (dup[0])
        ++ answer;
    
    return answer;
}