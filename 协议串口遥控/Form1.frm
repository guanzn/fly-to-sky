VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.2#0"; "MSCOMCTL.OCX"
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "mscomm32.ocx"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "上位机"
   ClientHeight    =   11280
   ClientLeft      =   9750
   ClientTop       =   2100
   ClientWidth     =   8055
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   11280
   ScaleWidth      =   8055
   Begin VB.Frame Frame9 
      Caption         =   "方向控制"
      Height          =   3495
      Left            =   1200
      TabIndex        =   60
      Top             =   7680
      Width           =   5055
      Begin VB.CheckBox Check3 
         Caption         =   "方向控制使能"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3240
         TabIndex        =   65
         Top             =   240
         Width           =   1575
      End
      Begin VB.TextBox Text16 
         Height          =   270
         Left            =   3480
         TabIndex        =   64
         Text            =   "Text16"
         Top             =   2400
         Width           =   615
      End
      Begin VB.TextBox Text15 
         Height          =   270
         Left            =   3480
         TabIndex        =   63
         Text            =   "Text15"
         Top             =   2040
         Width           =   615
      End
      Begin VB.Shape Shape3 
         FillColor       =   &H00E0E0E0&
         FillStyle       =   0  'Solid
         Height          =   400
         Left            =   1780
         Shape           =   3  'Circle
         Top             =   1460
         Width           =   400
      End
      Begin VB.Label Label25 
         Caption         =   "Y向偏移"
         Height          =   375
         Left            =   4200
         TabIndex        =   67
         Top             =   2400
         Width           =   735
      End
      Begin VB.Label Label24 
         Caption         =   "X向偏移"
         Height          =   255
         Left            =   4200
         TabIndex        =   66
         Top             =   2040
         Width           =   735
      End
      Begin VB.Label Label23 
         Caption         =   "X+"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3480
         TabIndex        =   62
         Top             =   3120
         Width           =   375
      End
      Begin VB.Label Label22 
         Caption         =   "Y+"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   360
         TabIndex        =   61
         Top             =   360
         Width           =   375
      End
      Begin VB.Line Line6 
         X1              =   3480
         X2              =   3240
         Y1              =   3360
         Y2              =   3480
      End
      Begin VB.Line Line5 
         X1              =   3480
         X2              =   3240
         Y1              =   3360
         Y2              =   3240
      End
      Begin VB.Line Line4 
         X1              =   240
         X2              =   3480
         Y1              =   3360
         Y2              =   3360
      End
      Begin VB.Line Line3 
         X1              =   240
         X2              =   360
         Y1              =   600
         Y2              =   840
      End
      Begin VB.Line Line2 
         X1              =   240
         X2              =   120
         Y1              =   600
         Y2              =   840
      End
      Begin VB.Line Line1 
         X1              =   240
         X2              =   240
         Y1              =   3360
         Y2              =   600
      End
      Begin VB.Shape Shape2 
         Height          =   3000
         Left            =   480
         Shape           =   3  'Circle
         Top             =   160
         Width           =   3000
      End
   End
   Begin VB.Frame Frame8 
      Caption         =   "注意事项"
      Height          =   1335
      Left            =   5280
      TabIndex        =   57
      Top             =   5520
      Width           =   2655
      Begin VB.Label Label21 
         Caption         =   "2.PID值范围0-25.5，小数点后1位有效数字，因采用乘10来保留一位小数的方式"
         Height          =   615
         Left            =   240
         TabIndex        =   59
         Top             =   600
         Width           =   2295
      End
      Begin VB.Label Label20 
         Caption         =   "1.PID值超范围，暂停发送，直到输入合法数值"
         Height          =   375
         Left            =   240
         TabIndex        =   58
         Top             =   240
         Width           =   2295
      End
   End
   Begin VB.Frame Frame7 
      Caption         =   "数据格式"
      Height          =   615
      Left            =   1680
      TabIndex        =   55
      Top             =   6960
      Width           =   6255
      Begin VB.Label Label19 
         Caption         =   "帧头1 + 帧头2 + 数据长度 + 数据 + 和校验(低八位) + 帧尾1"
         Height          =   255
         Left            =   720
         TabIndex        =   56
         Top             =   240
         Width           =   5175
      End
   End
   Begin VB.Frame Frame6 
      Caption         =   "电压检查"
      Height          =   615
      Left            =   1680
      TabIndex        =   50
      Top             =   6240
      Width           =   3375
      Begin VB.TextBox Text14 
         Height          =   270
         Left            =   1920
         TabIndex        =   51
         Text            =   "Text14"
         Top             =   240
         Width           =   855
      End
      Begin VB.Label Label16 
         Caption         =   "实时电压"
         Height          =   255
         Left            =   960
         TabIndex        =   52
         Top             =   240
         Width           =   735
      End
   End
   Begin VB.Frame Frame5 
      Caption         =   "PID参数"
      Height          =   2895
      Left            =   1680
      TabIndex        =   27
      Top             =   3120
      Width           =   3375
      Begin VB.CheckBox Check2 
         Caption         =   "安全范围"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   1250
         TabIndex        =   48
         Top             =   2230
         Value           =   1  'Checked
         Width           =   1215
      End
      Begin VB.TextBox Text13 
         Height          =   270
         Left            =   2640
         TabIndex        =   46
         Text            =   "Text13"
         Top             =   2400
         Width           =   615
      End
      Begin VB.TextBox Text12 
         Height          =   270
         Left            =   2640
         TabIndex        =   45
         Text            =   "Text12"
         Top             =   2040
         Width           =   615
      End
      Begin VB.CheckBox Check1 
         Caption         =   "PID使能"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   44
         Top             =   2230
         Width           =   1095
      End
      Begin VB.TextBox Text10 
         Height          =   375
         Left            =   2520
         TabIndex        =   36
         Text            =   "Text10"
         Top             =   1560
         Width           =   615
      End
      Begin VB.TextBox Text9 
         Height          =   375
         Left            =   1800
         TabIndex        =   35
         Text            =   "Text9"
         Top             =   1560
         Width           =   615
      End
      Begin VB.TextBox Text8 
         Height          =   375
         Left            =   1080
         TabIndex        =   34
         Text            =   "Text8"
         Top             =   1560
         Width           =   615
      End
      Begin VB.TextBox Text7 
         Height          =   375
         Left            =   2520
         TabIndex        =   33
         Text            =   "Text7"
         Top             =   1080
         Width           =   615
      End
      Begin VB.TextBox Text6 
         Height          =   375
         Left            =   1800
         TabIndex        =   32
         Text            =   "Text6"
         Top             =   1080
         Width           =   615
      End
      Begin VB.TextBox Text5 
         Height          =   375
         Left            =   1080
         TabIndex        =   31
         Text            =   "Text5"
         Top             =   1080
         Width           =   615
      End
      Begin VB.TextBox Text4 
         Height          =   375
         Left            =   2520
         TabIndex        =   30
         Text            =   "Text4"
         Top             =   600
         Width           =   615
      End
      Begin VB.TextBox Text3 
         Height          =   375
         Left            =   1800
         TabIndex        =   29
         Text            =   "Text3"
         Top             =   600
         Width           =   615
      End
      Begin VB.TextBox Text2 
         Height          =   375
         Left            =   1080
         TabIndex        =   28
         Text            =   "Text2"
         Top             =   600
         Width           =   615
      End
      Begin VB.Label Label17 
         Alignment       =   2  'Center
         Caption         =   ">"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   9
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   2400
         TabIndex        =   49
         Top             =   2111
         Width           =   255
      End
      Begin VB.Label Label15 
         Alignment       =   2  'Center
         Caption         =   "<"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   2400
         TabIndex        =   47
         Top             =   2450
         Width           =   255
      End
      Begin VB.Label Label14 
         Caption         =   "D"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   2760
         TabIndex        =   42
         Top             =   240
         Width           =   255
      End
      Begin VB.Label Label13 
         Caption         =   "I"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   2040
         TabIndex        =   41
         Top             =   240
         Width           =   135
      End
      Begin VB.Label Label12 
         Caption         =   "P"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   1320
         TabIndex        =   40
         Top             =   240
         Width           =   135
      End
      Begin VB.Label Label11 
         Caption         =   "Yaw"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   39
         Top             =   1560
         Width           =   615
      End
      Begin VB.Label Label5 
         Caption         =   "Roll"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   38
         Top             =   1080
         Width           =   615
      End
      Begin VB.Label Label4 
         Caption         =   "Pitch"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   37
         Top             =   600
         Width           =   735
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "串口协议"
      Height          =   2295
      Left            =   5280
      TabIndex        =   20
      Top             =   3120
      Width           =   2055
      Begin VB.ComboBox Combo9 
         Height          =   300
         Left            =   960
         TabIndex        =   53
         Text            =   "0x4D"
         Top             =   1800
         Width           =   975
      End
      Begin VB.ComboBox Combo8 
         Height          =   300
         ItemData        =   "Form1.frx":0000
         Left            =   960
         List            =   "Form1.frx":0002
         Locked          =   -1  'True
         TabIndex        =   23
         Text            =   "10"
         Top             =   1320
         Width           =   975
      End
      Begin VB.ComboBox Combo7 
         Height          =   300
         Left            =   960
         Locked          =   -1  'True
         TabIndex        =   22
         Text            =   "0x5A"
         Top             =   840
         Width           =   975
      End
      Begin VB.ComboBox Combo6 
         Height          =   300
         Left            =   960
         Locked          =   -1  'True
         TabIndex        =   21
         Text            =   "0xAA"
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label18 
         Caption         =   "帧尾1"
         Height          =   255
         Left            =   120
         TabIndex        =   54
         Top             =   1850
         Width           =   735
      End
      Begin VB.Label Label3 
         Caption         =   "数据长度"
         Height          =   375
         Left            =   120
         TabIndex        =   26
         Top             =   1320
         Width           =   855
      End
      Begin VB.Label Label2 
         Caption         =   "帧头2"
         Height          =   255
         Left            =   120
         TabIndex        =   25
         Top             =   840
         Width           =   855
      End
      Begin VB.Label Label1 
         Caption         =   "帧头1"
         Height          =   255
         Left            =   120
         TabIndex        =   24
         Top             =   360
         Width           =   855
      End
   End
   Begin VB.OptionButton Option2 
      Caption         =   "字符串"
      Height          =   255
      Left            =   4790
      TabIndex        =   19
      Top             =   840
      Width           =   855
   End
   Begin VB.OptionButton Option1 
      Caption         =   "HEX码"
      Height          =   255
      Left            =   4790
      TabIndex        =   18
      Top             =   600
      UseMaskColor    =   -1  'True
      Value           =   -1  'True
      Width           =   855
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   200
      Left            =   7440
      Top             =   3720
   End
   Begin MSComctlLib.Slider Slider1 
      DragIcon        =   "Form1.frx":0004
      Height          =   3225
      Left            =   480
      TabIndex        =   9
      Top             =   3720
      Width           =   675
      _ExtentX        =   1191
      _ExtentY        =   5689
      _Version        =   393216
      Orientation     =   1
      LargeChange     =   1
      Max             =   20
      SelectRange     =   -1  'True
      TickStyle       =   2
   End
   Begin VB.ComboBox Combo5 
      Height          =   300
      ItemData        =   "Form1.frx":3686
      Left            =   6840
      List            =   "Form1.frx":3693
      Style           =   2  'Dropdown List
      TabIndex        =   8
      Top             =   1920
      Width           =   975
   End
   Begin VB.ComboBox Combo4 
      Height          =   300
      ItemData        =   "Form1.frx":36A2
      Left            =   6840
      List            =   "Form1.frx":36B2
      Style           =   2  'Dropdown List
      TabIndex        =   7
      Top             =   1560
      Width           =   975
   End
   Begin VB.ComboBox Combo3 
      Height          =   300
      ItemData        =   "Form1.frx":36C2
      Left            =   6840
      List            =   "Form1.frx":36CF
      Style           =   2  'Dropdown List
      TabIndex        =   6
      Top             =   1200
      Width           =   975
   End
   Begin VB.ComboBox Combo2 
      Height          =   300
      ItemData        =   "Form1.frx":36DC
      Left            =   6840
      List            =   "Form1.frx":36F2
      Style           =   2  'Dropdown List
      TabIndex        =   5
      Top             =   840
      Width           =   975
   End
   Begin VB.ComboBox Combo1 
      Height          =   300
      ItemData        =   "Form1.frx":371E
      Left            =   6840
      List            =   "Form1.frx":3720
      Style           =   2  'Dropdown List
      TabIndex        =   4
      Top             =   480
      Width           =   975
   End
   Begin VB.CommandButton Command3 
      Caption         =   "启动串口"
      Height          =   495
      Left            =   6840
      TabIndex        =   3
      Top             =   2280
      Width           =   880
   End
   Begin VB.CommandButton Command2 
      Caption         =   "清空接收"
      Height          =   495
      Left            =   4790
      TabIndex        =   2
      Top             =   2280
      Width           =   880
   End
   Begin VB.CommandButton Command1 
      Caption         =   "开始发送"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   6960
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   2052
         SubFormatType   =   0
      EndProperty
      Height          =   2295
      Left            =   240
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   0
      Text            =   "Form1.frx":3722
      Top             =   480
      Width           =   4455
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   7320
      Top             =   3000
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
      InputLen        =   1
      RThreshold      =   1
      InputMode       =   1
   End
   Begin VB.Frame Frame1 
      Caption         =   "油门"
      DragIcon        =   "Form1.frx":372A
      Height          =   4455
      Left            =   120
      TabIndex        =   10
      Top             =   3120
      Width           =   1335
      Begin VB.TextBox Text11 
         Height          =   270
         Left            =   480
         TabIndex        =   43
         Text            =   "Text11"
         Top             =   360
         Width           =   495
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "接收区"
      Height          =   2655
      Left            =   120
      TabIndex        =   17
      Top             =   240
      Width           =   5655
   End
   Begin VB.Frame Frame2 
      Caption         =   "串口设置"
      Height          =   2655
      Left            =   5880
      TabIndex        =   11
      Top             =   240
      Width           =   2055
      Begin VB.Shape Shape1 
         BackColor       =   &H00C0C0C0&
         BorderColor     =   &H00000008&
         BorderStyle     =   6  'Inside Solid
         FillColor       =   &H00C0C0C0&
         FillStyle       =   0  'Solid
         Height          =   255
         Left            =   240
         Shape           =   4  'Rounded Rectangle
         Top             =   2160
         Width           =   495
      End
      Begin VB.Label Label10 
         Caption         =   "停止位"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   16
         Top             =   1720
         Width           =   735
      End
      Begin VB.Label Label9 
         Caption         =   "数据位"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   15
         Top             =   1365
         Width           =   735
      End
      Begin VB.Label Label8 
         Caption         =   "校验位"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   14
         Top             =   1010
         Width           =   735
      End
      Begin VB.Label Label7 
         Caption         =   "波特率"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   13
         Top             =   655
         Width           =   735
      End
      Begin VB.Label Label6 
         Caption         =   "端口号"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   12
         Top             =   300
         Width           =   735
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim flag_com(15) As Integer        '用于正确的打开串口
Dim baud As String              '串口波特率，停止位，校验位，数据位设置变量
Dim parity As String
Dim stopbit As String
Dim comnumbit As String
Dim flag_send As Boolean        '用于控制数据发送flag
Dim RecState As Byte           '接收状态控制
Dim LengthNum As Byte
Dim LengthTotal As Byte
Dim Checksum As Integer   '求和校验
Dim RecOk As Byte         '用于所接受数据是否正常
Dim DatRec(128) As Byte
Dim DirectX As Integer       '记录方向偏移
Dim DirectY As Byte
Const HEAD1 As Byte = 1
Const HEAD2 As Byte = 2
Const LENGTH As Byte = 3
Const data As Byte = 4
Const CHECK As Byte = 5
Const BOTTOM1 As Byte = 6
Const ShapeCentreTop = 1660
Const ShapeCentreLeft = 1980

