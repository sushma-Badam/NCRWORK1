#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lparam)
{	
	for (int i = 0; i < 10; i++) {
		printf("\nprocess %d", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD thid;
	HANDLE hthread;
	hthread = CreateThread(NULL, 0, thread_func, NULL, 0, &thid);
	if (hthread == NULL)
	{
		printf("Unable to thread to create %d", GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hthread);
	printf("Waiting for user input to exit\n");
	getchar();
	return 0;
}