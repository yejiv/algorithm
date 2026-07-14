using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long solution(int w, int h) {
    long long W = w;
    long long H = h;
    
    return (W * H) - (W + H - gcd(W, H));
}