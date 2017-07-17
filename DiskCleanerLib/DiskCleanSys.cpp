#include "stdafx.h"
#include <sstream>
#include "DiskCleanSys.h"

static DWORD WINAPI ConnectThread(LPVOID lpParam)
{
	DiskCleanSys::GetInstance().ConnectLoop();
	return 0;
}

DiskCleanSys::DiskCleanSys()
	: m_pStatusCallback(NULL), m_bExit(false), m_bConnected(false)
{
	m_pSerialPort = new CSerialPort();
	m_pCommander = new Command(m_pSerialPort);
}

DiskCleanSys::~DiskCleanSys()
{
	delete m_pCommander;
	delete m_pSerialPort;
}

DiskCleanSys& DiskCleanSys::GetInstance()
{
	static DiskCleanSys s;
	return s;
}

void DiskCleanSys::SetConnectParam(int iPort)
{

}

void DiskCleanSys::Init(ISysStatusCallback *pStatusCallback)
{
	m_bExit = false;
	CreateThread(NULL, 0, ConnectThread, this, 0, 0);
}

bool DiskCleanSys::IsConnected()
{
	return m_bConnected;
}

std::string DiskCleanSys::GetModel()
{
	std::stringstream ss;
	ss << "GET_MODEL";
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
		return strResponse;
	return "";
}

std::string DiskCleanSys::GetVersion()
{
	std::stringstream ss;
	ss << "GET_VERSION";
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
		return strResponse;
	return "";
}

int DiskCleanSys::GetPortsCount()
{
	std::stringstream ss;
	ss << "GET_PORT_QTY";
	std::string strResponse;
	if (m_pCommander->SendCommand(ss.str().c_str(), strResponse))
	{
		return atoi(strResponse.c_str());
	}
	return 0;
}

IDisk *DiskCleanSys::GetDisk(int iNumber)
{
	return NULL;
}

void DiskCleanSys::ConnectLoop()
{
	while (!WillExit())
	{
		if (IsConnected())
		{
			// test alive
			std::string strModel = GetModel();
			if (strModel.empty())
			{
				m_bConnected = false;
				m_pStatusCallback->OnDisconnected();
			}
		}
		else
		{
			// try connect
			if (!m_pSerialPort->IsOpen())
			{
				m_pSerialPort->Open(3);
			}
			if (m_pSerialPort->IsOpen())
			{
				std::string strModel = GetModel();
				if (strModel.size() > 0)
				{
					m_bConnected = true;
					m_pStatusCallback->OnConnected();
				}
			}
		}
		Sleep(3000);
	}
}