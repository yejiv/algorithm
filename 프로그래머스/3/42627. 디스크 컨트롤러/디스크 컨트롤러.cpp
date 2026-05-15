#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int idx;
    int start;
    int d;
};

struct NodeCmp{
    bool operator() (const Node & n1, const Node & n2)
    {
        if (n1.d != n2.d) return n1.d > n2.d;
        if (n1.start != n2.start) return n1.start > n2.start;
        return n1.idx > n2.idx;
    }
};

bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<Node, std::vector<Node>, NodeCmp> pq;
    
    sort(jobs.begin(), jobs.end(), cmp);
        
    int time = 0;
    int idx = 0;
    
    while(!pq.empty() || idx < jobs.size())
    {
        while(idx < jobs.size() && jobs[idx][0] <= time)
        {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            ++ idx;
        }
        
        if (!pq.empty())
        {
            Node cur = pq.top();
            pq.pop();
            time += cur.d;
            answer += (time - cur.start);
        }
        else
            ++time;
    }
    
    return answer /jobs.size() ;
}