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
int months_ahead = 0;

void TurnToStr(int month) //Transforms an integer from 1-12 into the designated month.
{
	std::string monthInLet;
	switch (month)
	{
	case 1: monthInLet = "Jan"; break;
	case 2: monthInLet = "Feb"; break;
	case 3: monthInLet = "Mar"; break;
	case 4: monthInLet = "Apr"; break;
	case 5:  monthInLet = "May"; break;
	case 6:  monthInLet = "Jun"; break;
	case 7:  monthInLet = "Jul"; break;
	case 8:  monthInLet = "Aug"; break;
	case 9:  monthInLet = "Sep"; break;
	case 10:  monthInLet = "Oct"; break;
	case 11:  monthInLet = "Nov"; break;
	case 12:  monthInLet = "Dec"; break;
	}
	std::cout << monthInLet;
}

int TurnToInt(const std::string& month) //Transforms a month from a string into the corresponding integer from 1-12.
{
	if (month == "Jan" || month == "January") return 1;
	else if (month == "Feb" || month == "February") return 2;
	else if (month == "Mar" || month == "March") return 3;
	else if (month == "Apr" || month == "April") return 4;
	else if (month == "May") return 5;
	else if (month == "Jun" || month == "June") return 6;
	else if (month == "Jul" || month == "July") return 7;
	else if (month == "Aug" || month == "August") return 8;
	else if (month == "Sep" || month == "September") return 9;
	else if (month == "Oct" || month == "October") return 10;
	else if (month == "Nov" || month == "November") return 11;
	else if (month == "Dec" || month == "December") return 12;

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

float AbsForFlo(float a) //Returns absolute value of the entered float.
{
	if (a < 0) return a * (-1);
	else return a;
}

int AbsForInt(int a) //Returns absolute value of the entered int.
{
	if (a < 0) return a * (-1);
	else return a;
}

bool areMonthsConsecutive(int monthArr[], int numberOfMonths)
{
	int min = 13;
	int max = 0;
	int count = 0;

	for (int i = 0; i < 12; i++)
	{
		if (monthArr[i] != 0)
		{
			count++;
			if (monthArr[i] < min) min = monthArr[i];
			if (monthArr[i] > max) max = monthArr[i];
		}
	}

	if (count != numberOfMonths)
		return false;

	return (max - min + 1 == count);
}

int NumberOfDigg(int number) //Returns the number of diggits in a number.
{
	std::cin >> number;
	if (number < 0)
	{
		number = -number;
	}
	if (number == 0)
	{
		std::cout << 1;
		return -1;
	}
	int count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	std::cout << count;
}

void ClearScreen() //Clears the output window.
{
	system("CLS");
}

void Setup(int& numberOfMonths) //Initializes a new financial profile for a number of months specified by the user.
{
	std::cout << "Enter a number of months: ";
	std::cin >> numberOfMonths;
	while (numberOfMonths < 2 || numberOfMonths > 12)
	{
		if (numberOfMonths == 1)
		{
			std::cout << "Not enough data for the program to operate properly. Enter another number: ";
			std::cin >> numberOfMonths;
		}
		else if (numberOfMonths != 1)
		{
			std::cout << "Invalid number of months! Try again! " << std::endl;
			std::cin >> numberOfMonths;
		}
	}
	std::cout << "Profile created succesfully." << std::endl;
}

void Add(int numberOfMonths, float incomeArr[], float expenseArr[], float balanceArr[]) //Takes the user's input and stores it in order of the months in the designated arreys. 
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
			if (monthArr[month - 1] != 0) //Checks if it's already added.
			{
				valid_month = false;
			}

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
	if (!areMonthsConsecutive(monthArr, numberOfMonths))
	{
		ClearScreen();
		std::cout << "Months were not consecutive! So the program couldn't function properly. Please try again!" << std::endl;
		Setup(numberOfMonths);
		Add(numberOfMonths, incomeArr, expenseArr, balanceArr);
	}
}


