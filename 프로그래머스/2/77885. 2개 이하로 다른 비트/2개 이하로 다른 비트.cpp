#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer(numbers.size(), 0);
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        string binary = "";
        while(numbers[i])
        {
            binary = to_string(numbers[i] % 2) + binary;
            numbers[i] = numbers[i] >> 1;
        }
        
        binary = "0" + binary;
        
        size_t idx = binary.rfind("01");
        size_t idx2 = binary.rfind("0");
        if (idx == string::npos || idx2 > idx ) binary[idx2] = '1';
        else swap(binary[idx], binary[idx + 1]);
                
        for(int j = 0; binary.size(); ++j)
        {
            answer[i] += (binary.back() - '0') * pow(2, j);
            binary.pop_back();
        }
    }
    
    return answer;
}