export module Ex_08;

export void Ex_08();

import std;
using namespace std;

//输入一串数字，求前n个数的和。
void Ex_08()
{
	cout << "Please enter some integers(press '|' to stop): " << '\n';
	vector<double> v;
	vector<double> differences;
	differences.push_back(0);
	double previous = 0, difference = 0;
	char c = ' ';
	int n = -1;

	while (c != '|')
	{
		if (cin >> n)
		{
			v.push_back(n);
			difference = n - previous;
			differences.push_back(difference);
			previous = n;
		}
		else
		{
			cin.clear();
			cin >> c;
			if (c != '|')
				cout << "That's not an integer! If you want to stop input, enter '|'." << '\n';
		}
	}

	//打印所有输入的数
	cout << "Integers you have entered: " << '\n';
	size_t size = v.size();
	for (int i = 0; i < size; ++i)
		cout << v[i] << '\n';
	cout << "That's " << size << "numbers in total." << '\n';

	cout << "Pleasee enter the number of values you want to sum: " << '\n';
	int number = 0;
	double sum = 0;

	bool b = true;
	while (b)
	{
		if (cin >> number)
		{
			if (number > size)
				cout << "That's more than the integers you have entered: " << size << " , Please think of another number." << '\n';
			else if (number < 0)
				cout << "The numbers should be greater than 0! Please think of another number." << '\n';
			else
				b = false;
		}
		else
		{
			cin.clear();
			cin >> c;
			cout << "That's not an integer! Please enter an integer." << '\n';
		}

	}
	cout << "The sum of the first " << number << " numbers ( ";
	for (int i = 0; i < number; ++i)
	{
		cout << v[i] << " ";
		sum += v[i];
	}
	cout << ")is " << sum << '\n';

	//输出difference数组--其中每个元素的值等于v数组位置对应的值与其前一个值的差
	cout << "differences：" << '\n';
	for (int i = 0; i < size; ++i)
	{
		cout << "v[" << i + 1 << "] - v[" << i << "] == " << differences[i + 1] << '\n';
	}
}