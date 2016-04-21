#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
std::string converter(int number);

int main(int argc, char *argv[])
{
    int argument = atoi(argv[1]);
	printf("Hello, World!\n");
	std::cout <<  converter(argument) << endl;
}

std::string converter(int number)
{
	int tab[7];

	for(int i = 6; i > -1; i--)
	{
		tab[i] = number%10;
		number/=10;
	}

	std::string ones[] = {"", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
	std::string teens[] = {"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie",
							"pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
	std::string tens[] = {"","dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdzesiat", "szescdziesiat",
							"siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
	std::string hundreds[] = {"", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset",
							"osiemset", "dziewiecset"};
	std::string millions[] = {"", "milion"};

	std::string result;

	if(tab[0] != 1 && tab[0] != 0)
		result = "Liczba jest zbyt duza. Podaj liczbe do tysiaca.";
	else
	{
		result = millions[tab[0]];

		result += " " + hundreds[tab[1]];

		if(tab[2] == 1 )
        	    result += " " + teens[tab[3]];
		else
			{
				result += " " + tens[tab[2]];
				result += " " + ones[tab[3]];
			}

			if(tab[1] == 0 && tab[2] == 0 && tab[3] == 1)
				result += " tysiac";
			if(tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0){}
			else if((tab[3] == 0 || tab[3] == 1) || tab[3] >= 5)
					result += " tysiecy";
				 else
					result += " tysiace";


		result += " " + hundreds[tab[4]];

		if(tab[5] == 1 )
				result += " " + teens[tab[6]];
		else
			{
				result += " " + tens[tab[5]];
				result += " " + ones[tab[6]];
			}

	}

	return result;
}