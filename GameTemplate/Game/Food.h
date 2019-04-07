#pragma once
class Food:public IGameObject
{
public:
	Food();
	~Food();
	bool Start() override;
	void Update();
	//void Update() override;
	enum {
		TYPE_RED = 1,
		TYPE_BLUE,
		TYPE_DOKU,
	};
	enum {
		JOUTAI_TEISI,				//é~Ç‹Ç¡ÇƒÇ¢ÇÈèÛë‘ÅB
		JOUTAI_MIGI_NI_UGOKU,
		JOUTAI_HIDARI_NI_UGOKU

	};
	prefab::CSkinModelRender* m_skinModelRender;
	int tima = 0;
	int type = TYPE_RED;
	int joutai = JOUTAI_TEISI;
	CVector3 pos;
};

