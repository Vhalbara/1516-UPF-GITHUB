#include <iostream>
#include <windows.h>

#include "../config"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	ZeroMemory(&si,sizeof(si));
	
	if(CreateProcess("../1-1/DisrupteurDimensionnel.exe",NULL,NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		int i=0,inter=(MAX/2)+1;
		while(i<inter)
		{
			printf("Fils arrete toi !\n");
			Sleep(TIME_FATHER);
			i++;
		}
		while(i<=MAX)
		{
			printf("Non !!!! Fils !!!! Je t'en prie!!!\n");
			Sleep(TIME_FATHER);
			i++;			
		}
		
		printf("\n\nAdieu monde cruel !!!\n");
		
		WaitForSingleObject(pi.hProcess,INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		
		printf("Et le silence fut ... \n");
	}
	
	return 0;
}
