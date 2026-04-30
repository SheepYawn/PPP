// 重做exercise_2，使用Name_pair类实现Name_pairs。

export module Ex_04;

export void Ex_04();

import PPP;
import functions;
using namespace std;

const string end_input = "finished";

class Name_pair
{
public:
	Name_pair(string s) :name{ s }, age{ 0 }{}
	string get_name() const { return name; }
	double get_age() const { return age; }
	void set_age(double a) { if (a < 0) PPP::error("age should be greater than 0"); age = a; }
private:
	string name;
	double age;
};

class Name_pairs
{
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();

private:
	vector<Name_pair> nps;
};

void Name_pairs::read_names()
{
	cout << "Enter a sequence of names. Type '" << end_input << "' to end input." << '\n';
	for (string s; cin >> s; )
	{
		if (s == end_input)
			return;
		Name_pair np{ s };
		nps.push_back(np);
	}
}

double get_age_of_name(const string& name)
{
	cout << "Please enter the age of " << name << '\n';
	while (true)
	{
		double age = get_double();
		if (age > 0)
			return age;
		cout << "Sorry, age should be greater than 0; please try again " << '\n';
	}
}

void Name_pairs::read_ages()
{
	int size = PPP::narrow_cast<int>(nps.size());
	for (int i = 0; i < size; ++i)
	{
		double age = get_age_of_name(nps[i].get_name());
		nps[i].set_age(age);
	}
}

void Name_pairs::print() const
{
	int size = PPP::narrow_cast<int>(nps.size());
	for (int i = 0; i < size; ++i)
	{
		cout << nps[i].get_name() << '\t' << nps[i].get_age() << '\n';
	}
}

void Ex_04()
{
	Name_pairs nps;
	nps.read_names();
	nps.read_ages();
	nps.print();
}