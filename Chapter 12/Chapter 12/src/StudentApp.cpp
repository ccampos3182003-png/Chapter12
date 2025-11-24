#include "StudentApp.h"
#include <sstream>
#include <fstream>
#include "Input.h"

StudentApp::StudentApp()
	: SubApp(EAppID::StudentApp)
{}

void StudentApp::Run()
{
	this->SetState(ESubAppState::Running);

	while (this->GetState() != ESubAppState::Exited)
	{
		std::system("cls");
		puts("\n\t3 > Application using hashing");
		puts(std::string(100, char(205)).c_str());
		puts("\tA > Read data file, hash and insert into the dynamic array");
		puts("\tB > Search an element from the dynamic array");
		puts("\tC > Insert an element into the dynamic array");
		puts("\tD > Remove an element from the dynamic array");
		puts("\tE > Display all records from the array");
		puts(std::string(100, char(196)).c_str());
		puts("\t0> return");
		puts(std::string(100, char(205)).c_str());

		HandleInput(Input::inputChar("\n\tOption: ", "ABCDE0"));
	}
}

void StudentApp::Restart()
{}

void StudentApp::Clean()
{}

void StudentApp::HandleInput(char p_Input)
{
	switch (p_Input)
	{
	case 'A':
	{
		const char* fileName{ "Students.dat" };
		std::ifstream fileStream(fileName);
		std::string line;

		size_t numToRead = Input::inputInteger("\n\tEnter the number of students to read: ", 1, 40);
		int64_t currStudent = numToRead;

		while (std::getline(fileStream, line) && currStudent > 0)
		{
			std::istringstream ss(line);
			std::string token;
			std::vector<std::string> tokens;
			size_t count{1};

			while (std::getline(ss, token, ','))
				tokens.push_back(token);

			Student student;
			student.SetID(std::stoi(tokens[0]));
			student.SetName(tokens[1]);
			student.SetMajor(tokens[2]);
			student.SetGPA(std::stof(tokens[3]));

			m_Students.insert({ (int)student.GetID() ,student });
			--currStudent;
		}

		printf("\n\tSuccessfully read %d students!", numToRead);
	}
		break;
	case 'B':
	{
		size_t ID = Input::inputInteger("Enter a student ID to search: ", true);
		int index;
		bool found = m_Students.find_index(ID, index);

		if (!found)
		{
			printf("\n\t ERROR: ID (%d) not found.", ID);
			break;
		}
		puts("");
		m_Students.display(index);
	}
		break;
	case 'C':
	{
		if (m_Students.size() >= 40)
		{
			puts("\n\tERROR: Array is full! Cannot insert anymore records.");
			break;
		}

		Student student;
		student.SetID(Input::inputInteger("\n\tEnter Student ID: ", true));
		int index;
		bool found = m_Students.find_index(student.GetID(), index);
		if(found)
		{
			printf("\n\tERROR: Student with ID (%d) already exists at index #%d", student.GetID(), index);
			break;
		}

		student.SetName(Input::inputString("\n\tEnter Student Name: ", true));
		student.SetMajor(Input::inputString("\n\tEnter Student Major: ", true));
		student.SetGPA((float) Input::inputDouble("\n\tStudent Student GPA (1.0 .. 4.0): ", 1.f, 4.f));

		m_Students.insert({ (int)student.GetID(), student });

		puts("\n\n\tInserted new record.");
	}
		break;
	case 'D':
	{
		size_t ID = Input::inputInteger("Enter a student ID to remove: ", true);
		bool removed = m_Students.remove(ID);

		if(!removed)
		{
			printf("\n\tStudent with ID (%d) could not be removed! Was NOT Found!", ID);
			break;
		}

		printf("\n\tStudent with ID (%d) was successfully removed!", ID);
	}
		break;
	case 'E':
		std::cout << "\n" << m_Students << std::endl;
		break;
	case '0':
		this->SetState(ESubAppState::Exited);
		return;
	}

	puts("");
	std::system("pause");
}
