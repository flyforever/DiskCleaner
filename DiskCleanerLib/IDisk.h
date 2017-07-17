#pragma once

enum DeviceStatus
{
	POWEROFF = 0,
	STARTUPING = 1,
	READY = 2,
	WRITEING = 3,
	FINISHED = 4
};

class IDisk 
{
public:
	virtual ~IDisk() {}

	virtual std::string GetMan() = 0;
	virtual std::string GetModel() = 0;
	virtual std::string GetVersion() = 0;
	virtual std::string GetSN() = 0;
	virtual INT64 GetCapa() = 0;
	virtual INT64 GetNativeAddr() = 0;

	virtual bool TurnOn() = 0;
	virtual bool TurnOff() = 0;
	virtual bool StopDevice() = 0;
	virtual bool WriteDevice(unsigned char c);
	virtual bool WriteRadamDevice();

	virtual bool GetStatus(DeviceStatus& status, INT64& iAddr);

};