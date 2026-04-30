#pragma once
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP.h"

using namespace Graph_lib;


int main()
{
    try
    {
        Application app;

        constexpr Point x{ 100,100 };

        Simple_window win{ x, 600, 400, "test" };
        
        Text t{ Point{200, 200}, "test" };

        win.attach(t);
        win.wait_for_button();
    }
    catch (...)
    {
        cout << "something went wrong\n";
    }
}


