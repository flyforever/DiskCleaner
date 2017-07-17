#include "stdafx.h"
#include <sstream>
#include "Command.h"

Command::Command(CSerialPort *pSerialPort)
	: m_pSerialPort(pSerialPort)
{

}

bool Command::SendCommand(const std::string& request, std::string& response)
{
	if (!m_pSerialPort->IsOpen())
		return false;

	std::stringstream ss;
	ss << "@" << request << "#";

	DWORD dwRes = m_pSerialPort->Write(ss.str().c_str(), ss.str().size());
	if (dwRes <= ss.str().size())
		return false;
	char szResponse[1024] = { 0 };
	dwRes = m_pSerialPort->Read(szResponse, sizeof(szResponse));
	if (dwRes > 0)
	{
		if (szResponse[0] == '@' && szResponse[dwRes] == '#')
		{
			response = szResponse;
			return true;
		}
	}
	return false;
}