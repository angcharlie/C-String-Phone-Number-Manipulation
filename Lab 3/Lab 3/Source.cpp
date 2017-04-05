//Charlie Ang
//01/24/16
//CSC 2430
//Prof. Tindall
//Lab #3
//This program inputs raw phone numbers and then outputs a report showing 
//both the raw number and the converted formatted number.

#include <iostream>
#include <cstring>

using namespace std;

const int RAW_MAX = 11;	//max size for raw array buffer 11 elements total plus null
const int FORMATTED_MAX = 15;	//max size for formatted array buffer 14 elements total plus null

//Function prototypes
void prompt(char arr[]);
void format(int lengthData, char raw[]);

int main()
{
	system("cls");	//clears extraneous text

	char rawData[RAW_MAX];	//10 digits max +1 for null character so 11 total

	int lengthRawData = 1;
	while (lengthRawData != 0)	//sentinel
	{
		prompt(rawData);	//calls prompt function to prompt user input 
		lengthRawData = strlen(rawData);	//determines length of user input 
		if (lengthRawData != 0)
		{
			if ((lengthRawData == 7) || (lengthRawData == 10))
			{
				format(lengthRawData, rawData);	
			}
		}

		if (lengthRawData != 0 && lengthRawData != 7 && lengthRawData != 10)
		{
			cout << "You have inputted an invalid phone number. Please enter a 7 or 10 digit number." << endl;
		}
		cout << " " << endl;	//space
	}
}

//This function takes in a char array and prompts the user to enter a phone number.
//It then stores the user input in the c-string array. 
void prompt(char arr[])
{
	cout << "Enter an unformatted phone number (hit \"Enter\" to quit): ";	//prompt to user
	cin.getline(arr, RAW_MAX, '\n');	//store user input into c-string array
}

//This function takes in an integer for the length of a data and a char array.
//It then processes and outputs a report showing both the raw phone number and the 
//formatted phone number. It also determines whether the phone number is an SPU number. 
void format(int lengthData, char raw[])
{
	char tempRaw[RAW_MAX];	//temp variable to store raw data
	if (lengthData == 7)
	{
		char temp[RAW_MAX];	//temp variable 
		strcpy_s(temp, RAW_MAX, "206");		//convert to 10 digit by adding default area code 	
		strcat_s(temp, RAW_MAX, raw);	//concatenate raw data to make it 10 digits
		strcpy_s(tempRaw, RAW_MAX, temp);	//copy temp into raw
	}
	else
	{
		strcpy_s(tempRaw, RAW_MAX, raw);	//copy raw input data into tempRaw for manipulations
	}

	char formattedTemp[FORMATTED_MAX];	//formatted c-string buffer variable 
	strcpy_s(formattedTemp, FORMATTED_MAX, "(");	//opening parenthesis
	char areaCode[RAW_MAX];	//variable to hold area code
	for (int i = 0; i < 3; i++)
	{
		areaCode[i] = tempRaw[i];	//extracting area code 
	}
	areaCode[3] = 0;	//append 0 for end of string sentinel
	strcat_s(formattedTemp, FORMATTED_MAX, areaCode);	//concatenate area code 
	strcat_s(formattedTemp, FORMATTED_MAX, ")");	//concatenate closing parenthesis 
	strcat_s(formattedTemp, FORMATTED_MAX, " ");	//concatenate space
	char middle[RAW_MAX];	//variable to hold middle three digits
	for (int i = 0; i < 3; i++)
	{
		middle[i] = tempRaw[i + 3];
	}
	middle[3] = 0;	//append 0 for end of string sentinel
	strcat_s(formattedTemp, FORMATTED_MAX, middle);	//concatenate middle three digits
	strcat_s(formattedTemp, FORMATTED_MAX, "-");	//concatenate a dash
	char lastFour[RAW_MAX];	//variable to hold last four digits
	for (int i = 0; i < 4; i++)
	{
		lastFour[i] = tempRaw[i + 6];
	}
	lastFour[4] = 0;	//append 0 for end of string sentinel
	strcat_s(formattedTemp, FORMATTED_MAX, lastFour);	//concatenate last four digits

	cout << "Unformatted phone number: " << raw << endl;	//prints out unformatted phone number 
	cout << "Formatted phone number: " << formattedTemp << endl;	//formatted phone number

	char spu1[RAW_MAX];	//variable to compare for SPU number
	strcpy_s(spu1, RAW_MAX, "281");
	char spu2[RAW_MAX];	//variable to compare for SPU number
	strcpy_s(spu2, RAW_MAX, "286");

	if (strcmp(spu1, middle) == 0 || strcmp(spu2, middle) == 0)	//if middle three digits equals 281 or 286
	{
		cout << "This is an SPU number." << endl;
	}
}