Private Sub Combo1_Click()
    MSComm1.CommPort = flag_com(Combo1.ListIndex)
End Sub

Private Sub Combo2_Click()
    baud = Combo2.Text
    MSComm1.Settings = baud & "," & parity & "," & comnumbit & "," & stopbit
End Sub

Private Sub Combo3_Click()
    parity = Combo3.Text
    MSComm1.Settings = baud & "," & parity & "," & comnumbit & "," & stopbit
End Sub

Private Sub Combo4_Click()
    comnumbit = Combo4.Text
    MSComm1.Settings = baud & "," & parity & "," & comnumbit & "," & stopbit
End Sub

Private Sub Combo5_Click()
    stopbit = Combo5.Text
    MSComm1.Settings = baud & "," & parity & "," & comnumbit & "," & stopbit
End Sub

Private Sub Combo8_Change()
    On Error Resume Next
    If Combo8.Text <> "" Then
        If IsNumeric(Combo8.Text) = True Then
            LengthTotal = Combo8.Text
        Else
            MsgBox ("请输入数字")
        End If
    End If
End Sub

Private Sub Combo8_Click()
    LengthTotal = Combo8.Text
End Sub

Private Sub Command1_Click()
Dim temp
  If MSComm1.PortOpen = False Then
      temp = MsgBox("请先启动串口", 0, "ERROR")
  Else
        If flag_send = False Then
            flag_send = True
            Timer1.Enabled = True
            Command1.Caption = "停止发送"
        Else
            flag_send = False
            Timer1.Enabled = False
            Command1.Caption = "开始发送"
        End If
        
  End If
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
End Sub

