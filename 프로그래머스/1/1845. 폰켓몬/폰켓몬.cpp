#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    return (nums.size() < max) ? nums.size() : max;
}