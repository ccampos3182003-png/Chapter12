#include "Application.h"
#include <string>
#include "UnsortedArrayDemoApp.h"
#include "SortedArrayDemoApp.h"
#include "StudentApp.h"
#include "Input.h"

Application::Application()
    : m_State(EMainAppState::MainApp),
    m_CurrentSubApp(EAppID::InvalidApp)
{
}

void Application::Run()
{
    while (m_State != EMainAppState::Exited)
    {
        switch (m_State)
        {
        case EMainAppState::MainApp:
            DisplayMainMenu();
            QueryState();
            break;
        case EMainAppState::SubApp:
            switch (m_CurrentSubApp)
            {
            case EAppID::UnsortedArrayDemoApp:
            {
                UnsortedArrayDemoApp app;
                app.Run();
            }
            break;
            case EAppID::SortedArrayDemoApp:
            {
                SortedArrayDemoApp app;
                app.Run();
            }
            break;
            case EAppID::StudentApp:
            {
                StudentApp app;
                app.Run();
            }
                break;
            case EAppID::InvalidApp:
            default:
                std::cout << "\n\tERROR: Invalid application selected";
                std::cout << "\n";
                std::system("pause");
                break;
            }

            m_State = EMainAppState::MainApp;
            m_CurrentSubApp = EAppID::InvalidApp;
            break;
        }
    }
}

void Application::Clean()
{
    // Cleanup if needed
    puts("\n\tApplication cleanup completed.");
}

void Application::DisplayMainMenu()
{
    std::system("cls");
    puts("\n\tCMPR131 Chapter 12: Searches and hashing by Group 8 (11/23/25)");
    puts(std::string(100, char(205)).c_str());
    puts("\t1 > Searching from an unsorted dynamic array");
    puts("\t2 > Searching from a sorted dynamic array");
    puts("\t3 > Application using hashing");
    puts(std::string(100, char(196)).c_str());
    puts("\t0> Exit");
    puts(std::string(100, char(205)).c_str());
}

void Application::QueryState()
{
    char choice = Input::inputChar("\n\tOption: ", "1230");
    switch (choice)
    {
    case '1':
        m_State = EMainAppState::SubApp;
        m_CurrentSubApp = EAppID::UnsortedArrayDemoApp;
        break;
    case '2':
        m_State = EMainAppState::SubApp;
        m_CurrentSubApp = EAppID::SortedArrayDemoApp;
        break;
    case '3':
        m_State = EMainAppState::SubApp;
        m_CurrentSubApp = EAppID::StudentApp;
        break;
    case '0':
        m_State = EMainAppState::Exited;
        break;
    }
}