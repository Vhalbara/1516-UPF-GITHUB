#include <iostream>
#include <windows.h>

#define NBPROCESS 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i;
	
	char buffer[3][200] = {"Pierre",
						  "",
						  "Jacques \"Je suis un génie!\" \"Ah, je suis tellement génial\" \"Pierre ....\""};
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi[3];
	HANDLE tab[3];
	
	
	ZeroMemory(&si,sizeof(si));
	
	for(i=0;i<NBPROCESS;i++)
	{
		if(CreateProcess("../2-1/fils.exe",(strcmp(buffer[i],"")!=0)?buffer[i]:NULL,NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi[i]))
		{
			printf("Et je dis que tu sois %d et tu fus\n\n",i);
			tab[i] = pi[i].hProcess;
		}		
	}
	Sleep(500);
	printf("\nZZZzzzzzzzzzz\n\n");
	
	WaitForMultipleObjects(NBPROCESS,tab,TRUE,INFINITE);
	
	printf("\n");
	
	for(i=NBPROCESS;i>0;i--)
	{
		CloseHandle(pi[i].hProcess);
		CloseHandle(pi[i].hThread);
		printf("< FATHER > I'M KILLING YOU %d MY CHILD.\n",i);
	}
	
	return 0;
}

