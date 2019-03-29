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
	//prefab::CSkinModelRenderのインスタンスを作る。
	//インスタンスを作る方法は、IGameObjectを継承しているクラスは
	//NewGOを使う。

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