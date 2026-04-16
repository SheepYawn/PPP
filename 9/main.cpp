import _9;
import std;

int main()
{
	try
	{
		read_temperature();
		//eg9_5();
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

	return 0;
}