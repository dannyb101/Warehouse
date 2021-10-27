#ifndef Warehouse_H
#define Warehouse_H

#include <string>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;


//Abstract parent Class declaration
class Item {

	string modelName;
	int numberItems;

	//aditional member attributes
	string manufacturer;
	double price;
	int modelNumber;
public:
	Item();
	Item(string name, int number, double newP, string man, int modNum);
	~Item() {};

	//Accesors
	string getName()const { return modelName; }
	int getNumItems() const { return numberItems; }
	string getManufact() const { return manufacturer; }
	double getPrice() const { return price; }
	int getModNum()const { return modelNumber; }
	virtual void printDetails() const = 0;

	//Mutators
	void addStock(int num) { numberItems += num; }
	void removeStock(int num) { numberItems -= num; }
	void setDetails();
	virtual void setPrice(float newP) { price = newP; }
	
};


//Derived class declarations
class Sofa :public Item
{
	string fabric;
	string colour;
public:
	Sofa();
	Sofa(string newName, int noItems, float newP, string man, int modNum, string newFab, string newCol) : Item(newName, noItems, newP, man, modNum), fabric(newFab), colour(newCol) {}
	
	//Accessors
	string getFabric() const { return fabric; }
	string getColour() const { return colour; }
	void printDetails() const;

	//Mutator
	void setDetails();

};

class Bed :public Item
{
	string frame;
	string frameColour;
	string mattress;
public:
	Bed();
	Bed(string newName, int noItems, float newP, string man, int modNum, string newFrame, string newCol, string newMat) :Item(newName, noItems, newP, man, modNum), frame(newFrame), frameColour(newCol), mattress(newMat) {}
	
	//Accesors
	string getFrame() const { return frame; }
	string getFrameColour() const{ return frameColour; }
	string getMattress() const { return mattress; }
	void printDetails() const;

	//Mutator
	void setDetails();
};

class Table :public Item
{
	string material;
	string colour;
public:
	Table();
	Table(string newName, int noItems, float newP, string man, int modNum, string newMat, string newCol) :Item(newName, noItems, newP, man, modNum), material(newMat), colour(newCol) {}
	
	//Accessors
	string getMaterial() const { return material; }
	string getColour() const { return colour; }
	void printDetails() const;

	//Mutator
	void setDetails();
};


//Container class declaration
class Storage {
	map<string, Bed> B;
	map<string, Sofa> S;
	map<string, Table> T;
public:
	Storage() :B{}, S{}, T{}{};
	void addBed(string name, Bed b) {B.insert(make_pair(name, b));}
	void addSofa(string name, Sofa s) { S.insert(make_pair(name, s)); }
	void addTable(string name, Table t) { T.insert(make_pair(name, t)); }

	//methods to return iterator from key of item name 
	map<string, Bed>::iterator findBed(string name) { return B.find(name); }
	map<string, Sofa>::iterator findSofa(string name){return S.find(name);}
	map<string, Table>::iterator findTable(string name) {return T.find(name);}

	//methods to check if item exists in the maps
	int searchSofa(string name) const;
	int searchBed(string name) const;
	int searchTable(string name) const;
	
	void printSofas();
	void printBeds();
	void printTables();

	void saveToFile(string fileName);
	void getFromFile(string fileName);

};


//Global functions

int selection();

void checkInput();

template<class T>
void stockUpdate(T t)
{
	cout << "You have selected " << t->second.getName() << ", current stock level is: " << t->second.getNumItems() << endl;
	cout << "Would you like to add or remove stock?" << endl;
	cout << "1.			Add" << endl;
	cout << "2.			Remove" << endl;
	int choice, num;
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "How many items would you like to add?" << endl;
		cin >> num;
		while (true) {
			int temp = num + t->second.getNumItems();
			if (temp < 0) {
				cout << "Stock level cannot drop below 0, please enter a new value.";
				cin >> num;
			}
			else {
				t->second.addStock(num);
				break;
			}
		}
		cout << "New stock level is: " << t->second.getNumItems();
		break;
	}
	case 2: {
		cout << "How many items would you like to remove?" << endl;
		cin >> num;
		while (true) {
			int temp = -num + t->second.getNumItems();
			if (temp < 0) {
				cout << "Stock level cannot drop below 0, please enter a new value.";
				cin >> num;
			}
			else {
				t->second.removeStock(num);
				break;
			}
		}
		cout << "New stock level is: " << t->second.getNumItems();
		break;
	}
	}
}

template<class X>
void updatePrice(X x) {
	cout << "The current price for " << x->second.getName() << " is: " << x->second.getPrice() << endl;
	cout << "Please enter the new price: ";
	double price;
	cin >> price;
	x->second.setPrice(price);
}
















#endif