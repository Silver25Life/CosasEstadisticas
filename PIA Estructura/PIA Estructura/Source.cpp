#include<iostream>
#include<Windows.h>
#include<fstream>
#include"resource.h"
using namespace std;
int opc;
HINSTANCE hInstGlobal;

//Aqui van las funciones sin codigo
int WINAPI WinMain(HINSTANCE hInicio, HINSTANCE hInicioPrev, PSTR cmdline, int cmdshow);
BOOL CALLBACK Inicio_Sesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Registro_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Info_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Baja_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Inicializador de ventanas
int WINAPI WinMain(HINSTANCE hInicio, HINSTANCE hInicioPrev, PSTR cmdline, int cmdshow) {
	hInstGlobal = hInicio;
	HWND hwInicio = CreateDialog(hInicio, MAKEINTRESOURCE(inicioSesion), NULL, Inicio_Sesion);
	ShowWindow(hwInicio, SW_SHOW);
	MSG mensajes;
	ZeroMemory(&mensajes, sizeof(mensajes));
	while (GetMessage(&mensajes, 0, 0, 0)) {
		TranslateMessage(&mensajes);
		DispatchMessage(&mensajes);
	}
	return mensajes.wParam;
}


BOOL CALLBACK Inicio_Sesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CLOSE:
		opc = MessageBox(hwnd, L"¿Seguro que desea salir?", L"AVISO", MB_YESNO | MB_ICONQUESTION);
		if(opc==IDYES){
			DestroyWindow(hwnd);
			PostQuitMessage(0);
		}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case inSalir:
			opc = MessageBox(hwnd, L"¿Seguro que desea salir?", L"AVISO", MB_YESNO | MB_ICONQUESTION);
			if (opc == IDYES) {
				DestroyWindow(hwnd);
				PostQuitMessage(0);
			}
			break;
		case inRegistro:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(registroUsuario), hwnd, Registro_Usuario);
			break;
		case inIngresar:
			//Le falta verificar los datos
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(infoUsuario), hwnd, Info_Usuario);
			break;

		//Sub-Menu
		{
		case infoUs:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(infoUsuario), hwnd, Info_Usuario);
			break;
		case altaUs:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(registroUsuario), hwnd, Registro_Usuario);
			break;
		case bajaUs:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(bajaUsuario), hwnd, Baja_Usuario);
			break;
		}



		}
		break;
	}
	return 0;
}

BOOL CALLBACK Registro_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Info_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Baja_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}