export module _8_4;

export void _8_4_try();

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

Date::Date(int y, int m, int d) :y{ y }, m{ m }, d{ d }
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

void _8_4_try()
{
	Date today(1200, 2, 29);
	cout << today;
}