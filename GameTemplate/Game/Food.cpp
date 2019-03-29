#include "stdafx.h"
#include "Food.h"


Food::Food()
{

}


Food::~Food()
{
}
 bool Food::Start()
{
	 m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	 if (type == 1) {
		 m_skinModelRender->Init(L"modelData/ringo_1.cmo");
	 }
	 else if(type==2)
	 {
		 m_skinModelRender->Init(L"modelData/ringo_2.cmo");
	 }
	
	pos.x = 30.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;
	m_skinModelRender->SetPosition(pos);
	return true;
}
void Food::Update()
{

	tima++;
	if (joutai == 0) {
		if (tima == 50) {
			DeleteGO(this);
			DeleteGO(m_skinModelRender);
		}
	}
	if (joutai == 1) {
		pos.x += 1;
		m_skinModelRender->SetPosition(pos);
		if (tima == 110) {
			DeleteGO(this);
			DeleteGO(m_skinModelRender);
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			ss->Init(L"sound/apple1.wav");
			ss->Play(false);

		}
	}
	if (joutai == 2) {
		pos.x -= 1;
		m_skinModelRender->SetPosition(pos);
		if (tima == 110) {
			DeleteGO(this);
			DeleteGO(m_skinModelRender);
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			ss->Init(L"sound/apple1.wav");
			ss->Play(false);
		}
	}
}
