export module functions;

export double get_double();

import PPP;
using namespace std;

// 跳过输入中不是数的部分。
void skip_to_double()
{
	if (cin.fail())
	{                                                   // we found something that wasn’t an integer
		cin.clear();                                             // we’d like to look at the characters
		for (char ch; cin >> ch; )
		{                      // throw away non-digits
			if (isdigit(ch) || ch == '.' || ch == '-')
			{
				cin.unget();                          // put the digit back, so that we can read the number
				return;
			}
		}
	}
	PPP::error("no input");                                           // eof or bad: give up
}

// 从cin获取double类型的数，如果不是数则需要重新输入。
double get_double()
{
	double num = 0;
	while (true)
	{
		if (cin >> num)
			return num;
		cout << "Sorry, that was not a number; please try again " << '\n';
		skip_to_double();
	}
}