#pragma once
#include "UI.h"

class CInven : public CUi
{
public:
	CInven(void);
	virtual	~CInven(void);

public:
	virtual void	Initialize(void);
	virtual int		Update(void);
	virtual void	Render(HDC _dc);
	virtual void	Release(void);
};