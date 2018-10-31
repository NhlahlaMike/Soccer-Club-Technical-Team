//---------------------------------------------------------------------------

#pragma hdrstop

#include "TTeam_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TTeam ::TTeam()
{
	cName = "UnKnown";
	tFormation = "x-x-x";
}

TTeam ::TTeam(AnsiString cN)
{
	cName = cN;
}

void TTeam ::setFormation(AnsiString tF)
{
    tFormation = tF;
}

void TTeam ::DisplayRadio(TRadioGroup *rdg)
{
	rdg->Items->Add(cName);
}

int TTeam ::defPerformance()
{
	int def = random(100)+ 30;

	return def;
}

int TTeam ::attPerformance()
{
	int att = random(100)+ 30;

	return att;
}

TTeam::~TTeam()
{

}


