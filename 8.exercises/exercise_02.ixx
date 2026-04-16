export module exercise_02;

import PPP;
using namespace std;

export void test_02();
export void test_03();

namespace ex_02
{
	export void test()
	{
		std::cout << "OK" << '\n';
		PPP::error("okok");
	}
}
