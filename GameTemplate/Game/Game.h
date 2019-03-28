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
	prefab::CDirectionLight* m_rit = nullptr;    //ƒ‰ƒCƒg‚Ì‚â‚Â
	prefab::CFontRender*m_fontRender;
	int tima = 0;
	int type = 0;
	int scoa = 0;

};

