/**
*
* Solution to course project # 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Iva Parunova
* @idnumber 0MI0600575
* @compiler VC
*
* <a file containing the code that handles the entire program's functionality>
*
*/


#include <iostream>
#include <string>

int numberOfMonths = 1; //The number of months for which the program will generate a financial report.
float incomeArr[12] = { 0 };
float expenseArr[12] = { 0 };
float balanceArr[12] = { 0 };
int monthArr[12] = { 0 }; //An array containing the months that the program is working with.
float total_incomeArr[12] = { 0 };
float total_expenseArr[12] = { 0 };


void Setup(int& numberOfMonths) //Initializes a new financial profile for a number of months specified by the user.
{
	std::cout << "Enter number of months: ";
	std::cin >> numberOfMonths;
	while (numberOfMonths < 1 || numberOfMonths > 12) 
	{
		std::cout << "Invalid number of months! Try again!" << std::endl;
		std::cin >> numberOfMonths;
	}
	std::cout << "Profile created succesfully." << std::endl;
}

void TurnToStr(int month) //Transforms an integer from 1-12 into the designated month.
{
	std::string monthInLet;
	switch (month)
	{
	case 1: monthInLet = "January"; break;
	case 2: monthInLet = "February"; break;
	case 3: monthInLet = "March"; break;
	case 4: monthInLet = "April"; break;
	case 5:  monthInLet = "May"; break;
	case 6:  monthInLet = "June"; break;
	case 7:  monthInLet = "July"; break;
	case 8:  monthInLet = "August"; break;
	case 9:  monthInLet = "September"; break;
	case 10:  monthInLet = "October"; break;
	case 11:  monthInLet = "November"; break;
	case 12:  monthInLet = "December"; break;
	}
	std::cout << monthInLet;
}

void TurnToInt(std::string month) //Transforms a month from a string into the corresponding integer from 1-12. 
{
	int monthInInt;
	switch (month)
	{
	case "January": monthInInt = 1; break;
	case "February": monthInInt = 2; break;
	case "March": monthInInt = 3; break;
	case "April": monthInInt = 4; break;
	case "May":  monthInInt = 5; break;
	case "June":  monthInInt = 6; break;
	case "July":  monthInInt = 7; break;
	case "August":  monthInInt = 8; break;
	case "September":  monthInInt = 9; break;
	case "October": monthInInt = 10; break;
	case "November":  monthInInt = 11; break;
	case "December":  monthInInt = 12; break;
	}
}

void Add(int numberOfMonths, int monthArr[], float incomeArr[], float expenseArr[], float balanceArr[]) //Takes the user's input and stores it in order of the months in the designated arreys. 
{
	int count = 0; 
	while (count < numberOfMonths)
	{
		int month;
		float expense, income;

		std::cout << "Enter month (1-12): "; //The number represents the month’s position within the year.
		std::cin >> month;

		while (month < 1 || month > 12)
		{
			std::cout << "Wrong input! Try again: ";
			std::cin >> month;
		}

		std::cout << "Enter income: ";
		std::cin >> income;

		while (income < 0)
		{
			std::cout << "Wrong input! Try again: ";
			std::cin >> income;
		}

		std::cout << "Enter expense: ";
		std::cin >> expense;

		while (expense < 0)
		{
			std::cout << "Wrong input! Try again: ";
			std::cin >> expense;
		}

		float balance = income - expense;
		std::cout << "Result: Balance for ";
		TurnToStr(month);
		std::cout << " = ";
		if (balance > 0) std::cout << "+" << balance << std::endl;
		else std::cout << balance << std::endl;
		std::cout << std::endl;
		incomeArr[month - 1] = income;
		expenseArr[month - 1] = expense;
		balanceArr[month - 1] = balance;
		monthArr[month - 1] = month;

		count++;
	}
}


void Report(float incomeArr[], float expenseArr[], float balanceArr[]) //Generates a report for the months selected by the user based on the provided input.
{
	float total_income = 0;
	float total_expense = 0;
	float total_balance = 0;
	for (int i = 0; i < numberOfMonths; i++)
	{
		total_income += incomeArr[i];
		total_incomeArr[i] = total_income;
	}
	for (int i = 0; i < numberOfMonths; i++)
	{
		total_expense += expenseArr[i];
		total_expenseArr[i] = total_expense;
	}
	for (int i = 0; i < numberOfMonths; i++)
	{
		total_balance += balanceArr[i];
	}
	float average_balance = (total_balance / numberOfMonths);
	std::cout << "   Month    |   Income   |   Expense   |   Balance  " << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	for (int i = 0; i < numberOfMonths; i++)
	{
		TurnToStr(monthArr[i]);
		std::cout << "|" << incomeArr[i] <<" | " << expenseArr[i] << " | ";
		if (balanceArr[i] > 0) std::cout << "+" << balanceArr[i] << std::endl;
		else std::cout << balanceArr[i] << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Total income: " << total_income << std::endl;
	std::cout << "Total expense: " << total_expense << std::endl;
	std::cout << "Average balance: ";
	if (average_balance > 0) std::cout << "+" << average_balance << std::endl;
	else std::cout << average_balance << std::endl;
}

void Search(std::string month) //Discloses information about a selected by the user month.
{
	std::cin >> month;
	TurnToInt(month);
	std::cout << "Income: " << incomeArr[month] << std::endl;
	std::cout << "Expense: " << expenseArr[month] << std::endl;
	std::cout << "Balance: ";
	if (bakanceArr[month] > 0) std::cout << "+" << bakanceArr[month] << std::endl;
	else std::cout << bakanceArr[month] << std::endl;
	float expense_ratio;
	expense_ratio = (total_expenseArr[month] / total_incomeArr[month]) * 100;
	std::cout << "Expense ratio: " << expense_ratio << " %";
}

int main()
{
	Setup(numberOfMonths);
	Add(numberOfMonths, monthArr, incomeArr, expenseArr, balanceArr);
	Report(incomeArr, expenseArr, balanceArr);
	Search(month);

	return 0;
}