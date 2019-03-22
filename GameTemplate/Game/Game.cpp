#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include"haikei.h"
#include "Player.h"

Game::Game()
{
}


Game::~Game()
{
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
	
	NewGO<haikei>(0);
	//キャラのインスタンスを作成する。
	NewGO< Player>(0);
	return true;
}

void Game::Update()
{

}