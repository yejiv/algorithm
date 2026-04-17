#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
   std::vector<long long> answer;
    for (long long number : numbers) {
        long long bit = 1;
        while ((number & bit) > 0) bit <<= 1;
        answer.push_back(number + bit - (bit >> 1));
    }
    return answer;
}