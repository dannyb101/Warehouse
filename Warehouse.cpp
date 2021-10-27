#include "Warehouse.h"

//Base class definitions
Item::Item() {
	cout << "What is the name of the model?\n";
	cin >> modelName;
	while (cout << "How many items would you like to add?\n" && !(cin >> numberItems)) {
		checkInput();
	}
	while(cout << "What is the price of one item?\n" && !(cin >> price)) {
		checkInput();
	}
	cout << "Who is the manufacturer?\n";
	cin >> manufacturer;
	while (cout << "What is the model number?\n" && !(cin >> modelNumber)) {
		checkInput();
	}
	
}
Item::Item(string Name, int Items, double newP, string man, int modNum) { 
	modelName = Name; 
	numberItems = Items; 
	price = newP; 
	manufacturer = man; 
	modelNumber = modNum; 
}

inline void Item::printDetails() const {
	cout << "Model Name: " << modelName << endl;
	cout << "Number of Items in Warehouse: " << numberItems << endl;
	cout << "Current Price: " << price << endl;
	cout << "Manufacturer: " << manufacturer << endl;
	cout << "Model Number: " << modelNumber << endl;
}
inline void Item::setDetails() {
	cout << "Please enter the new model name:\n";
	cin >> modelName;
	cout << "Please enter the new number of items:\n";
	cin >> numberItems;
	cout << "What is the new price of one item?\n";
	cin >> price;
	cout << "Who is the manufacturer?\n";
	cin >> manufacturer;
	cout << "What is the model number?\n";
	cin >> modelNumber;
}


//Derived class definitions

//Sofa definitions
Sofa::Sofa()
{
	cout << "Please enter the sofa fabric:\n";
	cin >> fabric;
	cout << "Pleae enter the sofa colour:\n";
	cin >> colour;
}
void Sofa::setDetails() {
	cout << "Adjusting details of sofa warehouse item.\n";
	Item::setDetails();
	cout << "Please enter the sofa fabric:\n";
	cin >> fabric;
	cout << "Please enter the sofa colour:\n";
	cin >> colour;

}
inline void Sofa::printDetails() const {
	Item::printDetails();
	cout << "Fabric: " << fabric << "\nColour: " << colour << "\n";
}


//Bed definitions
Bed::Bed()
{
	cout << "Please enter the type of frame:\n";
	cin >> frame;
	cout << "Pleae enter the frame colour:\n";
	cin >> frameColour;
	cout << "Please enter the mattress:\n";
	cin >> mattress;
}
inline void Bed::printDetails() const {
	Item::printDetails();
	cout << "Category: Beds\nFrame: " << frame << "\nFrame Colour: " << frameColour << "\nMattress: " << mattress << "\n";
}
void Bed::setDetails() {
	cout << "Adjusting details of bed warehouse item.\n";
	Item::setDetails();
	cout << "Please enter the bed frame:\n";
	cin >> frame;
	cout << "Please enter the bed frame colour:\n";
	cin >> frameColour;
	cout << "Please enter the type of mattress:\n";
	cin >> mattress;

}

//Table definitions
Table::Table()
{
	cout << "Please enter the table material:\n";
	cin >> material;
	cout << "Please enter the table colour:\n";
	cin >> colour;
}
inline void Table::printDetails() const {
	Item::printDetails();
	cout << "Material: " << material << "\nColour: " << colour << "\n";
}
void Table::setDetails() {
	cout << "Adjusting details of table warehouse item.\n";
	Item::setDetails();
	cout << "Please enter the table material:\n";
	cin >> material;
	cout << "Please enter the table colour:\n";
	cin >> colour;

}

//Storage definitions


