#include <iostream>
using namespace std;

class BankAccount
{
protected:
	double balance;
public:
	BankAccount()
	{
		balance = 0;
	}
	BankAccount(double bal)
	{
		balance = bal;
	}
	void virtual Display()
	{
		cout << "Nothing to Display" << endl;
	}
};

class CurrentAccount : public BankAccount
{
private:
	int DailyInterestRate;
public:
	CurrentAccount()
	{
		DailyInterestRate = 0;
	}
	CurrentAccount(double b,int Rate) :BankAccount(b)
	{
		DailyInterestRate = Rate;
	}
	void Display()
	{
		cout << balance << endl;
		cout << DailyInterestRate << endl;
		cout << balance * DailyInterestRate * 7 << endl;
	}
};

class SavingAccount : public BankAccount
{
private:
	int MonthlyInterestRate;
public:
	SavingAccount()
	{
		MonthlyInterestRate = 0;
	}
	SavingAccount(double b,int Rate):BankAccount(b)
	{
		MonthlyInterestRate = Rate;
	}
	void Display()
	{
		cout << balance << endl;
		cout << MonthlyInterestRate << endl;
		cout << balance * MonthlyInterestRate * 30 << endl;
	}
};

int main()
{
	BankAccount* BA;
	CurrentAccount C(10,2);
	SavingAccount S(10,3);
	BA = &C;
	BA->Display();
	BA = &S;
	BA->Display();


}