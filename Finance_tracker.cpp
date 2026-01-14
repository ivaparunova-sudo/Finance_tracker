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

int numberOfMonths = 1; //The number of months for which the program will generate a financial report.
bool ranCorrectly = false;
float incomeArr[12] = { 0 };
float expenseArr[12] = { 0 };
float balanceArr[12] = { 0 };

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
	ranCorrectly = true;
}

void TurnToLet(int month) //Transforms an integer from 1-12 into the designated month.
{
	std::string monthInLet;
	switch (month)
	{
	case 1: monthInLet = "Jenuary"; break;
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

void Add(int numberOfMonths, float incomeArr[], float expenseArr[], float balanceArr[]) //Takes the user's input and stores it in the designated arreys. 
{
	int count = 0; 
	while (count < numberOfMonths)
	{
		int month;
		float expense, income;

		std::cout << "Enter month (1-12): ";
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
		TurnToLet(month);
		std::cout << " = ";
		if (balance > 0) std::cout << "+" << balance << std::endl;
		else std::cout << balance << std::endl;
		incomeArr[month - 1] = income;
		expenseArr[month - 1] = expense;
		balanceArr[month - 1] = balance;

		count++;
	}

	ranCorrectly = true;
}

int main()
{
	Setup(numberOfMonths);
	Add(numberOfMonths, incomeArr, expenseArr, balanceArr));
	return 0;
}
