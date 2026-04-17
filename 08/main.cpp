import _8;
import std;

int main()
{
	try
	{
		//_8_4_try();
		//_8_5();
		//_8_6();
		_8_6_try();

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