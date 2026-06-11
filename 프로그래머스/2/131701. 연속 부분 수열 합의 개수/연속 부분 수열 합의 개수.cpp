#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> s;
    
    for(int size = 1; size <= elements.size(); ++size)
    {
        int sum = 0;
        for(int i = 0; i < size; ++i)
            sum += elements[i];
        s.insert(sum);

        for(int i = 1; i < elements.size(); ++i)
        {
            sum -= elements[i - 1];
            sum += elements[(i + (size - 1)) % elements.size()];
            s.insert(sum);
        }
    }
    
    return s.size();
}