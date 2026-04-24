export module Ex_07;

export void Ex_07();

import std;
using namespace std;

//求一元二次方程的根
void Ex_07()
{
	cout << "Please enter a, b, c for ax²+ bx +c = 0, and I' ll print the roots of the equation." << '\n';
	double a, b, c;
	cin >> a >> b >> c;
	cout << "The quadratic eqaution is \"" << a << "x² + " << b << "x + " << c << " = 0\"." << '\n';
	double θ;
	θ = b * b - 4 * a * c;
	if (θ < 0)
		cout << "The equation has no real roots. Sorry I can't solve this equation." << '\n';
	else
	{
		double sqθ = sqrt(θ);
		double x1, x2;
		if (θ == 0)
		{
			x1 = (-b + sqθ) / (2 * a);
			cout << "It has a double root at " << x1 << '\n';
		}
		else
		{
			x1 = (-b + sqθ) / (2 * a);
			x2 = (-b - sqθ) / (2 * a);
			cout << "Its roots are " << x1 << " and " << x2 << '\n';
		}
	}
}