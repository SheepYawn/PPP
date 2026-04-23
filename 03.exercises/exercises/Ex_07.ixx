export module Ex_07;

import std;
using namespace std;

//拼写0到9的数字
export void Ex_07()
{
	vector<string> nums{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int num;

	cout << "Please enter an integer between 0 and 9 and I'll spell it out" << '\n';
	cin >> num;
	if (num < 0 || num > 9)
		cout << "I can only spell the integer between 0 and 9" << '\n';
	else
		cout << "It's " << nums[num] << '\n';
}