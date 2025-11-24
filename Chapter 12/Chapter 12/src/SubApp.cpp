#include "SubApp.h"

SubApp::SubApp()
	: m_AppID(EAppID::InvalidApp),
	m_State(ESubAppState::Initialization)
{}

SubApp::SubApp(EAppID p_AppID)
	: m_AppID(p_AppID),
	m_State(ESubAppState::Initialization)
{}

EAppID SubApp::GetAppID() const
{
	return m_AppID;
}

ESubAppState SubApp::GetState() const
{
	return m_State;
}

void SubApp::SetState(ESubAppState p_State)
{
	m_State = p_State;
}
