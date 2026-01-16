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
std::string month;
std::string type;
float incomeArr[12] = { 0 };
float expenseArr[12] = { 0 };
float balanceArr[12] = { 0 };
int monthArr[12] = { 0 }; //An array containing the months that the program is working with.



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

int TurnToInt(const std::string& month) //Transforms a month from a string into the corresponding integer from 1-12.
{
	if (month == "January") return 1;
	else if (month == "February") return 2;
	else if (month == "March") return 3;
	else if (month == "April") return 4;
	else if (month == "May") return 5;
	else if (month == "June") return 6;
	else if (month == "July") return 7;
	else if (month == "August") return 8;
	else if (month == "September") return 9;
	else if (month == "October") return 10;
	else if (month == "November") return 11;
	else if (month == "December") return 12;

	return -1; // In case of invalid month.
}

void SwapFlo(float& a, float& b) //Switches the values of two floats.
{
	float temp = a;
	a = b;
	b = temp;
}

void SwapInt(int& a, int& b) //Switches the values of two integers.
{
	int temp = a;
	a = b;
	b = temp;
}

void Add(int numberOfMonths, int monthArr[], float incomeArr[], float expenseArr[], float balanceArr[]) //Takes the user's input and stores it in order of the months in the designated arreys. 
{
	int count = 0;
	while (count < numberOfMonths) //This allows months to be added in any order while storing them consecutively, regardless of the starting month.
	{
		int month;
		float expense, income;

		std::cout << "Enter month (1-12): "; //The number represents the month's position within the year.
		std::cin >> month;

		bool valid_month = false; //Checks if the month is correct or if it has already been added.

		while (!valid_month)
		{
			valid_month = true;
			if (month < 1 || month > 12) //Checks if it's a real month.
			{
				valid_month = false;
			}
			for (int i = 0; i < count; i++) //Checks if it's already added.
			{
				if (monthArr[i] == month)
					valid_month = false;
			}
			//for (int i = 0; i < count; i++) //Checks if the monts being added are consecutive.
			//{
			//	if (!(numberOfMonths-monthArr[i]<=numberOfMonths-1))
			//		valid_month = false;
			//}
			if (!valid_month)
			{
				std::cout << "Invalid or duplicate month! Try again: ";
				std::cin >> month;
			}
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
	}
	for (int i = 0; i < numberOfMonths; i++)
	{
		total_expense += expenseArr[i];
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
		std::cout << "|" << incomeArr[i] << " | " << expenseArr[i] << " | ";
		if (balanceArr[i] > 0) std::cout << "+" << balanceArr[i] << std::endl;
		else std::cout << balanceArr[i] << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Total income: " << total_income << std::endl;
	std::cout << "Total expense: " << total_expense << std::endl;
	std::cout << "Average balance: ";
	if (average_balance > 0) std::cout << "+" << average_balance << std::endl;
	else std::cout << average_balance << std::endl;
	std::cout << std::endl;
}

void Search(std::string month) //Discloses information about a selected by the user month.
{
	std::cout << "Pick a month: ";
	std::cin >> month;
	std::cout << "Income: " << incomeArr[TurnToInt(month) - 1] << std::endl;
	std::cout << "Expense: " << expenseArr[TurnToInt(month) - 1] << std::endl;
	std::cout << "Balance: ";
	if (balanceArr[TurnToInt(month) - 1] > 0) std::cout << "+" << balanceArr[TurnToInt(month) - 1] << std::endl;
	else std::cout << balanceArr[TurnToInt(month) - 1] << std::endl;
	float expense_ratio;
	expense_ratio = (expenseArr[TurnToInt(month) - 1] / incomeArr[TurnToInt(month) - 1]) * 100;
	std::cout << "Expense ratio: " << expense_ratio << "%" << std::endl;
	std::cout << std::endl;
}

void Sort(std::string type) //Sorts the three months with the highest income, expense or balance values in descending order.
{
	std::cout << "Sort by: ";
	std::cin >> type;
	while (type != "income" && type != "expense" && type != "balance")
	{
		std::cout << "Wrong input! Please choose from: income, expense or balance." << std::endl;
		std::cin >> type;
	}
	float tempIncome[12], tempExpense[12], tempBalance[12]; // Initializing copies of the arrays so that the original order is preserved.
	int tempMonth[12];
	for (int i = 0; i < numberOfMonths; i++)
	{
		tempIncome[i] = incomeArr[i];
		tempExpense[i] = expenseArr[i];
		tempBalance[i] = balanceArr[i];
		tempMonth[i] = monthArr[i];
	}
	int limit = (numberOfMonths < 3) ? numberOfMonths : 3; //Makes sure that if the program works with only two months there doesn't occur an error.
	if (type == "income")
	{
		for (int i = 0; i < numberOfMonths; i++)
		{
			for (int j = i + 1; j < numberOfMonths; j++)
			{
				if (tempIncome[i] < tempIncome[j]) //Sorting in descending order by switching up the places of the values in each arrey.
				{
					SwapFlo(tempIncome[i], tempIncome[j]);
					SwapFlo(tempExpense[i], tempExpense[j]);
					SwapFlo(tempBalance[i], tempBalance[j]);
					SwapInt(tempMonth[i], tempMonth[j]);
				}
			}
		}
		std::cout << "Sorted by monthly " << type << "(descending) :" << std::endl;
		for (int i = 0; i < limit; i++)
		{
			TurnToStr(tempMonth[i]);
			std::cout << " : " << tempIncome[i] << std::endl;
		}
	}
	else if (type == "expense")
	{
		for (int i = 0; i < numberOfMonths; i++)
		{
			for (int j = i + 1; j < numberOfMonths; j++)
			{
				if (tempExpense[i] < tempExpense[j])
				{
					SwapFlo(tempExpense[i], tempExpense[j]);
					SwapFlo(tempIncome[i], tempIncome[j]);
					SwapFlo(tempBalance[i], tempBalance[j]);
					SwapInt(tempMonth[i], tempMonth[j]);
				}
			}
		}
		std::cout << "Sorted by monthly " << type << "(descending) :" << std::endl;
		for (int i = 0; i < limit; i++)
		{
			TurnToStr(tempMonth[i]);
			std::cout << " : " << tempExpense[i] << std::endl;
		}
	}
	else if (type == "balance")
	{
		for (int i = 0; i < numberOfMonths; i++)
		{
			for (int j = i + 1; j < numberOfMonths; j++)
			{
				if (tempBalance[i] < tempBalance[j])
				{
					SwapFlo(tempBalance[i], tempBalance[j]);
					SwapFlo(tempExpense[i], tempExpense[j]);
					SwapFlo(tempIncome[i], tempIncome[j]);
					SwapInt(tempMonth[i], tempMonth[j]);
				}
			}
		}
		std::cout << "Sorted by monthly " << type << "(descending) :" << std::endl;
		for (int i = 0; i < limit; i++)
		{
			TurnToStr(tempMonth[i]);
			std::cout << " : ";
			if (tempBalance[i] > 0) std::cout << "+" << tempBalance[i] << std::endl;
			else std::cout << tempBalance[i] << std::endl;
		}
	}
}

void ClearScreen() //Clears the output window.
{
	system("CLS");
}

int main()
{
	std::cout << "Hello to your Finance tracker program!" << std::endl;
	std::cout << "Let's set it up!" << std::endl;
	Setup(numberOfMonths);
	std::cout << "Now for each consecutive month add the income and expense!" << std::endl;
	Add(numberOfMonths, monthArr, incomeArr, expenseArr, balanceArr);
	std::cout << "Choose what you want to see next! Do you want to:" << std::endl;
	std::cout << "See a generated report on your finances, search information about a specific month or see the three months with the highest income, expense or balance values?" << std::endl;
	std::cout << "To proceed pick one of the following: Report, Search, Sort;" << std::endl;
	std::cout << "If you want to end the program write: End" << std::endl;
	std::string selected_function;
	std::cin >> selected_function;
	std::cout << std::endl;
	while (selected_function != "Report" && selected_function != "Search" && selected_function != "Sort")
	{
		std::cout << "Wrong input! Please try again!";
		std::cin >> selected_function;
	}
	while (selected_function != "End")
	{
		if (selected_function == "Report")
		{
			Report(incomeArr, expenseArr, balanceArr);
		}
		else if (selected_function == "Search")
		{
			Search(month);
		}
		else if (selected_function == "Sort")
		{
			Sort(type);
		}
		std::cout << "Pick again!" << std::endl;
		std::cout << std::endl;
		std::cin >> selected_function;
		if (selected_function == "End")
		{
			ClearScreen();
			std::cout << "Thank you for useing my program! :) ";
		}
	}
	return 0;
}