export module Ex_04;

import std;
using namespace std;

export void Ex_04();
export int string_to_positive_integer(string);

//class for exercise4
class Name_value
{
public:
	string name;
	int grade;
	Name_value(string n) :name{ n }, grade{ -1 }
	{}
	Name_value(string n, int g) :name{ n }, grade{ g }
	{}
};

//function for exercise4 and exercise8
//处理数字前的正号'+'
void deal_with_plus_sign(string& s)
{
	if (s[0] == '+')
		s.erase(0, 1);
}

//function for exercise4 and exercise8
//判断字符串是不是正整数和0
bool is_integer(string& s)
{
	deal_with_plus_sign(s);
	for (char x : s)
	{
		if (x < '0' || x > '9')
			return false;
	}
	return true;
}

//function for exercise4 and exercise8
//输入字符串转换为正整数和0
int string_to_positive_integer(string s)
{
	if (is_integer(s))
	{
		int num = 0;
		const size_t size = s.size();
		unsigned int digit = unsigned int(pow(10, size - 1));
		int add = -1;
		for (size_t i = 0; i < size; ++i)
		{
			add = (s[i] - '0') * digit;
			//边界检查
			if (num > numeric_limits<int>::max() - add)
				return -1;
			num += add;
			digit /= 10;
		}
		return num;
	}
	else
		return -1;
}

//function for exercise4
//找同名位置，把位置存入数组
std::vector<int> search_name(vector<Name_value>& Nvs, string name)
{
	vector<int> names;
	for (int i = 0; i < Nvs.size(); ++i)
	{
		if (Nvs[i].name == name)
			names.push_back(i);
	}
	return names;
}

//function for exercise4
//找成绩，把位置存入数组
vector<int> search_grade(vector<Name_value>& Nvs, int grade)
{
	vector<int> grades;
	for (int i = 0; i < Nvs.size(); ++i)
	{
		if (Nvs[i].grade == grade)
			grades.push_back(i);
	}
	return grades;
}

//function for exercise4
//输入(名字_成绩)
void input_pairs(vector<Name_value>& Nvs)
{
	string input_name = " ";
	string input_grade = " ";
	int grade;
	vector<int> positions;
	while (true)
	{
		positions.clear();
		cin >> input_name >> input_grade;
		//输入字符串转换为正整数
		grade = string_to_positive_integer(input_grade);
		if (grade < 0 || grade > 100)
		{
			cout << "grade should be between 0 and 100" << '\n';
			continue;
		}
		//结束输入
		if (input_name == "NoName" && grade == 0)
			break;
		//检查输入名字是否已存在
		positions = search_name(Nvs, input_name);

		if (positions.size() > 0)
			cout << "It's a duplicate name, you have entered it before." << '\n';
		else
		{
			Name_value nv(input_name, grade);
			Nvs.push_back(nv);
		}
	}
}


//rework exercise20 of Chapter3
void Ex_04()
{
	cout << "Please enter a set of name-and-value pairs.(Input 'NoName 0' to terminate)" << '\n';
	vector<Name_value> Nvs;

	input_pairs(Nvs);

	cout << "You have completed entering!" << "\n"
		<< "Pairs you have entered: " << '\n';
	//打印所有输入(名字_成绩)
	for (Name_value x : Nvs)
		cout << "name: " << x.name << '\t' << "grade:" << x.grade << '\n';

	string input;
	while (cin)
	{
		cout << '\n' << "Input 1 to search by name." << "\n"
			<< "Input 2 to search by value" << "\n"
			<< "Input e to exit." << "\n";
		cin >> input;
		switch (input[0])
		{
		case '1':
		{
			cout << "Please enter the name you want to search:" << '\n';
			string input_name;
			cin >> input_name;
			vector<int> names = search_name(Nvs, input_name);
			if (names.size() > 0)
			{
				int position = -1;
				for (int i = 0; i < names.size(); ++i)
				{
					position = names[i];
					cout << Nvs[position].name << " 的成绩是 " << Nvs[position].grade << '\n';
				}
			}
			else
				cout << "name not foud" << '\n';
			break;
		}
		case '2':
		{
			cout << "Please enter the value you want to search:" << '\n';
			string input_value;
			cin >> input_value;
			int s_grade = -1;
			if (is_integer(input_value))
			{
				s_grade = string_to_positive_integer(input_value);
				if (s_grade < 0 || s_grade > 100)
					cerr << "Your integer should be between 0 and 100" << '\n';
			}
			else
				cerr << "You should enter an integer" << '\n';
			vector<int> names = search_grade(Nvs, s_grade);

			if (names.size() < 1)
				cout << "score not found" << '\n';
			else
			{
				cout << "成绩为 " << s_grade << " 的人有：" << '\n';
				for (int i = 0; i < names.size(); ++i)
					cout << Nvs[names[i]].name << "\n";
			}
			break;
		}
		case 'e':
			return;
		default:
			cout << "Sorry I don't understand that." << '\n';
			break;
		}
	}
}