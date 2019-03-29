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
	
	m_haikei = NewGO<haikei>(0);
	
	//�L�����̃C���X�^���X���쐬����B
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
	swprintf(text, L"�X�R�A \n%02d",scoa);
	m_fontRender->SetText(text);
	m_fontRender->SetPosition({ 100.0f, 100.0f });
	m_fontRender->SetPivot({ 0.0f, 0.0f });
	tima++;
	if (tima == 160) {
		Food* food = NewGO<Food>(0,"�t�[�h");
		//rand�֐��̓����_���Ȑ�����ԃt���Ă���B
		int r = rand();
		//����
		if (r % 2 == 0) {
			food->type = 1;
		}
		//�
		else {
			food->type = 2;
		}

		tima = 0;
	}	
	/* {
	(tima = 60)->NewGO<Food>(0);
	}*/
}