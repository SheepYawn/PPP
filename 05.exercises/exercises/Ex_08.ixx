export module Ex_08;

export void Ex_08();

import std;
import Ex_04;
using namespace std;

//fuction for exercise8
//计算排列
//如果用 P(a,b) = (a!)/((a-b)!)和阶乘的话，a最大只能为12.
int permutation(int a, int b)
{
	int permutation = 1;
	for (int i = 0; i < b; ++i)
	{
		if (permutation > numeric_limits<int>::max() / (a - i))
			return -1;
		permutation *= (a - i);
	}
	return permutation;
}

//function for exercise8
//计算组合
int combination(int a, int b)
{
	int num = permutation(a, b);
	if (num == -1)
		return -1;
	for (int i = b; i > 1; --i)
		num /= i;
	return num;
}

//fuction for exercise8
//输入两个字符串，转换成非负整数，存入数组。
bool input_two_integer(vector<int>& input)
{
	string a, b;
	cin >> a >> b;
	int num1 = string_to_positive_integer(a);
	int num2 = string_to_positive_integer(b);
	//没有在num1 = -1时马上退出，是为了让缓冲区的数据存入num2。
	if (num1 == -1 || num2 == -1)
		return false;
	input[0] = num1;
	input[1] = num2;
	return true;
}

//计算排列组合
//输入两个数，计算排列数或组合数。
//排列 P(a,b) = (a!)/((a-b)!); 组合C(a,b) = (P(a,b))/(b!)
void Ex_08()
{
	char func = '#';
	vector<int> input(2);
	int result = 0;
	int a = 0, b = 0;
	while (true)
	{
		cin.clear();
		cout << '\n' << "Please enter two non-negative integers." << '\n';
		if (input_two_integer(input))
		{
			a = input[0];
			b = input[1];
			if (a < b)
			{
				cout << a << " should be greater than " << b << '\n';
				continue;
			}
			cout << "Enter 'p' for permutation, 'c' for combination, 'q' to exit." << '\n';
			cin >> func;
			switch (func)
			{
			case 'p':
			{
				result = permutation(a, b);
				if (result == -1)
					cout << "Sorry, I can't solve that." << '\n';
				else
					cout << "P(" << a << " ," << b << ") = " << result << '\n';
				break;
			}
			case 'c':
			{
				result = combination(a, b);
				if (result == -1)
					cout << "Sorry, I can't solve that." << '\n';
				else
					cout << "C(" << a << " ," << b << ") = " << result << '\n';
				break;
			}
			case 'q':
			{
				return;
			}
			default:
			{
				cout << "Sorry I don't understand that." << '\n';
				break;
			}
			}
		}
		else
			cout << "Invalid input, please enter non-negative integers within range(0, 2147483647)." << '\n';
	}
}