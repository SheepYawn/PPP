import exercises;

import std;
using namespace std;

int main()
{
	try {
		//Ex_04();
		//Ex_05();
		//Ex_06();
		Ex_08();

	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown exception" << '\n';
		return 2;
	}
}