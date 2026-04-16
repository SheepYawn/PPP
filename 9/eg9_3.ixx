export module eg9_3;

import PPP;
using namespace std;

export void read_temperature();

struct Reading
{                               // a temperature reading
    int hour;                   // hour after midnight [0:23]
    double temperature;         // in Fahrenheit
};

void read_temperature()
{

    cout << "Current working directory: "
        << std::filesystem::current_path() << '\n';
    cout << "Please enter input file name: " << '\n';
    string iname;
    //cin >> iname;
    iname = "temperature_readings.txt";
    ifstream ist{ iname };                          // ist reads from the file named iname
    if (!ist)
        PPP::error("can't open input file ", iname);

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost{ oname };                       // ost writes to a file named oname
    if (!ost)
        PPP::error("can't open output file ", oname);

    vector<Reading> temps;                   // store the readings here
    int hour = -1;
    double temperature = -700;
    while (ist >> hour >> temperature) {
        if (hour < 0 || 23 < hour)
            PPP::error("hour out of range");
        temps.push_back(Reading{ hour,temperature });
    }

    for (Reading x : temps)
        ost << '(' << x.hour << ',' << x.temperature << ")\n";
}