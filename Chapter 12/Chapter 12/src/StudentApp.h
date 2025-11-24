#pragma once
#include "SubApp.h"
#include "HashTable.h"

class StudentApp : public SubApp
{
public:
	StudentApp();

	void Run() override;

	void Restart() override;

	void Clean() override;

private:
	void HandleInput(char p_Input) override;

private:
	Table m_Students;
};