Private Sub Command3_Click()
    Dim j As Integer
    If MSComm1.PortOpen = False Then
        On Error Resume Next
        MSComm1.PortOpen = True
        
        If MSComm1.PortOpen <> True Then
            MsgBox ("串口不存在或已被占用")
        Else
        Command3.Caption = "关闭串口"
        Shape1.FillColor = vbRed
        End If
    Else
        flag_send = False
        Timer1.Enabled = False
        Command1.Caption = "开始发送"
        MSComm1.PortOpen = False
        Command3.Caption = "打开串口"
        Shape1.FillColor = &HC0C0C0
         Combo1.Clear
        For i = 1 To 16
            MSComm1.CommPort = i
            On Error Resume Next
            MSComm1.PortOpen = True
            If MSComm1.PortOpen = True Then
               Combo1.AddItem ("COM" & i)
               flag_com(j) = i
               j = j + 1
            End If
            MSComm1.PortOpen = False
        Next i
        Combo1.ListIndex = 0
    End If
End Sub

Private Sub Form_Load()
    Dim j As Integer
'''''''串口同步帧参数设置'''''''
    RecState = HEAD1
    Checksum = 0
    LengthTotal = 0
    LengthNum = 0
    RecOk = False
    Text1.Text = ""
    Text2.Text = 0
    Text3.Text = 0
    Text4.Text = 0
    Text5.Text = 0
    Text6.Text = 0
    Text7.Text = 0
    Text8.Text = 0
    Text9.Text = 0
    Text10.Text = 0
    Text12.Text = 0
    Text13.Text = 10
    Text11.Text = Slider1.Value * 100
    Text14.Text = "0.00V"
    Text15.Text = 0
    Text16.Text = 0

    flag_send = False
    For i = 1 To 16
        MSComm1.CommPort = i
        On Error Resume Next
        MSComm1.PortOpen = True
        If MSComm1.PortOpen = True Then
           Combo1.AddItem ("COM" & i)
           flag_com(j) = i
           j = j + 1
        End If
        MSComm1.PortOpen = False
    Next i
    Combo1.ListIndex = 0
    Combo2.ListIndex = 2
    Combo3.ListIndex = 0
    Combo4.ListIndex = 0
    Combo5.ListIndex = 0
    Combo8.Text = 10
    baud = "9600"
    parity = "n"
    stopbit = "1"
    comnumbit = "8"
