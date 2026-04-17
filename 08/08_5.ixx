export module _8_5;

export void _8_5();

import std;
using namespace std;

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

void _8_5()
{
	cout << to_int(Month::nov) << '\n';

	bad_code(jan);
}