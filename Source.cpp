#include "DxLib.h" 
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	//ウィンドウモードに設定 
	ChangeWindowMode(TRUE);

	const char TITLE[] = "title01";

	const int WIN_HEIGHT = 400;
	const int WIN_WITDH = 600;


	// ウィンドウのタイトル
	SetMainWindowText(TITLE);
	//ウィンドウサイズを手動では変更できず、 
//かつウィンドウサイズに合わせて拡大できないようにする 
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// 画面サイズの最大サイズ、カラービット数を設定
	SetGraphMode(WIN_WITDH, WIN_HEIGHT, 32);

	// 画面サイズを設定（解像度との比率で設定）
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(128,200,338);

	//Dxライブラリを初期化 
	if (DxLib_Init() == -1)
	{
		//エラーが出たらマイナス値を返して終了 
		return -1;
	}

	while (1)
	{
		//ゲームロジック

		//ゲームロジック


		WaitTimer(20);

		if (ProcessMessage() == -1)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
	}

	//何か押されるまで待機 
	WaitKey();

	//Dxライブラリ終了処理 
	DxLib_End();

	return 0;
}