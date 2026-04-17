import std;

using namespace std;

//写信
int main()
{
	string first_name;
	string friend_name;
	int age;

	cout << "Enter the name of the person you want to write to" << endl;
	cin >> first_name;
	cout << "Dear " << first_name << "," << endl;
	cout << "  How are you? I am fine. I miss you. I have been reading your novel <<Brave New World>> recently." << endl;
	cout << "Enter the name of your friend" << endl;
	cin >> friend_name;
	cout << "  Have you seen " << friend_name << " lately?" << endl;
	cout << "Enter the age of the recipient" << endl;
	cin >> age;
	if (age <= 0 || age >= 110)
		cout << "You are kidding!" << endl;
	else
	{
		cout << "  I hear you just had a birthday and you are " << age << " years old.";
		if (age < 12)
			cout << "Next year you will be " << ++age << ".";
		if (age == 17)
			cout << "Next year you will be able to vote.";
		if (age > 70)
			cout << "Are you retired?";
		cout << endl;
		cout << "Yours sincerely," << endl << endl << "Alodous Huxley" << endl;
	}
	return 0;
}