#include <DxLib.h>

// �x�N�g���\����
struct Vector2 {
	float x, y;
};

// ���W�Ƃ��Ďg����悤��
using Position2 = Vector2;

// ��`�\����
struct Rect
{
	Position2 center;
	float w, h;

	float Left() const {
		return center.x - w;
	}
	float Right() const {
		return center.x + w;
	}
	float Top() const {
		return center.y - h;
	}
	float Bottom() const {
		return center.y + h;
	}

	float Width() const {
		return w * 2.0f;
	}
	float Height() const {
		return h * 2.0f;
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	Rect rcA = { 200,200,50,50 };
	char keystate[256];
	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		DrawString(100, 100, L"Hello World", 0x000000);

		GetHitKeyStateAll(keystate);
		constexpr float speed = 4.0f;
		if (keystate[KEY_INPUT_LEFT]) {
			rcA.center.x -= speed;
		}
		if (keystate[KEY_INPUT_RIGHT]) {
			rcA.center.x += speed;
		}
		if (keystate[KEY_INPUT_UP]) {
			rcA.center.y -= speed;
		}
		if (keystate[KEY_INPUT_DOWN]) {
			rcA.center.y += speed;
		}
		DrawBox(rcA.Left(), rcA.Top(), rcA.Right(), rcA.Bottom(), 0xffffff, true);
		ScreenFlip();
	}
	DxLib_End();
}