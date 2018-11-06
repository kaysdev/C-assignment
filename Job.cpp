//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Job.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmJob *frmJob;
//---------------------------------------------------------------------------
__fastcall TfrmJob::TfrmJob(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmJob::FormShow(TObject *Sender)
{
    ADOTable1->Active=true;
	while (!ADOTable1->Eof)
	{
		ddlUser->Items->Add(ADOTable1->FieldByName("user_name")->AsString);
		ADOTable1->Next();
	}
	ADOTable1->First();


	ADOTable3->Active=true;
	while (!ADOTable3->Eof)
	{
		ddlStatus->Items->Add(ADOTable3->FieldByName("status_name")->AsString);
		ADOTable3->Next();
	}
	ADOTable3->First();
}
//---------------------------------------------------------------------------

void __fastcall TfrmJob::btnSaveClick(TObject *Sender)
{
	if(txtJob->Text.Trim() == "")
	{
		ShowMessage("Please enter valid job number!");
	}
	else if(ddlCustomer->Text == "")
	{
        ShowMessage("Please select Customer!");
    }
	else if(memo1->Text.Trim() =="")
	{
        ShowMessage("Please enter valid job description!");
	}
	else if(ddlUser->Text == "")
	{
		ShowMessage("Please select Assigned To!");
	}
	else if(ddlStatus->Text == "")
	{
		ShowMessage("Please select Status!");
    }
	ShowMessage("Save Record!!!");
}
//---------------------------------------------------------------------------

