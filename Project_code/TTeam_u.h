//---------------------------------------------------------------------------

#ifndef TTeam_uH
#define TTeam_uH
#include <vcl.h>
//---------------------------------------------------------------------------
class TTeam
{
	private:
		AnsiString cName;
		AnsiString tFormation;
	public:
		TTeam();
		TTeam(AnsiString cN);
		void setFormation(AnsiString tF);
		void selcLineUp();
		int defPerformance();
		int attPerformance();
		void DisplayRadio(TRadioGroup *rdg);
		~TTeam();
};
#endif
