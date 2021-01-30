
// CodiceFiscale.h: file di intestazione principale per l'applicazione PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "includere 'pch.h' prima di includere questo file per PCH"
#endif

#include "resource.h"		// simboli principali


// CCodiceFiscaleApp:
// Per l'implementazione di questa classe, vedere CodiceFiscale.cpp
//

class CCodiceFiscaleApp : public CWinApp
{
public:
	CCodiceFiscaleApp();

// Override
public:
	virtual BOOL InitInstance();

// Implementazione

	DECLARE_MESSAGE_MAP()
};

extern CCodiceFiscaleApp theApp;
