#include <DxLib.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		//DrawString(100, 100, ,0x000000);
		DxLib_End();
	}
}