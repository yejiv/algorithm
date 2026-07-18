using namespace std;

long long solution(int price, int money, int count)
{
    long long total_cost = 1LL * price * count * (count + 1) / 2;
    
    long long shortfall = total_cost - money;

    return shortfall > 0 ? shortfall : 0;
}