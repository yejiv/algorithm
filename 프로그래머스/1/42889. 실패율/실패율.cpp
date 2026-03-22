#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<float, int> a, const pair<float, int> b)
{
    return (a.first == b.first) ? a.second < b.second : a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<pair<int, int>> v(N + 1);
    vector<pair<double, int>> failure(N);
    
    for(int i = N; i >= 0; -- i)
    {
        v[i].first = count(stages.begin(), stages.end(), i + 1); 
        v[i].second = (i < N) ? v[i].first + v[i + 1].second : v[i].first; 
    }
    
    for(int i = 0; i < N; ++i) 
    {
        if (v[i].first)
            failure[i] = { (double)v[i].first / (double)v[i].second, i + 1 };
        else
            failure[i] = {0, i + 1};
    }
        
    
    sort(failure.begin(), failure.end(), compare);

    for(int i = 0; i < N; ++i)
        answer[i] = failure[i].second;
    
    return answer;
}