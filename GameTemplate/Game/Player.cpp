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
	//アニメーションクリップをロードする、
	m_animClips[Animation_RHand].Load(L"animData/RHandAnim.tka");
	m_animClips[Animation_LHand].Load(L"animData/LHandAnim.tka");
	//CSkinModelRenderのインスタンスを作成する。
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	//モデルをロードする。
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
	Game* geme = FindGO<Game>("スコア");
	if (geme->GameOver == true) {
		return;
	}
	if (joutai == JOUTAI_TEISI) {
		//プレイヤーが棒立ちしているときの処理
		if (Pad(0).IsTrigger(enButtonA)) {
			//赤
			//Foodのjoutaiを1にする。
			//Foodのインスタンスを検索する。FindGOを使えば行けそう。
			Food* hoge;
			hoge = FindGO<Food>("フード", false);
			if (hoge != nullptr) {
				//見つかったなら
				hoge->joutai = 1;
				//もし食べ物が赤なら
				if (hoge->type == Food::TYPE_RED) {
					Game* game = FindGO<Game>("スコア");
					game->scoa++;
				}
				else if (hoge->type == Food::TYPE_DOKU) {
					GameOver*over = NewGO<GameOver>(0, "ゲームオーバー");
					geme->GameOver = true;
				}
				else
				{
					GameOver*over = NewGO<GameOver>(0, "ゲームオーバー");
					geme->GameOver = true;
					/*m_spritRender = NewGO<prefab::CSpriteRender>(0);
					m_spritRender->Init(L"sprite/Game.dds", 500, 500);*/
				}
			}
			joutai = JOUTAI_MIGI;
			m_modelRender->PlayAnimation(Animation_RHand);
		}

		if (Pad(0).IsTrigger(enButtonB)) {
			//青
			Food* hoge;
			hoge = FindGO<Food>("フード", false);
			if (hoge != nullptr) {
				hoge->joutai = 2;
				//もし食べ物が青なら
				if (hoge->type == Food::TYPE_BLUE) {
					Game*game = FindGO<Game>("スコア");
					game->scoa++;
				}
				else if (hoge->type == Food::TYPE_DOKU) {
					GameOver*over = NewGO<GameOver>(0, "ゲームオーバー");
					geme->GameOver = true;
				}

				else {

					//GameOverクラスのインスタンスを作る。
					GameOver*over = NewGO<GameOver>(0, "ゲームオーバー");
					geme->GameOver = true;

					/*m_spritRender = NewGO<prefab::CSpriteRender>(0);
					m_spritRender->Init(L"sprite/Game.dds",500,500);*/
				}
			}
			joutai = JOUTAI_MIGI;
			m_modelRender->PlayAnimation(Animation_LHand);
		}


		if (joutai == JOUTAI_MIGI) {
			//アニメーションの再生が終わったら、joutaiを0にする。
			if (m_modelRender->IsPlayingAnimation() == false)
			{
				joutai = JOUTAI_TEISI;
			}
		}
	}

}
