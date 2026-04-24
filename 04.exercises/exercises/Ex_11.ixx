export module Ex_11;

export void Ex_11();

import std;
using namespace std;

//Fibonacci series
void Ex_11()
{
	cout << "How many terms do you want to request of a Fibonacci series?" << '\n';
	int num = -1;
	bool b = false;
	string s = "-1";

	while (!b)
	{
		if (cin >> num)
		{
			if (num < 1)
				cout << "Your enter value should be greater than 0!" << '\n';
			else
				b = true;
		}
		else
		{
			cin.clear();
			cin >> s;
			cout << "You should enter an integer!" << '\n';
		}
	}
	if (num == 1)
		cout << "The first term of Fibonacci series is 0" << '\n';
	else if (num == 2)
		cout << "The first 2 terms of Fibonacci series are 0 and 1" << '\n';
	else
	{
		vector<int> Fibonacci;
		int term = -1;
		Fibonacci.push_back(0);
		Fibonacci.push_back(1);
		for (int i = 2; i < num; ++i)
		{
			term = Fibonacci[i - 1] + Fibonacci[i - 2];
			Fibonacci.push_back(term);
		}

		cout << "The first " << num << " terms of Fibonacci series are:\n";
		for (int i = 0; i < Fibonacci.size(); ++i)
			cout << Fibonacci[i] << '\n';
	}
}