// CA計測くん.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CA計測くん.h"

int main(void)
{
	// C++の計算
	int a = 10; int b = 20;

	clock_t startCPP = clock();

	int C_C = C(a, b);

	clock_t endCPP = clock();
	const double timeCPP = static_cast<double>(endCPP - startCPP) / CLOCKS_PER_SEC * 1000.0;

	printf("計算結果：%d\n", C_C);
	printf("C++の計算時間:%lf\n", timeCPP);


	//インラインアセンブラの計算
	a = 10; b = 20;

	clock_t startASM = clock();

	int ASM_ASM = ASM(a, b);

	clock_t endASM = clock();
	const double timeASM = static_cast<double>(endASM - startASM) / CLOCKS_PER_SEC * 1000.0;

	printf("計算結果：%d\n", ASM_ASM);
	printf("インラインアセンブラの計算時間:%lf\n", timeASM);

	getchar();

	return 0;
}

int C(int a, int b)
{
	int c = 0;

	int AA = a; int BB = b; int CC = a; int d = 1; int s = 1;
	
	for (d; d < 1000000; d++)
	{
		AA	 +=	 BB;
		CC	 =	 CC * BB;
		CC   =-	 AA;
		s	 =	 d;
	}

	c = s;

	return c;
}

int ASM(int a, int b)
{
	int c = 0;

	__asm
	{
			mov     eax,  a
			mov     ebx,  b
			mov	    ecx,  eax
			mov		edx,  1
			mov		esi,  1

FOR_START:  cmp		edx,  1000000
            je      FOR_END

			add		eax,  ebx
			imul	ecx,  ebx
			sub		ecx,  eax
			mov		esi,  edx

			add		edx,  1

			jmp		FOR_START

FOR_END:	mov     c,    esi
	}

	return c;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
