export module Ex_18;

import std;
using namespace std;

//输入一对名字和值，检查是否重复输入。
//rework version in Chapter5 exercise4
export void Ex_18()
{
	cout << "Please enter a set of name-and-value pairs.(Input 'NoName 0' to terminate)" << '\n';
	vector<string> names;
	vector<int> scores;
	string name;
	int value;
	bool duplicate_name;

	while (cin >> name >> value)
	{
		if (name == "NoName" && value == 0)
			break;
		duplicate_name = false;

		for (const string& x : names)
		{
			if (name == x)
			{
				duplicate_name = true;
				break;
			}
		}
		if (duplicate_name)
		{
			cout << "It's a duplicate name, you have entered it before." << '\n';
		}
		else
		{
			names.push_back(name);
			scores.push_back(value);
		}
	}
	cout << "You have completed entering!" << "\n";

	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << '\t' << scores[i] << '\n';
	}

	cout << "Input 1 to search by name." << "\n"
		<< "Input 2 to search by value" << "\n"
		<< "Input a character to exit." << "\n";

	int input;
	while (cin >> input)
	{
		switch (input)
		{
		case 1:
		{
			cout << "Please enter the name you want to search:" << '\n';
			string search_name;
			cin >> search_name;
			size_t size = names.size();
			int search_value;
			bool has_found = false;
			for (int i = 0; i < size; ++i)
			{
				if (search_name == names[i])
				{
					search_value = scores[i];
					has_found = true;
					break;
				}
			}
			if (has_found)
				cout << search_name << " 的成绩是 " << search_value << '\n';
			else
				cout << "name not foud" << '\n';
			break;
		}

		case 2:
		{
			cout << "Please enter the value you want to search:" << '\n';
			int search_value;
			cin >> search_value;
			size_t size = scores.size();
			vector<string> search_names;
			for (int i = 0; i < size; ++i)
			{
				if (search_value == scores[i])
				{
					search_names.push_back(names[i]);
				}
			}
			if (search_names.size() < 1)
			{
				cout << "score not found" << '\n';
			}
			else
			{
				cout << "成绩为 " << search_value << " 的人有：" << '\n';
				for (const string& x : search_names)
					cout << x << "\n";
			}
			break;
		}

		default:
			cout << "Sorry I don't understand that." << '\n';
			break;
		}

		cout << "Input 1 to search by name." << "\n"
			<< "Input 2 to search by value" << "\n"
			<< "Input a character to exit." << "\n";
	}
}