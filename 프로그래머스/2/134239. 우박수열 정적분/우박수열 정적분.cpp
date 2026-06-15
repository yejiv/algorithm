#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> graph;
    vector<double> acc_sum;
    
    graph.push_back(k);
    acc_sum.push_back(0);
    
    while(k > 1)
    {
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
                
        acc_sum.push_back(acc_sum.back() + ((graph.back() + k) / 2));
        graph.push_back(k);
    }
    
    for(const auto & r : ranges)
    {
        int end_idx = acc_sum.size() + r[1] - 1;
        if (r[0] > end_idx)
            answer.push_back(-1);
        else
            answer.push_back(acc_sum[end_idx] - acc_sum[r[0]]);
    }
    
    return answer;
}