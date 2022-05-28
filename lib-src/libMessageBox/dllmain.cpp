#include "pch.h"
#include "MessageBoxDlg.h"


_declspec(dllexport)
void run() {
    MessageBoxDlg* messageBoxDlg = new MessageBoxDlg();
    messageBoxDlg->DoModal();
}
