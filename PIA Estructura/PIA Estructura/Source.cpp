#include<iostream>
#include<Windows.h>
#include<fstream>
#include"resource.h"
#include <string>

using namespace std;

int main()
{
	string cadena;
	char caracter;
	cout << "introduce la secuencia: ";

	cin >> cadena;
	int longitud = cadena.length();
	for (int i = 0; i < longitud; i++) {
		caracter = cadena[i];
	}
	system("Pause");
	return 0;
}


/*
int opc;
HINSTANCE hInstGlobal;

struct Especialidades {
	Especialidades* ant;
	string tipo;
	Especialidades* sig;
};
Especialidades* especial = new Especialidades;
struct Medicos {
	int cedula;
	string nombre;

};

//Aqui van las funciones sin codigo
int WINAPI WinMain(HINSTANCE hInicio, HINSTANCE hInicioPrev, PSTR cmdline, int cmdshow);
BOOL CALLBACK Inicio_Sesion(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Registro_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Info_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Baja_Usuario(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Alta_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Baja_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Modificar_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Alta_Px(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Baja_Px(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista_Px(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Alta_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Cancelar_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Buscar_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Alta_Esp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Baja_Esp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista_Esp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
		if (opc == IDYES) {
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
			//Le falta verificar que existan los datos
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(infoUsuario), hwnd, Info_Usuario);
			break;

			//Sub-Menu
			{
		case infoUsSub://<- Es el sub-menu		vvEste es la ventana,   vvLa funcion para la ventana correspondiente
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(infoUsuario), hwnd, Info_Usuario);
			break;
		case altaUsSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(registroUsuario), hwnd, Registro_Usuario);
			break;
		case bajaUsSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(bajaUsuario), hwnd, Baja_Usuario);
			break;
		case altaMedicoSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(altaMedico), hwnd, Alta_Medico);
			break;
		case bajaMedicoSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(bajaMedico), hwnd, Baja_Medico);
			break;
		case modMedicoSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(modificarMedico), hwnd, Modificar_Medico);
			break;
		case listaMedicoSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(listaMedicos), hwnd, Lista_Medico);
			break;
		case altaPxSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(altaPx), hwnd, Alta_Px);
			break;
		case bajaPxSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(bajaPx), hwnd, Baja_Px);
			break;
		case altaCitaSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(altaCita), hwnd, Alta_Cita);
			break;
		case cancelarCitaSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(cancelarCita), hwnd, Cancelar_Cita);
			break;
		case listaCitaSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(listaCita), hwnd, Lista_Cita);
			break;
		case buscarCitaSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(buscarCita), hwnd, Buscar_Cita);
			break;
		case altaEspSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(altaEsp), hwnd, Alta_Esp);
			break;
		case bajaEspSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(bajaEsp), hwnd, Baja_Esp);
			break;
		case listaEspSub:
			EndDialog(hwnd, 0);
			DialogBox(hInstGlobal, MAKEINTRESOURCE(listaEsp), hwnd, Lista_Esp);
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

BOOL CALLBACK Alta_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Baja_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Modificar_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Lista_Medico(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Alta_Px(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Baja_Px(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Lista_Px(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Alta_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Cancelar_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Lista_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Buscar_Cita(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Alta_Esp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Baja_Esp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

BOOL CALLBACK Lista_Esp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return 0;
}

*/