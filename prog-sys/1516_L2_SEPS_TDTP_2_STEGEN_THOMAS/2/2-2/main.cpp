#include <iostream>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	ZeroMemory(&si,sizeof(si));
	
	if(CreateProcess("../1-1/DisrupteurDimensionnel.exe","\"Test\" \"1\" \"2\" \"3\" \"4\" ",NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		
		WaitForMultipleObjects(pi.hProcess,INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	return 0;
}
