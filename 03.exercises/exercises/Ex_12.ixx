export module Ex_12;

import std;
using namespace std;

//找出1到100的质数
export void Ex_12()
{
	vector<int> primes = { 2 };
	bool is_prime;

	for (int i = 2; i < 101; ++i)
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
	cout << "prime numbers between 0 and 100:" << '\n';
	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << '\n';
}