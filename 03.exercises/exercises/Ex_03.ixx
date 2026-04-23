export module Ex_03;

import std;
using namespace std;

//打印中位数
export void Ex_03()
{
	vector<double> temps;
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0;
	for (double x : temps)
		sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';

	ranges::sort(temps);
	cout << "Median temperature: ";
	if (temps.size() % 2 != 0)
		cout << temps[temps.size() / 2] << '\n';
	else
		cout << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << endl;
}