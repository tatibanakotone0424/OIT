#include "stdafx.h"
#include "GameOver.h"
#include"Game.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
}
bool GameOver::Start()
{
	
	return true;
}
void GameOver::Update()
{
	//timaを毎フレーム、インクリメントする。
	//timaの値が60になったら、
	//prefab::CSpriteRenderのインスタンスを作成して、
	//maの値が120になったら、
	//DeleteGO(this)とDeleteGO(m_spritRender)を実行して、
	//GameOverの2Dを消す。
	tima++; 
	if (tima == 60) {
		m_spritRender = NewGO<prefab::CSpriteRender>(0);
		m_spritRender->Init(L"sprite/Game.dds", 500, 500);	
	}
	if (tima == 300) {
		DeleteGO(this);
		DeleteGO(m_spritRender);
		//Gameクラスのインスタンスを削除して、
		//新しいGameクラスのインスタンスを作る。
		Game* g = FindGO<Game>("スコア");
		DeleteGO(g);

		NewGO<Game>(0,"スコア");
	}
}
