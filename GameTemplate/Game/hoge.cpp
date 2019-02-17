#include "stdafx.h"
#include "hoge.h"


hoge::hoge()
{
}


hoge::~hoge()
{
}
void hoge::Update()
{
	int x = 0;
	int y = 0;
	wchar_t tex[100];
	swprintf(tex, L"Œ¾—t%d",kazu);
	m_fontRender->SetText(tex);

}
