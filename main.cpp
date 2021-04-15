#include <string>
#include <fstream>  // this is to import the ifstream and ofstream objects
#include <iostream>  // this is to import the cin and cout objects
#include <sstream>
using namespace std;
#include <vector>


/**
 * Reads csv file into table, exported as a vector of vector of doubles.
 * @param inputFileName input file name (full path).
 * @return data as vector of vector of doubles.
 */
vector<vector<double>> parse2DCsvFile(string inputFileName) {

    vector<vector<double> > data;
    ifstream inputFile(inputFileName);
    int l = 0;

    while (inputFile) {
        l++;
        string s;
        if (!getline(inputFile, s)) break;
        if (s[0] != '#') {
            istringstream ss(s);
            vector<double> record;

            while (ss) {
                string line;
                if (!getline(ss, line, ','))
                    break;
                try {
                    record.push_back(stof(line));
                }
                catch (const std::invalid_argument e) {
                    cout << "NaN found in file " << inputFileName << " line " << l
                         << endl;
                    e.what();
                }
            }

            data.push_back(record);
        }
    }

    if (!inputFile.eof()) {
        cerr << "Could not read file " << inputFileName << "\n";
        __throw_invalid_argument("File not found.");
    }

    return data;
}

int main()
{

    const char comma = ',';
    string line, word;

    ifstream in( "C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\ml\\human.txt" );   if ( !in ) { cerr << "Can't open file"; return 1; }
    ofstream out( "C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\ml\\human_mir.csv" );

    while( getline( in, line ) )          // get successive line of text
    {
        stringstream ss( line );
        bool first = true;
        while ( ss >> word )               // get successive words per line
        {
            if ( !first ) out << comma;     // second and later words need a separator
            out << word;
            first = false;
        }
        out << '\n';                      // end of line of output
    }

    vector<vector<double>> data;
    data = parse2DCsvFile("C:\\D\\MS Study\\3rd Semester\\AIS\\RedPitaya\\ml\\human_mir.csv");

    for (auto l : data) {
        for (auto x : l)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
