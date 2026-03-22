#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int         size = s.size();
    vector<int> answer(size, -1);
    int         rt;
    
    for(int i = 0; i < size; ++i)
    {
        rt = -1;
        while(true)
        {
            rt = s.find(s[i], (rt == -1) ? 0 : rt + 1);
            if (rt == string::npos || rt >= i) break;
            answer[i] = i - rt;
        }
    }
    
    return answer;
}