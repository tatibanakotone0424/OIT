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
	//���C�g�ݒ肷��
	m_rit = NewGO<prefab::CDirectionLight>(0);
	m_rit->SetDirection({ 0.707f,-0.707,0.0f });
	m_rit->SetColor({ 1.8f,1.8,1.8,1.0f });

	//�J������ݒ�B
	MainCamera().SetTarget({ 29.0f, 100.0f, 100.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(1000.0f);
	//������������������߂Â��Ă���
	MainCamera().SetPosition({ 29.0f, 120.0f, 180.0f });
	MainCamera().Update();
	
	NewGO<haikei>(0);
	//�L�����̃C���X�^���X���쐬����B
	NewGO< Player>(0);
	return true;
}

void Game::Update()
{

}