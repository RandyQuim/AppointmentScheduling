/*
 *      File  : Doctor.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : The declaration of the class that contains the
 *              data model of a doctor and their appointments.
 */
#ifndef DOCTOR_H_
#define DOCTOR_H_
#pragma once

#include "Appointment.h"
#include<string>

class Doctor {
public:
	static const int APPT_SIZE = 8;
	Doctor(std::string name = "", int age = 0, std::string specialty = "NoSpecialty");
	std::string GetName();
	int GetAge();
	std::string GetSpecialty();
	Appointment* GetAppt();
private:
	std::string name;
	int age;
	std::string specialty;
	Appointment appointment[APPT_SIZE];
};

#endif /* DOCTOR_H_ */