#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  std::string tempString = argv[1];
	int signalLevel = atoi(tempString.c_str());
	
	system("watch ./wifiSignal.out %i", signalLevel);
    return 0;
}