End Sub

Private Sub frame9_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Text1.Text = X
    Text14.Text = Y
    If Shift = 1 Then
        If X > 1930 And X < 2030 And Y > 1610 And Y < 1710 Then
            Shape3.FillColor = vbRed
        End If
    Else
        Shape3.FillColor = &HE0E0E0
        Shape3.Top = 1460  '设置到中心点
        Shape3.Left = 1780
        DirectX = 0
        DirectY = 0
    End If
    If Shape3.FillColor = vbRed Then
        If (Y - ShapeCentreTop) ^ 2 + (X - ShapeCentreLeft) ^ 2 < 1495 ^ 2 Then
            Shape3.Top = Y - 200
            Shape3.Left = X - 200
        Else
            If Y = ShapeCentreTop Then
                Shape3.Top = ShapeCentreTop - Shape3.Height / 2
                If X > ShapeCentreLeft Then
                    Shape3.Left = ShapeCentreLeft - Shape3.Width / 2 + Shape2.Width / 2
                ElseIf X < ShapeCentreLeft Then
                    Shape3.Left = ShapeCentreLeft - Shape3.Width / 2 - Shape2.Width / 2
                End If
            ElseIf X = ShapeCentreLeft Then
                Shape3.Left = ShapeCentreLeft - Shape3.Width / 2
                If Y > ShapeCentreTop Then
                    Shape3.Top = ShapeCentreTop - Shape3.Height / 2 + Shape2.Height / 2
                ElseIf Y < ShapeCentreTop Then
                    Shape3.Top = ShapeCentreTop - Shape3.Height / 2 - Shape2.Height / 2
                End If
            Else
                Shape3.Top = ShapeCentreTop - Shape3.Height / 2 + (Y - ShapeCentreTop) * Shape2.Height / 2 _
                             / Sqr((Y - ShapeCentreTop) ^ 2 + (X - ShapeCentreLeft) ^ 2)
                Shape3.Left = ShapeCentreLeft - Shape3.Width / 2 + (X - ShapeCentreLeft) * Shape2.Width / 2 _
                             / Sqr((Y - ShapeCentreTop) ^ 2 + (X - ShapeCentreLeft) ^ 2)
            End If
        End If
        DirectX = (Shape3.Left + Shape3.Width / 2 - ShapeCentreLeft) / Shape2.Width * 200 + 100
        DirectY = -(Shape3.Top + Shape3.Height / 2 - ShapeCentreTop) / Shape2.Height * 200 + 100
        Text15.Text = DirectX
        Text16.Text = DirectY
    End If
    
