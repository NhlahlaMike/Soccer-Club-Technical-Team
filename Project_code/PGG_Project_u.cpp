//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PGG_Project_u.h"
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTournament *frmTournament;
AnsiString cName;
TPanel *pnlPlayer;
TLabel *lblPlayer;
AnsiString compTeam,players[11];
//---------------------------------------------------------------------------
__fastcall TfrmTournament::TfrmTournament(TComponent* Owner)
	: TForm(Owner)
{
	countGK = 0,countDF = 0,countMF = 0,countFW = 0,countPlayers = 0;
	randomize();
	Randomize();
	PageControl1->ActivePageIndex =  0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTournament::btnLoadClick(TObject *Sender)
{
	rdgCountry->Items->Clear();
	TStringList *myList = new TStringList();

	myList->LoadFromFile("afcon2013_teams.txt");
	AnsiString line, country;

	for(int c = 0; c < 2; c++)
	{
		myList->Delete(0);
	}
	for (int x = 0 ; x < myList->Count;x++)
	{
		line = myList->Strings[x];

		int pos = line.AnsiPos("\t");

		for(int i = 0; i < 2; i++)
		{
			line =  line.Delete(1,pos);
			line = line.Trim();
			pos = line.AnsiPos("\t");
		}
		teams[x] = new TTeam(line.SubString(1,pos-1));
		teams[x]->DisplayRadio(rdgCountry);
	}
	btnLoad->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTournament::rdgCountryClick(TObject *Sender)
{
	randomize();
	frmSquad->chkSquad->Enabled = true;
	frmSquad->lsbxStart->Clear();
	frmSquad->lsbxSubs->Clear();
	computerLineup();
	if(compTeam != rdgCountry->Items->Strings[rdgCountry->ItemIndex])
	{
		tbsCountry->Enabled = false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmTournament::FormShow(TObject *Sender)
{
	imgTournament->Picture->LoadFromFile("PICS//opening1.bmp");
}
//---------------------------------------------------------------------------
void TfrmTournament::computerLineup()
{
	int RandTeam;
	RandTeam = random(rdgCountry->Items->Count);
	compTeam = rdgCountry->Items->Strings[RandTeam];
	frmSquad->chkSquad->Clear();
	cName = compTeam;

	AnsiString rdgCountryText,LineNumber,Position,Names,line,line2,ItemX[4];
	int posTab;
	bool found = false;

	TStringList *myList = new TStringList();
	myList->LoadFromFile("afcon2013_players.txt");

	if(RandTeam != rdgCountry->ItemIndex)
	{

		int index = 0;
		for (int i = 0; i < myList->Count;i++)
		{
			line = myList->Strings[i];
			index++;
			if(line.Trim().UpperCase() == rdgCountry->Items->Strings[rdgCountry
				->ItemIndex].UpperCase())
			{
				frmSquad->lblTeamSquad->Caption = line.Trim().UpperCase();
				found = true;
				break;
			}
		}
		if (!found)
		{
		 return;

		}
		int t = 0;
		for(int x = index+1 ; x < myList->Count; x++)
		{
			line2 = myList->Strings[x];

			if(line2.IsEmpty())
			{
				break;
			}
			posTab = line2.AnsiPos("\t");
			ItemX[0] = line2.SubString(1,posTab-1);
			line2 = line2.Delete(1,posTab).Trim();
			posTab = line2.AnsiPos("\t");
			ItemX[1] = line2.SubString(1,posTab-1);
			line2 = line2.Delete(1,posTab).Trim();
			posTab = line2.AnsiPos("\t");
			ItemX[2] = line2.SubString(1,posTab-1);
			line2 = line2.Delete(1,posTab).Trim();
			ItemX[3] = line2.Trim();

			teamSquad[t] = new TPlayer(ItemX[2],ItemX[3],ItemX[1],
			ItemX[0].ToInt());

			frmSquad->chkSquad->Items->Add(IntToStr(teamSquad[t]->getJersyNo())+
			" "+teamSquad[t]->getPosition()+" "+teamSquad[t]->getName());
			t++;
		}

	   frmSquad->Show();
	}
	else
	{
		ShowMessage("You have selected the same team as the computer");
	}
	int indx = 0;
	AnsiString comLine,comLine2,comItem[3],comSquad[25];
	found = false;

	for(int x = 0; x < myList->Count; x++)
	{
		comLine = myList->Strings[x];
		indx++;
		if(comLine.Trim().UpperCase() == compTeam.Trim().UpperCase())
		{
			found = true;
			break;
		}
	}

	if(!found)
	{
	   return;
	}
	int n = 0;
	for(int m = indx+1; m < myList->Count; m++)
	{
		comLine2 = myList->Strings[m];

		if(comLine2.IsEmpty())
		{
			break;
		}  //ShowMessage(comLine2);
		posTab = comLine2.AnsiPos("\t");
		comItem[0] = comLine2.SubString(1,posTab-1);
		comLine2 = comLine2.Delete(1,posTab).Trim();
		posTab = comLine2.AnsiPos("\t");
		comItem[1] = comLine2.SubString(1,posTab-1);
		comLine2 = comLine2.Delete(1,posTab).Trim();
		posTab = comLine2.AnsiPos("\t");
		comItem[2] = comLine2.SubString(1,posTab-1);
		comLine2 = comLine2.Delete(1,posTab).Trim();

		comSquad[n] = comItem[0]+" "+comItem[1]+" "+comItem[2];
		n++;

	}
	AnsiString role,itemP;

	AnsiString GK,DF[4],MF[4],FW[2];

	for(int v = 0; v < 11;v++)
	{
		if (countPlayers == 11)
		{
			break;
			countPlayers = 0;
		}

		for (int s = 0; s < 25; s++)
		{
			int randPlayers = Random(23);

			itemP = comSquad[randPlayers];
			role = itemP.SubString(itemP.AnsiPos(" "),3).Trim();

			if (role == "GK")
			{
				GK = comSquad[randPlayers];
			}
			if (role == "DF")
			{
				switch (countDF)
				{
					case 0: DF[0] = comSquad[randPlayers]; break;
					case 1: DF[1] = comSquad[randPlayers]; break;
					case 2: DF[2] = comSquad[randPlayers]; break;
					case 3: DF[3] = comSquad[randPlayers]; break;
				}
				countDF++;
			}
			if (role == "MF")
			{
				switch (countMF)
				{
					case 0: MF[0] = comSquad[randPlayers]; break;
					case 1: MF[1] = comSquad[randPlayers]; break;
					case 2: MF[2] = comSquad[randPlayers]; break;
					case 3: MF[3] = comSquad[randPlayers]; break;
				}
				countMF++;
			}
			if (role == "FW")
			{
				switch (countFW)
				{
					case 0: FW[0] = comSquad[randPlayers]; break;
					case 1: FW[1] = comSquad[randPlayers]; break;
				}
				countFW++;
			}
		}

		countPlayers++;
	  }
		countGK = 0,countDF = 0,countMF = 0,countFW = 0,countPlayers = 0;

		comLineUp[0] = GK;
		comLineUp[1] = DF[0];
		comLineUp[2] = DF[1];
		comLineUp[3] = DF[2];
		comLineUp[4] = DF[3];
		comLineUp[5] = MF[0];
		comLineUp[6] = MF[1];
		comLineUp[7] = MF[2];
		comLineUp[8] = MF[3];
		comLineUp[9] = FW[0];
		comLineUp[10] = FW[1];

}
//-----------------------------------------------------------------------
void __fastcall TfrmTournament::tbsResultShow(TObject *Sender)
{
	AnsiString pRole,jNo;int pos;
	AnsiString tempLine;

	for(int x = 0; x < 11; x++)
	{
		pnlPlayer = new TPanel(this);
		lblPlayer = new TLabel(this);
		lblPlayer->Parent = Panel1;
		pnlPlayer->Parent = Panel1;
		pnlPlayer->ParentBackground = false;
		pnlPlayer->Width = 20;
		pnlPlayer->Height = 20;
		pnlPlayer->Color = clBlue;
		pnlPlayer->Left = 30 + (30*x);

		tempLine = comLineUp[x];

		pos = tempLine.AnsiPos(" ");
		jNo = tempLine.SubString(1,pos-1);
		tempLine = tempLine.Delete(1,pos).Trim();
		pos = tempLine.AnsiPos(" ");
		pRole = tempLine.SubString(1,pos-1).Trim();



		if(pRole == "GK")
		{
			pnlPlayer->Left = 30 + (30*x);
			pnlPlayer->Top = Panel1->Height-(Panel1->Height/1.9);
			pnlPlayer->Caption = jNo;
			lblPlayer->Top = pnlPlayer->Top-20;
			lblPlayer->Caption = tempLine.Trim();
		}
		if(pRole == "DF")
		{
			pnlPlayer->Left = 30 + (30*4);
			pnlPlayer->Top = 10 + (70*(x));
			lblPlayer->Top = pnlPlayer->Top-20;
			lblPlayer->Left = 30 + (30*4);
			pnlPlayer->Caption = jNo;
			lblFormation->Tag = 3;
			lblPlayer->Caption = tempLine.Trim();
		}
		if(pRole == "MF")
		{
			pnlPlayer->Left = 30 + (30*8);
			pnlPlayer->Top = 10 + (70*(x-4));
			lblPlayer->Top = pnlPlayer->Top-20;
			pnlPlayer->Caption = jNo;
			lblPlayer->Left = 30 + (30*8);
			lblPlayer->Caption = tempLine.Trim();
		}
		if(pRole == "FW")
		{
			pnlPlayer->Left = 30 + (30*12);
			pnlPlayer->Top = 60 + (70*(x-8));
			lblPlayer->Top = pnlPlayer->Top-20;
			pnlPlayer->Caption = jNo;
			lblPlayer->Left = 30 + (30*12);
			lblPlayer->Caption = tempLine.Trim();
		}
	}
	imgGround->Picture->LoadFromFile("Ground.bmp");
	lblCompTeam->Caption ="COMPUTER TEAM : " +cName;
	lblFormation->Caption = "FORMATION : 4-4-2";
}
//---------------------------------------------------------------------------
void TfrmTournament::userLineUp()
{
    AnsiString Splayers,formation,pRole,jNo,name;

	formation = frmSquad->cmbFormation->Text;
	//dynamically create panels representing the formation of 4-4-2 else of 4-3-3
	if (formation == "4-4-2")
	{
		for (int x = 0; x < 11; x++)
		{
			Splayers =  frmSquad->lsbxStart->Items->Strings[x];

			jNo = Splayers.SubString(1,Splayers.AnsiPos(" ")-1);
			pRole = Splayers.SubString(Splayers.AnsiPos(" "),3).Trim();
			name = Splayers.SubString(Splayers.AnsiPos(" "),Splayers.Length());

			TPanel *pnlPlayer = new TPanel(this);
			TLabel *lblPlayer = new TLabel(this);
			lblPlayer->Parent = Panel1;
			pnlPlayer->Parent = Panel1;
			pnlPlayer->ParentBackground = false;
			pnlPlayer->Width = 40;
			pnlPlayer->Height = 20;
			pnlPlayer->Color = clRed;
			pnlPlayer->Left = 30 + (30*x);

			if(pRole == "GK")
			{
				pnlPlayer->Left = 30 + (30*x);
				pnlPlayer->Top = Panel1->Height-(Panel1->Height/1.8);
				pnlPlayer->Caption = jNo;
				lblPlayer->Top = pnlPlayer->Top-20;
				lblPlayer->Caption = name;
			}
			if(pRole == "DF")
			{
				pnlPlayer->Left = 30 + (30*4);
				pnlPlayer->Top = 10 + (70*(x));
				lblPlayer->Top = pnlPlayer->Top-20;
				lblPlayer->Left = 30 + (30*4);
				pnlPlayer->Caption = jNo;
				lblPlayer->Caption = name;
			}
			if(pRole == "MF")
			{
				pnlPlayer->Left = 30 + (30*8);
				pnlPlayer->Top = 10 + (70*(x-4));
				lblPlayer->Top = pnlPlayer->Top-20;
				pnlPlayer->Caption = jNo;
				lblPlayer->Left = 30 + (30*8);
				lblPlayer->Caption = name;
			}
			if(pRole == "FW")
			{
				pnlPlayer->Left = 30 + (30*12);
				pnlPlayer->Top = 60 + (70*(x-8));
				lblPlayer->Top = pnlPlayer->Top-20;
				pnlPlayer->Caption = jNo;
				lblPlayer->Left = 30 + (30*12);
				lblPlayer->Caption = name;
			}

		}

	}
	else
	{
		for (int x = 0; x < 11; x++)
		{
			Splayers =  frmSquad->lsbxStart->Items->Strings[x];

			jNo = Splayers.SubString(1,Splayers.AnsiPos(" ")-1);
			pRole = Splayers.SubString(Splayers.AnsiPos(" "),3).Trim();
			name = Splayers.SubString(Splayers.AnsiPos(" "),Splayers.Length());

			TPanel *pnlPlayer = new TPanel(this);
			TLabel *lblPlayer = new TLabel(this);
			lblPlayer->Parent = Panel1;
			pnlPlayer->Parent = Panel1;
			pnlPlayer->ParentBackground = false;
			pnlPlayer->Width = 40;
			pnlPlayer->Height = 20;
			pnlPlayer->Color = clRed;
			pnlPlayer->Left = 30 + (30*x);

			if(pRole == "GK")
			{
				pnlPlayer->Left = 30 + (30*x);
				pnlPlayer->Top = Panel1->Height-(Panel1->Height/1.8);
				pnlPlayer->Caption = jNo;
				lblPlayer->Top = pnlPlayer->Top-20;
				lblPlayer->Caption = name;
			}
			if(pRole == "DF")
			{
				pnlPlayer->Left = 30 + (30*4);
				pnlPlayer->Top = 10 + (70*(x));
				lblPlayer->Top = pnlPlayer->Top-20;
				lblPlayer->Left = 30 + (30*4);
				pnlPlayer->Caption = jNo;
				lblPlayer->Caption = name;
			}
			if(pRole == "MF")
			{
				pnlPlayer->Left = 30 + (30*8);
				pnlPlayer->Top = 40 + (70*(x-4));
				lblPlayer->Top = pnlPlayer->Top-20;
				pnlPlayer->Caption = jNo;
				lblPlayer->Left = 30 + (30*8);
				lblPlayer->Caption = name;
			}
			if(pRole == "FW")
			{
				pnlPlayer->Left = 30 + (30*12);
				pnlPlayer->Top = 40+ (70*(x-7));
				lblPlayer->Top = pnlPlayer->Top-20;
				pnlPlayer->Caption = jNo;
				lblPlayer->Left = 30 + (30*12);
				lblPlayer->Caption = name;
			}

		}

	}


}
//---------------------------------------------------------------------------
void __fastcall TfrmTournament::btnPerFormacceClick(TObject *Sender)
{


	Sleep(1000);
	tbsPerFormance->Show();
	tbsCountry->Enabled = true;
	btnLoad->Enabled = true;

	int compAttPerf = random(100)+ 30;
	int compDefPerf = random(100)+ 30;
	int scoreUser,scoreComp;
	int userDefPerf = teams[rdgCountry->ItemIndex]->defPerformance();
	int userAttPerf = teams[rdgCountry->ItemIndex]->attPerformance();

	if(compAttPerf < userAttPerf)
	{
		scoreUser = random(4)+2;
		scoreComp = random(2);
	}
	else
	{
		scoreComp = random(4)+2;
		scoreUser = random(2);
	}
	if(compDefPerf < userDefPerf)
	{
		scoreComp = scoreComp * 0.5;
		scoreUser = scoreUser * 1;
	}
	else
	{
		scoreComp = scoreComp * 1;
		scoreUser = scoreUser * 0.5;
    }

	imgPerFormance->Picture->LoadFromFile("PICS//opening2.bmp");
	imgBackGround->Picture->LoadFromFile("PICS//OPENING.JPG");

	 AnsiString Headers[] = {"Stats",compTeam,rdgCountry->Items->
	 Strings[rdgCountry->ItemIndex]};
	 AnsiString fColumn[] = {"Deffence","Attack","Score"};

	 for(int j = 1; j < 4;j++)
	 {
		stgOverallPerformance->Cells[0][j] = fColumn[j-1];
	 }
	 for(int c = 0; c < 3; c++)
	 {
		stgOverallPerformance->Cells[c][0] = Headers[c];
	 }
	 int userStats[] = {compDefPerf,userAttPerf,scoreUser};
	 for(int d = 1; d < 4; d++)
	 {
		stgOverallPerformance->Cells[2][d] =  userStats[d-1];
	 }
	 int compStats[] = {userDefPerf,compAttPerf,scoreComp};
	 for(int e = 1; e < 4; e++)
	 {
		stgOverallPerformance->Cells[1][e] =  compStats[e-1];
	 }
	 AnsiString venue[5] = {"Mbombela","RustenBurg","Moses Mabida","Soccer City"
	 ,"Polokwane"};

	 lblStadium->Caption = "Match was played at "+venue[random(5)]+ " On "+
	 FormatDateTime("dddd,'the' dd 'of' mmmm,yyyy '@' hh:nn",Now());
}
//---------------------------------------------------------------------------
void __fastcall TfrmTournament::btnDisplayFormationClick(TObject *Sender)
{
	lblCompTeam->Caption ="USER TEAM : " +rdgCountry->Items->
	 Strings[rdgCountry->ItemIndex];
	lblFormation->Caption = "FORMATION : "+ frmSquad->cmbFormation->Text;
	userLineUp();
	btnDisplayFormation->Enabled = false;

	for (int i = 0; i < 22;i++)
	  {
			Sleep(50);
			Update();
			delete Components[17];

	  }


}
//---------------------------------------------------------------------------



