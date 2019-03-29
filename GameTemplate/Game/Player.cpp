#include "stdafx.h"
#include "Player.h"
#include"Food.h"
#include "Game.h"
#include "GameOver.h"
Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_modelRender);
}

bool Player::Start()
{
	//�A�j���[�V�����N���b�v�����[�h����A
	m_animClips[Animation_RHand].Load(L"animData/RHandAnim.tka");
	m_animClips[Animation_LHand].Load(L"animData/LHandAnim.tka");
	//CSkinModelRender�̃C���X�^���X���쐬����B
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	//���f�������[�h����B
	m_modelRender->Init(L"modelData/chara.cmo", m_animClips, AnimationNoKazu);
	CVector3 pos;
	pos.x = 35.0f;
	pos.y = -50.0f;
	pos.z = -110.0f;
	m_modelRender->SetPosition( pos );
	
	CQuaternion ro;
	CVector3 axis;
	axis.x = 0;
	axis.y = 1;
	axis.z = 0;
	ro.SetRotationDeg(axis, 90);
	m_modelRender->SetRotation(ro);

	return true;
}
void Player::Update()
{
	Game* geme = FindGO<Game>("�X�R�A");
	if (geme->GameOver == true) {
		return;
	}
	if (joutai == 0) {
		//�v���C���[���_�������Ă���Ƃ��̏���
		if (Pad(0).IsTrigger(enButtonA)) {
			//��
			//Food��joutai��1�ɂ���B
			//Food�̃C���X�^���X����������BFindGO���g���΍s�������B
			Food* hoge;
			hoge = FindGO<Food>("�t�[�h", false);
			if (hoge != nullptr) {
				//���������Ȃ�
				hoge->joutai = 1;
				//�����H�ו����ԂȂ�
				if (hoge->type == 1) {
					Game* game = FindGO<Game>("�X�R�A");
					game->scoa++;
				}
				else
				{
					GameOver*over = NewGO<GameOver>(0,"�Q�[���I�[�o�[");
					geme->GameOver = true;
					/*m_spritRender = NewGO<prefab::CSpriteRender>(0);
					m_spritRender->Init(L"sprite/Game.dds", 500, 500);*/
				}
			}
			joutai = 1;
			m_modelRender->PlayAnimation(Animation_RHand);
		}

		if (Pad(0).IsTrigger(enButtonB)) {
			//��
			Food* hoge;
			hoge = FindGO<Food>("�t�[�h", false);
			if (hoge != nullptr) {
				hoge->joutai = 2;
				//�����H�ו����Ȃ�
				if (hoge->type == 2) {
					Game*game = FindGO<Game>("�X�R�A");
					game->scoa++;

				}
				else {
					//GameOver�N���X�̃C���X�^���X�����B
					GameOver*over = NewGO<GameOver>(0,"�Q�[���I�[�o�[");
					geme->GameOver = true;
					/*m_spritRender = NewGO<prefab::CSpriteRender>(0);
					m_spritRender->Init(L"sprite/Game.dds",500,500);*/
				}
			}
			joutai = 1;
			m_modelRender->PlayAnimation(Animation_LHand);
		}
	}
	if (joutai == 1) {
		//�A�j���[�V�����̍Đ����I�������Ajoutai��0�ɂ���B
		if (m_modelRender->IsPlayingAnimation()== false)
		{
			joutai = 0;
		}
	}
}
