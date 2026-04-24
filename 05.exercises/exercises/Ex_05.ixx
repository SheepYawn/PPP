export module Ex_05;

export void Ex_05();

import std;
using namespace std;

void error(std::string s)
{
	throw runtime_error(s);
}

//class for exercise5
class Token
{
public:
	char kind;
	int value;
	Token(char k) :kind{ k }, value{ 0 }
	{}
	Token(char k, int v) :kind{ k }, value{ v }
	{}
};

//class for exercise5
class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full = false;
	Token buffer{ '0' };
};

//fuction for exercise5
void Token_stream::putback(Token t)
{
	if (full)
		cerr << "putback() into a full buffer" << '\n';
	buffer = t;
	full = true;
}

//fuction for exercise5
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch = 0;
	if (!(cin >> ch))
		cerr << "no input" << '\n';

	switch (ch)
	{
	case ';':
	case 'q':
	case '(': case ')': case '{': case '}':
	case '&': case '|': case '^': case'~':
		return Token{ ch };
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);	//将一个字符放回输入流中，然后在缓冲区中持续读取数字，直到cin >> val;(double类型)失败。
		int val = 0;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		cerr << "Bad Token" << '\n';
		return -100;
	}
}

//global variable for exercise5
Token_stream ts;
int expression();

//fuction for exercise5
//处理‘（’，‘{’，‘~’，整数
int primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		int d = expression();
		t = ts.get();
		if (t.kind != ')')
			cerr << "'(' expected" << '\n';
		return d;
	}
	case '{':
	{
		int d = expression();
		t = ts.get();
		if (t.kind != '}')
			cerr << "'{' expected" << '\n';
		return d;
	}
	case '~':
	{
		int d = expression();
		d = ~d;
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
		return -100;
	}
}

//fuction for exercise5
int expression()
{
	int left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '&':
			left &= primary();
			t = ts.get();
			break;
		case '|':
			left |= primary();
			t = ts.get();
			break;
		case '^':
			left ^= primary();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//整数按位运算计算器
//能处理‘~’，‘&’，‘|’，‘^’，运算。
//根据第五章的计算器改的。
void Ex_05()
{
	cout << "calculator that deal with bitwise expressions(~, &, |, ^)." << '\n'
		<< "put ';' at the end of each expression to present its end." << '\n';
	int val = 0;
	while (cin)
	{
		Token t = ts.get();
		if (t.kind == 'q')
			break;
		if (t.kind == ';')
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
}