/*
 *      File  : MenuController.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : The class that controls the logic (business logic)
 *              of the system.  All functions perform some kind of
 *              action.
 */
#include "pch.h"
#include "MenuController.h"
#include "DoctorList.h"
#include "PatientList.h"
#include<iostream>

using namespace std;

void MenuController::ScheduleAppointment(string docName, int timeSlot, string patientName) const
{
	int doctorPos = FindDoctor(docName);
	if (TimeSlotAvailable(timeSlot, doctorPos)) {
		InsertAppointment(doctorPos, timeSlot, patientName);
	}
	else {
		cout << "Unfortunately, the doctor has no availability for the given timeslot..." << endl;
	}
}

void MenuController::RemoveAppointment(string docName, int timeSlot) const
{
	int doctorPos = FindDoctor(docName);
	for (int i = 0; i < Doctor::APPT_SIZE; i++) {
		if (DoctorList::doctors[doctorPos].GetAppt()[i].GetTimeSlot() == timeSlot) {		
			DoctorList::doctors[doctorPos].GetAppt()[i].SetTimeSlot(0);
			Patient patient;
			DoctorList::doctors[doctorPos].GetAppt()[i].SetPatient(patient);
			cout << "You successfully removed the appointment..." << endl;
			break;
		}
	}
}

void MenuController::CheckAvailability(std::string docName, int timeSlot) const
{
	int doctorPos = FindDoctor(docName);
	if (!TimeSlotAvailable(timeSlot, doctorPos)){
		cout << "Unfortunately, that time slot is booked." << endl;
	}
	else {
		cout << "Time slot is available!!" << endl;
	}

	
}

void MenuController::RetrieveRecord(std::string iD, int choice) const
{
	int pos = 0;
	if (choice == 1) {
		pos = FindPatient(iD);
		cout << "Name: " << PatientList::patients[pos].GetName() << "\nAge: "
			<< PatientList::patients[pos].GetAge() << "\nGender: "
			<< PatientList::patients[pos].GetGender() << endl;
	}
	else if (choice == 2) {
		pos = FindDoctor(iD);
		std::cout << "Name: Dr. " << DoctorList::doctors[pos].GetName() 
			<< "\nAge: " << DoctorList::doctors[pos].GetAge() << "\nSpecialty: "
			<< DoctorList::doctors[pos].GetSpecialty() << " \nSchedule: " << endl;
		for (int i = 0; i < Doctor::APPT_SIZE; i++) {
			std::cout << DoctorList::doctors[pos].GetAppt()[i].GetPatient().GetName()
				<< "  " << FormatTimeSlot(DoctorList::doctors[pos].GetAppt()[i].GetTimeSlot()) << endl;
		}
	}
	else {
		cout << "That is not an option!" << endl;
	}
}

void MenuController::PrintDrInfo() const
{
	for (int i = 0; i < DoctorList::size; i++) {
		cout << "Dr. " << DoctorList::doctors[i].GetName() 
			<< ", Age: " << DoctorList::doctors[i].GetAge() 
			<< ", Specialty: " << DoctorList::doctors[i].GetSpecialty()
			<< endl;
		cout << "Patients: " << endl;
		for (int j = 0; j < Doctor::APPT_SIZE; j++) {
			cout << DoctorList::doctors[i].GetAppt()[j].GetPatient().GetName() 
				<< " " << FormatTimeSlot(DoctorList::doctors[i].GetAppt()[j].GetTimeSlot()) << endl;
		}
		cout << endl;
	}
}

void MenuController::PrintPatientInfo() const
{
	for (int i = 0; i < PatientList::size; i++) {
		cout << PatientList::patients[i].GetName()
			<< ", Age: " << PatientList::patients[i].GetAge()
			<< ", Gender: " << PatientList::patients[i].GetGender() << endl;
	}
}

void MenuController::PrepopulateAppointments() const
{
	int counter1 = 1;
	int patientPos = 0;
	// Auto-fills timeslots and patients for doctors.
	for (int i = 0; i < DoctorList::size; i++) {
		for (int j = 0; j < Doctor::APPT_SIZE - 2; j++) {
			DoctorList::doctors[i].GetAppt()[j].SetPatient(PatientList::patients[patientPos]);
			++patientPos;
			++counter1;
			// Varies the timeslots taken up by patients
			if (counter1 > 8) {
				counter1 = counter1 % 4;
			}

			DoctorList::doctors[i].GetAppt()[j].SetTimeSlot(counter1);
		}
	}
}

int MenuController::FindDoctor(string docName) const
{
	for (int i = 0; i < DoctorList::size; i++) {
		if (DoctorList::doctors[i].GetName() == docName) {
			return i;
		}
	}
}

int MenuController::FindPatient(std::string patientName) const
{
	for (int i = 0; i < PatientList::size; i++) {
		if (PatientList::patients[i].GetName() == patientName) {
			return i;
		}
	}
}

bool MenuController::TimeSlotAvailable(int timeSlot, int doctorPos) const
{
	for (int i = 0; i < Doctor::APPT_SIZE; i++) {
		if (DoctorList::doctors[doctorPos].GetAppt()[i].GetTimeSlot() == timeSlot) {
			return false;
		}
	}
	return true;
}

void MenuController::InsertAppointment(int doctorPos, int timeSlot, string patientName) const
{
	for (int i = 0; i < Doctor::APPT_SIZE; i++) {
		if (DoctorList::doctors[doctorPos].GetAppt()[i].GetTimeSlot() == 0) {
			DoctorList::doctors[doctorPos].GetAppt()[i].SetTimeSlot(timeSlot);
			Patient patient(patientName);
			DoctorList::doctors[doctorPos].GetAppt()[i].SetPatient(patient);
			cout << "You have successfully booked an appointment!" << endl;
			break;
		}
	}
}

string MenuController::FormatTimeSlot(int timeSlot) const
{
	string formattedTime = "";
	switch (timeSlot) {
	case 1:
		formattedTime = "08:00 AM";
		break;
	case 2:
		formattedTime = "09:00 AM";
		break;
	case 3:
		formattedTime = "10:00 AM";
		break;
	case 4:
		formattedTime = "11:00 AM";
		break;
	case 5:
		formattedTime = "12:00 PM";
		break;
	case 6:
		formattedTime = "01:00 PM";
		break;
	case 7:
		formattedTime = "02:00 PM";
		break;
	case 8:
		formattedTime = "03:00 PM";
		break;
	default:
		formattedTime = "FREE";
		break;
	}
	return formattedTime;
}