int Storage::searchSofa(string name) const {
	if (S.count(name) > 0) {
		return 1;
	}
	else return 0;
}
int Storage::searchBed(string name) const {
	if (B.count(name) > 0) {
		return 1;
	}
	else return 0;
}
int Storage::searchTable(string name) const {
	if (T.count(name) > 0) {
		return 1;
	}
	else return 0;
}
void Storage::printSofas() {
	map<string, Sofa>::iterator pos;
	for (pos = S.begin(); pos != S.end(); ++pos) {
		cout << pos->second.getName() << endl;
	}
}
void Storage::printBeds() {
	map<string, Bed>::iterator pos;
	for (pos = B.begin(); pos != B.end(); ++pos) {
		cout << pos->second.getName() << endl;
	}
}
void Storage::printTables() {
	map<string, Table>::iterator pos;
	for (pos = T.begin(); pos != T.end(); ++pos) {
		cout << pos->second.getName() << endl;
	}
}


void Storage::saveToFile(string fileName) {
	ofstream myfile(fileName);
	map<string, Sofa>::iterator pos;
	for (pos = S.begin(); pos != S.end();++pos) {
		myfile << "sofa " << pos->second.getName() << " " << pos->second.getNumItems() << " " << pos->second.getManufact() 
			<< " " << pos->second.getPrice() << " " << pos->second.getModNum() << " " << pos->second.getFabric() << " " << pos->second.getColour() << endl;
	}
	map<string, Bed>::iterator it;
	for (it = B.begin(); it != B.end(); ++it) {
		myfile << "bed " << it->second.getName() << " " << it->second.getNumItems() << " " << it->second.getManufact()
			<< " " << it->second.getPrice() << " " << it->second.getModNum() << " " << it->second.getFrame() << " " << it->second.getFrameColour() << " " << it->second.getMattress() << endl;
	}
	map<string, Table>::iterator iter;
	for (iter = T.begin(); iter != T.end(); ++iter) {
		myfile << "table " << iter->second.getName() << " " << iter->second.getNumItems() << " " << iter->second.getManufact()
			<< " " << iter->second.getPrice() << " " << iter->second.getModNum() << " "  << iter->second.getMaterial() << " " << iter->second.getColour() << endl;
	}
	myfile.close();
	
}
void Storage::getFromFile(string fileName) {
	

	ifstream myfile(fileName);
	if (myfile) {
		string line, type, name, manufac, fab, col, frame, framecol, mattress, material, colour;
		int numItem, modNum;
		double price;
		while (myfile >> type) {
			if (type == "bed") break;
			else {
				myfile >> name >> numItem >> manufac >> price >> modNum >> fab >> col;
			}
			Sofa sof(name, numItem, price, manufac, modNum, fab, col);
			S.insert(make_pair(name, sof));
		}
		myfile >> name >> numItem >> manufac >> price >> modNum >> frame >> framecol >> mattress;
		Bed bed(name, numItem, price, manufac, modNum, frame, framecol, mattress);
		B.insert(make_pair(name, bed));
		while (myfile >> type) {
			if (type == "table")break;
			else {
				myfile >> name >> numItem >> manufac >> price >> modNum >> frame >> framecol >> mattress;
				Bed bed(name, numItem, price, manufac, modNum, frame, framecol, mattress);
				B.insert(make_pair(name, bed));
			}
		}
		myfile >> name >> numItem >> manufac >> price >> modNum >> material >> colour;
		Table tab(name, numItem, price, manufac, modNum, material, colour);
		T.insert(make_pair(name, tab));
		while (myfile >> type) {
			myfile >> name >> numItem >> manufac >> price >> modNum >> material >> colour;
			Table tab(name, numItem, price, manufac, modNum, material, colour);
			T.insert(make_pair(name, tab));
		}
		cout << "Juicy.txt loaded to Warehosue." << endl;
	}
	else {
		cout << "File does not exist" << endl;
	}
	
}





//Global function definitions

//sub-menu selection to choose between different object types
int selection() {
	cout << "Which category does the item belong to?\n" << endl;
	cout << "1.		Sofa" << endl;
	cout << "2.		Bed" << endl;
	cout << "3.		Table" << endl;
	cout << "4.		Return to main menu.\n" << endl;
	int choice;
	while (cout << "Enter your selection (1-4):\n" && !(cin >> choice) || choice < 1 || choice > 4) {
		checkInput();
	}
	
	return choice;
}

//funciton to facilitate checking input to menu options is valid
void checkInput() {
	cout << "Incorrect input, please re-enter." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


