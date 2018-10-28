/*
 *      File  : Menu.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : Class contains menues and menu options for
 *              users.  Passes user choices to a menu controller. 
 */
#include "pch.h"
#include "Menu.h"
#include "DoctorList.h"
#include "PatientList.h"
#include<iostream>

using namespace std;

Menu::Menu()
{

}

Menu::Menu(MenuController controller)
{
	this->controller = controller;
}

bool Menu::MainMenu() const
{
	bool exit = false;
	int choice = 0;
	cout << endl;
	cout << "Please choose an option: " << endl;
	cout << "1. Schedule an appointment\n2. Remove an appointment\n" << 
		"3. Search for doctor or patient record by name\n4. Print all patient info\n" <<
		"5. Print all doctor info\n6. Check appointment availability" << 
		"\n7. Quit Program" << endl;
	cin >> choice;
	switch(choice){
	case 1:
		controller.ScheduleAppointment(DocNameMenu(), TimeSlotMenu(), PatientNamePrompt());
		break;
	case 2:
		controller.RemoveAppointment(DocNameMenu(), TimeSlotMenu());
		break;
	case 3:
		IdMenu();
		break;
	case 4:
		controller.PrintPatientInfo();
		break;
	case 5:
		controller.PrintDrInfo();
		break;
	case 6:
		controller.CheckAvailability(DocNameMenu(), TimeSlotMenu());
		break;
	case 7:
		exit = true;
		break;
	default:
		cout << "That is not a menu option!" << endl;
		break;
	}

	return exit;
}

string Menu::DocNameMenu() const
{
	int choice = 0;
	string name = "";
	bool flag = false;

	while (!flag) {
		cout << "Please choose a doctor: " << endl;
		for (int i = 0; i < DoctorList::size; i++) {
			cout << i + 1 << ". " << DoctorList::doctors[i].GetName() << endl;
		}
		cin >> choice;
		switch (choice) {
		case 1:
			flag = true;
			name = "Gerardo Socia";
			break;
		case 2:
			flag = true;
			name = "Jeremy Porche";
			break;
		case 3:
			flag = true;
			name = "Tamiko Poat";
			break;
		case 4:
			flag = true;
			name = "Marjorie Weatherman";
			break;
		case 5:
			flag = true;
			name = "Cheyenne Stevenson";
			break;
		default:
			cout << "That is not a valid input.  Try again." << endl;
			break;
		}
	}

	return name;
}

int Menu::TimeSlotMenu() const
{
	int choice = 0;
	int timeSlot = 0;
	bool flag = false;

	while (!flag) {
		cout << "Please choose an appointment time: " << endl;
		cout << "1. 08:00 AM\n2. 09:00 AM\n3. 10:00 AM\n4. 11:00 AM\n5." <<
			" 12:00 PM\n6. 01:00 PM\n7. 02:00 PM\n8. 03:00 PM" << endl;
		cin >> choice;
		if ((choice >= 1) && (choice <= 8)) {
			flag = true;
			timeSlot = choice;
		}
		else {
			cout << "That is not an option.  Please try again." << endl;
		}	
	}

	return timeSlot;
}

string Menu::PatientNamePrompt() const
{
	bool flag = false;
	string patientName = "";
	string junk = "";
	
	cout << "Please enter a patient name from the list: ";
	// Just used to read the \n character from the previous << operator
	getline(cin, junk);
	
	while (!flag) {
		getline(cin, patientName);
		for (int i = 0; i < PatientList::size; i++) {
			if (patientName == PatientList::patients[i].GetName()) {
				flag = true;
			}
		}
		if (!flag) {
			cout << "\nThat is not a patient in the records.  Try again." << endl;
			cout << "Enter a patient name from the list: ";
		}
	}

	return patientName;
}

void Menu::IdMenu() const
{
	string name = "";
	int choice = 0;
	cout << "Please identify the type of record: " << endl;
	cout << "1. Patient\n2. Doctor" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		name = PatientNamePrompt();
		break;
	case 2:
		name = DocNameMenu();
		break;
	}

	controller.RetrieveRecord(name, choice);
}
