#include "Student.h"

Student::Student()
{}

Student::Student(size_t p_ID, const std::string& p_Name, const std::string& p_Major, float p_GPA)
	: m_ID(p_ID),
	m_Name(p_Name),
	m_Major(p_Major),
	m_GPA(p_GPA)
{}


size_t Student::GetID() const
{
	return m_ID;
}

const std::string& Student::GetName() const
{
	return m_Name;
}

const std::string& Student::GetMajor() const
{
	return m_Major;
}

float Student::GetGPA() const
{
	return m_GPA;
}

void Student::SetID(size_t p_ID)
{
	m_ID = p_ID;
}

void Student::SetName(const std::string& p_Name)
{
	m_Name = p_Name;
}

void Student::SetMajor(const std::string& p_Major)
{
	m_Major = p_Major;
}

void Student::SetGPA(float p_GPA)
{
	m_GPA = p_GPA;
}
