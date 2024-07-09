//Raajih Roland
//CIS 1202.5T1
//July 9, 2024

#include "Publication.h"
#include <fstream>

//Prototype
void getPublicationInfo(Publication&);
void getPublications(Publication[], int&);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

int main()
{
	const int MAX_SIZE = 20;
	Publication library[MAX_SIZE];
	int numBooks, userChoice;
	string temp;//Holds title user is looking for
	int searchIndex;//Holds the index of title we're looking for or -1 if not found

	//Create array of Publications
	getPublications(library, numBooks);

	do {
		userChoice = getMenuChoice();
		cin.ignore();
		switch (userChoice)
		{
		case 1://Show all info
			showPublications(library, numBooks);
			break;
		case 2://Show all titles
			showTitles(library, numBooks);
			break;
		case 3://Find a publication
			cout << "What is the title of the publication (case sensitive): ";
			getline(cin, temp);
			searchIndex = findPublication(library, numBooks, temp);
			if (searchIndex == -1)
			{
				cout << "Title not found";
				break;
			}
			else
			{
				library[searchIndex].displayInfo();//Output information about publication
			}
			break;
		case 4://Check out
			cout << "What is the title of the publication you want to check out (case sensitive): ";
			getline(cin, temp);
			searchIndex = findPublication(library, numBooks, temp);
			if (searchIndex == -1)
			{
				cout << "Title not found";
				break;
			}
			else
			{
				library[searchIndex].checkOut();
			}
			break;
		case 5:
			cout << "What is the title of the publication you want to check in (case sensitive): ";
			getline(cin, temp);
			searchIndex = findPublication(library, numBooks, temp);
			if (searchIndex == -1)
			{
				cout << "Title not found";
				break;
			}
			else
			library[searchIndex].checkIn();
			break;

		}
	} while (userChoice != 6);
	
	return 0;
}

void getPublicationInfo(Publication& x)
{
	string tempTitle, tempPublisher;
	float tempPrice;
	int tempYear;
	PublicationType tempType;
	int integerType;
	int tempStock;

	//Prompt and get info
	cout << "Title?: ";
	getline(cin, tempTitle);
	cout << "Publisher?: ";
	getline(cin, tempPublisher);
	cout << "Price?: ";
	cin >> tempPrice;
	while (tempPrice < 0)//Validate price
	{
		cout << "ERROR. INVALID INPUT. Please try again: ";
		cin >> tempPrice;
	}
	cout << "Year?: ";
	cin >> tempYear;

	//Get integer for publication type and convert to enum
	cout << "1.Book / 2.Magazine / 3.Newspaper / 4.Audio / 5.Video";
	cout << "\nType?: ";
	cin >> integerType;
	while (integerType < BOOK || integerType > VIDEO)//Validate type
	{
		cout << "ERROR. Invalid type. Please try again: ";
		cin >> integerType;
	}
	integerType--;//ALMOST FORGOT
	tempType = static_cast<PublicationType>(integerType);//Convert to publicationtype 
	cout << "Stock?: ";
	cin >> tempStock;
	while (tempStock < 0)//Validate stock
	{
		cout << "ERROR. INVALID INPUT. Please try again: ";
		cin >> tempStock;
	}


	//Initialize publication object
	x.storePublication(tempTitle, tempPublisher, tempPrice, tempYear, tempType, tempStock);
}

//Read info from file
void getPublications(Publication library[], int& size)
{
	//File operations
	fstream dataFile;
	dataFile.open("publications.txt", ios::in);

	//Temp variables
	string tempTitle, tempPublisher;
	float tempPrice;
	int tempYear;
	PublicationType tempType;
	int tempIntType;
	//One of the stocks is a decimal so have to do this to truncate
	double tempStock;
	int actualTempStock;

	//Initialize size
	size = 0;

	if (dataFile)//Check to see if it opens correctly
	{
		while (getline(dataFile, tempTitle))//Make sure we're not at the end of the file
		{
			
			getline(dataFile, tempPublisher);
			dataFile >> tempPrice;
			dataFile >> tempYear;
			dataFile >> tempIntType;
			tempType = static_cast<PublicationType>(tempIntType);//Convert to publicationtype 
			dataFile >> tempStock;
			actualTempStock = tempStock;

			dataFile.ignore();

			//Put all info into this element of Publications array
			library[size].storePublication(tempTitle, tempPublisher, tempPrice, tempYear, tempType, actualTempStock);
			size++;
		}
	}
	else
		cout << "File could not open.";
		
	dataFile.close();

}

//Loop through array of publications
void showPublications(Publication library[], int size)
{
	for (int i = 0; i < size; i++)
	{
		library[i].displayInfo();
	}
	cout << "\n";
}

//Show titles
void showTitles(Publication library[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << library[i].getTitle() << "\n";
	}
}

int findPublication(Publication library[], int size, string titleWanted)
{
	
	for (int i = 0; i < size; i++)
	{
	
		if (library[i].getTitle() == titleWanted)
			return i;
		
	}

	return -1;
}

int getMenuChoice()
{
	int choice;
	cout << "\n1. Display all publications\n"
		<< "2. Display publication titles\n"
		<< "3. Find a publication\n"
		<< "4. Check out\n"
		<< "5. Check in\n"
		<< "6. Exit\n";
	
	cin >> choice;
	while (choice < 1 || choice > 6)
	{
		cout << "ERROR INVALID CHOICE. Please try again: ";
		cin >> choice;
	}
	
	return choice;
}