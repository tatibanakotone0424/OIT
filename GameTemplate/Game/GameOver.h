#pragma once
class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spritRender;
	int tima = 0;
};

