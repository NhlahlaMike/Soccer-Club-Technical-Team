//---------------------------------------------------------------------------

#pragma hdrstop

#include "TPlayer_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TPlayer::TPlayer()
{
	 name = "Unknown" ;
	 birthDate = "1800/01/01";
	 position = "xx";
	 jersyNo = 0;
}
TPlayer::TPlayer(AnsiString nm,AnsiString bD,AnsiString pos,int jN)
{
	name = nm;
	birthDate = bD;
	position = pos;
	jersyNo = jN;
}
TPlayer::~TPlayer()
{

}
