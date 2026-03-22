#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    int keyNum = keymap.size();
    int targetNum = targets.size();
    vector<int> answer(targetNum);

    for(int k = 0; k < targetNum; ++k)
    {
        int keydepthSum = 0;
        for(auto& alpha : targets[k])
        {
            int keydepth = -1;
            for(int i = 0; i < keyNum; ++i)
            {
                int idx = keymap[i].find(alpha);
                if (idx != string::npos && (keydepth == -1 || keydepth > idx))
                    keydepth = idx + 1;
            }
            if (keydepth == -1)
            {
                keydepthSum = -1; break;
            }
            keydepthSum += keydepth;
        }
        answer[k] = keydepthSum;
    }
    return answer;
}