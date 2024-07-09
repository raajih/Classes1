//Raajih Roland
//CIS 1202.5T1
//July 2, 2024
//IMPLEMENTATION FILE
#include "Publication.h"


//Store all member variable info
void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock)
{
	title = itemTitle;
	publisher = itemPublisher;
	price = itemPrice;
	year = itemYear;
	type = itemType;
	stock = itemStock;
}

//Output member variables
void Publication::displayInfo()
{
	cout << "\nTitle: " << title
		<< "\nPublisher: " << publisher
		<< "\nPrice: " << price
		<< "\nYear: " << year
		<< "\nType: " << type
		<< "\nStock: " << stock;
		
}

void Publication::checkOut()
{
	if (stock < 1)
		cout << "Sorry we are out of stock\n";
	else
	{
		stock--;
		cout << "Publication is checked out!\n";
	}

}

void Publication::checkIn()
{
	stock++;
	cout << "Publication checked in!";
}

string Publication::getTitle() const
{
	return title;
}

int Publication::getStock() const
{
	return stock;
}