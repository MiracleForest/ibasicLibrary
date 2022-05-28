// MessageBoxDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "MessageBoxDlg.h"


IMPLEMENT_DYNAMIC(MessageBoxDlg, CDialogEx)

MessageBoxDlg::MessageBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MessageBoxDlg::~MessageBoxDlg()
{
}

void MessageBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MessageBoxDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MessageBoxDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MessageBoxDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// MessageBoxDlg 消息处理程序


void MessageBoxDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}


void MessageBoxDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
