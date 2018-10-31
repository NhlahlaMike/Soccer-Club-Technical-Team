//---------------------------------------------------------------------------
#ifndef TPlayer_uH
#define TPlayer_uH
#include <vcl.h>
//---------------------------------------------------------------------------
class TPlayer
{
	private:
		AnsiString name;
		AnsiString birthDate;
		AnsiString position;
		int jersyNo;

	public:
	   TPlayer();
	   TPlayer(AnsiString nm,AnsiString bD,AnsiString pos,int jN);
	   AnsiString getName(){return name;};
	   AnsiString getBirthDate(){return birthDate;};
	   AnsiString getPosition(){return position;};
	   int getJersyNo(){return jersyNo;};
	   ~TPlayer();
};
#endif
