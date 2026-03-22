#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int size = numbers.size();
    vector<int> answer;
    
    for(int i = 0; i < size - 1; ++ i)  
        for(int j = i + 1; j < size; ++ j)  
            answer.push_back(numbers[i] + numbers[j]);            
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}