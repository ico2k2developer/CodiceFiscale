
// CodiceFiscaleDlg.h: file di intestazione
//

#pragma once


// Finestra di dialogo CCodiceFiscaleDlg
class CCodiceFiscaleDlg : public CDialogEx
{
// Costruzione
public:
	CCodiceFiscaleDlg(CWnd* pParent = nullptr);	// costruttore standard

// Dati della finestra di dialogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CODICEFISCALE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// supporto DDX/DDV


// Implementazione
protected:
	HICON m_hIcon;

	// Funzioni generate per la mappa dei messaggi
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
