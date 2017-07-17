#pragma once

#include "serialport.h"
#include "Command.h"
#include "IDisk.h"

class ISysStatusCallback
{
public:
	virtual ~ISysStatusCallback() {}

	virtual void OnConnected() = 0;
	virtual void OnDisconnected() = 0;
};

class DiskCleanSys
{
public:
	DiskCleanSys();
	~DiskCleanSys();

	static DiskCleanSys& GetInstance();

	void SetConnectParam(int iPort);
	void Init(ISysStatusCallback *pStatusCallback);

	bool IsConnected();
	std::string GetModel();
	std::string GetVersion();
	int GetPortsCount();
	IDisk *GetDisk(int iNumber);

	bool WillExit() { return m_bExit; }
	void SetExit() { m_bExit = true; }

	void ConnectLoop();

private:
	ISysStatusCallback *m_pStatusCallback;
	std::vector<IDisk> m_disks;
	CSerialPort *m_pSerialPort;
	Command *m_pCommander;
	bool m_bExit;
	bool m_bConnected;
};
