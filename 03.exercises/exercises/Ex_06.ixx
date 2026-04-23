export module Ex_06;

import std;
using namespace std;

//简易四则运算
export void Ex_06()
{
	cout << "Please enter two values and an operator.(+, -, *, /)" << endl;
	double v1, v2;
	char op;
	cin >> v1 >> v2 >> op;
	if (op == '+')
		cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2;
	else if (op == '-')
		cout << "The difference between " << v1 << " and " << v2 << " is " << v1 - v2;
	else if (op == '*')
		cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2;
	else if (op == '/')
		cout << "The division of " << v1 << " and " << v2 << " is " << v1 / v2;
	else
		cout << "Sorry I don't understand that operator.";
	cout << endl;
}