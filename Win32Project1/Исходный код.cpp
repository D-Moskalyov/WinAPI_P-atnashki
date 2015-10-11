#include <windows.h>
#include "resource.h"
#include <string>
#include <time.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HMENU hMenu;

HINSTANCE hInst;

int mas[4][4];
HWND buttons[15];
int n, m, d, gorBlnk, verBlnk, gor, ver, rndm, count=0;
char name[3], buff[10];
std::string str_msg = "";

bool Chek(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(mas[i][j]-(i*4+j+1)){
				if(i!=3||j!=3)
					return 0;	
			}
		}
	}
	return 1;
}

void Shuffle(){
	count=0;
	srand(time(0));
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(mas[i][j]==0){
				gorBlnk=i;
				verBlnk=j;
				//itoa(verBlnk, buff, 10);
				//MessageBox(NULL, buff, "lalala", MB_OK);
			}
		}
	}
	for(int i=0; i<1000; i++){
		rndm=rand()%4;
		if(rndm==0){
			/*MessageBox(NULL, "0", "lalala", MB_OK);*/
			if(verBlnk!=3){
				mas[gorBlnk][verBlnk]=mas[gorBlnk][verBlnk+1];
				mas[gorBlnk][verBlnk+1]=0;
				verBlnk++;
			}
			else{
				mas[gorBlnk][verBlnk]=mas[gorBlnk][verBlnk-1];
				mas[gorBlnk][verBlnk-1]=0;
				verBlnk--;
			}
		}
		if(rndm==1){
			/*MessageBox(NULL, "1", "lalala", MB_OK);*/
			if(gorBlnk!=3){
				mas[gorBlnk][verBlnk]=mas[gorBlnk+1][verBlnk];
				mas[gorBlnk+1][verBlnk]=0;
				gorBlnk++;
			}
			else{
				mas[gorBlnk][verBlnk]=mas[gorBlnk-1][verBlnk];
				mas[gorBlnk-1][verBlnk]=0;
				gorBlnk--;
			}
		}
		if(rndm==2){
			/*MessageBox(NULL, "2", "lalala", MB_OK);*/
			if(verBlnk!=0){
				mas[gorBlnk][verBlnk]=mas[gorBlnk][verBlnk-1];
				mas[gorBlnk][verBlnk-1]=0;
				verBlnk--;
			}
			else{
				mas[gorBlnk][verBlnk]=mas[gorBlnk][verBlnk+1];
				mas[gorBlnk][verBlnk+1]=0;
				verBlnk++;
			}
		}
		if(rndm==3){
			/*MessageBox(NULL, "3", "lalala", MB_OK);*/
			if(gorBlnk!=0){
				mas[gorBlnk][verBlnk]=mas[gorBlnk-1][verBlnk];
				mas[gorBlnk-1][verBlnk]=0;
				gorBlnk--;
			}
			else{
				mas[gorBlnk][verBlnk]=mas[gorBlnk+1][verBlnk];
				mas[gorBlnk+1][verBlnk]=0;
				gorBlnk++;
			}
		}
	}
	return;
}

char WinName[] = "MainFrame";

