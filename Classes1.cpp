//Raajih Roland
//CIS 1202.5T1
//July 2, 2024
//DRIVER FILE

#include "Publication.h"


void getPublicationInfo(Publication&);

int main()
{
	Publication var;
	getPublicationInfo(var);
	cout << "Title: " << var.getTitle() << endl;
	var.checkOut();
	cout << var.getStock() << " in stock.\n";
	var.checkIn();
	cout << var.getStock() << " in stock.\n";


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