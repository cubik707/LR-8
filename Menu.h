#pragma once
#include "StudentContainers.h"
#include "Validator.h"

class Menu
{
public:
	void showContainerMenu();
	void showQueueMenu();
	void showStackMenu();
	void showPriorityQueueMenu();

	Student inputStudent();
};

