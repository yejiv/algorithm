#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> assistance;
    int idx = 1;
    
    while(true)
    {   
        if (idx == order[answer])
        {
            ++ answer; ++ idx;
        }
        else if (assistance.size() && assistance.top() == order[answer])
        {
            ++ answer; assistance.pop();
        }
        else if (idx < order.size())
            assistance.push(idx++);
        else 
            break;
    }
    
    return answer;
}
