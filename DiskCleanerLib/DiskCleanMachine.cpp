#include "StdAfx.h"
#include <sstream>
#include "DiskCleanMachine.h"

bool DiskCleanMachine::Init()
{
	return true;
}

std::string DiskCleanMachine::GetModel()
{
	std::stringstream ss;
	ss << "GET_DEVICE_MODEL " << m_iPort;
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
		return strResponse;
	return "";
}

std::string DiskCleanMachine::GetVersion()
{
	std::stringstream ss;
	ss << "GET_DEVICE_VERSION " << m_iPort;
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
		return strResponse;
	return "";
}

std::string DiskCleanMachine::GetSN()
{
	std::stringstream ss;
	ss << "GET_DEVICE_SERIAL_NO " << m_iPort;
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
		return strResponse;
	return "";
}

INT64 DiskCleanMachine::GetCapa()
{
	std::stringstream ss;
	ss << "GET_DEVICE_CAPACITY " << m_iPort;
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
	{
		return _atoi64(strResponse.c_str());
	}
	return 0;
}