void Report(float incomeArr[], float expenseArr[], float balanceArr[]) //Generates a report for the months selected by the user based on the provided input.
{
	float total_income = 0;
	float total_expense = 0;
	float total_balance = 0;

	for (int i = 0; i < numberOfMonths; i++)
	{
		if (monthArr[i] != 0) //Checks if the month is part of the current data the program is working with.
		{
			total_income += incomeArr[i];
		}
	}
	for (int i = 0; i < numberOfMonths; i++)
	{
		if (monthArr[i] != 0)
		{
			total_expense += expenseArr[i];
		}
	}
	for (int i = 0; i < numberOfMonths; i++)
	{
		if (monthArr[i] != 0)
		{
			total_balance += balanceArr[i];
		}
	}
	float average_balance = (total_balance / numberOfMonths);
	std::cout << "   Month    |   Income   |   Expense   |   Balance  " << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	int temp = numberOfMonths; //It keeps the original value of numberOfMonths intact.
	for (int i = 0; i < temp; i++)
	{
		if (monthArr[i] == 0) //Skips the months in the arrey that are not part of the program.
		{
			temp++;
			continue;
		}
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
	bool month_in_monthArr = false;
	while (!month_in_monthArr)
	{
		month_in_monthArr = false; // Resets the validation process.
		for (int i = 0; i < numberOfMonths; i++)
		{
			if (monthArr[i] == TurnToInt(month))
			{
				month_in_monthArr = true;
				break;
			}
		}

		if (!month_in_monthArr)
		{
			std::cout << "Month isn't a part of the data. Pick a new month: ";
			std::cin >> month;
		}
	}
	std::cout << "Income: " << incomeArr[TurnToInt(month) - 1] << std::endl;
	std::cout << "Expense: " << expenseArr[TurnToInt(month) - 1] << std::endl;
	std::cout << "Balance: ";
	if (balanceArr[TurnToInt(month) - 1] > 0) std::cout << "+" << balanceArr[TurnToInt(month) - 1] << std::endl;
	else std::cout << balanceArr[TurnToInt(month) - 1] << std::endl;
	float expense_ratio;
	if (incomeArr[TurnToInt(month) - 1] == 0)
	{
		std::cout << "Expense ratio is undefined (income is 0).";
	}
	else if ((incomeArr[TurnToInt(month) - 1]) != 0)
	{
		expense_ratio = (expenseArr[TurnToInt(month) - 1] / incomeArr[TurnToInt(month) - 1]) * 100;
		std::cout << "Expense ratio: " << expense_ratio << "%" << std::endl;
		std::cout << std::endl;
	}
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
			int temp = numberOfMonths;
			if (tempMonth[i] == 0)
			{
				temp++;
				continue;
			}
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
			int temp = numberOfMonths;
			if (tempMonth[i] == 0)
			{
				temp++;
				continue;
			}
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
			int temp = numberOfMonths;
			if (tempMonth[i] == 0)
			{
				temp++;
				continue;
			}
			TurnToStr(tempMonth[i]);
			std::cout << " : ";
			if (tempBalance[i] > 0) std::cout << "+" << tempBalance[i] << std::endl;
			else std::cout << tempBalance[i] << std::endl;
		}
	}
}

void Forecast(int months_ahead) //Forecasts savings or debts based on the current trend.
{
	float current_savings = 0;
	for (int i = 0; i < numberOfMonths; i++)
	{
		current_savings += balanceArr[i];
	}

	int earliest = 13, latest = 0; //Initialized variables to determine the earliest and the latest month:
	int earliestIndex = -1, latestIndex = -1;

	for (int i = 0; i < 12; i++)
	{
		if (monthArr[i] != 0)
		{
			if (monthArr[i] < earliest)
			{
				earliest = monthArr[i];
				earliestIndex = i;
			}
			if (monthArr[i] > latest)
			{
				latest = monthArr[i];
				latestIndex = i;
			}
		}
	}

	float average_monthly_change = 0;
	if (numberOfMonths > 1 && earliestIndex != -1 && latestIndex != -1)
	{
		float total_change = balanceArr[latestIndex] - balanceArr[earliestIndex];
		int months_between = latest - earliest;
		if (months_between > 0)
		{
			average_monthly_change = total_change / months_between;
		}
	}

	if (average_monthly_change > 0)
	{
		std::cout << "Enter for how many months ahead you wish the program to predict your savings: ";
		std::cin >> months_ahead;
		while (months_ahead < 1)
		{
			std::cout << "Incorrect input! Enter a number greater than 0.";
			std::cin >> months_ahead;
		}
		float predicted_savings;
		predicted_savings = current_savings + months_ahead * average_monthly_change;
		std::cout << "Your current savings are: " << current_savings << std::endl;
		std::cout << "Your average monthly change is: +" << average_monthly_change << std::endl;
		std::cout << "Predicted savings after " << months_ahead << " months : " << predicted_savings << std::endl;
	}
	else if (average_monthly_change < 0)
	{
		int months_till_no_money;
		months_till_no_money = current_savings / AbsForFlo(average_monthly_change);
		std::cout << "Your current savings are: " << current_savings << std::endl;
		std::cout << "Your average monthly change is: " << average_monthly_change << std::endl;
		std::cout << "Expected to run out of money after " << AbsForInt(months_till_no_money) << " months." << std::endl;
	}
	else if (average_monthly_change == 0)
	{
		std::cout << "Your balance is stable. No significant changes expected." << std::endl;
	}
}

