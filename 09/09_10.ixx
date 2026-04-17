export module _9_10;

export void _9_10_1_try();
export void _9_10_1();
export void _9_10_6_try();
export void _9_11();

import PPP;
using namespace std;

void _9_10_1_try()
{
	int x = 2003;
	cout << x << '\t' << hex << x << '\t' << oct << x << '\t' << dec << x << '\n';
}

void _9_10_1()
{
	int a = 4095;
	int b = 255;
	int c = 15;
	cout << hex;
	cout << a << '\t' << b << '\t' << c << '\n';
	cout << oct;
	cout << a << '\t' << b << '\t' << c << '\n';
	cout << dec;
	cout << a << '\t' << b << '\t' << c << '\n';
}

void _9_10_6_try()
// a: hexfloat
// e: scientific
// f : fixed
// g : general, with precision 6
// none : general, with default precision
{
	constexpr double d = 1234.56789;
	cout << format("format: {} − {:a} − {:e} − {:f} − {:g}\n", d, d, d, d, d);
	cout << format("width: {} − {:8} − {:16} −\n", d, d, d);
	cout << "width: " << d << " − " << setw(8) << d << "−" << setw(16) << d << '\n';
	cout << format("− {:12} − {:12.8f} − {:30.20e} −\n", d, d, d);
	cout << format("− {:2.2} − {:12.1f} − {:30.2e} −\n", d, d, d);
	cout << format("− {:2.5} − {:12.1f} − {:30.2e} −\n", d, d, d);
}

struct Point
{
	int x, y;
};

Point get_coordinates(const string& s)    // extract {x,y} from "(x,y)"
{
	istringstream is{ s };         // make a stream so that we can read from s
	Point xy;
	char left_paren, ch, right_paren;
	is >> left_paren >> xy.x >> ch >> xy.y >> right_paren;
	if (!is || left_paren != '(' || ch != ',' || right_paren != ')')
		PPP::error("format error: ", s);
	return xy;
}

void _9_11()
{
	auto c1 = get_coordinates("(2,3)");
	auto c2 = get_coordinates("( 200, 300) ");
	//auto c3 = get_coordinates("100,400");              // will call error()

	cout << c1.x << '\t' << c1.y << '\n';
	cout << c2.x << '\t' << c2.y << '\n';
}
