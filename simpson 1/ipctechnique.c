#include <stdio.h>
#include <windows.h>

DWORD WINAPI thread1f(LPVOID arg);
DWORD WINAPI thread2f(LPVOID arg);
volatile LONG turn = 1;

int main() {
    HANDLE thread1 = CreateThread(NULL, 0, thread1f, NULL, 0, NULL);
    HANDLE thread2 = CreateThread(NULL, 0, thread2f, NULL, 0, NULL);

    if (thread1 == NULL || thread2 == NULL) {
        fprintf(stderr, "Failed to create thread.\n");
        if (thread1 != NULL) {
            CloseHandle(thread1);
        }
        if (thread2 != NULL) {
            CloseHandle(thread2);
        }
        return 1;
    }

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);
    CloseHandle(thread1);
    CloseHandle(thread2);
    return 0;
}

DWORD WINAPI thread1f(LPVOID arg) {
    (void)arg;
    int a=0;
    while(a++<20) {
        while (InterlockedCompareExchange(&turn, 1, 1) != 1) {
            SwitchToThread();
        }
        fputc('b', stderr);
        InterlockedExchange(&turn, 0);
    }
    return 0;
}

DWORD WINAPI thread2f(LPVOID arg) {
    (void)arg;
    int b=0;
    while(b++<20) 
    {
        while (InterlockedCompareExchange(&turn, 0, 0) != 0) {
            SwitchToThread();
        }
        fputc('a', stderr);
        InterlockedExchange(&turn, 1);
    }
    return 0;
}
