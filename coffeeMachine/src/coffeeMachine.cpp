#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdlib>

using namespace std;

#define COST_ESPRESSO 1.0
#define COST_CAPPUCCINO 1.5
#define COST_LATTE 1.5
#define PIN 1234
#define CUPS 7

void showMainMenu();
void showMainMenuNoCups();
void showBalance(double balance);
void showInputBynMenu();
double inputBYN(double &totalBalance);
void makeEspresso();
void makeCappuccino();
void makeLatte();
void makeCoffeeMenu();
void progressBar();

void service(double &balance, double &totalBalance, int &cups);
void showServiceMenu();
void checkPIN();
void showPINcorrectMenu(double &totalBalance, int &cups);
void showPINisWrongMenu();
void blockTheMachine();

int main() {

	int userChoice = 0;
	double balance = 0.0;
	double totalBalance = 0.0;
	int cups = CUPS;

	while (true) {
		showBalance(balance);
		if (cups > 0) {
			showMainMenu();
			cin >> userChoice;
			if (userChoice == 1) {
				showBalance(balance);
				balance += inputBYN(totalBalance);
			} else if (userChoice == 2) {
				if (balance >= COST_ESPRESSO) {
					makeEspresso();
					balance -= COST_ESPRESSO;
					--cups;
				} else {
					balance += inputBYN(totalBalance);
				}
			} else if (userChoice == 3) {
				if (balance >= COST_CAPPUCCINO) {
					makeCappuccino();
					balance -= COST_CAPPUCCINO;
					--cups;
				} else {
					balance += inputBYN(totalBalance);
				}
			} else if (userChoice == 4) {
				if (balance >= COST_LATTE) {
					makeLatte();
					balance -= COST_LATTE;
					--cups;
				} else {
					balance += inputBYN(totalBalance);
				}
			} else if (userChoice == 5) {
				service(balance, totalBalance, cups);
			}
		} else {
			showMainMenuNoCups();
			cin >> userChoice;
			if (userChoice == 5) {
				service(balance, totalBalance, cups);
			}
		}
	}
	return 0;
}

void showBalance(double balance) {
	cout << "**********************************" << endl;
	cout << "BALANCE: " << balance << " BYN" << endl;
}

void showMainMenu() {
	cout << "**********************************" << endl;
	cout << "Dear Customer, make your choice:" << endl << endl;
	cout << "If there's not enough money, " << endl
			<< "you should top up the balance first." << endl << endl;
	cout << "|1| Deposit money" << endl;
	cout << "|2| Espresso          1 BYN" << endl;
	cout << "|3| Cappuccino        1,5 BYN" << endl;
	cout << "|4| Latte             1,5 BYN" << endl;
	cout << "|5| Service" << endl;
	cout << "**********************************" << endl;
}

void showMainMenuNoCups() {
	cout << "**********************************" << endl;
	cout << "We are very sorry," << endl << "but there are no cups left"
			<< endl;
	cout << "**********************************" << endl;
	cout << "|5| Service" << endl;
	cout << "**********************************" << endl;
}

void showInputBynMenu() {
	cout << "**********************************" << endl;
	cout << "Please, deposit coins" << endl;
	cout << "!!! Pay attention that the machine" << endl
			<< "doesn't give change!" << endl << endl;
	cout << "|1|  10 coins" << endl;
	cout << "|2|  20 coins" << endl;
	cout << "|3|  50 coins" << endl;
	cout << "|4|  1 BYN" << endl;
	cout << "|5|  2 BYN" << endl;
	cout << "|6|  Back to Main menu" << endl;
	cout << "**********************************" << endl;
}

double inputBYN(double &totalBalance) {
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
	case 6:
		break;
	}

	cout << "Ok, " << byn << " BYN is received" << endl;
	totalBalance += byn;
	return byn;
}

void makeCoffeeMenu() {
	cout << "Please, wait for a few seconds!" << endl
			<< "Your coffee is being prepared now!" << endl;
	progressBar();
	cout << "Here is the best coffee in the city! Help yourself!" << endl;
}
void makeEspresso() {
	makeCoffeeMenu();
	system("pause>nul");
}

void makeCappuccino() {
	makeCoffeeMenu();
	system("pause>nul");
}

void makeLatte() {
	makeCoffeeMenu();
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
void service(double &balance, double &totalBalance, int &cups) {
	showServiceMenu();
	int button = 0;
	bool again = true;
	while (again) {
		cin >> button;
		switch (button) {
		case 1: {
			checkPIN();
			again = false;
			break;
		}
		case 2: {
			again = false;
			return;
		}
		}
	}
	while (true) {
		showPINcorrectMenu(totalBalance, cups);
		int serviceButton = 0;
		cin >> serviceButton;
		switch (serviceButton) {
		case 1: {
			cout << "How many cups are you adding?" << endl;
			int addedCups = 0;
			cin >> addedCups;
			cups += addedCups;
			break;
		}
		case 2: {
			cout << (totalBalance + balance) << " BYN were given away" << endl;
			totalBalance = 0;
			balance = 0;
			break;
		}
		case 3:
			return;
		}
	}

}
void showServiceMenu() {
	cout << "**********************************" << endl;
	cout << "Please, make your choice:" << endl;
	cout << "|1| Input PIN" << endl;
	cout << "|2| Back to Main menu" << endl << endl;
	cout << "**********************************" << endl;
}
void checkPIN() {
	int i = 0;
	int pin = 0;
	while (i < 3) {
		cout << "PIN is: ";
		cin >> pin;
		if (pin == PIN) {
			break;
		} else {
			++i;
			showPINisWrongMenu();
		}
	}
	if (i == 3)
		blockTheMachine();
}
void showPINcorrectMenu(double &totalBalance, int &cups) {
	cout << "**********************************" << endl;
	cout << "Total balance of the Machine is " << totalBalance << " BYN"
			<< endl;
	cout << "There are " << cups << " cups loaded" << endl << endl;
	cout << "Choose the option: " << endl;
	cout << "|1|  Add cups" << endl;
	cout << "|2|  Withdrawal of proceeds" << endl;
	cout << "|3|  Back to main menu" << endl;
	cout << "**********************************" << endl;

}
void showPINisWrongMenu() {
	cout << "**********************************" << endl;
	cout << "PIN is wrong, please, input PIN" << endl << endl;
	cout << "**********************************" << endl;
}
void blockTheMachine() {
	cout << "**********************************" << endl;
	cout << "The Machine is blocked!!!" << endl << endl;
	cout << "**********************************" << endl;
	system("pause>nul");
	exit(-1);
}
