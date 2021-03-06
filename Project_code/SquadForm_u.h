//---------------------------------------------------------------------------

#ifndef SquadForm_uH
#define SquadForm_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>
#include "PGG_Project_u.h"
#include "TPlayer_u.h"
#include "TTeam_u.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmSquad : public TForm
{
__published:	// IDE-managed Components
	TCheckListBox *chkSquad;
	TListBox *lsbxStart;
	TListBox *lsbxSubs;
	TLabel *lblSubst;
	TLabel *lblLineup;
	TLabel *lblTeamSquad;
	TTimer *Timer1;
	TComboBox *cmbFormation;
	TLabel *lblFormation;
	void __fastcall chkSquadClickCheck(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cmbFormationChange(TObject *Sender);
private:	// User declarations
	int maxGK,maxDF,maxMF,maxFW;
public:		// User declarations
	__fastcall TfrmSquad(TComponent* Owner);
		void __fastcall myButton1Click(TObject *Sender);
		void __fastcall mybuttonClick(TObject *Sender);
		void MaxPlayerRole();

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSquad *frmSquad;
//---------------------------------------------------------------------------
#endif
