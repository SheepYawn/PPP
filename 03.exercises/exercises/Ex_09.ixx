export module Ex_09;

import std;
using namespace std;

//国王赏不起的米。给1000、1000000、1000000000粒米要多少个格子
export void Ex_09()
{
	int sum = 0;
	int square = 0, grain = 1;
	for (int i = 1000; i <= 1000000000; i *= 1000)
	{
		while (sum < i)
		{
			++square;
			sum = sum + grain;
			grain *= 2;
			cout << square << " squares of grains amonut to " << sum << '\n';
		}
		cout << "To give the inventor at least " << i << " grains, " << square << " squares are needed." << '\n';
		if (i == 1000000000)
			break;
	}
}