#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#define COST_ESPRESSO 1.0
#define COST_CAPPUCCINO 1.5
#define COST_LATTE 1.5

void showMainMenu();
void showBalance(double balance);
void showInputBynMenu();
double inputBYN();
void makeEspresso();
void makeCappuccino();
void makeLatte();

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
			cout << "Sorry, no cups" << endl;

			break;
		}
	}

	return 0;
}
void showBalance(double balance) {
	cout << "BALANCE: " << balance << " BYN" << endl;
}

void showMainMenu() {
	cout << "Dear customer, make your choice:" << endl;
	cout << "1 " << endl;
	cout << "2 " << endl;
	cout << "3 " << endl;
	cout << "4 " << endl;
	cout << "5 " << endl;

	//cout << "We are very sorry, but there are no cups left" << endl;
	//cout << "5 Service" << endl;
}

void showInputBynMenu() {
	cout << "Please, deposit coins" << endl;
	cout << "Pay attention that the coffee machine doesn't give change!"
			<< endl;
	cout << "1" << endl;
	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;
	cout << "5" << endl;
}

double inputBYN() {
	showInputBynMenu();
	double byn = 0.0;
	cin >> byn;
	cout << "Ok, " << byn << " BYN is received" << endl;
	return byn;
}

void makeEspresso() {
	cout << "Espresso" << endl;
}
void makeCappuccino() {
	cout << "Cappuccino" << endl;
}
void makeLatte() {
	cout << "Latte" << endl;
}
