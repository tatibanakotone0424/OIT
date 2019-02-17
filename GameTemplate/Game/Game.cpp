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
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	
	return true;
}

void Game::Update()
{
	CQuaternion aRot;
	aRot.SetRotationDeg({0.0f,1.0f,0.0f},5.0f);

	m_rotaion *= aRot;
	m_skinModelRender->SetRotation(m_rotaion);

	m_position.x += Pad(0).GetLStickXF()*-20.0f;
	m_moveSpeed.x = Pad(0).GetLStickXF()*20.0f;
	m_skinModelRender->SetPosition(m_position);

}