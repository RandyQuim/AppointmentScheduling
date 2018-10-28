/*
 *      File  : Doctor.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : Data model for individualized doctor objects.
 */
#include "pch.h"
#include "Doctor.h"
#include "PatientList.h"
#include<iostream>

using namespace std;

Doctor::Doctor(string name, int age, std::string specialty)
{
	this->name = name;
	this->age = age;
	this->specialty = specialty;
}

string Doctor::GetName()
{
	return name;
}

int Doctor::GetAge() 
{
	return age;
}

string Doctor::GetSpecialty()
{
	return specialty;
}

Appointment * Doctor::GetAppt()
{
	return appointment;
}


