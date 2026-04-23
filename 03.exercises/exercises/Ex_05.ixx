export module Ex_05;

import std;
using namespace std;

//1到100猜数字
export void Ex_05()
{
	cout << "Think a number between 1 and 100 and I'll try to figure it out." << endl;
	int low = 1, high = 100, mid;
	char answer;

	while (low < high)
	{
		mid = (low + high + 1) / 2;
		cout << "Is the number smaller than " << mid << " ? (y/n)" << endl;
		cin >> answer;
		if (answer == 'y')
			high = mid - 1;
		else if (answer == 'n')
			low = mid;
		else
			cout << "I don't understand your input, please enter 'y' or 'n'." << endl;
	}
	cout << "The number must be " << low << " !" << endl;
}

//遍历1到100检查上一个函数
export void check_Ex_05()
{
	for (int i = 1; i < 100; i++)
	{
		int low = 1, high = 100, mid;
		while (low < high)
		{
			mid = (low + high + 1) / 2;
			if (i < mid)
				high = mid - 1;
			else
				low = mid;
		}
		if (low != i)
			cout << "Found a problem, the input number is " << i << endl;
	}
}