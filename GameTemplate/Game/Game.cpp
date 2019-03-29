#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include"haikei.h"
#include "Player.h"
#include"Food.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_haikei);
	DeleteGO(m_fontRender);
	DeleteGO(m_player);
	DeleteGO(m_rit);
}
bool Game::Start()
{
	//ライト設定する
	m_rit = NewGO<prefab::CDirectionLight>(0);
	m_rit->SetDirection({ 0.707f,-0.707,0.0f });
	m_rit->SetColor({ 1.8f,1.8,1.8,1.0f });

	//カメラを設定。
	MainCamera().SetTarget({ 29.0f, 100.0f, 100.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(1000.0f);
	//↓数字小さくしたら近づいてくる
	MainCamera().SetPosition({ 29.0f, 120.0f, 180.0f });
	MainCamera().Update();
	
	m_haikei = NewGO<haikei>(0);
	
	//キャラのインスタンスを作成する。
	m_player = NewGO<Player>(0);
	
	m_fontRender = NewGO<prefab::CFontRender>(0);
	return true;
}

void Game::Update()
{
	if (GameOver == true) {
		return;
	}
	wchar_t text[256];
	swprintf(text, L"スコア \n%02d",scoa);
	m_fontRender->SetText(text);
	m_fontRender->SetPosition({ 100.0f, 100.0f });
	m_fontRender->SetPivot({ 0.0f, 0.0f });
	tima++;
	if (tima == 160) {
		Food* food = NewGO<Food>(0,"フード");
		//rand関数はランダムな整数を返フしてくる。
		int r = rand();
		//偶数
		if (r % 2 == 0) {
			food->type = 1;
		}
		//奇数
		else {
			food->type = 2;
		}

		tima = 0;
	}	
	/* {
	(tima = 60)->NewGO<Food>(0);
	}*/
}