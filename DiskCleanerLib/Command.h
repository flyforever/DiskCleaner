#pragma once

#include "serialport.h"

class Command
{
public:
	Command(CSerialPort *pSerialPort);
	bool SendCommand(const std::string& request, std::string& response);
private:
	CSerialPort *m_pSerialPort;
};