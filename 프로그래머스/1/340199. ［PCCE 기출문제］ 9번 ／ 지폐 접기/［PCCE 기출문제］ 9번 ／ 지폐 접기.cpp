#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(max(wallet[0], wallet[1]) < max(bill[0], bill[1]) 
        || min(wallet[0], wallet[1]) < min(bill[0], bill[1]))
    {
        (bill[0] > bill[1]) ? bill[0] = bill[0] >> 1 : bill[1] = bill[1] >> 1;
        ++ answer;
    }
    
    return answer;
}