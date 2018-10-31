object frmTournament: TfrmTournament
  Left = 0
  Top = 0
  Caption = 'African Cup Of Nation'
  ClientHeight = 482
  ClientWidth = 757
  Color = clMaroon
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 24
    Top = 24
    Width = 689
    Height = 450
    ActivePage = tbsResult
    TabOrder = 0
    object tbsCountry: TTabSheet
      Caption = 'Country'
      object imgTournament: TImage
        Left = 0
        Top = 0
        Width = 681
        Height = 422
        Align = alClient
        Stretch = True
        ExplicitWidth = 689
        ExplicitHeight = 273
      end
      object btnLoad: TButton
        Left = 24
        Top = 16
        Width = 113
        Height = 25
        Caption = 'Load Teams'
        TabOrder = 0
        OnClick = btnLoadClick
      end
      object rdgCountry: TRadioGroup
        Left = 143
        Top = 0
        Width = 321
        Height = 386
        Color = clMaroon
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentColor = False
        ParentFont = False
        TabOrder = 1
        OnClick = rdgCountryClick
      end
    end
    object tbsResult: TTabSheet
      Caption = 'Formation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      OnShow = tbsResultShow
      object lblCompTeam: TLabel
        Left = 40
        Top = 15
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblFormation: TLabel
        Left = 40
        Top = 29
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Panel1: TPanel
        Left = 24
        Top = 48
        Width = 638
        Height = 354
        Color = clGreen
        ParentBackground = False
        TabOrder = 0
        object imgGround: TImage
          Left = 0
          Top = 0
          Width = 625
          Height = 353
        end
      end
      object btnPerFormacce: TButton
        Left = 422
        Top = 3
        Width = 227
        Height = 25
        Caption = 'Extract The Perfomances of the two Team'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = btnPerFormacceClick
      end
      object btnDisplayFormation: TButton
        Left = 207
        Top = 3
        Width = 209
        Height = 25
        Caption = 'Display Your Team Formation'
        TabOrder = 2
        OnClick = btnDisplayFormationClick
      end
    end
    object tbsPerFormance: TTabSheet
      Caption = 'Result'
      ImageIndex = 2
      object imgBackGround: TImage
        Left = -3
        Top = -5
        Width = 681
        Height = 406
        Stretch = True
      end
      object imgPerFormance: TImage
        Left = 27
        Top = 72
        Width = 294
        Height = 241
        Stretch = True
      end
      object lblStadium: TLabel
        Left = 27
        Top = 345
        Width = 5
        Height = 19
        Color = clAqua
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object stgOverallPerformance: TStringGrid
        Left = 360
        Top = 72
        Width = 297
        Height = 241
        ColCount = 3
        DefaultColWidth = 90
        DrawingStyle = gdsGradient
        FixedColor = clWhite
        ParentColor = True
        TabOrder = 0
      end
    end
  end
end
