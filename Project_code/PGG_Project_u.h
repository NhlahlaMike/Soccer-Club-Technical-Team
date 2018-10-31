//---------------------------------------------------------------------------

#ifndef PGG_Project_uH
#define PGG_Project_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TPlayer_u.h"
#include "TTeam_u.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "SquadForm_u.h"
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmTournament : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tbsCountry;
	TImage *imgTournament;
	TButton *btnLoad;
	TRadioGroup *rdgCountry;
	TTabSheet *tbsResult;
	TLabel *lblCompTeam;
	TLabel *lblFormation;
	TPanel *Panel1;
	TImage *imgGround;
	TButton *btnPerFormacce;
	TTabSheet *tbsPerFormance;
	TStringGrid *stgOverallPerformance;
	TImage *imgBackGround;
	TImage *imgPerFormance;
	TLabel *lblStadium;
	TButton *btnDisplayFormation;
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall rdgCountryClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall tbsResultShow(TObject *Sender);
	void __fastcall btnPerFormacceClick(TObject *Sender);
	void __fastcall btnDisplayFormationClick(TObject *Sender);

private:	// User declarations
		int countGK,countDF,countMF,countFW,countPlayers;

public:		// User declarations
	__fastcall TfrmTournament(TComponent* Owner);
	void computerLineup();
	TTeam *teams[18];
	TPlayer *teamSquad[25];
	void extractLineUp();
	AnsiString comLineUp[11];
	void userLineUp();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTournament *frmTournament;
//---------------------------------------------------------------------------
#endif
