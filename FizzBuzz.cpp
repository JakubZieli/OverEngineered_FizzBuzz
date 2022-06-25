#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct FizzBuzzInput
{
	int number;
	std::string letterOutput;
};

bool compareByNumbers(const FizzBuzzInput& a, const FizzBuzzInput& b)
{
	return a.number < b.number;
}

int main()
{
	std::vector<FizzBuzzInput> userInput;
	std::string tmpUserInput;
	FizzBuzzInput procesingUserInput;
	int range = 100;


	std::cout << "Hello, and welcome to the modular FizzBuzz" << std::endl;
	//std::cout << "You can input as many numbers and coresponding phrases as you want, douplicates of numbers wont be accepted" << std::endl << std::endl;

	std::cout << "In order to input the next FizzBuzz first type the number then the phrase," << std::endl;
	std::cout << "the number and the phrase have to be separeted by a single space " << std::endl;
	std::cout << "Example:" << std::endl << "4 Fizz" << std::endl << std::endl;
	std::cout << "Just press enter without typing to end inputing fizz buzz combos " << std::endl;

	//more user interface here later


	//User inputs custom FizzBuzz number phrases combinations
	do
	{
		std::cout << "Give me the next FizzBuzz pair of number and text/phrase" << std::endl;
		std::cout << "Enter combination : ";
		std::getline(std::cin, tmpUserInput);

		if (tmpUserInput == "")
		{
			break;
		}
		procesingUserInput.number = std::stoi(tmpUserInput);
		procesingUserInput.letterOutput = tmpUserInput.substr(tmpUserInput.find_first_of(" ")+1, tmpUserInput.length() - 1);

		userInput.push_back(procesingUserInput);
	} while (true);


	//Grouping vector of FizzBuzzInput divisible by each other into a vector of vectors, descending ex. {2,4,6} , {3,9} , {5,25}
	std::sort(userInput.begin(),userInput.end(),compareByNumbers);

	std::vector<std::vector<FizzBuzzInput>> smalestDivisors;
	std::vector<FizzBuzzInput> singleSmalestDivisors;

	for (int j = 0; j < userInput.size(); j++)
	{
	singleSmalestDivisors.push_back(userInput[j]);
	
		//check all the numbers, starting from the 2nd one	
		for (int i = j+1; i < userInput.size(); i++)
		{
			if (userInput[i].number % userInput[j].number == 0)
			{
				singleSmalestDivisors.push_back(userInput[i]);
				userInput.erase(userInput.begin()+i);
				i--;
			}

		}
		smalestDivisors.push_back(singleSmalestDivisors);
		singleSmalestDivisors.erase(singleSmalestDivisors.begin(), singleSmalestDivisors.end());
	}


	//actual FizzBuzz

	//numbers go from 1 to range
	bool entered=false;
	for (int check = 1; check <= range; check++)
	{

		int j;
		//check each smalest divisior
		for (j = 0; j < smalestDivisors.size(); j++)
		{
			if (check % smalestDivisors[j][0].number == 0)
			{
				//FizzBuzzin
				for (int i = 0; i < smalestDivisors[j].size()  ; i++)
				{
					if (check < smalestDivisors[j][i].number)
					{
						entered = true;
						break;
					}
					if (check % smalestDivisors[j][i].number == 0)
					{
					std::cout << smalestDivisors[j][i].letterOutput ;
					entered = true;
					}
				}
			}

		}

		//check if did a FizzBuzz or need to display a number
		if (!entered)
		{
				std::cout << check;
				std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			entered = false;
		}

	}





}
