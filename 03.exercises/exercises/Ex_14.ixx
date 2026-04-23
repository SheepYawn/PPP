export module Ex_14;

import std;
using namespace std;

//找出前n个自然数
export void Ex_14()
{
	cout << "Enter a num and I'll return the first n primes." << '\n';
	int n;
	cin >> n;

	vector<int> primes = { 2 };
	bool is_prime;

	for (int i = 2; primes.size() < n; ++i)
	{
		is_prime = true;
		for (int j = 0; j < primes.size(); ++j)
		{
			if (i % primes[j] == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			primes.push_back(i);
	}
	cout << "The first " << n << " primes are: " << '\n';
	for (int i = 0; i < n; ++i)
		cout << primes[i] << '\n';
}