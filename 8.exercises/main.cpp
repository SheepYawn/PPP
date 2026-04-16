import exercises;
import std;

int main()
{
	try
	{
		test_02();
		test_03();
		ex_02::test();

		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		std::cerr << "Oops: unknown exception!" << '\n';
		return 2;
	}
}