int APIENTRY WinMain(HINSTANCE This,		
	HINSTANCE Prev,						
	LPTSTR cmd,					
	int mode)							
{
	HWND hWnd;								
	MSG msg;								
	WNDCLASS wc;							
									
	wc.hInstance = This;		
	wc.lpszClassName = WinName;		
	wc.lpfnWndProc = WndProc;			
	wc.style = CS_HREDRAW | CS_VREDRAW;			
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);	
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.cbClsExtra = 0;		
	wc.cbWndExtra = 0;		
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	if(!RegisterClass(&wc)) return 0;	

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++)
			mas[i][j]=i*4+j+1;
	}
	mas[3][3]=0;
	gorBlnk=3;
	verBlnk=3;

	Shuffle();

	hWnd = CreateWindow(WinName, "Ptnashki - 0", WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX, 20, 20, 295, 340, HWND_DESKTOP, NULL, This, NULL);

	ShowWindow(hWnd, mode); 

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
				 WPARAM wParam, LPARAM lParam)
{	

	switch(message){
		case WM_DESTROY:{ PostQuitMessage(0); break;}
		case WM_CREATE:{
			hMenu=LoadMenu(0, MAKEINTRESOURCE(IDR_MENU1));
			SetMenu(hWnd, hMenu);
			if(mas[0][0]!=0) {itoa(mas[0][0], buff, 10);	buttons[mas[0][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,10,65,65, hWnd, (HMENU)(mas[0][0]+100), hInst, 0);}
			if(mas[0][1]!=0) {itoa(mas[0][1], buff, 10);	buttons[mas[0][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,10,65,65, hWnd, (HMENU)(mas[0][1]+100), hInst, 0);}
			if(mas[0][2]!=0) {itoa(mas[0][2], buff, 10);	buttons[mas[0][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,10,65,65, hWnd, (HMENU)(mas[0][2]+100), hInst, 0);}
			if(mas[0][3]!=0) {itoa(mas[0][3], buff, 10);	buttons[mas[0][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,10,65,65, hWnd, (HMENU)(mas[0][3]+100), hInst, 0);}
			if(mas[1][0]!=0) {itoa(mas[1][0], buff, 10);	buttons[mas[1][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,75,65,65, hWnd, (HMENU)(mas[1][0]+100), hInst, 0);}
			if(mas[1][1]!=0) {itoa(mas[1][1], buff, 10);	buttons[mas[1][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,75,65,65, hWnd, (HMENU)(mas[1][1]+100), hInst, 0);}
			if(mas[1][2]!=0) {itoa(mas[1][2], buff, 10);	buttons[mas[1][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,75,65,65, hWnd, (HMENU)(mas[1][2]+100), hInst, 0);}
			if(mas[1][3]!=0) {itoa(mas[1][3], buff, 10);	buttons[mas[1][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,75,65,65, hWnd, (HMENU)(mas[1][3]+100), hInst, 0);}
			if(mas[2][0]!=0) {itoa(mas[2][0], buff, 10);	buttons[mas[2][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,140,65,65, hWnd, (HMENU)(mas[2][0]+100), hInst, 0);}
			if(mas[2][1]!=0) {itoa(mas[2][1], buff, 10);	buttons[mas[2][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,140,65,65, hWnd, (HMENU)(mas[2][1]+100), hInst, 0);}
			if(mas[2][2]!=0) {itoa(mas[2][2], buff, 10);	buttons[mas[2][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,140,65,65, hWnd, (HMENU)(mas[2][2]+100), hInst, 0);}
			if(mas[2][3]!=0) {itoa(mas[2][3], buff, 10);	buttons[mas[2][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,140,65,65, hWnd, (HMENU)(mas[2][3]+100), hInst, 0);}
			if(mas[3][0]!=0) {itoa(mas[3][0], buff, 10);	buttons[mas[3][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,205,65,65, hWnd, (HMENU)(mas[3][0]+100), hInst, 0);}
			if(mas[3][1]!=0) {itoa(mas[3][1], buff, 10);	buttons[mas[3][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,205,65,65, hWnd, (HMENU)(mas[3][1]+100), hInst, 0);}
			if(mas[3][2]!=0) {itoa(mas[3][2], buff, 10);	buttons[mas[3][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,205,65,65, hWnd, (HMENU)(mas[3][2]+100), hInst, 0);}
			if(mas[3][3]!=0) {itoa(mas[3][3], buff, 10);	buttons[mas[3][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,205,65,65, hWnd, (HMENU)(mas[3][3]+100), hInst, 0);}
			break;
		}
		case WM_COMMAND:{
			if(LOWORD(wParam)==ID_RESTART){
				for(int i=0; i<15; i++)
					DestroyWindow(buttons[i]);
				Shuffle();
				SetWindowText(hWnd, "Ptnashki - 0");
				if(mas[0][0]!=0) {itoa(mas[0][0], buff, 10);	buttons[mas[0][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,10,65,65, hWnd, (HMENU)(mas[0][0]+100), hInst, 0);}
				if(mas[0][1]!=0) {itoa(mas[0][1], buff, 10);	buttons[mas[0][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,10,65,65, hWnd, (HMENU)(mas[0][1]+100), hInst, 0);}
				if(mas[0][2]!=0) {itoa(mas[0][2], buff, 10);	buttons[mas[0][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,10,65,65, hWnd, (HMENU)(mas[0][2]+100), hInst, 0);}
				if(mas[0][3]!=0) {itoa(mas[0][3], buff, 10);	buttons[mas[0][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,10,65,65, hWnd, (HMENU)(mas[0][3]+100), hInst, 0);}
				if(mas[1][0]!=0) {itoa(mas[1][0], buff, 10);	buttons[mas[1][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,75,65,65, hWnd, (HMENU)(mas[1][0]+100), hInst, 0);}
				if(mas[1][1]!=0) {itoa(mas[1][1], buff, 10);	buttons[mas[1][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,75,65,65, hWnd, (HMENU)(mas[1][1]+100), hInst, 0);}
				if(mas[1][2]!=0) {itoa(mas[1][2], buff, 10);	buttons[mas[1][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,75,65,65, hWnd, (HMENU)(mas[1][2]+100), hInst, 0);}
				if(mas[1][3]!=0) {itoa(mas[1][3], buff, 10);	buttons[mas[1][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,75,65,65, hWnd, (HMENU)(mas[1][3]+100), hInst, 0);}
				if(mas[2][0]!=0) {itoa(mas[2][0], buff, 10);	buttons[mas[2][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,140,65,65, hWnd, (HMENU)(mas[2][0]+100), hInst, 0);}
				if(mas[2][1]!=0) {itoa(mas[2][1], buff, 10);	buttons[mas[2][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,140,65,65, hWnd, (HMENU)(mas[2][1]+100), hInst, 0);}
				if(mas[2][2]!=0) {itoa(mas[2][2], buff, 10);	buttons[mas[2][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,140,65,65, hWnd, (HMENU)(mas[2][2]+100), hInst, 0);}
				if(mas[2][3]!=0) {itoa(mas[2][3], buff, 10);	buttons[mas[2][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,140,65,65, hWnd, (HMENU)(mas[2][3]+100), hInst, 0);}
				if(mas[3][0]!=0) {itoa(mas[3][0], buff, 10);	buttons[mas[3][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,205,65,65, hWnd, (HMENU)(mas[3][0]+100), hInst, 0);}
				if(mas[3][1]!=0) {itoa(mas[3][1], buff, 10);	buttons[mas[3][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,205,65,65, hWnd, (HMENU)(mas[3][1]+100), hInst, 0);}
				if(mas[3][2]!=0) {itoa(mas[3][2], buff, 10);	buttons[mas[3][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,205,65,65, hWnd, (HMENU)(mas[3][2]+100), hInst, 0);}
				if(mas[3][3]!=0) {itoa(mas[3][3], buff, 10);	buttons[mas[3][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,205,65,65, hWnd, (HMENU)(mas[3][3]+100), hInst, 0);}
				break;
			}
			if(LOWORD(wParam)==ID_SCORE){
				str_msg=std::to_string((long long )count);
				MessageBox(NULL, str_msg.c_str(), "Score", MB_OK);
				break;
			}
			if(LOWORD(wParam)==ID_EXIT){
				DestroyWindow(hWnd);
				break;
			}
			if(HIWORD(wParam)==BN_CLICKED){
				for(int i=0; i<4; i++){
					for(int j=0; j<4; j++){
						if(mas[i][j]+100==LOWORD(wParam)){
							gor=i;
							ver=j;
							//char buff2[10];
							//itoa(ver, buff2, 10);
							//MessageBox(NULL, buff2, "lalala", MB_OK);
						}
					}
				}
				//char buff2[10], buff3[10];
				//itoa(gorBlnk, buff2, 10);
				//itoa(verBlnk, buff3, 10);
				//MessageBox(NULL, buff2, buff3, MB_OK);
				//itoa(gor, buff2, 10);
				//itoa(ver, buff3, 10);
				//MessageBox(NULL, buff2, buff3, MB_OK);
				if(gorBlnk==gor){
					n=verBlnk-ver;
					m=0;
					if(n>0){
						while(n>0){
							//char buff2[10], buff3[10];
							//itoa(gorBlnk, buff2, 10);
							//itoa(verBlnk, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							//itoa(gor, buff2, 10);
							//itoa(ver, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							count++;
							DestroyWindow(buttons[mas[gorBlnk][verBlnk-1]-1]);
							/*Sleep(500);*/
							str_msg=std::to_string((long long )mas[gorBlnk][verBlnk-1]);
							//itoa(mas[gorBlnk][verBlnk-1]-1, buff2, 10);
							//MessageBox(NULL, buff2, "lalala", MB_OK);
							d=mas[gorBlnk][verBlnk-1];
							buttons[d-1] = CreateWindow("button", str_msg.c_str(), WS_CHILD|WS_VISIBLE, 65*(ver+n)+10, 65*(gor+m)+10, 65, 65, hWnd, (HMENU)(d+100), hInst, 0);
							n--;
							//char buff2[10];
							//itoa(LOWORD(wParam), buff2, 10);
							//MessageBox(NULL, buff2, "lalala", MB_OK);
							//itoa(LOWORD(wParam), buff3, 10);
							//MessageBox(NULL, buff3, "wParam", MB_OK);
							mas[gorBlnk][verBlnk]=mas[gorBlnk][verBlnk-1];
							mas[gorBlnk][verBlnk-1]=0;
							verBlnk--;
							str_msg="Ptnashki - "+std::to_string((long long )count);
							SetWindowText(hWnd, str_msg.c_str());
						}
					}
					else{
						while(n<0){
							//char buff2[10], buff3[10];
							//itoa(gorBlnk, buff2, 10);
							//itoa(verBlnk, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							//itoa(gor, buff2, 10);
							//itoa(ver, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							count++;
							DestroyWindow(buttons[mas[gorBlnk][verBlnk+1]-1]);
							/*Sleep(500);*/
							str_msg=std::to_string((long long )mas[gorBlnk][verBlnk+1]);
							/*itoa(mas[gorBlnk][verBlnk+1], name, 10);*/
							d=mas[gorBlnk][verBlnk+1];
							buttons[d-1] = CreateWindow("button", str_msg.c_str(), WS_CHILD|WS_VISIBLE, 65*(ver+n)+10, 65*(gor+m)+10, 65, 65, hWnd, (HMENU)(d+100), hInst, 0);
							n++;
							mas[gorBlnk][verBlnk]=mas[gorBlnk][verBlnk+1];
							mas[gorBlnk][verBlnk+1]=0;
							verBlnk++;
							str_msg="Ptnashki - "+std::to_string((long long )count);
							SetWindowText(hWnd, str_msg.c_str());
						}
					}
					if(Chek()){
						str_msg=std::to_string((long long )count);
						MessageBox(NULL, str_msg.c_str(), "Winner", MB_OK);
						for(int i=0; i<15; i++)
							DestroyWindow(buttons[i]);
						Shuffle();
						SetWindowText(hWnd, "Ptnashki - 0");
						if(mas[0][0]!=0) {itoa(mas[0][0], buff, 10);	buttons[mas[0][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,10,65,65, hWnd, (HMENU)(mas[0][0]+100), hInst, 0);}
						if(mas[0][1]!=0) {itoa(mas[0][1], buff, 10);	buttons[mas[0][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,10,65,65, hWnd, (HMENU)(mas[0][1]+100), hInst, 0);}
						if(mas[0][2]!=0) {itoa(mas[0][2], buff, 10);	buttons[mas[0][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,10,65,65, hWnd, (HMENU)(mas[0][2]+100), hInst, 0);}
						if(mas[0][3]!=0) {itoa(mas[0][3], buff, 10);	buttons[mas[0][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,10,65,65, hWnd, (HMENU)(mas[0][3]+100), hInst, 0);}
						if(mas[1][0]!=0) {itoa(mas[1][0], buff, 10);	buttons[mas[1][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,75,65,65, hWnd, (HMENU)(mas[1][0]+100), hInst, 0);}
						if(mas[1][1]!=0) {itoa(mas[1][1], buff, 10);	buttons[mas[1][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,75,65,65, hWnd, (HMENU)(mas[1][1]+100), hInst, 0);}
						if(mas[1][2]!=0) {itoa(mas[1][2], buff, 10);	buttons[mas[1][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,75,65,65, hWnd, (HMENU)(mas[1][2]+100), hInst, 0);}
						if(mas[1][3]!=0) {itoa(mas[1][3], buff, 10);	buttons[mas[1][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,75,65,65, hWnd, (HMENU)(mas[1][3]+100), hInst, 0);}
						if(mas[2][0]!=0) {itoa(mas[2][0], buff, 10);	buttons[mas[2][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,140,65,65, hWnd, (HMENU)(mas[2][0]+100), hInst, 0);}
						if(mas[2][1]!=0) {itoa(mas[2][1], buff, 10);	buttons[mas[2][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,140,65,65, hWnd, (HMENU)(mas[2][1]+100), hInst, 0);}
						if(mas[2][2]!=0) {itoa(mas[2][2], buff, 10);	buttons[mas[2][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,140,65,65, hWnd, (HMENU)(mas[2][2]+100), hInst, 0);}
						if(mas[2][3]!=0) {itoa(mas[2][3], buff, 10);	buttons[mas[2][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,140,65,65, hWnd, (HMENU)(mas[2][3]+100), hInst, 0);}
						if(mas[3][0]!=0) {itoa(mas[3][0], buff, 10);	buttons[mas[3][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,205,65,65, hWnd, (HMENU)(mas[3][0]+100), hInst, 0);}
						if(mas[3][1]!=0) {itoa(mas[3][1], buff, 10);	buttons[mas[3][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,205,65,65, hWnd, (HMENU)(mas[3][1]+100), hInst, 0);}
						if(mas[3][2]!=0) {itoa(mas[3][2], buff, 10);	buttons[mas[3][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,205,65,65, hWnd, (HMENU)(mas[3][2]+100), hInst, 0);}
						if(mas[3][3]!=0) {itoa(mas[3][3], buff, 10);	buttons[mas[3][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,205,65,65, hWnd, (HMENU)(mas[3][3]+100), hInst, 0);}
					}
					break;
				}
				if(verBlnk==ver){
					m=gorBlnk-gor;
					n=0;
					if(m>0){
						while(m>0){
							//char buff2[10], buff3[10];
							//itoa(gorBlnk, buff2, 10);
							//itoa(verBlnk, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							//itoa(gor, buff2, 10);
							//itoa(ver, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							count++;
							DestroyWindow(buttons[mas[gorBlnk-1][verBlnk]-1]);
							/*Sleep(500);*/
							str_msg=std::to_string((long long )mas[gorBlnk-1][verBlnk]);
							/*itoa(mas[gorBlnk-1][verBlnk], name, 10);*/
							d=mas[gorBlnk-1][verBlnk];
							buttons[d-1] = CreateWindow("button", str_msg.c_str(), WS_CHILD|WS_VISIBLE, 65*(ver+n)+10, 65*(gor+m)+10, 65, 65, hWnd, (HMENU)(d+100), hInst, 0);
							m--;
							mas[gorBlnk][verBlnk]=mas[gorBlnk-1][verBlnk];
							mas[gorBlnk-1][verBlnk]=0;
							gorBlnk--;
							str_msg="Ptnashki - "+std::to_string((long long )count);
							SetWindowText(hWnd, str_msg.c_str());
						}
					}
					else{
						while(m<0){
							//char buff2[10], buff3[10];
							//itoa(gorBlnk, buff2, 10);
							//itoa(verBlnk, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							//itoa(gor, buff2, 10);
							//itoa(ver, buff3, 10);
							//MessageBox(NULL, buff2, buff3, MB_OK);
							count++;
							DestroyWindow(buttons[mas[gorBlnk+1][verBlnk]-1]);
							/*Sleep(500);*/
							str_msg=std::to_string((long long )mas[gorBlnk+1][verBlnk]);
							/*itoa(mas[gorBlnk+1][verBlnk], name, 10);*/
							d=mas[gorBlnk+1][verBlnk];
							buttons[d-1] = CreateWindow("button", str_msg.c_str(), WS_CHILD|WS_VISIBLE, 65*(ver+n)+10, 65*(gor+m)+10, 65, 65, hWnd, (HMENU)(d+100), hInst, 0);
							m++;
							mas[gorBlnk][verBlnk]=mas[gorBlnk+1][verBlnk];
							mas[gorBlnk+1][verBlnk]=0;
							gorBlnk++;
							str_msg="Ptnashki - "+std::to_string((long long )count);
							SetWindowText(hWnd, str_msg.c_str());
						}
					}
					if(Chek()){
						str_msg=std::to_string((long long )count);
						MessageBox(NULL, str_msg.c_str(), "Winner", MB_OK);
						for(int i=0; i<15; i++)
							DestroyWindow(buttons[i]);
						Shuffle();
						SetWindowText(hWnd, "Ptnashki - 0");
						if(mas[0][0]!=0) {itoa(mas[0][0], buff, 10);	buttons[mas[0][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,10,65,65, hWnd, (HMENU)(mas[0][0]+100), hInst, 0);}
						if(mas[0][1]!=0) {itoa(mas[0][1], buff, 10);	buttons[mas[0][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,10,65,65, hWnd, (HMENU)(mas[0][1]+100), hInst, 0);}
						if(mas[0][2]!=0) {itoa(mas[0][2], buff, 10);	buttons[mas[0][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,10,65,65, hWnd, (HMENU)(mas[0][2]+100), hInst, 0);}
						if(mas[0][3]!=0) {itoa(mas[0][3], buff, 10);	buttons[mas[0][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,10,65,65, hWnd, (HMENU)(mas[0][3]+100), hInst, 0);}
						if(mas[1][0]!=0) {itoa(mas[1][0], buff, 10);	buttons[mas[1][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,75,65,65, hWnd, (HMENU)(mas[1][0]+100), hInst, 0);}
						if(mas[1][1]!=0) {itoa(mas[1][1], buff, 10);	buttons[mas[1][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,75,65,65, hWnd, (HMENU)(mas[1][1]+100), hInst, 0);}
						if(mas[1][2]!=0) {itoa(mas[1][2], buff, 10);	buttons[mas[1][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,75,65,65, hWnd, (HMENU)(mas[1][2]+100), hInst, 0);}
						if(mas[1][3]!=0) {itoa(mas[1][3], buff, 10);	buttons[mas[1][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,75,65,65, hWnd, (HMENU)(mas[1][3]+100), hInst, 0);}
						if(mas[2][0]!=0) {itoa(mas[2][0], buff, 10);	buttons[mas[2][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,140,65,65, hWnd, (HMENU)(mas[2][0]+100), hInst, 0);}
						if(mas[2][1]!=0) {itoa(mas[2][1], buff, 10);	buttons[mas[2][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,140,65,65, hWnd, (HMENU)(mas[2][1]+100), hInst, 0);}
						if(mas[2][2]!=0) {itoa(mas[2][2], buff, 10);	buttons[mas[2][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,140,65,65, hWnd, (HMENU)(mas[2][2]+100), hInst, 0);}
						if(mas[2][3]!=0) {itoa(mas[2][3], buff, 10);	buttons[mas[2][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,140,65,65, hWnd, (HMENU)(mas[2][3]+100), hInst, 0);}
						if(mas[3][0]!=0) {itoa(mas[3][0], buff, 10);	buttons[mas[3][0]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 10,205,65,65, hWnd, (HMENU)(mas[3][0]+100), hInst, 0);}
						if(mas[3][1]!=0) {itoa(mas[3][1], buff, 10);	buttons[mas[3][1]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 75,205,65,65, hWnd, (HMENU)(mas[3][1]+100), hInst, 0);}
						if(mas[3][2]!=0) {itoa(mas[3][2], buff, 10);	buttons[mas[3][2]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 140,205,65,65, hWnd, (HMENU)(mas[3][2]+100), hInst, 0);}
						if(mas[3][3]!=0) {itoa(mas[3][3], buff, 10);	buttons[mas[3][3]-1] =  CreateWindow("button",buff, WS_CHILD|WS_VISIBLE, 205,205,65,65, hWnd, (HMENU)(mas[3][3]+100), hInst, 0);}
					}
					break;
				}
				/*MessageBox(NULL, "no", "lalala", MB_OK);*/
				break;
			}
			break;
		}
		default: break;
	};
	return DefWindowProc(hWnd, message, wParam, lParam);
}