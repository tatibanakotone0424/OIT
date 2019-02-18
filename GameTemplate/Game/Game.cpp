#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"

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

	GraphicsEngine().GetShadowMap().SetLightDirection;

	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(1000.0f);
	//↓数字小さくしたら近づいてくる
	MainCamera().SetPosition({ 0.0f, 70.0f, 500.0f });
	MainCamera().Update();
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	
	return true;
}

void Game::Update()
{
	CQuaternion aRot;
	aRot.SetRotationDeg({0.0f,1.0f,0.0f},5.0f);
	//↓回すプログラム
	//m_rotaion *= aRot;
	m_skinModelRender->SetRotation(m_rotaion);

	m_position.x += Pad(0).GetLStickXF()*-20.0f;
	m_moveSpeed.x = Pad(0).GetLStickXF()*20.0f;
	m_skinModelRender->SetPosition(m_position);

}