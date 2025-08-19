#include <iostream>
#include <cstdlib>
#include <map>
#include <thread>
#include<string>
#include<chrono>
// to run this file for testing multi-threading programming
// " gcc -o testFile.exe src/testFile.cpp -lstdc++ "
using namespace std::chrono_literals;

void weatherForcast(std::map<std::string, int> weatherData) {
    while(true) {
        for(auto& item : weatherData) {
            item.second++;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        std::this_thread::sleep_for(2000ms);
    }
}
int main(){

    std::map<std::string, int> weatherData = {
        {"Austin",15},
        {"Berline",12},
        {"Egypt",24}
    };   

    std::thread bgWorker(weatherForcast, weatherData);
    system("pause>nul");
}