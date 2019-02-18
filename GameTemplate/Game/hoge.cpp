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
	swprintf(tex, L"Œ¾—t%d");
	m_fontRender->SetText(tex);
	m_fontRender->SetPosition({ 30.0f,30.0f});
	m_fontRender->SetPivot({ 0.0f, 0.0f });
}
