#pragma once

#include "framework.h"
#include "resource.h"


class MessageBoxDlg : public CDialogEx {
	DECLARE_DYNAMIC(MessageBoxDlg)

public:
	MessageBoxDlg(CWnd* pParent = nullptr);
	virtual ~MessageBoxDlg();


#ifdef AFX_DESIGN_TIME
	enum {
		IDD = IDD_DIALOG1
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
