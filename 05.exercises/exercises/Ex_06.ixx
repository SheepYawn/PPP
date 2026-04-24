export module Ex_06;

export void Ex_06();

import std;
using namespace std;

//function for exercise6
//生成不重复的随机字母组合
void spawn_random_num(vector<char>& target)
{
	unsigned int seconds = unsigned int(time(0));
	default_random_engine engine(seconds);
	uniform_int_distribution<int> dist(97, 122);
	int random_num = '#';
	bool different = true;
	for (int i = 0; i < 4; ++i)
	{
		//检查是否和已插入字母重复
		random_num = char(dist(engine));
		for (char& x : target)
		{
			if (random_num == x)
			{
				different = false;
				break;
			}
		}
		if (different)
			target.push_back(random_num);
		else
		{
			--i;
			different = true;
		}
	}
}

//function for exercise6
bool check_input(string s)
{
	if (s.size() != 4)
	{
		cout << "Invalid input. Your number should have exactly 4 letters." << '\n';
		return false;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			//检查每位输入是否是a到z
			if (s[i] < 'a' || s[i] > 'z')
			{
				cout << s[i] << " is not a lowercase letter." << '\n';
				return false;
			}
			//检查每位输入是否重复
			for (int j = i + 1; j < 4; ++j)
			{
				if (s[i] == s[j])
				{
					cout << "Invalid input. All letters must be different." << '\n';
					return false;
				}
			}
		}
		return true;
	}
}

//function for exercise6
void print_introduction()
{
	cout << "Bulls and Cows! Have a try to guess my letters." << '\n'
		<< "You get a 'Bull' for each lowercase letter that is correct and in the correct position." << '\n'
		<< "You get a 'Cow' for each lowercase letter that is correct but in the wrong position." << '\n'
		<< "Please enter 4 different lowercase letters." << '\n';
}

//function for exercise6
void leak_answer(vector<char> target)
{
	cout << "The target is:";
	for (int i = 0; i < target.size(); ++i)
		cout << target[i];
	cout << '!' << '\n';
}

//redo exercise12 in Chapter 4
//这次是生成4个不重复字母
void Ex_06()
{
	//生成4位不重复数字组合
	vector<char> target;
	spawn_random_num(target);
	//cout << "Random letters is ready!" << '\n';

	//leak_answer(target);

	print_introduction();

	int count = 1;
	bool valid_input = false;
	int Bull = 0;
	int Cow = 0;
	string s = " ";
	while (true)
	{
		std::cin >> s;
		if (s == "+-*/" && count > 20)
			break;
		valid_input = check_input(s);
		//核对答案
		if (valid_input)
		{
			for (int i = 0; i < 4; ++i)
			{
				//因为4位各不相同，所以直接找是否有相同的。
				for (char& x : target)
				{
					if (s[i] == x)
						++Cow;
				}
				if (s[i] == target[i])
				{
					++Bull;
					--Cow;
				}
			}
			cout << Bull << " Bull and " << Cow << " Cow" << '\n';
			if (Bull == 4)
				break;
		}
		//恢复默认值
		valid_input = false;
		Cow = 0;
		Bull = 0;
		cin.clear();		//单独输入ctrl+z会使cin为错误状态，程序进入死循环。
		s.clear();
		++count;
		if (count > 20)
		{
			cout << "In case you want to give up, enter '+-*/'." << '\n';
		}
	}
	if (s != "+-*/")
		cout << "Bravo! You guessed it! ";
	for (char& c : target)
		cout << c;
	cout << " is the right answer!\n" << "Rounds you have spent: " << count << '\n';
}

//exercise7 has been implemented in some of my previous exercises