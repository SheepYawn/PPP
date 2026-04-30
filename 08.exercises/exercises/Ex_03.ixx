// 用全局<<替换Name_pairs::print()；
// 为Name_pairs定义 == 和 !=

export module Ex_03;

export void Ex_03();

import Ex_02;
import PPP;
using namespace std;

ostream& operator<<(ostream& os, const Name_pairs& nps)
{
	nps.print();
	return os;
}

bool operator==(const vector<string>& vs1, const vector<string>& vs2)
{
	if (vs1.size() != vs2.size())
		return false;
	size_t size = vs1.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (vs1[i] != vs2[i])
			return false;
	}
	return true;
}

bool operator==(const vector<double>& vs1, const vector<double>& vs2)
{
	if (vs1.size() != vs2.size())
		return false;
	int size = PPP::narrow_cast<int>(vs1.size());
	for (int i = 0; i < size; ++i)
	{
		if (vs1[i] != vs2[i])
			return false;
	}
	return true;
}

bool operator==(const Name_pairs& nps1, const Name_pairs& nps2)
{
	if (nps1.get_name() != nps2.get_name())
		return false;
	if (nps1.get_age() != nps2.get_age())
		return false;
	return true;
}

bool operator!=(const Name_pairs& nps1, const Name_pairs& nps2)
{
	return !(nps1 == nps2);
}

void Ex_03()
{
	Name_pairs nps;
	nps.read_names();
	nps.read_ages();
	Name_pairs nps2;
	nps2.read_names();
	nps2.read_ages();
	if (nps == nps2)
		cout << "The two Name_pairs are euqal" << '\n';
	else
		cout << "The two Name_pairs are not euqal" << '\n';
	cout << nps << '\n';
}
