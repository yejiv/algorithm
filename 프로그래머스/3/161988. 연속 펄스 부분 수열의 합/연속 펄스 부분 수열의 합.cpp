#include <string>
#include <vector>
#include <numeric>

using namespace std;

long long partialSum(vector<int>& sequence)
{
    long long current_sum = sequence[0];
    long long max_sum = sequence[0];
    
    for(int i = 1; i < sequence.size(); ++i)
    {
        long long num = sequence[i];
        current_sum = max((long long)num, current_sum + num);
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}

long long solution(vector<int> sequence) {
    int sign = 1;
    
    for(auto & A : sequence)
    {
        A *= sign;
        sign *= -1;
    }
    
    long long sum1 = partialSum(sequence);
    
    for(auto & A : sequence) A *= -1;
    
    long long sum2 = partialSum(sequence);

    return max(sum1, sum2);
}