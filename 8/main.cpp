import _8;
import std;

int main()
{
	try
	{
		//e8_4_t();
		//e8_5();
		//e8_6();
		e8_6_t();

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