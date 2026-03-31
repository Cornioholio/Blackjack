#pragma once
#include <iostream>
#include <string>
class InputUtils
{
public:
	template <typename T>
	static T GetValidatedIntInput(const std::string& prompt, T min, T max)
	{
		T input;
		int error = 0;
		do
		{
			std::cout << prompt;
			std::cin >> input;
			if (std::cin.fail() || input < min || input > max) // Check for input fail and valid range
			{
				std::cout << "Invalid input. Please enter valid input between " << min << " and " << max << std::endl;
				std::cin.clear(); // Clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
				error = 1;
			}
			else
			{
				error = 0;
			}
		} while (error == 1); // Loop until valid input
		return input;
	}
};

