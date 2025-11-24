#include "SortedArrayDemoApp.h"
#include "Input.h"

SortedArrayDemoApp::SortedArrayDemoApp()
	: SubApp(EAppID::SortedArrayDemoApp)
{}

void SortedArrayDemoApp::Run()
{
	this->SetState(ESubAppState::Running);

	while (this->GetState() != ESubAppState::Exited)
	{
		std::system("cls");
		puts("\n\t2 > Searching unsorted dynamic arrays");
		puts(std::string(100, char(205)).c_str());
		puts("\tA > Create new array");
		puts("\tB > Add an element to the dynamic array");
		puts("\tC > Display elements from the array");
		puts("\tD > Search for an element from the array");
		puts("\tE > Clear the array");
		puts(std::string(100, char(196)).c_str());
		puts("\t0> return");
		puts(std::string(100, char(205)).c_str());

		HandleInput(Input::inputChar("\n\tOption: ", "ABCDE0"));
	}
}

void SortedArrayDemoApp::Restart()
{}

void SortedArrayDemoApp::Clean()
{
	m_List.clear();
}

void SortedArrayDemoApp::HandleInput(char p_Input)
{
	switch (p_Input)
	{
	case 'A':
	{
		m_List.clear();
		size_t size = Input::inputInteger("\n\tInput size of dynamic array: ", true);
		for (size_t i = 0; i < size; i++)
			m_List.insert("str#" + std::to_string(i));

		puts("\n\tRandom elements have been populated into the array.");
	}
	break;
	case 'B':
	{
		std::string str = Input::inputString("\n\tInput new element: ", true);
		m_List.insert(str);

		printf("\n\t\"%s\" was successfully inserted into the array!", str.c_str());
	}
		break;
	case 'C':
		puts("");
		for (const auto& ele : m_List)
			printf("%s ", ele.c_str());
		break;
	case 'D':
	{
		ESearchType type = Input::inputChar("\n\tChoose search type (S)Serial or (B)Binary: ", "SB") == 'S' ? ESearchType::Serial : ESearchType::Binary;

		switch (type)
		{
		case SortedArrayDemoApp::ESearchType::Serial:
		{
			puts("\n\tSerial Search");
			puts(std::string(50, char(196)).c_str());
			std::string str = Input::inputString("\n\tEnter the element to search: ", true);
			auto iter = std::find(m_List.begin(), m_List.end(), str);
			if (iter == m_List.end())
			{
				printf("\"%s\" is not found in the sorted array!", str.c_str());
				break;
			}

			size_t index = std::distance(m_List.begin(), iter);
			printf("\n\t\"%s\" is found in the sorted array at index [%d]!", str.c_str(), index);
		}
			break;
		case SortedArrayDemoApp::ESearchType::Binary:
		{
			puts("\n\tBinary Search");
			puts(std::string(50, char(196)).c_str());
			std::string str = Input::inputString("\n\tEnter the element to search: ", true);
			auto iter = std::lower_bound(m_List.begin(), m_List.end(), str);

			if (iter == m_List.end())
			{
				printf("\"%s\" is not found in the sorted array!", str.c_str());
				break;
			}
			--iter;

			size_t index = std::distance(m_List.begin(), iter);
			printf("\n\t\"%s\" is found in the sorted array at index [%d]!", str.c_str(), index);
		}
			break;
		}
		break;
	}
	case 'E':
		m_List.clear();
		puts("\n\tElements from the array have been cleared/deleted.");
		break;
	case '0':
		this->SetState(ESubAppState::Exited);
		return;
	}

	puts("");
	std::system("pause");
}

