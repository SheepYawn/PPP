export module Ex_02;

export void Ex_02();

import std;
using namespace std;

double ctok(double c)
{
	//int k = c + 273.25;
	//return int
	if (c < -273.15)
	{
		cout << "I don't think that's a right value." << '\n';
		return -1;
	}
	return c + 273.15;
}

double ktoc(double k)
{
	if (k < 0)
	{
		cout << "I dont' think that's a right value." << "\n";
		return -300;
	}
	return k - 273.15;
}

//摄氏度和开氏度的转换
void Ex_02()
{
	double t = 0;
	char m = '\t';
	std::cout << "Input a temperature in Celsius(C) or Kelvin(K) and I'll convert it to the other." << '\n';
	cin >> t >> m;
	switch (m)
	{
	case 'C':
	{
		double k = ctok(t);
		if (k == -1)
			cout << "Your input must be greater than -273.15C!" << '\n';
		else
			cout << "It's " << k << "K" << '\n';
		break;
	}
	case 'K':
	{
		double c = ktoc(t);
		if (c == -300)
			cout << "Your input must be greater than 0K!" << '\n';
		else
			cout << "It's " << c << "C" << '\n';
		break;
	}
	default:
	{
		cout << "You must enter a value with the suffix of 'C' or 'K'!";
		break;
	}
	}
}