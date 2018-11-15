//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JobList.h"
#include "Job.h"
#include "ConnectionDataModule.h"

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

void __fastcall TfmrJobList::BtnAddJobClick(TObject *Sender)
{
	frmJob->txtJob->Text = "";
	frmJob->ddlCustomer->KeyValue = "";
	frmJob->ddlStatus->KeyValue = "";
	frmJob->ddlAssigned->KeyValue = "";
   	frmJob->memo1->Text = "";
	frmJob->ShowModal();

}
//---------------------------------------------------------------------------


void __fastcall TfmrJobList::FormShow(TObject *Sender)
{
	//to display the column name in TStringGrid
	gridJobList->Cells[0][0] = "Job Id";
	gridJobList->ColWidths[0] = 50;
	gridJobList->Cells[1][0] = "Job Number";
	gridJobList->ColWidths[1] = 70;
	gridJobList->Cells[2][0] = "Description";
	gridJobList->ColWidths[2] = 110;
	gridJobList->Cells[3][0] = "Customer";
	gridJobList->ColWidths[3] = 80;
	gridJobList->Cells[4][0] = "Mobile Number";
	gridJobList->ColWidths[4] = 80;
	gridJobList->Cells[5][0] = "Status";
	gridJobList->ColWidths[5] = 60;
	gridJobList->Cells[6][0] = "Technician";
	gridJobList->ColWidths[6] = 80;
	gridJobList->Cells[7][0] = "Time Spent";
	gridJobList->ColWidths[7] = 70;
	gridJobList->Cells[8][0] = "Customer ID";
	gridJobList->ColWidths[8] = 70;
	gridJobList->Cells[9][0] = "Status ID";
	gridJobList->ColWidths[9] = 70;
	gridJobList->Cells[10][0] = "User ID";
	gridJobList->ColWidths[10] = 70;
	int rowCounter = 1;

	DataSet_Job->Active = true;
	gridJobList->RowCount = DataSet_Job->RecordCount + 1;
	//to fill customer data in the TStringGrid
	while (!DataSet_Job->Eof)
	{
		gridJobList->Cells[0][rowCounter] =
					DataSet_Job->FieldByName("job_id")->AsString;
		gridJobList->Cells[1][rowCounter] =
					DataSet_Job->FieldByName("job_number")->AsString;
		gridJobList->Cells[2][rowCounter] =
					DataSet_Job->FieldByName("job_description")->AsString;
		gridJobList->Cells[3][rowCounter] =
					DataSet_Job->FieldByName("customer")->AsString;
		gridJobList->Cells[4][rowCounter] =
					DataSet_Job->FieldByName("mobile_number")->AsString;
		gridJobList->Cells[5][rowCounter] =
					DataSet_Job->FieldByName("status_name")->AsString;
		gridJobList->Cells[6][rowCounter] =
					DataSet_Job->FieldByName("user_name")->AsString;
		gridJobList->Cells[7][rowCounter] =
					DataSet_Job->FieldByName("time_spent")->AsString;
		gridJobList->Cells[8][rowCounter] =
					DataSet_Job->FieldByName("customer_id")->AsString;
		gridJobList->Cells[9][rowCounter] =
					DataSet_Job->FieldByName("status_id")->AsString;
		gridJobList->Cells[10][rowCounter] =
					DataSet_Job->FieldByName("login_id")->AsString;
		rowCounter++;
		DataSet_Job->Next();
	}
    gridJobList->ColCount = 8;
	DataSet_Job->First();
}
//---------------------------------------------------------------------------

void __fastcall TfmrJobList::gridJobListSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
	if(ARow != 0)  // if the header row is not selected
	{
		frmJob->txtJob->Text = gridJobList->Cells[1][ARow];
		frmJob->memo1->Text = gridJobList->Cells[2][ARow];
		frmJob->ddlCustomer->KeyValue = gridJobList->Cells[8][ARow];
		frmJob->ddlStatus->KeyValue = gridJobList->Cells[9][ARow];
		frmJob->ddlAssigned->KeyValue = gridJobList->Cells[10][ARow];
		frmJob->ShowModal();
	}
}
//---------------------------------------------------------------------------

