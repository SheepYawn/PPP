export module Ex_04;

import std;
using namespace std;

//输入一组城市间的距离，打印最短、最长和平局距离
export void Ex_04()
{
	cout << "Please enter the distances between two neibouring cities." << endl;
	vector<double> distances;
	double distance;

	if (!(cin >> distance))
	{
		cout << "You haven't entered a value!" << endl;
		return;
	}
	distances.push_back(distance);
	double smallest = distance;
	double greatest = distance;
	double sum = distance;

	while (cin >> distance)
	{
		distances.push_back(distance);
		if (distance > greatest)
			greatest = distance;
		else if (distance < smallest)
			smallest = distance;

		sum += distance;
	}

	cout << "The greatest distance between two neibouring cities is " << greatest << endl
		<< "The smallest distance between two neibouring cities is " << smallest << endl
		<< "The mean distance between two neibouring cities is " << sum / distances.size() << endl;
}