
// CodiceFiscaleDlg.cpp: file di implementazione
//

#include "pch.h"
#include "framework.h"
#include "CodiceFiscale.h"
#include "CodiceFiscaleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Finestra di dialogo CCodiceFiscaleDlg



CCodiceFiscaleDlg::CCodiceFiscaleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CODICEFISCALE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCodiceFiscaleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodiceFiscaleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GENERATE,onGenerateClick)
	ON_BN_CLICKED(IDC_MALE,onSexClick)
	ON_BN_CLICKED(IDC_FEMALE,onSexClick)
END_MESSAGE_MAP()


// Gestori di messaggi di CCodiceFiscaleDlg

BOOL CCodiceFiscaleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Impostare l'icona per questa finestra di dialogo.  Il framework non esegue questa operazione automaticamente
	//  se la finestra principale dell'applicazione non è una finestra di dialogo.
	SetIcon(m_hIcon, TRUE);			// Impostare icona grande.
	//SetIcon(m_hIcon, FALSE);		// Impostare icona piccola.

	// TODO: aggiungere qui inizializzazione aggiuntiva.
	HWND hwnd = AfxGetMainWnd()->GetSafeHwnd();
	generate = (CButton*)GetDlgItem(IDC_GENERATE);
	male = (CButton*)GetDlgItem(IDC_MALE);
	female = (CButton*)GetDlgItem(IDC_FEMALE);
	name = (CEdit*)GetDlgItem(IDC_NAME);
	surname = (CEdit*)GetDlgItem(IDC_SURNAME);
	male->SetCheck(BST_CHECKED);
	return TRUE;  // restituisce TRUE a meno che non venga impostato lo stato attivo su un controllo.
}

// Se si aggiunge alla finestra di dialogo un pulsante di riduzione a icona, per trascinare l'icona sarà necessario
//  il codice sottostante.  Per le applicazioni MFC che utilizzano il modello documento/visualizzazione,
//  questa operazione viene eseguita automaticamente dal framework.

void CCodiceFiscaleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contesto di dispositivo per il disegno

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrare l'icona nel rettangolo client.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Disegnare l'icona
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Il sistema chiama questa funzione per ottenere la visualizzazione del cursore durante il trascinamento
//  della finestra ridotta a icona.
HCURSOR CCodiceFiscaleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCodiceFiscaleDlg::onGenerateClick()
{
	
}

void CCodiceFiscaleDlg::onSexClick()
{
	if (male->GetCheck() == BST_CHECKED)
	{
		male->SetCheck(BST_UNCHECKED);
		female->SetCheck(BST_CHECKED);
	}
	else
	{
		female->SetCheck(BST_UNCHECKED);
		male->SetCheck(BST_CHECKED);
	}
}

