#include <string>
#include <fstream>  // this is to import the ifstream and ofstream objects
#include <iostream>  // this is to import the cin and cout objects
#include <sstream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <limits>
// main.cpp

#include <QCoreApplication>
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketTest cTest;
    cTest.Connect();

    return a.exec();
}
