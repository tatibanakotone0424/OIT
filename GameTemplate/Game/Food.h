#pragma once
class Food:public IGameObject
{
public:
	Food();
	~Food();
	bool Start() override;
	void Update();
	//void Update() override;
	
	prefab::CSkinModelRender* m_skinModelRender;
	int tima = 0;
	int type = 0;
	int joutai = 0;
	CVector3 pos;
};

