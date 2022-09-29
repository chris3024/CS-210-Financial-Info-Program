#pragma once


class FinancialInformation {

public:

	FinancialInformation();

	void userDataInput();

	double calcBalanceNoDeposit(double t_initialInvestmentAmount, double t_annualInterest, int t_years);

	double calcBalanceWithDeposit(double t_initialInvestmentAmount, double t_monthlyDeposit, double t_annualInterest, int t_years);

	void setInitialIvestmentAmount(double t_initialInvestmentAmount);

	void setMonthlyDeposit(double t_montlyDeposit);

	void setNumberOfYears(int t_years);

	void setInterest(double t_annualInterest);

	double getInitialIvestmentAmount() const;
	
	double getMonthlyDeposit() const;

	double getInterest() const;

	int getNumberOfYears() const;



private:

	double m_initialInvestAmount;
	double m_monthlyDeposit;
	int m_numberOfYears;
	double m_interestAmount;
	double m_totalAmount;
	
};