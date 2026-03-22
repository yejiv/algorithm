#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0, maxH = 0;
    
    for(auto& v : sizes)
    {
        if(v[0] < v[1])
            swap(v[0], v[1]);
        
        maxW = (v[0] > maxW) ? v[0] : maxW;
        maxH = (v[1] > maxH) ? v[1] : maxH;
    }
    
    return maxW * maxH;
}