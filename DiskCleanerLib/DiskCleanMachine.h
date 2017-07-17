#pragma once

#include "IDisk.h"
#include "Command.h"

class DiskCleanMachine : public IDisk
{
public:
	bool Init();

	virtual std::string GetMan();
	virtual std::string GetModel();
	virtual std::string GetVersion();
	virtual std::string GetSN();
	virtual INT64 GetCapa();

private:
	Command *m_pCommander;
	int m_iPort;
};