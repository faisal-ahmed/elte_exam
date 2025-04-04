#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool fileReadError = true, taskThreeFoundFlag = false;
    int passengers, exerciseOneAnswer = 0, highestPassengerPerFlight = 0, highestPassengerPerAirlines = 0;
    std::stringstream ss;
    map<string, int> airlinesWithMostPassengerMapping;
    map<string, int>::iterator it_for_airlinesWithMostPassengerMapping;
    string eachLine, airlines, destination;
    string exerciseOneKey = "Frankfurt";
    string exerciseTwoAnswer = "The file is empty!";
    string exerciseThreeAnswer = "There is no flight with passengers less than 100.";
    string exerciseFourAnswer = "The file is empty!";
    ifstream flightDetailsInputFile("input.txt");
    try {
        if ( flightDetailsInputFile.is_open() ) {
            while ( getline(flightDetailsInputFile, eachLine) )
            {   
                ss.clear();
                airlines.clear();
                
                ss << eachLine;
                ss >> airlines >> destination >> passengers;
                if (airlines.empty()) continue;
                
                //Task 1 Solution
                exerciseOneAnswer += ( (destination == exerciseOneKey) ? 1 : 0 );
                
                //Task 2 Solution
                if (highestPassengerPerFlight < passengers) {
                    highestPassengerPerFlight = passengers;
                    exerciseTwoAnswer = ( airlines + " " + destination + " " + std::to_string(passengers) );
                }
                
                //Task 3 Solution
                if (!taskThreeFoundFlag && passengers < 100) {
                    taskThreeFoundFlag = true;
                    exerciseThreeAnswer = ( airlines + " " + destination + " " + std::to_string(passengers) );
                }
                
                //Task 4 Solution Mapping
                if (airlinesWithMostPassengerMapping.find(airlines) != airlinesWithMostPassengerMapping.end())
                    airlinesWithMostPassengerMapping[airlines] += passengers;
                else airlinesWithMostPassengerMapping[airlines] = passengers;
            }

            //Task 4 Solution Generation
            for (it_for_airlinesWithMostPassengerMapping = airlinesWithMostPassengerMapping.begin(); it_for_airlinesWithMostPassengerMapping != airlinesWithMostPassengerMapping.end(); it_for_airlinesWithMostPassengerMapping++) {
                if (highestPassengerPerAirlines < it_for_airlinesWithMostPassengerMapping->second) {
                    highestPassengerPerAirlines = it_for_airlinesWithMostPassengerMapping->second;
                    exerciseFourAnswer = ( it_for_airlinesWithMostPassengerMapping->first + " " + std::to_string(it_for_airlinesWithMostPassengerMapping->second) );
                }
            }
            flightDetailsInputFile.close();
        } else throw(fileReadError);
    } catch (bool error) {
        cout << "File reading error for input.";
    }

    //Write output to a file
    ofstream outputFile ("output.txt");
    try {
        if ( outputFile.is_open() ) {
            outputFile << exerciseOneAnswer << endl;
            outputFile << exerciseTwoAnswer << endl;
            outputFile << exerciseThreeAnswer << endl;
            outputFile << exerciseFourAnswer << endl;
            outputFile.close();
        } else throw(fileReadError);
    } catch (bool error) {
        cout << "File reading error for output.";
    }

    return 0;
}