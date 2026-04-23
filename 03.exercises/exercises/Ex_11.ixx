export module Ex_11;

import std;
using namespace std;

//剪刀石头布
export void Ex_11()
{
	cout << "Please enter '0' to represent 'Rock', '1' to represent 'Paper'and '2' to represent 'Scissors'.(Enter a character to exit.)" << '\n';
	int input;

	clock_t start_time = clock();
	clock_t current_time;
	int duration;

	string result;
	int win = 0, lose = 0, draw = 0;

	while (cin >> input)
	{
		current_time = clock();
		duration = (current_time - start_time);
		duration %= 3;

		switch (input)
		{
		case 0:
			switch (duration)
			{
			case 0:
				result = "Draw";
				++draw;
				break;

			case 1:
				result = "You Lose";
				++lose;
				break;

			case 2:
				result = "You Win";
				++win;
				break;
			}
			break;

		case 1:
			switch (duration)
			{
			case 0:
				result = "You Win";
				++win;
				break;

			case 1:
				result = "Draw";
				++draw;
				break;

			case 2:
				result = "You Lose";
				++lose;
				break;
			}
			break;

		case 2:
			switch (duration)
			{
			case 0:
				result = "You Lose";
				++lose;
				break;

			case 1:
				result = "You Win";
				++win;
				break;

			case 2:
				result = "Draw";
				++draw;
				break;
			}
			break;

		default:
			result = "Please enter 0, 1, or 2.";
			break;
		}
		cout << result << '\n';
	}

	cout << "You have won " << win << " times, "
		<< "drawn " << draw << " times, "
		<< "lost " << lose << " times.";
}