/*
 *      File  : Patient.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : The declaration of the class that contains the 
 *              data model of a patient.
 */
#ifndef PATIENT_H_
#define PATIENT_H_
#pragma once

#include<string>

class Patient {
public:
	Patient(std::string name = "", int age = 0, std::string gender = "NoGender");
	std::string GetName();
	int GetAge();
	std::string GetGender();

private:
	std::string name;
	int age;
	std::string gender;
};

#endif /* PATIENT_H_ */