#include "FinancialInformation.h"
#include <iostream>


auto information = FinancialInformation();

int main() {
	char userInput = 'a';

	while (userInput !='q') {
		try
		{
			system("CLS");

			information.userDataInput();

			system("CLS");

			information.calcBalanceNoDeposit(information.getInitialIvestmentAmount(), information.getInterest(), information.getNumberOfYears());
			std::cout << std::endl;
			information.calcBalanceWithDeposit(information.getInitialIvestmentAmount(), information.getMonthlyDeposit(), information.getInterest(), information.getNumberOfYears());

			std::cout << std::endl;
			std::cout << "Enter press a character or number to continue. Press q to quit" << std::endl;
			std::cin >> userInput;

		}
		catch (std::runtime_error & excpt)
		{
			std::cout << excpt.what() << std::endl;
			system("PAUSE");
			std::cin.clear();
			std::cin.ignore();
			
			system("CLS");
		
		}
		
		

	}


}