/*
 *      File  : Appointment.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : The declaration of the class that contains the
 *              data model of an appointment.
 */
#pragma once
#ifndef APPOINTMENT_H_
#define APPOINTMENT_H_

#include "Patient.h"

class Appointment {
public:
	Appointment();
	Appointment(int timeSlot, Patient patient);
	int GetTimeSlot();
	Patient GetPatient();
	void SetPatient(Patient patient);
	void SetTimeSlot(int timeSlot);
private:
	int timeSlot;
	Patient patient;
};

#endif /* APPOINTMENT_H_ */