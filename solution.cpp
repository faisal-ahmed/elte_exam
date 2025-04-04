#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool fileReadError = true;
    ifstream flightDetailsInputFile("input.txt");
    try {
        if (flightDetailsInputFile.is_open()) {
            std::stringstream ss;
            string eachLine, airlines, destination;
            int passengers;

            while ( getline(flightDetailsInputFile, eachLine) )
            {   
                ss.clear();
                ss << eachLine;
                ss >> airlines >> destination >> passengers;
                cout << airlines << "---" << destination << "---" << passengers << endl;
            }

            flightDetailsInputFile.close();
        } else throw(fileReadError);
    } catch (bool error) {
        cout << "File reading error.";
    }

    return 0;
}