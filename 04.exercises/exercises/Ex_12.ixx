export module Ex_12;

export void Ex_12();

import std;
using namespace std;

//"Bulls and Cows"。 猜4位不重复的数字组合，返回“Bull”或者“Cow”。
//“Bull”代表数字正确且位置正确；“Cow”代表数字正确，但位置不正确。
void Ex_12()
{
	//生成4位不重复数字组合
	vector<char> target;
	time_t seconds = time(0);
	default_random_engine engine(seconds);
	uniform_int_distribution<int> dist(48, 57);
	int random_num = '#';
	bool different = true;
	for (int i = 0; i < 4; ++i)
	{
		//检查是否和已插入数字重复
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
		{
			target.push_back(random_num);
		}
		else
		{
			--i;
			different = true;
		}
	}
	cout << "Random number is ready!" << '\n';

	//透视
	//cout << "The target is:";
	//for (int i = 0; i < target.size(); ++i)
	//	cout << target[i];
	//cout << '!' << '\n';

	cout << "Bulls and Cows! Have a try to guess my number." << '\n'
		<< "You get a 'Bull' for each digit that is correct and in the correct position." << '\n'
		<< "You get a 'Cow' for each digit that is correct but in the wrong position." << '\n'
		<< "Please enter a 4-digit number with different digits." << '\n';

	//
	vector<char> input;
	int count = 1;
	bool incorrect = true;
	bool valid_input = false;
	int Bull = 0;
	int Cow = 0;
	while (incorrect)
	{
		//输入数据
		string s = " ";
		std::cin >> s;
		if (s.size() != 4)
		{
			cout << "Invalid input. Your number should have exactly 4 digits." << '\n';
			continue;
		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				//检查每位输入是否是0到9
				if (s[i] < '0' || s[i] > '9')
				{
					cout << s[i] << "is not a number." << '\n';
					break;
				}
				//检查每位输入是否已重复
				for (char& x : input)
				{
					if (s[i] == x)
					{
						different = false;
						break;
					}
				}
				if (different)
					input.push_back(s[i]);
				else
				{
					cout << "Invalid input. All digits must be different." << '\n';
					break;
				}
			}
		}

		//for (char& c : input)
		//	std::cout << c << '\n';
		if (input.size() == 4)
			valid_input = true;

		//核对答案
		if (valid_input)
		{
			for (int i = 0; i < 4; ++i)
			{
				//因为4位各不相同，所以直接找是否有相同的。
				for (char& x : target)
				{
					if (input[i] == x)
						++Cow;
				}
				if (input[i] == target[i])
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
		different = true;
		valid_input = false;
		input.clear();
		cin.clear();		//单独输入ctrl+z会使cin为错误状态，程序进入死循环。
		Cow = 0;
		Bull = 0;
		++count;
	}
	cout << "Bravo! You guessed it! ";
	for (char& c : target)
		cout << c;
	cout << " is the right answer!\n" << "Rounds you have spent: " << count << '\n';
}