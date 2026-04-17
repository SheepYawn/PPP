export module _8_6;

export void _8_6();
export void _8_6_try();

import std;
using namespace std;

vector<string> month_tbl
{
	"Not a month", "January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int to_int(Month m)
{
	return static_cast<int>(m);
}

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month{ to_int(m) + 1 };
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << month_tbl[to_int(m)];
}

void _8_6()
{
	cout << Month::jan << '\n';
	cout << Month::apr << '\n';
	Month m = Month::oct;
	cout << ++m << '\n';
	cout << ++m << '\n';
	cout << ++m << '\n';
}

Month operator+(const Month& m1, const Month& m2)
{
	int m = (to_int(m1) + to_int(m2)) % 12;
	Month month = (m == 0) ? Month::dec : Month{ m };
	return month;
}

struct Month2
{
	Month operator[](const int& m)
	{
		return Month{ m };
	}
};

void _8_6_try()
{
	Month m1 = Month::apr;
	Month m2 = Month::aug;
	cout << m1 + m2 << '\n';
	Month2 month;
	Month m3 = month[5];
	Month m4 = month[0];
	cout << m3 << '\n';
	cout << m4 << '\n';
}