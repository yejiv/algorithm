#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> CostTable;
unordered_map<string, string> ParentTable;

void selling(const auto & seller, int amount)
{
    int Shared = amount / 10;
    int myShare = (Shared < 1) ? amount : amount - Shared;
    
    CostTable[seller] += myShare;
    
    if (Shared < 1 || ParentTable[seller] == "-")
        return;
    
    selling(ParentTable[seller], Shared);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); ++i)
        ParentTable[enroll[i]] = referral[i];
    
    for(int i = 0; i < seller.size(); ++i)
        selling(seller[i], amount[i] * 100);
    
    for(const auto & e : enroll)
        answer.push_back(CostTable[e]);
    
    return answer;
}