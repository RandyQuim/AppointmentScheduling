/*
 *      File  : Patient.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : Data model for individualized patient objects.
 */
#include "pch.h"
#include "Patient.h"
#include<iostream>

using namespace std;

Patient::Patient(std::string name, int age, std::string gender)
{
	this->name = name;
	this->age = age;
	this->gender = gender;
}

string Patient::GetName()
{
	return name;
}

int Patient::GetAge()
{
	return age;
}

string Patient::GetGender()
{
	return gender;
}