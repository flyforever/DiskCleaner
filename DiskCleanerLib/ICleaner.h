#pragma once

class ICleaner
{
public:
	virtual ~ICleaner() {}

	virtual void FullClean() = 0;
};