End Sub

Private Sub MSComm1_OnComm()
    Dim tempstr As Variant '定义一个Variant型的数，这个非常重要
    Dim i As Integer
    Select Case MSComm1.CommEvent
        Case comEvReceive
    If MSComm1.InputLen <> 0 Then
        tempstr = MSComm1.Input
        Select Case RecState
            Case HEAD1:
                If tempstr(0) = &HAA Then
                    RecState = HEAD2
                End If
            Case HEAD2:
                If tempstr(0) = &H5A Then
                    RecState = LENGTH
                ElseIf tempstr(0) = &HAA Then
                    RecState = HEAD2
                Else
                    RecState = HEAD1
                End If
            Case LENGTH:
                If tempstr(0) <= 32 Then
                    LengthTotal = tempstr(0)
                    RecState = data
                Else
                    RecState = HEAD1
                End If
            Case data:
                DatRec(LengthNum) = tempstr(0)
                Checksum = Checksum + tempstr(0)
                LengthNum = LengthNum + 1
                If LengthNum = LengthTotal Then
                    LengthNum = 0
                    RecState = CHECK
                    Checksum = Checksum Mod 256
                End If
            Case CHECK:
                If Checksum = tempstr(0) Then
                    RecState = BOTTOM1
                Else
                    RecState = HEAD1
                End If
                Checksum = 0
            Case BOTTOM1:
                If tempstr(0) = &H4D Then
                    RecOk = True
                End If
                RecState = HEAD1
        End Select
        If RecOk = True Then
            RecOk = False
            For i = 0 To LengthTotal - 1
                If Option1.Value = True Then
                    If DatRec(i) < 16 Then
                        Text1.Text = Text1.Text + "0" + Hex(DatRec(i)) + " "
                    Else
                        Text1.Text = Text1.Text + Hex(DatRec(i)) + " "
                    End If
                Else
                    Text1.Text = Text1.Text + Chr(DatRec(i))
                End If
            Next i
            Text14.Text = Str(DatRec(0) * 2 / 100) + "V"
        End If
    End If
        
    End Select
