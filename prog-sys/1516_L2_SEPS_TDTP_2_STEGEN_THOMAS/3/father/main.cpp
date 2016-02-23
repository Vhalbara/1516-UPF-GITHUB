#include <iostream>
#include <windows.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	long unsigned int i=0;
	ZeroMemory(&si,sizeof(si));
	
	char buffer[50] = " ";
	
	cout << "<Father> Quel est votre calcul elementaire? (n'oublier pas les espace!)\n";
	fgets(&buffer[1],50,stdin);
	
	if(CreateProcess("../child/CalculSavant.exe",buffer, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		WaitForSingleObject(pi.hProcess,INFINITE);	
		if(GetExitCodeProcess(pi.hProcess,&i) == FALSE)
		{
			perror("Erreur de récupération");
		}
		if(i != STILL_ACTIVE)
		{
			cout << "<Father> Le reponse est-elle " << i << "?\n";
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);			
		}		
	}
	
	return 0;
}

