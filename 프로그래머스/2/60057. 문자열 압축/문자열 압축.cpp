#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int length = s.size();
    int answer = length;
    
    for(int scale = 1; scale <= length >> 1; ++scale)
    {
        string compressed_str = "";
        
        for(int i = 0; i < length; )
        {
            int count = 1;
            string compared_str = s.substr(i, scale);
            
            while(i + scale < length && s.compare(i + scale, scale, compared_str) == 0)
            {
                ++count;
                i += scale;
            }
            
            if (count > 1)
                compressed_str += to_string(count) + compared_str;
            else
                compressed_str += compared_str;
                
            i += scale;
        }
        
        if (compressed_str.size() < answer)
        {
            answer = compressed_str.size(); 
        }
    }
    
    return answer;
}