/*
 *      File  : Menu.h
 *      Author: Randy Quimby
 *      Course: COP3014
 *      Proj  : Project 02
 *      Descr : The declaration of the class that contains menues
 *              and menu options for users.
 */
#ifndef MENU_H_
#define MENU_H_
#pragma once

#include "MenuController.h"
#include<string>
#include<iostream>

class Menu {
public:
	Menu();
	Menu(MenuController controller);
	~Menu() { std::cout << "object killed" << std::endl; }
    bool MainMenu() const;
private:
	MenuController controller;
	std::string DocNameMenu() const;
	int TimeSlotMenu() const;
	std::string PatientNamePrompt() const;
	void IdMenu() const;
};

#endif /* MENU_H_ */