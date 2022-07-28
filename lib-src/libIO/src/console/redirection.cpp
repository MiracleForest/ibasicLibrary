#include "../../../../include/icore/lib/libIO/console/redirection.h"



SPACE(i) {
	SPACE(core) {
		SPACE(libIO) {
			SPACE(console) {

				Redirection::Redirection(void) {
					_ChildInputWrite = NULL;
					_ChildInputRead = NULL;
					_ChildOutputWrite = NULL;
					_ChildOutputRead = NULL;
					ZeroMemory(&_CmdPI, sizeof(_CmdPI));
				}

				Redirection::~Redirection(void) {
					stopProcess();
				}

				bool Redirection::runProcess(const type::iwstring & process)
				{
					SECURITY_ATTRIBUTES   sa { };
					sa.bInheritHandle = TRUE;
					sa.lpSecurityDescriptor = NULL;
					sa.nLength = sizeof(sa);

					//创建子进程输出匿名管道 
					if ( FALSE == ::CreatePipe(&_ChildOutputRead, &_ChildOutputWrite, &sa, 0) )
					{
						return false;
					}

					//创建子进程输入匿名管道   
					if ( FALSE == CreatePipe(&_ChildInputRead, &_ChildInputWrite, &sa, 0) )
					{
						::CloseHandle(_ChildOutputWrite);
						::CloseHandle(_ChildOutputRead);
						return false;
					}

					ZeroMemory(&_CmdPI, sizeof(_CmdPI));
					STARTUPINFO  si;
					GetStartupInfo(&si);

					si.cb = sizeof(STARTUPINFO);
					si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
					si.wShowWindow = SW_HIDE;
					si.hStdInput = _ChildInputRead;     //重定向子进程输入   
					si.hStdOutput = _ChildOutputWrite;   //重定向子进程输入    
					si.hStdError = _ChildOutputWrite;

					if ( FALSE == ::CreateProcess(
						NULL,
						(wchar_t*)
						process.cStr(),
						NULL,
						NULL,
						TRUE,
						NORMAL_PRIORITY_CLASS,
						NULL,
						NULL,
						&si,
						&_CmdPI
						)
						)
					{
						::CloseHandle(_ChildInputWrite);
						::CloseHandle(_ChildInputRead);
						::CloseHandle(_ChildOutputWrite);
						::CloseHandle(_ChildOutputRead);
						_ChildInputWrite = NULL;
						_ChildInputRead = NULL;
						_ChildOutputWrite = NULL;
						_ChildOutputRead = NULL;
						ZeroMemory(&_CmdPI, sizeof(_CmdPI));
						return false;
					}

					return true;
				}


				bool Redirection::stopProcess(void)
				{
					::CloseHandle(_ChildInputWrite);
					::CloseHandle(_ChildInputRead);
					::CloseHandle(_ChildOutputWrite);
					::CloseHandle(_ChildOutputRead);
					_ChildInputWrite = NULL;
					_ChildInputRead = NULL;
					_ChildOutputWrite = NULL;
					_ChildOutputRead = NULL;
					::TerminateProcess(_CmdPI.hProcess, -1);
					::CloseHandle(_CmdPI.hProcess);
					::CloseHandle(_CmdPI.hThread);
					ZeroMemory(&_CmdPI, sizeof(_CmdPI));
					return true;
				}


				bool Redirection::getOutput(int timeout, type::istring & outstr)
				{
					if ( NULL == _ChildOutputRead )
					{
						return false;
					}

					outstr = "";
					char buffer[4096] = { 0 };
					DWORD readBytes = 0;
					while ( timeout > 0 )
					{
						//对管道数据进行读，但不会删除管道里的数据，如果没有数据，就立即返回
						if ( FALSE == PeekNamedPipe(_ChildOutputRead, buffer, sizeof(buffer) - 1, &readBytes, 0, NULL) )
						{
							return false;
						}

						//检测是否读到数据，如果没有数据，继续等待
						if ( 0 == readBytes )
						{
							timeout -= 1;
							continue;
						}

						readBytes = 0;
						if ( ::ReadFile(_ChildOutputRead, buffer, sizeof(buffer) - 1, &readBytes, NULL) )
						{
							outstr.insert(outstr.end(), buffer, buffer + readBytes);
							timeout -= 1;
						}
						else
						{
							return false;
						}
					}

					return false;
				}


				bool Redirection::setInput(const type::istring & cmd)
				{
					if ( NULL == _ChildInputWrite )
					{
						return "";
					}

					type::istring tmp = cmd + "\r\n";
					DWORD writeBytes = 0;
					if ( FALSE == ::WriteFile(_ChildInputWrite, tmp.cStr(), tmp.size(), &writeBytes, NULL) )
					{
						return false;
					}
					return true;
				}


			}//SPACE(console)
		}//SPACE(libIO)
	}//SPACE(core)
}//SPACE(i) 
