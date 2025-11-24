#pragma once
#include "SubApp.h"
#include <set>
#include <string>

class SortedArrayDemoApp : public SubApp
{
public:
	enum class ESearchType
	{
		Serial,
		Binary
	};

public:
	SortedArrayDemoApp();

	void Run() override;

	void Restart() override;

	void Clean() override;

private:
	void HandleInput(char p_Input) override;

private:
	std::multiset<std::string> m_List;
};

