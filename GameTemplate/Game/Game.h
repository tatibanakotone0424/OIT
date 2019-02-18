#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CQuaternion m_rotaion = CQuaternion::Identity;         //回すやつ　
	CVector3 m_position = CVector3::Zero;                  //動くやつ
	CVector3 m_moveSpeed = CVector3::Zero;                 //スピード
	prefab::CDirectionLight* m_rit = nullptr;    //ライトのやつ


};

