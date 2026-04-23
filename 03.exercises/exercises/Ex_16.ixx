export module Ex_16;

import std;
using namespace std;

//找出字符串的最小、最大和出现次数最多的单词
export void Ex_16()
{
	cout << "Please enter a sequence of strings." << '\n';
	vector<string> sequence;
	vector<string> string_group;
	vector<int> string_frequencies;
	bool has_appeared;

	for (string s; cin >> s;)
	{
		sequence.push_back(s);
		has_appeared = false;

		for (int i = 0; i < string_group.size(); ++i)
		{
			if (s == string_group[i])
			{
				++string_frequencies[i];
				has_appeared = true;
				break;
			}
		}
		if (!has_appeared)
		{
			string_group.push_back(s);
			string_frequencies.push_back(1);
		}
	}

	if (string_group.size() < 1)
		cout << "You haven't entered a string!" << '\n';
	else
	{
		int location = -1;
		int more_frequency = 0;
		for (int i = 0; i < string_frequencies.size(); ++i)
		{
			if (more_frequency < string_frequencies[i])
			{
				more_frequency = string_frequencies[i];
				location = i;
			}
		}

		string biggest = " ";
		string smallest = "~";
		for (int i = 0; i < string_group.size(); ++i)
		{
			string s = string_group[i];
			if (biggest < s)
				biggest = s;
			if (smallest > s)
				smallest = s;
		}

		cout << "The min string is " << smallest << '\n'
			<< "The max string is " << biggest << '\n'
			<< "The mod string is " << string_group[location] << '\n';		//没有处理有多个众数的情况。
	}
}