End Sub

Private Sub Slider1_Click()
    Text11.Text = Slider1.Value * 50
End Sub

Private Sub Slider1_Scroll()
    Text11.Text = Slider1.Value * 50
End Sub

Private Sub Text1_Change()
Text1.SelStart = Len(Text1.Text)    '光标停留在最后
End Sub

Private Sub Text2_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text2.Text <> "" Then
            If Val(Text2.Text) < Val(Text12.Text) Or Val(Text2.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text3_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text3.Text <> "" Then
            If Val(Text3.Text) < Val(Text12.Text) Or Val(Text3.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text4_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text4.Text <> "" Then
            If Val(Text4.Text) < Val(Text12.Text) Or Val(Text4.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text5_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text5.Text <> "" Then
            If Val(Text5.Text) < Val(Text12.Text) Or Val(Text5.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text6_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text6.Text <> "" Then
            If Val(Text6.Text) < Val(Text12.Text) Or Val(Text6.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text7_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text7.Text <> "" Then
            If Val(Text7.Text) < Val(Text12.Text) Or Val(Text7.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text8_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text8.Text <> "" Then
            If Val(Text8.Text) < Val(Text12.Text) Or Val(Text8.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text9_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text9.Text <> "" Then
            If Val(Text9.Text) < Val(Text12.Text) Or Val(Text9.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Text10_Change()
    While MSComm1.OutBufferCount <> 0
        DoEvents
    Wend
    Timer1.Enabled = False
    
    If Check2.Value = 1 Then
        On Error Resume Next
        If Text10.Text <> "" Then
            If Val(Text10.Text) < Val(Text12.Text) Or Val(Text10.Text) > Val(Text13.Text) Then
                MsgBox ("输入参数不在安全范围内")
            Else
                Timer1.Enabled = True
            End If
        End If
    End If
End Sub

Private Sub Timer1_Timer()
    Dim Sum As Integer
    Dim i As Integer

    If flag_send = True Then
            Select Case Check1.Value + Check3.Value * 2
            Case 0:             '表示PID和方向控制数据均不发送
            
                Dim data(5) As Byte
                Combo8.Text = 1
                Sum = Slider1.Value
                
                data(0) = &HAA
                data(1) = &H5A
                data(2) = Combo8.Text
                data(3) = Slider1.Value
                data(4) = Sum Mod 256
                data(5) = &H4D
                
                MSComm1.Output = data
            Case 1:              '表示PID数据发送而方向控制不发送
                Dim data1(14) As Byte
                Combo8.Text = 10
                data1(0) = &HAA
                data1(1) = &H5A
                data1(2) = Combo8.Text
                data1(3) = Slider1.Value
                data1(4) = Text2.Text * 10 Mod 256
                data1(5) = Text3.Text * 10 Mod 256
                data1(6) = Text4.Text * 10 Mod 256
                data1(7) = Text5.Text * 10 Mod 256
                data1(8) = Text6.Text * 10 Mod 256
                data1(9) = Text7.Text * 10 Mod 256
                data1(10) = Text8.Text * 10 Mod 256
                data1(11) = Text9.Text * 10 Mod 256
                data1(12) = Text10.Text * 10 Mod 256
                Sum = 0
                For i = 1 To Combo8.Text
                    Sum = Sum + data1(i + 2)
                Next i
                data1(13) = Sum Mod 256
                data1(14) = &H4D
            
                MSComm1.Output = data1
            Case 2:             '表示PID数据不发送而方向控制数据发送
                Dim data2(7) As Byte
                Combo8.Text = 3
                data2(0) = &HAA
                data2(1) = &H5A
                data2(2) = Combo8.Text
                data2(3) = Slider1.Value
                data2(4) = DirectX
                data2(5) = DirectY
                Sum = 0
                For i = 1 To Combo8.Text
                    Sum = Sum + data2(i + 2)
                Next i
                data2(6) = Sum Mod 256
                data2(7) = &H4D
                
                MSComm1.Output = data2
            Case 3:             '表示PID和方向控制数据均发送
                Dim data3(16) As Byte
                Combo8.Text = 12
                data3(0) = &HAA
                data3(1) = &H5A
                data3(2) = Combo8.Text
                data3(3) = Slider1.Value
                data3(4) = Text2.Text * 10 Mod 256
                data3(5) = Text3.Text * 10 Mod 256
                data3(6) = Text4.Text * 10 Mod 256
                data3(7) = Text5.Text * 10 Mod 256
                data3(8) = Text6.Text * 10 Mod 256
                data3(9) = Text7.Text * 10 Mod 256
                data3(10) = Text8.Text * 10 Mod 256
                data3(11) = Text9.Text * 10 Mod 256
                data3(12) = Text10.Text * 10 Mod 256
                data3(13) = DirectX
                data3(14) = DirectY
                Sum = 0
                For i = 1 To Combo8.Text
                    Sum = Sum + data3(i + 2)
                Next i
                data3(15) = Sum Mod 256
                data3(16) = &H4D
            
                MSComm1.Output = data3
            
            End Select
    End If
End Sub
