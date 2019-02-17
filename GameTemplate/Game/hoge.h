#pragma once
class hoge:public IGameObject
{
public:
	hoge();
	~hoge();
	//bool Start();
	void Update();
	prefab::CFontRender*m_fontRender = nullptr;
	int kazu = 0;
};

