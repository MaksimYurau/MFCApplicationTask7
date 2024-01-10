
// Lab7Random.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLab7RandomApp:
// Сведения о реализации этого класса: Lab7Random.cpp
//

class CLab7RandomApp : public CWinApp
{
public:
	CLab7RandomApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLab7RandomApp theApp;
