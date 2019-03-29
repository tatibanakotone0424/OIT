#include "stdafx.h"
#include "haikei.h"


haikei::haikei()
{
}


haikei::~haikei()
{
	DeleteGO(m_sound);
	DeleteGO(m_skinModelRender);
}

bool haikei::Start()
{
	//prefab::CSkinModelRender�̃C���X�^���X�����B
	//�C���X�^���X�������@�́AIGameObject���p�����Ă���N���X��
	//NewGO���g���B

	m_skinModelRender = NewGO<prefab::CSkinModelRender>( 0 );
	m_skinModelRender->Init(L"modelData/tageru.cmo");

	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/aaa.wav");
	m_sound->Play(true);
	m_sound->SetVolume(0.5f);
	return true;
}
void haikei::Update()
{
	return ;
}