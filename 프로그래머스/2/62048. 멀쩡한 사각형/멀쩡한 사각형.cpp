#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long solution(int w,int h) {
    long long mod = gcd(w, h);
    long long count = mod - 1;
    
    return (long long)w * h - ((w - 1 - count) + (long long)h);
}