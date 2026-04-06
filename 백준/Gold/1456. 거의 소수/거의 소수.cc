#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void Sieve_of_Eratosthenes(vector<long long>& arr, long long size);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, calB;
	int result(0);

	cin >> a;
	cin >> b;
	calB = sqrt(b) + 1;

	vector<long long> arr(calB, 0);
	
	Sieve_of_Eratosthenes(arr, arr.size());

	for (long long i = 2; i < arr.size(); ++i)
	{
		if (arr[i] != 0)
		{
			for (int j = 2; arr[i] <= b / pow(arr[i], j - 1); ++j)
			{ 
				if (arr[i] >= a / pow(arr[i], j - 1))
					++result;
			}
		}
	}
	
	cout << result << endl;

	return 0;
}

void Sieve_of_Eratosthenes(vector<long long>& arr, long long size)
{
	arr[0] = 0;
	arr[1] = 0;

	//(1) 시작 범위부터 끝까지 해당 숫자로 초기화
	for (long long i = 2; i < size; ++i)
		arr[i] = i;

	//(2) 소수 아닌 거 루프 돌면서 없애기
	for (long long i = 2; i < size; ++i)
	{
		if (0 == arr[i])
			continue;

		for (long long j = 2; i * j < size; ++j)
			arr[i * j] = 0;
	}
}