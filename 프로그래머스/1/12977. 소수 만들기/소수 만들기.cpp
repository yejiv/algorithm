#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();
    
    for(int i = 0; i < size - 2; ++i)
    {
        for(int j = i + 1; j < size - 1; ++j)
        {
            for(int k = j + 1; k < size; ++ k)
            {
                bool flag = true;
                int sum = nums[i] + nums[j] + nums[k];
                for(int m = 2; m <= sqrt(sum); ++m) 
                    if (sum % m == 0)
                        flag = false; 
                if (flag)
                    ++answer;
            }
        }
    }

    return answer;
}