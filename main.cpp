/* Main Entry into program */

#include "Cprog.h"
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;

int main()
{
	Cprog GeoProg;

	char inputSelect;
	string iSelect;

	do {
	 GeoProg.printMenu();
				
		cin >> inputSelect;
		
		switch (inputSelect){

		case 'A':
		case 'a': {
			GeoProg.threeBody();
			break;
		}
		case 'B':
		case 'b': {
			GeoProg.nBody();
			break;
		}
		case 'C':
		case 'c': {
			GeoProg.nBody_Planetary();
			break;
		}
		case 'Q':
		case 'q':
			cout << "Quiting" << endl;
			exit(0);
			break;
		default:
			cout << "Command not found\n";
			inputSelect = 0;
			break;

		}
		if (inputSelect != 0) {
			cout << "Back to Main Menu?(y/n): ";
			cin >> inputSelect;
		} 
		

	} while (inputSelect == 'Y' || inputSelect == 'y'|| inputSelect == 0);
		
	return 0;

}

