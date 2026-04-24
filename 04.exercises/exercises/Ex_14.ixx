export module Ex_14;

export void Ex_14();

import std;
using namespace std;

//读入多对数据，计算特殊名称对应的值之和。
void Ex_14()
{
	vector<string> day_of_the_week
	{ "Monday", "Mon.", "Tuesday", "Tues.", "Wednesday", "Wed.",
	"Thursday", "Thur.", "Friday", "Fri.",
	"Saturday", "Sat.", "Sunday", "Sun." };

	vector<string> days;
	vector<int> values;
	string s;
	string num;
	int number = 0;
	bool no_stop = true;
	bool is_integer = true;
	bool is_negative = false;

	cout << "Enter a set of string and value pairs, but only the day of the week string's value will be summed up." << '\n'
		<< "Enter 'Stop!' to end input." << '\n';

	//输入数据
	while (no_stop)
	{
		cin >> s;
		if (s == "Stop!")
			break;

		cout << "You have entered a string. Now enter its value." << '\n';
		cin >> num;

		for (int i = 0; i < num.size(); ++i)
		{
			if (num[0] == '-' && num.size() > 1)
			{
				is_negative = true;
				continue;
			}
			if (num[i] < '0' || num[i] > '9')
			{
				cout << num << " is not an integer. Please enter another pair." << '\n';
				is_integer = false;
				break;
			}
		}

		//存数据
		if (is_integer)
		{
			int digit = 1;
			if (is_negative)
			{
				for (int i = num.size() - 1; i > 0; --i)
				{
					number += (num[i] - '0') * digit;
					digit *= 10;
				}
				number = -number;
			}
			else
			{
				for (int i = num.size() - 1; i > -1; --i)
				{
					number += (num[i] - '0') * digit;
					digit *= 10;
				}
			}
			values.push_back(number);
			days.push_back(s);

			cout << "A pair has been input. You can enter another one." << '\n'
				<< "If you want to end input, enter 'Stop!'." << '\n';

			//for (int i = 0; i < days.size(); ++i)
			//{
			//	cout << "days == " << days[i] << ", value == " << values[i] << '\n';
			//}
		}
		number = 0;
		is_integer = true;
		is_negative = false;
	}
	//比较数据，输出
	int rejected = 0;
	int sum = 0;
	bool match = false;
	for (int i = 0; i < days.size(); ++i)
	{
		for (string& s : day_of_the_week)
		{
			if (days[i] == s)
			{
				match = true;
				break;
			}
		}
		if (match)
			sum += values[i];
		else
			++rejected;

		match = false;
	}
	cout << "The sum of the day-of-the-week values is " << sum << '.' << '\n'
		<< rejected << " numbers have been rejected." << '\n';
}