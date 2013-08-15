#include "stdafx.h"
#include "StartTestDlg.h"

StartTestDlg::StartTestDlg()
{
    SET_FONT
	CreateWidget();
}

StartTestDlg::~StartTestDlg()
{

}

void StartTestDlg::CreateWidget()
{
	newTestbtn_ = new QPushButton(this);
	loadTestbtn_ = new QPushButton(this);
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(newTestbtn_);
	layout->addWidget(loadTestbtn_);
}

void StartTestDlg::ReTranslateString()
{
	newTestbtn_->setText("新建测验");
	loadTestbtn_->setText("加载测验");
}

void StartTestDlg::NewTest()
{
	
}

void StartTestDlg::LoadTest()
{

}