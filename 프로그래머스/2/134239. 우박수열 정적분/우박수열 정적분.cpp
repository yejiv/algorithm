#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    double prev_node = k;
    vector<double> acc_sum;
    
    acc_sum.push_back(0);
    
    while(k > 1)
    {
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
                
        acc_sum.push_back(acc_sum.back() + ((prev_node + k) / 2));
        prev_node = k;
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