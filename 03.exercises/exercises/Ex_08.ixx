export module Ex_08;

export void Ex_08();

import std;
using namespace std;

vector<string> nums{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> nums_2{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

int string_to_int(const string& s)
{
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (s == nums[i])
			return (int)i;
	}
	for (size_t i = 0; i < nums_2.size(); ++i)
	{
		if (s == nums_2[i])
			return (int)i;
	}
	cerr << "I can't recognize the number: " << s << '\n';
	return -1;
}

void calculate(int v1, int v2, char op)
{
	if ((v1 < 0 || v1 > 9) || (v2 < 0) || (v2 > 9))
	{
		cerr << "The integer number should be in the range (0, 9)." << '\n';
		return;
	}
	if (op == '+')
		cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2;
	else if (op == '-')
		cout << "The difference between " << v1 << " and " << v2 << " is " << v1 - v2;
	else if (op == '*')
		cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2;
	else if (op == '/')
		cout << "The division of " << v1 << " and " << v2 << " is " << v1 / v2;
	else
		cout << "Sorry I don't understand that operator: " << op << '\n';
}

void Ex_08()
{
	cout << "Please enter two integer values(in the range[0, 9]) or their spelled out(e.g.nine) and an operator.(+, -, *, /).\nThe enter sequence should be: number, number, operator" << endl;
	string v1, v2;
	char op;
	cin >> v1 >> v2 >> op;
	int int_v1 = string_to_int(v1);
	int int_v2 = string_to_int(v2);
	calculate(int_v1, int_v2, op);
}