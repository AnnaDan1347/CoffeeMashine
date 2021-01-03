#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdlib>

using namespace std;

#define COST_ESPRESSO 1.0
#define COST_CAPPUCCINO 1.5
#define COST_LATTE 1.5

void showMainMenu();
void showMainMenuNoCups();
void showBalance(double balance);
void showInputBynMenu();
double inputBYN();
void makeEspresso();
void makeCappuccino();
void makeLatte();
void progressBar();

int main() {

	int userChoice = 0;
	double balance = 0.0;
	int cups = 7;

	while (true) {
		showBalance(balance);
		if (cups > 0) {
			showMainMenu();
			cin >> userChoice;
			if (userChoice == 1) {
				showBalance(balance);

				balance += inputBYN();
			} else if (userChoice == 2) {
				if (balance >= COST_ESPRESSO) {
					makeEspresso();
					balance -= COST_ESPRESSO;
					--cups;
				} else {
					balance += inputBYN();
				}
			} else if (userChoice == 3) {
				if (balance >= COST_CAPPUCCINO) {
					makeCappuccino();
					balance -= COST_CAPPUCCINO;
					--cups;
				} else {
					balance += inputBYN();
				}
			} else if (userChoice == 4) {
				if (balance >= COST_LATTE) {
					makeLatte();
					balance -= COST_LATTE;
					--cups;
				} else {
					balance += inputBYN();
				}
			} else if (userChoice == 5) {
				cout << "Service" << endl;
				break;
			} else {
				cout << "Input [1..5], please" << endl;
				break;
			}
		} else {
			showMainMenuNoCups();
			cin >> userChoice;
			if (userChoice == 5) {
				cout << "Service" << endl;
				break;
			} else {
				cout << "Input [5], please" << endl;
				break;
			}
			break;
		}
	}
	return 0;
}
void showBalance(double balance) {
	cout << "********************************" << endl;
	cout << "BALANCE: " << balance << " BYN" << endl;
}

void showMainMenu() {
	cout << "********************************" << endl;
	cout << "Dear customer, make your choice:" << endl << endl;
	cout << "|1| Deposit money" << endl;
	cout << "|2| Espresso          1 BYN" << endl;
	cout << "|3| Cappuccino        1,5 BYN" << endl;
	cout << "|4| Latte             1,5 BYN" << endl;
	cout << "|5| Service" << endl;
	cout << "********************************" << endl;
}

void showMainMenuNoCups() {
	cout << "********************************" << endl;
	cout << "We are very sorry," << endl << "but there are no cups left"
			<< endl;
	cout << "********************************" << endl;
	cout << "|5| Service" << endl;
	cout << "********************************" << endl;
}

void showInputBynMenu() {
	cout << "********************************" << endl;
	cout << "Please, deposit coins" << endl;
	cout << "!!! Pay attention that the machine" << endl
			<< "doesn't give change!" << endl << endl;
	cout << "|1|  10 coins" << endl;
	cout << "|2|  20 coins" << endl;
	cout << "|3|  50 coins" << endl;
	cout << "|4|  1 BYN" << endl;
	cout << "|5|  2 BYN" << endl;
	cout << "********************************" << endl;
}

double inputBYN() {
	showInputBynMenu();
	double byn = 0.0;
	int button = 0;
	cin >> button;
	switch (button) {
	case 1:
		byn = 0.1;
		break;
	case 2:
		byn = 0.2;
		break;
	case 3:
		byn = 0.5;
		break;
	case 4:
		byn = 1.0;
		break;
	case 5:
		byn = 2.0;
		break;
	}
	cout << "Ok, " << byn << " BYN is received" << endl;
	return byn;
}

void makeEspresso() {
	cout << "Please, wait for a few seconds!" << endl
			<< "Your Espresso is being prepared now!" << endl;
	progressBar();
	cout << "Here is the best Espresso in the city! Help yourself!" << endl;
	system("pause>nul");
}

void makeCappuccino() {
	cout << "Please, wait for a few seconds!" << endl
			<< "Your Cappuccino is being prepared now!" << endl;
	progressBar();
	cout << "Here is the best Cappuccino in the city! Help yourself!" << endl;
	system("pause>nul");
}

void makeLatte() {
	cout << "Please, wait for a few seconds!" << endl
			<< "Your Latte is being prepared now!" << endl;
	progressBar();
	cout << "Here is the best Latte in the city! Help yourself!" << endl;
	system("pause>nul");
}

void progressBar() {
	int time = 500;
	cout << "         $     $     $" << endl << flush;
	Sleep(time);
	cout << "          $     $     $" << endl << flush;
	Sleep(time);
	cout << "           $     $     $" << endl << flush;
	Sleep(time);
	cout << "          $     $     $" << endl << flush;
	Sleep(time);
	cout << "         $     $    $" << endl << flush;
	Sleep(time);
	cout << "     $$$$$$$$$$$$$$$$$$$$" << endl;
	Sleep(time);
	cout << "     $                  $" << endl;
	Sleep(time);
	cout << "   $$$                  $" << endl;
	Sleep(time);
	cout << " $                      $" << endl;
	Sleep(time);
	cout << "$  $$                   $" << endl;
	Sleep(time);
	cout << "$ $ $                   $" << endl;
	Sleep(time);
	cout << "$  $$                   $" << endl;
	Sleep(time);
	cout << " $                      $" << endl;
	Sleep(time);
	cout << "   $$$                  $" << endl;
	Sleep(time);
	cout << "      $                $" << endl;
	Sleep(time);
	cout << "       $$$$$$$$$$$$$$$$" << endl;
}

