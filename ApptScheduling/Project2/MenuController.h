/*
 *      File  : MenuController.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : The declaration of the class that controls the
 *              logic (business logic) of the system.
 */
#pragma once
#ifndef MENUCONTROLLER_H_
#define MENUCONTROLLER_H_

#include<string>
#include<iostream>

class MenuController {
public:
	void ScheduleAppointment(std::string docName, int timeSlot, std::string patientName) const;
	void RemoveAppointment(std::string docName, int timeSlot) const;
	void CheckAvailability(std::string docName, int timeSlot) const;
	void RetrieveRecord(std::string iD, int choice) const;
	void PrintDrInfo() const;
	void PrintPatientInfo() const;
	void PrepopulateAppointments() const;
	std::string FormatTimeSlot(int timeSlot) const;
private:
	int FindDoctor(std::string docName) const;
	int FindPatient(std::string patientName) const;
	bool TimeSlotAvailable(int timeSlot, int doctorPos) const;
	void InsertAppointment(int doctorPos, int timeSlot, std::string patientName) const;
};


#endif /* MENUCONTROLLER_H_ */