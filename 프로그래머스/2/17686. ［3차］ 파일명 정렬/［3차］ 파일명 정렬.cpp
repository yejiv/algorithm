#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    string  HEAD;
    string  NUMBER;
    string  TAIL;
    string  head_upper = "";
    int     num;
};

bool cmp(const Node& a, const Node& b)
{
    if (a.head_upper != b.head_upper)
        return a.head_upper < b.head_upper;
    return a.num < b.num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Node> n;
    
    for(const auto & A : files)
    {
        Node newnode;
        int head_idx = 0;
        
        while(head_idx < A.size() && !isdigit(A[head_idx]))
            ++ head_idx;

        int num_idx = head_idx;
        
        while(num_idx < A.size() && isdigit(A[num_idx]))
            ++ num_idx;
        
        newnode.HEAD = A.substr(0, head_idx);
        newnode.NUMBER = A.substr(head_idx, num_idx - head_idx);
        newnode.TAIL = A.substr(num_idx);
        newnode.num = stoi(newnode.NUMBER);
        for(const auto & A : newnode.HEAD)
            newnode.head_upper += toupper(A);
        
        n.push_back(newnode);
    }
    
    stable_sort(n.begin(), n.end(), cmp);
    
    for(const auto & A : n)
        answer.push_back(A.HEAD + A.NUMBER + A.TAIL);
    
    return answer;
}