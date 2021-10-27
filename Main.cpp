#include "Warehouse.h" 
using namespace std;

int main() {


	Sofa newSof1("Sofa1", 1, 99.99, "Dunelm", 001, "Tweed", "Yellow");
	Sofa newSof2("Sofa2", 5, 187, "Wilko", 101, "Plaid", "Black");
	Sofa newSof3("Sofa3", 20, 65, "M&S", 057, "Cotton", "Magenta");

	Table newTab1("Tab1", 2, 239.87, "Ikea", 123, "Mahogany", "Brown");
	Table newTab2("Tab2", 2, 77.17, "Tables 'R Us", 107, "Oak", "Green");
	Table newTab3("Tab3", 2, 3892.32, "Furniture Land", 034, "Steel", "Red");

	Bed newBed1("Bed1", 2, 66, "Dreams", 192, "Queen", "Black", "Super Soft");
	Bed newBed2("Bed2", 2, 99.00, "Bedland", 182, "King", "Orange", "Deluxe");
	Bed newBed3("Bed3", 2, 187.43, "Beddies", 177, "Twin", "Brown", "Comfy");

	Storage Warehouse;

	Warehouse.addSofa(newSof1.getName(), newSof1);
	Warehouse.addSofa(newSof2.getName(), newSof2);
	Warehouse.addSofa(newSof3.getName(), newSof3);

	Warehouse.addTable(newTab1.getName(), newTab1);
	Warehouse.addTable(newTab2.getName(), newTab2);
	Warehouse.addTable(newTab3.getName(), newTab3);

	Warehouse.addBed(newTab1.getName(), newBed1);
	Warehouse.addBed(newBed2.getName(), newBed2);
	Warehouse.addBed(newBed3.getName(), newBed3);

	
	map<string, Bed>::iterator iB;
	map<string, Sofa>::iterator iS;
	map<string, Table>::iterator iT;


	cout << "\nWelcome to the Furniture Land catalogue system.\n\n\n";
	int choice = 0, temp;
	while (choice != 7) {
		cout << "**************      MAIN MENU      **************\n\n";
		cout << "1.		Register a new model to the system" << endl;
		cout << "2.		Add/Remove stock to an existing item in warehouse" << endl;
		cout << "3.		Update the price of a model" << endl;
		cout << "4.		Check model info" << endl;
		cout << "5.		Display all items in Warehouse" << endl;
		cout << "6.		Save/load warehouse file." << endl;
		cout << "7.		Exit\n" << endl;
		while (cout << "Enter your selection (1-7):\n" && !(cin >> choice) || choice < 1 || choice>7) {
			checkInput();
		}
		switch (choice) {
		case 1: {
			cout << "\n***********     Registration Menu     ************\n\n";
			int choicey = selection();
			switch (choicey) {
			case 1: {
				cout << "\n***********     Sofa Registration     ************\n\n";
				cout << "Please enter the model name to ensure model is not currently in warehouse:" << endl;
				string name;
				cin >> name;
				if (Warehouse.searchSofa(name) != 0)cout << "Model already in Warehouse. Please check model information first.";
				else {
					cout << "Model not currently in warehouse, follow instructions to add to warehouse." <<endl;
					Sofa newSof;
					Warehouse.addSofa(newSof.getName(), newSof);
				}				
				break;
			}
			case 2: {
				cout << "\n***********     Bed Registration     ************\n\n";
				cout << "Please enter the model name to ensure model is not currently in warehouse:" << endl;
				string name;
				cin >> name;
				if (Warehouse.searchBed(name) != 0)cout << "Model already in Warehouse. Please check model information first.";
				else {
					cout << "Model not currently in warehouse, follow instructions to add to warehouse.";
					Bed newBed;
					Warehouse.addBed(newBed.getName(), newBed);
				}
				break;
			}
			case 3: {
				cout << "\n***********     Table Registration     ************\n\n";
				cout << "Please enter the model name to ensure model is not currently in warehouse:" << endl;
				string name;
				cin >> name;
				if (Warehouse.searchTable(name) != 0)cout << "Model already in Warehouse. Please check model information first.";
				else {
					cout << "Model not currently in warehouse, follow instructions to add to warehouse.";
					Table newTab;
					Warehouse.addTable(newTab.getName(), newTab);
				}
				break;
			}
			case 4: {
				continue;
			}

			}
			break;
		}
		case 2: {
			cout << "\n***********    Stock Levels Menu     ************\n\n";
			int choicey = selection();
			switch (choicey) {
			case 1: {
				cout << "\n***********     Sofa Stock     ************\n\n";
				cout << "Please follow the instructions below to change sofa stock levels.\n\n";
				cout << "Please enter the model name:" << endl;
				string name;
				cin >> name;
				iS = Warehouse.findSofa(name);
				stockUpdate(iS);
				break;
			}
			case 2: {
				cout << "\n***********     Bed Stock     ************\n\n";
				cout << "Please follow the instructions below to change bed stock levels.\n\n";
				cout << "Please enter the model name:" << endl;
				string name;
				cin >> name;
				iB = Warehouse.findBed(name);
				stockUpdate(iS);
				break;
			}
			case 3: {
				cout << "\n***********     Table Stock     ************\n\n";
				cout << "Please follow the instructions below to change table stock levels.\n\n";
				cout << "Please enter the model name:" << endl;
				string name;
				cin >> name;
				iT = Warehouse.findTable(name);
				stockUpdate(iT);
				break;
			}
			case 4: {
				continue;
			}

			}
			break;
		}
		case 3: {
			cout << "\n***********     Updating Price Menu     ************\n\n";
			int choicey = selection();
			switch (choicey) {
			case 1: {
				cout << "\n***********     Update Sofa Price     ************\n\n";
				cout << "Please enter the model name: " << endl;
				string name;
				cin >> name;
				if (int x = Warehouse.searchSofa(name) == 1) {
					iS = Warehouse.findSofa(name);
					updatePrice(iS);
				}
				else cout << "Sofa not in warehouse.";
				break;
			}
			case 2: {
				cout << "\n***********     Update Bed Price     ************\n\n";
				cout << "Please enter the model name: " << endl;
				string name;
				cin >> name;
				if (int x = Warehouse.searchBed(name) == 1) {
					iB = Warehouse.findBed(name);
					updatePrice(iB);
				}
				else cout << "Bed not in warehouse.";
				break;
			}
			case 3: {
				cout << "\n***********     Update Table Price     ************\n\n";
				cout << "Please enter the model name: " << endl;
				string name;
				cin >> name;
				if (int x = Warehouse.searchTable(name) == 1) {
					iT = Warehouse.findTable(name);
					updatePrice(iT);
				}
				else cout << "Sofa not in warehouse.";
				break;
			}
			case 4: {
				continue;
			}

			}
			break;

		}
		case 4: {
			cout << "Checking model info" << endl;
			//int modNum = modNo();
			cout << "\n***********     Model Information Menu     ************\n\n";
			int choicey = selection();
			switch (choicey) {
			case 1: {
				cout << "\n***********     Sofa Information     ************\n\n";
				cout << "Please enter the model name: " << endl;
				string name;
				cin >> name;
				if (int x = Warehouse.searchSofa(name) == 1) {
					iS = Warehouse.findSofa(name);
					iS->second.printDetails();
				}
				else cout << "Sofa not in warehouse.";
				break;
			}
			case 2: {
				cout << "\n***********    Bed Information     ************\n\n";
				cout << "Please enter the model name: " << endl;
				string name;
				cin >> name;
				if (int x = Warehouse.searchBed(name) == 1) {
					iB = Warehouse.findBed(name);
					iB->second.printDetails();
				}
				else cout << "Bed not in warehouse.";
				break;
			}
			case 3: {
				cout << "\n***********     Table Information     ************\n\n";
				cout << "Please enter the model name: " << endl;
				string name;
				cin >> name;
				if (int x = Warehouse.searchTable(name) == 1) {
					iT = Warehouse.findTable(name);
					iT->second.printDetails();
				}
				else cout << "Table not in warehouse.";
				break;
			}
			case 4: {
				continue;
			}

			}
			break;


		}
		case 5: {
			cout << "\n***********     Warehouse Inventory     ************\n\n";
			cout << "***********     SOFAS     ************\n";
			Warehouse.printSofas();
			cout << "\n***********     BEDS     ************\n\n";
			Warehouse.printBeds();
			cout << "\n***********     TABLES     ************\n\n";
			Warehouse.printTables();
			break;
		}
		case 6: {
			cout << "Would you like to load or save file?" << endl;
			cout << "1.			Save" << endl;
			cout << "2.			Load" << endl;
			int choice, num;
			cin >> choice;
			switch (choice) {
			case 1: {
				string name;
				cout << "\n***********     Saving     ************\n";
				cout << "Please enter the name for the warehouse file.";
				cin >> name;
				Warehouse.saveToFile(name + ".txt");
				break;
			}
			case 2: {
				string file;
				cout << "\n***********     Loading     ************\n" << endl;
				cout << "Please enter the file name to be loaded." << endl;
				cin >> file;
				Warehouse.getFromFile(file);
				break;
			}
			}
			
		}
		case 7: {
			break;
		}
		}
		cout << "\nAre you sure you want to exit? (y/n)" << endl;
		while (true) {
			string selection;
			cin >> selection;
			if (selection == "n") {
				choice = 7;
				break;
			}
			else if (selection == "y") {
				choice = 0;
				break;
			}
			else {
				cout << "Incorrect input please enter y or no.\n";
				continue;
			}
		}
	}
	





	return 0;
}

