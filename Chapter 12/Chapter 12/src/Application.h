#pragma once
#include "SubApp.h"

enum class EMainAppState
{
	MainApp,
	SubApp,
	Exited
};

class Application
{
public:

	Application();

	/*
	* Precondition: None
	*
	* Postcondition: Initializes main application loop; handles each SubApp
	*/
	void Run();

	/*
	* Precondition: None
	*
	* Postcondition: Cleans all SubApps
	*/
	void Clean();

private:
	void DisplayMainMenu();
	void QueryState();

private:
	EMainAppState m_State;
	EAppID m_CurrentSubApp;

};

