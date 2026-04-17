export module _9_5;

export void _9_5();

import PPP;
using namespace std;

void skip_to_int()
{
    if (cin.fail())
    {
        cin.clear();
        for (char ch; cin >> ch;)
        {
            if (isdigit(ch) || ch == '-')
            {
                cin.unget();
                return;
            }
        }
    }
    PPP::error("no input");
}

int get_int()
{
    int n = 0;
    while (true)
    {
        if (cin >> n)
            return n;
        cout << "Sorry, that was not a number; please try again" << '\n';
        skip_to_int();
    }
}

int get_int(int low, int high, const string& greeting, const string& sorry)
{
    cout << greeting << ": [" << low << ':' << high << "]" << '\n';

    while (true)
    {
        int n = get_int();
        if (low <= n && n <= high)
            return n;
        cout << sorry << ": [" << low << ':' << high << "]" << '\n';
    }
}

void _9_5()
{
    int strength = get_int(1, 10, "enter strength", "Not in range, try again");
    cout << "strength: " << strength << "\n";
}