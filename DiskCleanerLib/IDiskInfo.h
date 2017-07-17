#pragma once

class IDiskInfo
{
public:
	virtual ~IDiskInfo() {}

	virtual std::string GetMan() = 0;
	virtual std::string GetModel() = 0;
	virtual std::string GetVersion() = 0;
	virtual std::string GetSN() = 0;
	virtual INT64 GetCapa() = 0;
};