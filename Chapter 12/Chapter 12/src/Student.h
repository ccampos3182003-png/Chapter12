#pragma once
#include <string>

class Student
{
public:
	Student();
	Student(size_t p_ID, const std::string& p_Name, const std::string& p_Major, float p_GPA);

	size_t GetID() const;
	const std::string& GetName() const;
	const std::string& GetMajor() const;
	float GetGPA() const;

	void SetID(size_t p_ID);
	void SetName(const std::string& p_Name);
	void SetMajor(const std::string& p_Major);
	void SetGPA(float p_GPA);

private:
	size_t m_ID{ NULL };
	std::string m_Name{ "\0" };
	std::string m_Major{ "\0" };
	float m_GPA{ 0.f };
};

