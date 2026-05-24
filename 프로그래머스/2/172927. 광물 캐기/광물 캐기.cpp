#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int diamond;
    int iron;
    int stone;
};

bool cmp (const Node& n1, const Node& n2)
{
    if (n1.diamond != n2.diamond) return n1.diamond > n2.diamond;
    if (n1.iron != n2.iron) return n1.iron > n2.iron;
    return n1.stone > n2.stone;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<Node> v;
    Node n = {0, 0, 0};
    int c = min(picks[0] * 5 + picks[1] * 5 + picks[2] * 5, (int)minerals.size());

    for(int i = 0; i < c; ++i)
    {
        if (minerals[i] == "diamond") ++ n.diamond;
        else if (minerals[i] == "iron") ++ n.iron;
        else  ++ n.stone;
        
        if ((i + 1) % 5 == 0 || i == c - 1)
        {
            v.push_back(n);
            n = {0, 0, 0};
        }
    }
    
    sort(v.begin(), v.end(), cmp);
        
    for(int i = 0; i < v.size(); ++i)
    {
        if (picks[0])
        {
            answer += v[i].diamond;
            answer += v[i].iron;
            answer += v[i].stone;
            --picks[0];
        }
        else if (picks[1])
        {
            answer += v[i].diamond * 5;
            answer += v[i].iron;
            answer += v[i].stone;
            --picks[1];
        }
        else if (picks[2])
        {
            answer += v[i].diamond * 25;
            answer += v[i].iron * 5;
            answer += v[i].stone;
            --picks[2];
        }
    }
    
    return answer;
}