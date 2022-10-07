#include "DxLib.h" 
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	//�E�B���h�E���[�h�ɐݒ� 
	ChangeWindowMode(TRUE);

	const char TITLE[] = "title01";

	const int WIN_HEIGHT = 400;
	const int WIN_WITDH = 600;


	// �E�B���h�E�̃^�C�g��
	SetMainWindowText(TITLE);
	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A 
//���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ��� 
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
	SetGraphMode(WIN_WITDH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(128,200,338);

	//Dx���C�u������������ 
	if (DxLib_Init() == -1)
	{
		//�G���[���o����}�C�i�X�l��Ԃ��ďI�� 
		return -1;
	}

	while (1)
	{
		//�Q�[�����W�b�N

		//�Q�[�����W�b�N


		WaitTimer(20);

		if (ProcessMessage() == -1)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
	}

	//�����������܂őҋ@ 
	WaitKey();

	//Dx���C�u�����I������ 
	DxLib_End();

	return 0;
}