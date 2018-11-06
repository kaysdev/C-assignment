//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JobList.h"
#include "Job.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmrJobList *fmrJobList;
//---------------------------------------------------------------------------
__fastcall TfmrJobList::TfmrJobList(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TfmrJobList::Button1Click(TObject *Sender)
{
	frmJob->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfmrJobList::DBGrid1DblClick(TObject *Sender)
{
	ShowMessage("Hello");
}
//---------------------------------------------------------------------------


