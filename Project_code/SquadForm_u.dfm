object frmSquad: TfrmSquad
  Left = 0
  Top = 0
  Caption = 'Team Squad'
  ClientHeight = 474
  ClientWidth = 764
  Color = clMaroon
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object lblSubst: TLabel
    Left = 543
    Top = 258
    Width = 75
    Height = 16
    Caption = 'Substitutes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblLineup: TLabel
    Left = 368
    Top = 112
    Width = 129
    Height = 16
    Caption = 'Starting_Lineup(XI)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblTeamSquad: TLabel
    Left = 8
    Top = 2
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblFormation: TLabel
    Left = 216
    Top = 2
    Width = 184
    Height = 16
    Caption = 'Select Formation To Proceed'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object chkSquad: TCheckListBox
    Left = 8
    Top = 24
    Width = 321
    Height = 401
    OnClickCheck = chkSquadClickCheck
    Color = clMaroon
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object lsbxStart: TListBox
    Left = 368
    Top = 152
    Width = 137
    Height = 273
    Color = clMaroon
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object lsbxSubs: TListBox
    Left = 543
    Top = 288
    Width = 121
    Height = 137
    Color = clMaroon
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 2
  end
  object cmbFormation: TComboBox
    Left = 223
    Top = 39
    Width = 161
    Height = 21
    TabOrder = 3
    OnChange = cmbFormationChange
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 696
    Top = 376
  end
end
