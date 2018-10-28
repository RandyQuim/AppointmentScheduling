/*
 *      File  : Appointment.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : Data model for appointments (holds data for patients and their timeslot).
 */
#include "pch.h"
#include "Appointment.h"
#include "Patient.h"

Appointment::Appointment()
{
	this->timeSlot = 0;
    this->patient = Patient();
}

Appointment::Appointment(int timeSlot, Patient patient)
{
	this->timeSlot = timeSlot;
	this->patient = patient;
}

int Appointment::GetTimeSlot()
{
	return timeSlot;
}

Patient Appointment::GetPatient()
{
	return patient;
}

void Appointment::SetPatient(Patient patient)
{
	this->patient = patient;
}

void Appointment::SetTimeSlot(int timeSlot)
{
	this->timeSlot = timeSlot;
}
