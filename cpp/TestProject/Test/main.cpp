/*
	autor Martin Watolla

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
#define MAX 100
double value[MAX];

int main(){

	int i;
	double anz;
	

	//read numbers
	cout << "Bis zu 100 ganze Zahlen eingeben\n"
		<< "(Abbruch mit einem Buchstaben): " << endl;
	for (i = 0; i < MAX && cin >> value[i]; i++){
		anz = i;
	}

	//Addition of numbers
	double summe = 0;
	for (i = 0; i < anz; ++i){
		summe += value[i];
	}
	cout << "Summierte valueen: " << endl;
	cout << summe << endl;
	cout << endl;

	//average of numbers
	int counter = 0; 
	double mult = 0;
	double result = 1;
	for (i = 0; i < anz; i++){
		counter++;
		mult += value[i];
		result = mult / counter;
	}
	cout << "Durchschnitt: " << endl;
	cout << result << endl;
	cout << endl;

	//reverse sequence of numbers
	cout << "Umgekehrte Reihenfolge: \n";
	for (i > anz; i >= 0; i--){
		cout << value[i] << " ";
	}
	cout << endl;
	cout << endl;


	//sort numbers
	bool sort = false;
	long help;
	double end = anz;

	while (!sort){
		sort = true;
		--end;
		for (i = 0; i < end; ++i){
			if (value[i] > value[i + 1]){
				sort = false;
				help = value[i];
				value[i] = value[i + 1];
				value[i + 1] = help;
			}
		}
	}

	//print sort numbers
	cout << "Die sortierten valueen: \n";
	for (i = 0; i < anz+1; i++){
		cout << value[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Hallo ich habe Christophs änderungen gelöscht.";

	return 0;
}