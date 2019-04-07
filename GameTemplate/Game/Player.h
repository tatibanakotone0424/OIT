#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	enum {
		Animation_RHand,
		Animation_LHand,
		AnimationNoKazu,
	};
	enum {
		JOUTAI_TEISI,
		JOUTAI_MIGI,
	};
	CAnimationClip m_animClips[AnimationNoKazu];
	prefab::CSkinModelRender* m_modelRender = nullptr;
	//prefab::CSpriteRender* m_spritRender = nullptr;
	int joutai = JOUTAI_TEISI;


};

