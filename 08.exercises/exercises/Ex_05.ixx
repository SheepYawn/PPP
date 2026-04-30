// 实现图书类
// 成员有：ISBN、title、author、copyright date、checked out(书是否已被。

export module Ex_05;

export void Ex_05();

import PPP;
using namespace std;

class ISBN
{
public:
	ISBN(int, int, int, char);
	bool valid();
private:
	int group;
	int publisher;
	int title;
	char check;
};

ISBN::ISBN(int g, int p, int t, char c):group(g), publisher(p), title(t), check(c)
{
	if (!valid)
		PPP::error("Invalid ISBN");
}

// 获取整数的位数。正负数都可以。
int get_digit(int num)
{
	if (num == 0)
		return 1;
	int digit = 0;
	for (; num != 0 ; ++digit)
		num /= 10;
	return digit;
}

bool ISBN::valid()
// 检验ISBN的有效性。
{
	int group_digit = get_digit(group);
	int publisher_digit = get_digit(publisher);
	int title_digit = get_digit(title);

	constexpr int gmax = 5;				// group的最大有效位数。
	constexpr int pmin = 2;				// publisher的最小有效位数。
	constexpr int pmax = 7;				// publisher的最大有效位数。
	constexpr int tmax = 6;				// title的最大有效位数。
	constexpr int valid_digits = 10;	// ISBN的有效位数

	if (gmax < group_digit)
		return false;
	if (publisher_digit < pmin || pmax < publisher_digit)
		return false;
	if (tmax < title_digit)
		return false;
	if ((group_digit + publisher_digit + title_digit) != valid_digits - 1)
		return false;

	// 计算并检验ISBN的有效位。
	int multiplier = 2;
	int sum = 0;
	// 从低位到高位，每次对10取模，获得最低位的数；再乘以权重。
	for (int i = title; i > 0; i /= 10)
	{
		sum += (i % 10) * multiplier;
		++multiplier;
	}
	for (int i = publisher; i > 0; i /= 10)
	{
		sum += (i % 10) * multiplier;
		++multiplier;
	}
	for (int i = group; i > 0; i /= 10)
	{
		sum += (i % 10) * multiplier;
		++multiplier;
	}

	char check_digit;
	const int int_check = 11 - sum % 11;
	switch (int_check)
	{
	case 11:
		check_digit = '0';
		break;
	case 10:
		check_digit = 'X';
		break;
	default:
		check_digit = int_check + '0';
		break;
	}
	if (check_digit != check)
		return false;
	return true;
}

class Book
{
public:
	Book(ISBN, string, string, string);
	ISBN get_ISBN() const { return isbn; }
	string get_title() const { return title; }
	string get_author() const { return author; }
	string get_copyright_date() const { return copyright_date; }
	bool is_checked_out() const { return checked_out; }
	void check_in() { checked_out = false; }				// 还书
	void check_out() { checked_out = true; }			// 借书
private:
	ISBN isbn;
	string title;
	string author;
	string copyright_date;
	bool checked_out = false;
};

Book::Book(ISBN isbn, string p, string t, string v)
{
	
}