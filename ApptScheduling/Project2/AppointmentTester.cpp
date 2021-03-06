/*
 *      File  : AppointmentTester.cpp
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : This file contains the 'main' function. Program execution begins and
 *              ends there.
 */

#include "pch.h"
#include "Menu.h"
#include "MenuController.h"

using namespace std;

int main()
{
	const MenuController controller;
	Menu menu(controller);
	controller.PrepopulateAppointments();
	while (!menu.MainMenu()) {}	
}
