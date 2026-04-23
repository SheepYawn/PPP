export module Ex_15;

import std;
using namespace std;

//找众数
export void Ex_15()
{
	cout << "Please enter a set of integers." << '\n';
	vector<int> nums;
	vector<int> groups;			//相同的值
	vector<int> group_value;	//相同的值的个数，两个vector数组下标对应。
	bool is_match;

	for (int num; cin >> num;)
	{
		nums.push_back(num);
		is_match = false;

		//遍历groups，查找是否有与输入值相等的值。有就把值的个数加一；没有就添加输入值进vector。
		for (int i = 0; i < groups.size(); ++i)
		{
			if (num == groups[i])
			{
				++group_value[i];
				is_match = true;
				break;
			}
		}
		if (!is_match)
		{
			groups.push_back(num);
			group_value.push_back(1);
		}
	}

	if (groups.size() < 1)
		cout << "You haven't entered an integer!" << '\n';
	else
	{
		int location = -1;

		int frequency = 0;
		for (int i = 0; i < group_value.size(); ++i)
			if (frequency < group_value[i])
			{
				frequency = group_value[i];
				location = i;
			}

		//没有处理有多个众数的情况。
		cout << "The integer which appears most is " << groups[location] << ", it appears " << group_value[location] << " times." << '\n';
	}
}