void Chart() //Creates a visual representation of the user's balance troughout the year dependidng on the months the program is working with.
{
	std::cout << "================YEARLY FINANTIAL CHART================";

	float matrixScale[5][1] = { 0 }; //Initiateing a scale matrix for the left side of the graph that is made up from integers.
	float max_balance = balanceArr[0];
	float min_balance = balanceArr[0];
	for (int i = 0; i < numberOfMonths; i++) //Finds the highest and  balance in the arrey.
	{
		if (balanceArr[i] > max_balance) max_balance = balanceArr[i];
		if (balanceArr[i] < min_balance) min_balance = balanceArr[i];
	}
	matrixScale[0][0] = max_balance;
	matrixScale[4][0] = min_balance;
	matrixScale[2][0] = (max_balance + min_balance) / 2; //Middle value of the scale.
	matrixScale[1][0] = (matrixScale[0][0] + matrixScale[2][0]) / 2;
	matrixScale[3][0] = (matrixScale[2][0] + matrixScale[4][0]) / 2;

	char matrixHashmarks[5][12] = { 0 }; //Initiateing the hashmarks matrix of the graph.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			matrixHashmarks[i][j] = ' ';
			if (monthArr[j] != 0 && balanceArr[j] >= matrixScale[i][0])
			{
				matrixHashmarks[i][j] = '#';
			}
		}
	}

	for (int i = 0; i < 5; i++) //Printing the matices.
	{
		std::cout << matrixScale[i] << " | ";
		for (int j = 0; j < 12; j++)
		{
			std::cout << matrixHashmarks[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	int needed_free_space = 1;
	for (int i = 0; i < 5; i++) //Finds the number with the highest diggit count. It will help with the better visualization of the graph.
	{
		if (NumberOfDigg(matrixScale[i][0]) > needed_free_space)
		{
			needed_free_space = NumberOfDigg(matrixScale[i][0]);
		}
	}
	char freeSpaceArr[1] = { 0 }; //Created arrey for proper design uses.
	freeSpaceArr[needed_free_space] = { ' ' };
	std::cout << freeSpaceArr << "-----------------------------------------------";
	std::cout << freeSpaceArr << "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec";
}

int main()
{
	std::cout << "Hello! Welcome to your Finance tracker program!" << std::endl;
	std::cout << "Let's set it up!" << std::endl;
	Setup(numberOfMonths);
	std::cout << "Now for each consecutive month add the income and expense!" << std::endl;
	Add(numberOfMonths, incomeArr, expenseArr, balanceArr);
	std::cout << "Choose what you want to see next! Do you want to:" << std::endl;
	std::cout << "- see a generated report on your finances\n- search information about a specific month" << std::endl;
	std::cout << "- see the three months with the highest income, expense or balance values" << std::endl;
	std::cout << "- see a forecast for your savings or debts based on the current trend" << std::endl;
	std::cout << "- see a visual representation of your balance troughout the year" << std::endl;
	std::cout << "To proceed pick one of the following: Report, Search, Sort, Forecast, Chart;" << std::endl;
	std::cout << "If you want to end the program write: End;" << std::endl;
	std::string selected_function;
	std::cin >> selected_function;
	std::cout << std::endl;
	while (selected_function != "Report" && selected_function != "Search" && selected_function != "Sort" && selected_function != "Forecast" && selected_function != "Chart")
	{
		if (selected_function == "End")
		{
			ClearScreen();
			std::cout << "Thank you for using my program! :) ";
		}
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
		else if (selected_function == "Forecast")
		{
			Forecast(months_ahead);
		}
		else if (selected_function == "Chart")
		{
			Chart();
		}
		std::cout << "Pick again!" << std::endl;
		std::cout << std::endl;
		std::cin >> selected_function;
		if (selected_function == "End")
		{
			ClearScreen();
			std::cout << "Thank you for using my program! :) ";
		}
	}
	return 0;
}

