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
	//tima�𖈃t���[���A�C���N�������g����B
	//tima�̒l��60�ɂȂ�����A
	//prefab::CSpriteRender�̃C���X�^���X���쐬���āA
	//ma�̒l��120�ɂȂ�����A
	//DeleteGO(this)��DeleteGO(m_spritRender)�����s���āA
	//GameOver��2D�������B
	tima++; 
	if (tima == 60) {
		m_spritRender = NewGO<prefab::CSpriteRender>(0);
		m_spritRender->Init(L"sprite/Game.dds", 500, 500);	
	}
	if (tima == 300) {
		DeleteGO(this);
		DeleteGO(m_spritRender);
		//Game�N���X�̃C���X�^���X���폜���āA
		//�V����Game�N���X�̃C���X�^���X�����B
		Game* g = FindGO<Game>("�X�R�A");
		DeleteGO(g);

		NewGO<Game>(0,"�X�R�A");
	}
}
