#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int fill = section[0] - 1;
    int sectionNum = section.size();
    
    for(int i = 0; i < sectionNum; ++i)
    {
        if (fill < section[i])
        {
            fill = section[i] + m - 1;
            ++ answer;
        }
        if (fill >= section[sectionNum - 1])
            break;
    }
    
    return answer;
}