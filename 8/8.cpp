module _8;

import PPP;

using namespace std;


struct Date
{
public:
	Date(int y, int m, int d);
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }

private:
	int y;
	int m;
	int d;
};

Date::Date(int y, int m, int d):y{y}, m{m}, d{d}
{
	if (y < 0 || y > 3000)
		PPP::error("invalid year");
	if (m < 1 || m > 12)
		PPP::error("invalid month");
	if (d < 1)
		PPP::error("invalid day");
	if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		{
			if (d > 29)
				PPP::error("invalid day in February");
		}
		else
		{
			if (d > 28)
				PPP::error("invalid day in February");
		}
	}
	else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d > 31)
		{
			PPP::error("invalid day");
		}
	}
	else
	{
		if (d > 30)
		{
			PPP::error("invalid day");
		}
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
        return os << d.year() << '/' << d.month() << '/' << d.day();
}

void e8_4_t()
{
	Date today(1200, 2, 29);
	cout << today;
}

enum Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum Day_of_Wekk
{
	Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

int to_int(Month m)
{
	return static_cast<int>(m);
}

void bad_code(Month m)
{
	if (m == 17)
		cout << "do_something" << '\n';
	if (m == Monday)
		cout << "do_somthing_else" << '\n';
}

void e8_5()
{
	cout << to_int(Month::nov) << '\n';

	bad_code(jan);
}

vector<string> month_tbl
{
	"Not a month", "January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

enum class Month2
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int to_int(Month2 m)
{
	return static_cast<int>(m);
}

Month2 operator++(Month2& m)
{
	m = (m == Month2::dec) ? Month2::jan : Month2{ to_int(m) + 1 };
	return m;
}

ostream& operator<<(ostream& os, Month2 m)
{
	return os << month_tbl[to_int(m)];
}

void e8_6()
{
	cout << Month2::jan << '\n';
	cout << Month2::apr << '\n';
	Month2 m = Month2::oct;
	cout << ++m << '\n';
	cout << ++m << '\n';
	cout << ++m << '\n';
}

Month2 operator+(const Month2& m1, const Month2& m2)
{
	int m = (to_int(m1) + to_int(m2)) % 12;
	Month2 month = (m == 0) ? Month2::dec : Month2{ m };
	return month;
}

struct Month3
{
	Month2 operator[](const int& m)
	{
		return Month2{ m };
	}
};

void e8_6_t()
{
	Month2 m1 = Month2::apr;
	Month2 m2 = Month2::aug;
	cout << m1 + m2 << '\n';
	Month3 month;
	Month2 m3 = month[5];
	Month2 m4 = month[0];
	cout << m3 << '\n';
	cout << m4 << '\n';
}