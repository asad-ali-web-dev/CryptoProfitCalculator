#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h>
#include <iomanip>
using namespace std;

void startAnimation() {
	for (int i = 0; i < 300; i++) {
		cout << " " << rand()
			<< " " << rand() 
			<< " " << rand() 
			<< " " << rand() 
			<< " " << rand() 
			<< " " << rand()
			<< " " << rand() << endl;
	}
		
	system("cls");
}

int main(bool loading = true) {
	
	system("cls && color 0A");
	HWND conwin = GetConsoleWindow();
	MoveWindow(conwin, 600, 100, 680, 900, TRUE);
	
	srand(time(0));
	
	if (loading) {
		startAnimation();
	}
	
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(outcon, false, &font);
	font.dwFontSize.X = 16;
    font.dwFontSize.Y = 36;
    SetCurrentConsoleFontEx(outcon, false, &font);
	
	double coinBuyPrice = 0;
	double coinSellPrice = 0;
	double investPrice = 0;
	
	double numCoinsBuy = 0;
	double numCoinsSell = 0;
	double numProfCoins = 0;
	
	double numCoinsIncreased = 0;
	
	double totalIncome = 0;
	double totalProfit = 0;
	
	SetConsoleTextAttribute(outcon, 0x27);
	cout << "                                        " << endl;
	cout << "         Crypto Profit Finder           " << endl;
	cout << "                                        " << endl;
	SetConsoleTextAttribute(outcon, 0x17);
	cout << "Owner: Danish Fareed                    " << endl;
	cout << "Version: v1.0.0 (stable)                " << endl;
	SetConsoleTextAttribute(outcon, 0x0A);
	
	
	cout << setw(26) << left << "Buying Price of 1 COIN: "; cin >> coinBuyPrice;
	cout << setw(26) << "Selling Price of 1 COIN: "; cin >> coinSellPrice;
	cout << setw(26) << "Total Investment: "; cin >> investPrice;
	
//	Coins against 1 usdt for example
	double coinsPerInvest = 0;
	coinsPerInvest = 1 / coinBuyPrice;
	
	numCoinsBuy = coinsPerInvest * investPrice;
	
	coinsPerInvest = 1 / coinSellPrice;
	
	numProfCoins = coinsPerInvest * investPrice;
	
	numCoinsIncreased = numCoinsBuy - numProfCoins;
	totalProfit = numCoinsIncreased * coinSellPrice;
	
	totalIncome = investPrice + totalProfit;
	
	system("cls");
	
	SetConsoleTextAttribute(outcon, 0x27);
	cout << "                                        " << endl;
	cout << "         Crypto Profit Finder           " << endl;
	cout << "                                        " << endl;
	SetConsoleTextAttribute(outcon, 0x17);
	cout << "Owner: Danish Fareed                    " << endl;
	cout << "Version: v1.0.0 (stable)                " << endl;
	SetConsoleTextAttribute(outcon, 0x0A);
	
	cout << setw(26) << left << "Total Investment: " << investPrice << endl;
	cout << setw(26) << "Buying Price: " << coinBuyPrice << endl;
	cout << setw(26) << "Expected Selling Price: " << coinSellPrice << endl;
	cout << setw(26) << "NOS Coins Buy: " << numCoinsBuy << endl;
	cout << setw(26) << "NOS Coins Sell: " << numProfCoins << endl;
	cout << setw(26) << "Fluctuation: " << numCoinsIncreased << endl;
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	} cout << endl;
	cout << setw(26) << "Total Income: " << totalIncome << endl;
	
	if (totalProfit > 0) {
		SetConsoleTextAttribute(outcon, 0x27);
		cout << setw(26) << "Total Profit: " << setw(14) << totalProfit << endl;
	} else {
		SetConsoleTextAttribute(outcon, 0x47);
		cout << setw(26) << "OHNO! Your are in LOSS: " << setw(14) << totalProfit << endl;
	}
	
	SetConsoleTextAttribute(outcon, 0x0A);
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	} cout << endl;
	cout << setw(26) << "Previous Balance: " << investPrice << endl;
	cout << setw(26) << "New Balance: " << totalIncome << endl;
	
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	} cout << endl;
	
	char choice = '0';
	cout << "Use Again! (y/n)" << endl;
	cin >> choice;
	
	switch(choice) {
		case 'y': {
			system("cls");
			main(false);
			break;
		}
		case 'Y': {
			system("cls");
			main(true);
			break;
		}
		case 'n': {
			ShowWindow(conwin, 0);
			break;
		}
		case 'N': {
			startAnimation();
			ShowWindow(conwin, 0);
			break;
		}
		default: {
			startAnimation();
			system("cls");
			cout << "Error: Something went wrong!" << endl;
			system("pause");
			ShowWindow(conwin, 0);
			break;
		}
	}
	return 0;
}
