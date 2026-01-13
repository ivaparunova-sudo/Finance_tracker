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

void Setup(int& numberOfMonths) //Initializes a new financial profile for a number of months specified by the user.
{
	std::cout << "Enter number of months: ";
	std::cin >> numberOfMonths;
	if (numberOfMonths < 1 || numberOfMonths > 12) {
		std::cout << "Invalid number of months! Try again!" << std::endl;
		return;
	}

	else
	{
		std::cout << "Profile created succesfully." << std::endl;
		ranCorrectly = true;
	}
}


int main()
{
	Setup(numberOfMonths);
	while (!ranCorrectly) //Repeats the setup process until valid input is provided.
	{
		Setup(numberOfMonths);
	}
	return 0;
}
