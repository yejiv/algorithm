#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    for(int i = 0; i < arr.size(); ++i)
    {
        if (answer < arr[i]) swap(answer, arr[i]);

        int a = answer; int b = arr[i];
                
        while(b)
        {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        
        answer = (answer / a) * arr[i];
    }
    
    return answer;
}