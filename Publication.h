//Raajih Roland
//CIS 1202.5T1
//July 2, 2024
//SPECIFICATION FILE
#pragma once
#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string>
#include <iostream>
using namespace std;

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication
{
private:
	//Member variables
	string title;
	string publisher;
	float price;
	int year;
	PublicationType type;
	int stock;

public:
	//Member functions
	void storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock);//Store parameters in publication member variables
	void displayInfo();//Display contents of member variables
	void checkOut();//Make sure stock isn't zero, then subtract 1
	void checkIn();//Add 1 to stock
	string getTitle() const;//Return title
	int getStock() const;//Return stock


};


#endif