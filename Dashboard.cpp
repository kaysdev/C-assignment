//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dashboard.h"
#include "CustomerList.h"
#include "JobList.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDashboard *frmDashboard;
//---------------------------------------------------------------------------
__fastcall TfrmDashboard::TfrmDashboard(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// on click on Customer menu bar; customer list will open
void __fastcall TfrmDashboard::Customer1Click(TObject *Sender)
{
	frmCustomerList->ShowModal();
}
//---------------------------------------------------------------------------
// on click on job menu bar; job list will be open
void __fastcall TfrmDashboard::Jobs2Click(TObject *Sender)
{
	fmrJobList->ShowModal();
}
//---------------------------------------------------------------------------

