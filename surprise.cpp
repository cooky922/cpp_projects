#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

#include <thread>
#include <chrono>

int main() {
    using std::this_thread::sleep_for;
    using std::chrono::milliseconds;
    using std::chrono::seconds;

    std::string color_list[10] = {
                               "color 2e", "color e2", "color 3f",
                               "color f3", "color 9e", "color e9",
                               "color 1f", "color f1", "color 57",
                               "color 75"
                                 };

    std::string console_title = "Suprise!";
    system((std::string("title ") + console_title).c_str());

    for (int i = 1; i <= 10; ++i) {
        std::cout << " " << i << " . . ." << '\n';
        system(color_list[i - 1].c_str());
        sleep_for(seconds(1));
    }
    std::cout << '\n' << " CONGRATULATIONS!!";
    for (int i = 0; i < 10; ++i) {
        system(color_list[i].c_str());
        sleep_for(milliseconds(200));
    }
    sleep_for(seconds(1));
    system("color 07");
    std::cout << '\n';

    return 0;
}
