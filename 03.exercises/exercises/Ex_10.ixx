export module Ex_10;

import std;
using namespace std;

//研究double打印64个格子的米的精度
export void Ex_10()
{
	//int sum = 0;
	double sum = 0;

	//int grain = 1;
	double grain = 1;

	for (int square = 1; square < 65; ++square)
	{
		sum += grain;
		grain *= 2;
		cout << square << "squares of grains amount to " << sum << '\n';
	}
}