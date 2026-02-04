// guessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "guess.h"
#include "guessDlg.h"

#include "stdio.h"
#include "math.h"
#include <stdlib.h>
#include <time.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CguessDlg 对话框




CguessDlg::CguessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CguessDlg::IDD, pParent)
	, tmie(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CguessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, se1);
	DDX_Control(pDX, IDC_EDIT2, se2);
	DDX_Control(pDX, IDC_BUTTON1, gus);
	DDX_Control(pDX, IDC_BUTTON2, st);
	DDX_Text(pDX, IDC_EDIT3, tmie);
}

BEGIN_MESSAGE_MAP(CguessDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CguessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CguessDlg::OnBnClickedstart)
	ON_BN_CLICKED(IDC_BUTTON3, &CguessDlg::OnBnClickedAbout)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CguessDlg 消息处理程序

BOOL CguessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		//strAboutMenu.LoadString(IDS_ABOUTBOX);
		VERIFY(strAboutMenu.LoadString(IDS_ABOUTBOX));
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CguessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CguessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CguessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int a1,a2,a3,a4,b1=1,b2=2,b3=3,b4=4,c=0,tt=0;



int bijiao(int x11,int x22,int x33,int x44,int y11,int y22,int y33,int y44)
{
    int a=0;
    if(x11==y11)
        a++;
    if(x22==y22)
        a++;
    if(x33==y33)
        a++;
    if(x44==y44)
        a++;
    return a;
}
int bijiao2(int x11,int x22,int x33,int x44,int y11,int y22,int y33,int y44)
{
    int b=0;
    if(x11==y22||x11==y33||x11==y44)
        b++;
    if(x22==y11||x22==y33||x22==y44)
        b++;
    if(x33==y11||x33==y22||x33==y44)
        b++;
    if(x44==y11||x44==y22||x44==y33)
        b++;
    return b;
}

CStringW t=L"";

void CguessDlg::OnBnClickedstart()
{
	// TODO: Add your control notification handler code here
	t="";
	c=0;
	KillTimer(1);
	tt=0;

	se1.SetLimitText(4);
	srand(time(0));
	
	while(1)
	{
	
		b1=rand()%10;
		b2=rand()%10;
		b3=rand()%10;
		b4=rand()%10;
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"");
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(L"");
		if(b1!=b2&&b1!=b3&&b1!=b4&&b2!=b3&&b2!=b4&&b3!=b4)break;
		
	}
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetReadOnly(0);
	gus.EnableWindow(1);
	se1.SetFocus();
		


}

void CguessDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int a,b;
	CStringW p;	
	a1=GetDlgItemInt(IDC_EDIT1)/1000;
	a2=(GetDlgItemInt(IDC_EDIT1)/100)-(a1*10);
	a3=(GetDlgItemInt(IDC_EDIT1)/10)-(a1*100)-(a2*10);
	a4=GetDlgItemInt(IDC_EDIT1)-(a1*1000)-(a2*100)-(a3*10);


	a=bijiao(a1,a2,a3,a4,b1,b2,b3,b4);
	b=bijiao2(a1,a2,a3,a4,b1,b2,b3,b4);
	
 if(c<7)
 {


	if(c==0)SetTimer(1,1000,NULL);

	if(a!=4)
	{
		
		p.Format(L"%d%d%d%d:%dA%dB",a1,a2,a3,a4,a,b);
		se1.SetFocus();
	}
	else 
	{
		p.Format(L"%d%d%d%d\r\n正确",a1,a2,a3,a4);
		((CEdit*)GetDlgItem(IDC_EDIT1))->SetReadOnly(1);
		gus.EnableWindow(0);
		GetDlgItem(IDC_BUTTON2)->SetFocus();
		KillTimer(1);
	}
	//t.Format(L"%s\r\n%s",t,p);
	t += L"\r\n" + p;

	GetDlgItem(IDC_EDIT2)->SetWindowTextW(t);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"");
	se2.LineScroll(se2.GetLineCount());
	

 }
 else if(c==7&&a==4)
 {
		p.Format(L"%d%d%d%d\r\n正确",a1,a2,a3,a4);
		//t.Format(L"%s\r\n%s",t,p);
		t += L"\r\n" + p;
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(t);
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"");
		se2.LineScroll(se2.GetLineCount());
		((CEdit*)GetDlgItem(IDC_EDIT1))->SetReadOnly(1);
		gus.EnableWindow(0);
		GetDlgItem(IDC_BUTTON2)->SetFocus();
		KillTimer(1);
 }
 else
 {
	 GetDlgItem(IDC_EDIT2)->SetWindowTextW(L"8次未猜对,Game Over");
	 ((CEdit*)GetDlgItem(IDC_EDIT1))->SetReadOnly(1);
	 gus.EnableWindow(0);
	 GetDlgItem(IDC_BUTTON2)->SetFocus();
	 KillTimer(1);
 }
 c++;
/*	int a;

	
	CStringW t;
	
	a=GetDlgItemInt(IDC_EDIT1);

	t.Format(L"%d",a);

	GetDlgItem(IDC_EDIT2)->SetWindowTextW(t);
*/	
}



void CguessDlg::OnBnClickedAbout()
{
	// TODO: Add your control notification handler code here
	CAboutDlg *dlgab=new CAboutDlg;
	dlgab->Create(IDD_ABOUTBOX);
	dlgab->ShowWindow(SW_SHOW);
}



void CguessDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	tt++;
	tmie.Format(L"%ds",tt);
	UpdateData(FALSE);


	CDialog::OnTimer(nIDEvent);
}
