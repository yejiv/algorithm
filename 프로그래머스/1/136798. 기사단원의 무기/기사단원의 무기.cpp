#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int N = 1; N < number + 1; ++N)
    {
        int sum = 0;
        for(int i = 1; i <= sqrt(N); ++i)
        {
            if (N % i == 0)
            {
                ++ sum;
                if (i != N / i) ++ sum;
            }
            if (sum > limit)
            {
                sum = power;
                break;
            }
        }
        answer += sum;
    }
    
    return answer;
}