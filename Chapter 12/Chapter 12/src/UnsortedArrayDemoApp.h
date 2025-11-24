#pragma once
#include "SubApp.h"
#include <vector>
#include <string>

class UnsortedArrayDemoApp : public SubApp
{
public:
	enum class ESearchType
	{
		Serial,
		Binary
	};

public:
	UnsortedArrayDemoApp();

	void Run() override;

	void Restart() override;

	void Clean() override;

private:
	void HandleInput(char p_Input) override;

private:
	std::vector<std::string> m_List;

};

