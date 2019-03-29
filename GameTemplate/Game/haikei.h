#pragma once
class haikei:public IGameObject
{
public:
	haikei();
	~haikei();
	bool Start();
	void Update();
	prefab::CSkinModelRender *m_skinModelRender;
	prefab::CSoundSource* m_sound;
};

