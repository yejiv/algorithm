#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
static int answer = -1;
static unordered_map <int, int> bucket;

void f(int x, int y, int n, int depth)
{
    if (answer != -1 && answer < depth) return;
    if (x == y)  { answer = depth; return; }
    
    if (!bucket.empty())
    {
        auto it = bucket.find(y);
        if (it != bucket.end() && it->second < depth) return;
    }
    bucket[y] = depth; 

    if (y % 2 == 0 && y >> 1 >= x) f(x, y >> 1, n, depth + 1);
    if (y % 3 == 0 && y / 3 >= x) f(x, y / 3, n, depth + 1);
    if (y - n >= x) f(x, y - n, n, depth + 1); 
}

int solution(int x, int y, int n) {

    f(x, y, n, 0);
    return answer;
}
