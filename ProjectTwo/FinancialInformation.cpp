#include <iostream>
#include "FinancialInformation.h"
#include <iomanip>
#include <string>
#include <stdexcept>

FinancialInformation::FinancialInformation() {
	m_initialInvestAmount = 0;
	m_monthlyDeposit = 0;
	m_interestAmount = 0;
	m_numberOfYears = 0;
	m_totalAmount = 0;
}

void FinancialInformation::userDataInput() {
	double initialInvestAmount;
	double monthlyDeposit;
	double interest;
	int years;

	
		std::cout << std::setfill('*') << std::setw(34) << "" << std::endl;
		std::cout << std::setfill('*') << std::setw(11) << "" << " Data Input " << "" << std::setfill('*') << std::setw(11) << "" << std::endl;
		std::cout << "Initial Investment Amount: $";
		std::cin >> initialInvestAmount;
		
		setInitialIvestmentAmount(initialInvestAmount);
		std::cout << "Monthly Deposit: $";
		std::cin >> monthlyDeposit;
		setMonthlyDeposit(monthlyDeposit);
		std::cout << "Annual Interest: %";
		std::cin >> interest;
		setInterest(interest);
		std::cout << "Number of Years: ";
		std::cin >> years;
		setNumberOfYears(years);

		system("PAUSE");
	}
	


void FinancialInformation::setInitialIvestmentAmount(double t_initialInvestmentAmount) {
	m_initialInvestAmount = t_initialInvestmentAmount;
}

void FinancialInformation::setMonthlyDeposit(double t_montlyDeposit) {
	m_monthlyDeposit = t_montlyDeposit;
}

void FinancialInformation::setNumberOfYears(int t_years) {
	m_numberOfYears = t_years;
}

void FinancialInformation::setInterest(double t_annualInterest) {
	m_interestAmount = t_annualInterest;
}

double FinancialInformation::getInitialIvestmentAmount() const {
	return m_initialInvestAmount;
}

double FinancialInformation::getMonthlyDeposit() const {
	return m_monthlyDeposit;
}

double FinancialInformation::getInterest() const {
	return m_interestAmount;
}

int FinancialInformation::getNumberOfYears() const {
	return m_numberOfYears;
}

double FinancialInformation::calcBalanceNoDeposit(double t_initialInvestmentAmount, double t_annualInterest, int t_years) {
	
	std::cout << std::setfill(' ') << std::setw(5) << "" << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << std::setfill('=') << std::setw(66) << "" << std::endl;

	std::cout << " Year" << std::setfill(' ') << std::setw(10) << "" << "Year End Balance" << std::setfill(' ') << std::setw(10) << "" << "Year End Earned Interest" << std::endl;
	std::cout << std::setfill('-') << std::setw(66) << "" << std::endl;

	
	return m_totalAmount;
}

double FinancialInformation::calcBalanceWithDeposit(double t_initialInvestmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_years) {
	
	std::cout << std::setfill(' ') << std::setw(5) << "" << "Balance and Interest with Additional Monthly Deposits" << std::endl;
	std::cout << std::setfill('=') << std::setw(66) << "" << std::endl;

	std::cout << " Year" << std::setfill(' ') << std::setw(10) << "" << "Year End Balance" << std::setfill(' ') << std::setw(10) << "" << "Year End Earned Interest" << std::endl;
	std::cout << std::setfill('-') << std::setw(66) << "" << std::endl;

	
	//std::cout << " " << std::left << (i + 1) << std::setfill(' ') << std::setw(20) << "" << std::fixed << std::setprecision(2) << "$" << m_totalAmount << "" << std::setfill(' ') << std::setw(30) << "" << m_yearlyInterest << std::endl;
	
	return m_totalAmount;

}
