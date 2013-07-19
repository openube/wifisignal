#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  // Setup passed int
	std::string tempString = argv[1];
	int signalLevel = atoi(tempString.c_str());
	cout << "Runaway Level: " << signalLevel << endl;
	
	FILE *btfp;
	int btStatus;
 	std::string btNumberString;
	char btPath[1035];
	int samples = 0;
	int awayCount = 0;
	
	
while (samples < 10){
  /* Open the command for reading. */
  //btfp = popen("sudo l2ping -c1 -v 88:CB:87:9A:AB:DE |grep time| awk -F 'time' '{print $ms}' | awk '{print $8}' |cut -d'm' -f1", "r"); //old using ping
  btfp = popen("sudo hcitool rssi 88:CB:87:9A:AB:DE |grep RSSI| awk '{print $4}'", "r");
  if (btfp == NULL) {
    printf("Failed to run command\n" );
    exit;
  }

  /* Read the output a line at a time - output it. */
  while (fgets(btPath, sizeof(btPath)-1, btfp) != NULL) {
  
    //printf("%s", path);
    btNumberString = btPath;
  }

  /* close */
  pclose(btfp);

	
	int btValue = atoi(btNumberString.c_str());
	cout << btValue << endl;
	
	
	if (btValue < signalLevel){
		awayCount ++;
		if (awayCount == 5){
		system("python mailer.py");
		cout << "It's running away!"<< endl;
		return 0;
		}
		else
		cout << "Possibly running away..." << endl;
	}
	
	samples++;
	}
	

    return 0;
}
