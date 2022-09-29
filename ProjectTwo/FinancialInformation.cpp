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
		if (initialInvestAmount < 0 || std::cin.fail()) {
			throw std::runtime_error("Please Enter Positive Integer!");
		}
		setInitialIvestmentAmount(initialInvestAmount);
		
		std::cout << "Monthly Deposit: $";
		std::cin >> monthlyDeposit;
		if (monthlyDeposit < 0 || std::cin.fail()) {
			throw std::runtime_error("Please Enter Positive Integer!");
		}
		setMonthlyDeposit(monthlyDeposit);
		
		std::cout << "Annual Interest: %";
		std::cin >> interest;
		if (interest < 0 || std::cin.fail()) {
			throw std::runtime_error("Please Enter Positive Integer!");
		}
		setInterest(interest);
		
		std::cout << "Number of Years: ";
		std::cin >> years;
		if (years < 0 || std::cin.fail()) {
			throw std::runtime_error("Please Enter Positive Integer!");
		}
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
	double totalAmount = m_initialInvestAmount;
	double interestAmt;

	std::cout << std::setfill(' ') << std::setw(5) << "" << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << std::setfill('=') << std::setw(66) << "" << std::endl;

	std::cout << " Year" << std::setfill(' ') << std::setw(10) << "" << "Year End Balance" << std::setfill(' ') << std::setw(10) << "" << "Year End Earned Interest" << std::endl;
	std::cout << std::setfill('-') << std::setw(66) << "" << std::endl;

	for (int i = 0; i < t_years; i++) {
		interestAmt = totalAmount * (t_annualInterest / 100);
		totalAmount = totalAmount + interestAmt;

		std::cout << " " << std::setfill(' ') << std::setw(3) << std::left << i + 1 << std::setw(25) << std::right << std::fixed << std::setprecision(2) << totalAmount << std::setw(30) << std::right << interestAmt << std::endl;
	}

	
	return totalAmount;
}

double FinancialInformation::calcBalanceWithDeposit(double t_initialInvestmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_years) {
	double totalAmount = m_initialInvestAmount;
	double interestAmt;
	double yearlyInterest;

	std::cout << std::setfill(' ') << std::setw(5) << "" << "Balance and Interest with Additional Monthly Deposits" << std::endl;
	std::cout << std::setfill('=') << std::setw(66) << "" << std::endl;

	std::cout << " Year" << std::setfill(' ') << std::setw(10) << "" << "Year End Balance" << std::setfill(' ') << std::setw(10) << "" << "Year End Earned Interest" << std::endl;
	std::cout << std::setfill('-') << std::setw(66) << "" << std::endl;

	for (int i = 0; i < t_years; i++) {
		yearlyInterest = 0.0;

		for (int j = 0; j < 12; j++) {
			interestAmt = (totalAmount + t_monthlyDeposit) * ((t_annualInterest / 100) / 12);
			yearlyInterest = yearlyInterest + interestAmt;
			totalAmount = totalAmount + m_monthlyDeposit + interestAmt;
		}

		std::cout << " " << std::setfill(' ') << std::setw(3) << std::left << i + 1 << std::setw(25) << std::right << totalAmount << std::setw(30) << std::right << yearlyInterest << std::endl;

	}
	return m_totalAmount;

}
