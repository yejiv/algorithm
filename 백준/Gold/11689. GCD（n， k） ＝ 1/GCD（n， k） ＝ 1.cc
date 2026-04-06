#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N(0);
	long long result(0);

	cin >> N;
	result = N;

	for (long long i = 2; i <= sqrt(N); ++i)
	{
		if (N % i != 0)
			continue;
		
		result -= result / i;

		while (N % i == 0)
			N /= i;

	}

	if (N > 1)
		result -= result / N;

	cout << result << endl;

	return 0;
}