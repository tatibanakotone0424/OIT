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
	 if (type == TYPE_RED) {
		 m_skinModelRender->Init(L"modelData/ringo_1.cmo");
	 }
	 else if(type== TYPE_BLUE)
	 {
		 m_skinModelRender->Init(L"modelData/ringo_2.cmo");
	 }
	 else if (type == TYPE_DOKU)
	 {
		 m_skinModelRender->Init(L"modelData/rinngo_3.cmo");
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
	if (joutai == JOUTAI_TEISI) {
		if (tima == 50) {
			DeleteGO(this);
			DeleteGO(m_skinModelRender);
		}
	}
	if (joutai == JOUTAI_MIGI_NI_UGOKU) {
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
	if (joutai == JOUTAI_HIDARI_NI_UGOKU) {
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
