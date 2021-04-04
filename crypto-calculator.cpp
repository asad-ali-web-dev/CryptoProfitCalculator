#include <iostream>
#include <limits>
using namespace std;

int main() {
	
	double coinBuyPrice = 0;
	double coinSellPrice = 0;
	double investPrice = 0;
	
	double numCoinsBuy = 0;
	double numCoinsSell = 0;
	double numProfCoins = 0;
	
	double numCoinsIncreased = 0;
	
	double totalIncome = 0;
	double totalProfit = 0;
	
	cout << "Crypto Profit Calculator (v0.0.1)\nby\n\tDanish Fareed" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Buying Price of one COIN: "; cin >> coinBuyPrice;
	cout << "Expected Selling Price of one COIN: "; cin >> coinSellPrice;
	cout << "Total Investment (spended to buy COINs): "; cin >> investPrice;
	
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
	
	cout << "Crypto Profit Calculator (v0.0.1)\n by Danish Fareed" << endl;
	cout << "--------------------------------------" << endl;
	
	cout << "Investment: " << investPrice << endl;
	cout << "Coin Buying Price: " << coinBuyPrice << endl;
	cout << "Coin Expected Selling Price: " << coinSellPrice << endl;
	cout << "Number of Coins Buy: " << numCoinsBuy << endl;
	cout << "Number of Coins Sell: " << numProfCoins << endl;
	cout << "Number of Coins Changed: " << numCoinsIncreased << endl;
	cout << "--------------------------------------" << endl;
	cout << "Total Income: " << totalIncome << endl;
	
	if (totalProfit > 0) {
		cout << "Total Profit: " << totalProfit << endl;
	} else {
		cout << "OHNO! OHNO! LOOOOSE: " << totalProfit << endl;
	}
	
	cout << "--------------------------------------" << endl;
	cout << "Previous Balance: " << investPrice << endl;
	cout << "New Balance: " << totalIncome << endl;
	
	char choice = '0';
	
	cout << "--------------------------------------" << endl;
	cout << "Do you want to use calculator again! (y/n)" << endl;
	cin >> choice;
	
	switch(choice) {
		case 'y': {
			system("cls");
			main();
			break;
		}
		case 'n': {
			exit(0);
			break;
		}
		default: {
			cout << "Error: Something went wrong!" << endl;
			system("pause");
			break;
		}
	}
	
	return 0;
}
