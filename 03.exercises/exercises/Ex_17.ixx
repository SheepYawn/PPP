export module Ex_17;

import std;
using namespace std;

//求一元二次方程的解
export void Ex_17()
{
	cout << "Please enter a, b and c of a quadratic equation ax² + bx + c = 0." << '\n';
	double a, b, c, θ, solution1, solution2;
	cin >> a >> b >> c;
	θ = b * b - 4 * a * c;

	if (θ > 0)
	{
		cout << "方程有实数解" << '\n';
		solution1 = (-b + sqrt(θ)) / (2 * a);
		solution2 = (-b - sqrt(θ)) / (2 * a);
		cout << "方程的解为：" << '\n'
			<< solution1 << " 和 " << solution2 << '\n';
	}
	else
	{
		cout << "方程没有实数解" << '\n';
		cout << "方程的解为：" << '\n'
			<< -b / (2 * a) << " + " << sqrt(-θ) / (2 * a) << "i" << " 和 "
			<< -b / (2 * a) << " - " << sqrt(-θ) / (2 * a) << "i" << '\n';
	}
}