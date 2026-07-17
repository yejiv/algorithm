#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> signals) {
    long long max_t = 1;
    
    for (const auto& sig : signals) 
    {
        int c = sig[0] + sig[1] + sig[2];
        max_t = std::lcm(max_t, (long long)c);
    }
    
    for (long long t = 1; t <= max_t; ++t) 
    {
        bool all_yellow = true;
        
        for (const auto& sig : signals) {
            int g = sig[0];
            int y = sig[1];
            int c = g + y + sig[2];
            
            long long current_time_in_cycle = (t - 1) % c;
            
            if (!(g <= current_time_in_cycle && current_time_in_cycle < g + y)) 
            {
                all_yellow = false;
                break;
            }
        }
        
        if (all_yellow)
            return (int)t;
    }
    
    return -1;
}