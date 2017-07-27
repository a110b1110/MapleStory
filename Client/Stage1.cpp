#include "stdafx.h"
#include "Stage1.h"
#include "ObjMgr.h"
#include "BitMapMgr.h"
#include "BitMap.h"
#include "Stage1_Back.h"
#include "Stage1_Map.h"
#include "Player.h"

//Npc
//-------------------------------------
#include "Store_Npc.h"
//-------------------------------------
//UI
//-------------------------------------
#include "Status.h"
#include "Inven.h"
#include "Equip.h"
#include "Skill.h"
#include "Skill_Input.h"
#include "Stat.h"
#include "HpBar.h"
#include "MpBar.h"
#include "ExpBar.h"
//-------------------------------------

CStage1::CStage1(void)
{
}

CStage1::~CStage1(void)
{
	Release();
}

void CStage1::Initialize(void)
{
	GETS(CBitMapMgr)->LoadImageByScene(SCENE_STAGE1);

	//Stage1 Back Object Create
	CObj* pObj = new CStage1_Back();
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_BACKGROUND, pObj);
	((CStage1_Back*)pObj)->SetRedner(true);

	//Stage1 Map Object Create
	pObj = new CStage1_Map();
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_BACKGROUND, pObj);
	((CStage1_Map*)pObj)->SetRedner(true);

	//Player
	pObj = new CPlayer;
	pObj->Initialize();
	pObj->SetPos(800.f, 600.f);
	GETS(CObjMgr)->AddObject(OBJ_PLAYER, pObj);

	//NPC
	pObj = new CStore_Npc;
	pObj->Initialize();
	pObj->SetPos(WINCX / 2 + 600.f, WINCY / 2 + 305.f);
	GETS(CObjMgr)->AddObject(OBJ_NPC, pObj);

	//UI
	//---------------------------------------------------------------------
	//Status
	pObj = new CStatus;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);	
	//Inven
	pObj = new CInven;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);
	//Equip
	pObj = new CEquip;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);
	//Skill
	CObj* pSkill = new CSkill_UI;
	pSkill->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pSkill);
	pObj = new CSkill_Input(*(pSkill->GetInfo()));
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);	
	//Stat
	pObj = new CStat;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);
	//Hp_Bar
	pObj = new CHpBar;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);
	//Mp_Bar
	pObj = new CMpBar;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);
	//Exp_Bar
	pObj = new CExpBar;
	pObj->Initialize();
	GETS(CObjMgr)->AddObject(OBJ_UI, pObj);
	//---------------------------------------------------------------------
}

int CStage1::Update(void)
{
	GETS(CObjMgr)->Update();

	return 0;
}

void CStage1::Render(HDC _dc)
{
	GETS(CObjMgr)->Render(_dc);
}

void CStage1::Release(void)
{
	GETS(CObjMgr)->DestroyInstance();
}
