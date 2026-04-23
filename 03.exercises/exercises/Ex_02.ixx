export module Ex_02;

import std;
using namespace std;

//输入字符串，遍历打印其每个字符和对应的ASCII值
export void Ex_02()
{
	std::cout << "Please enter a string" << endl;
	string s;
	cin >> s;
	for (char c : s)
		cout << c << '\t' << int(c) << endl;
}