import std;

using namespace std;

int main()
{
    while (cin)
    {
        char ch;
        cin.get(ch);
        if (ch == '\n')
            cout << "find a \\n";
        if (ch == ' ')
            cout << "find a whitespace.";
        if (isspace(ch))
            cout << " That's a space." << '\n';
    }
}