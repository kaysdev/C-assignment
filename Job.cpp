//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Job.h"
#include "JobList.h"
#include "ConnectionDataModule.h"
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

void __fastcall TfrmJob::btnSaveClick(TObject *Sender)
{
	if(this->btnSave->Caption == "Close")
	{
        frmJob->Close();
	}
	else
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
		else if(ddlStatus->Text == "")
		{
			ShowMessage("Please select Status!");
		}
		else if(ddlAssigned->Text == "")
		{
			ShowMessage("Please select Assigned To!");
		}
		else
		{
			TADOQuery* ADOQuery;
			/* SQL Query to insert the job data into job table*/
			String SQLStr = "INSERT INTO Job (job_number,customer_id, \
							job_description,status_id, assigned_to) VALUES \
							("+txtJob->Text.Trim()\
							+ ", " + ddlCustomer->KeyValue + ",'"
							+ memo1->Text.Trim() + "', "
							+ ddlStatus->KeyValue + ","
							+ ddlAssigned->KeyValue + ");";
			ADOQuery = new TADOQuery(this);
			ADOQuery->Connection = DataBaseModule->DBConnection;

			ADOQuery->Prepared = true;
			ADOQuery->SQL->Clear();
			ADOQuery->SQL->Add(SQLStr);
			try
			{
				ADOQuery->ExecSQL(); // this will save the job record in database
				ADOQuery->Close();

				int rowCounter = 1;

				fmrJobList->DataSet_Job->Active = false;
				fmrJobList->DataSet_Job->Active = true;
				fmrJobList->DataSet_Job->Refresh();

				fmrJobList->gridJobList->RowCount = fmrJobList->DataSet_Job->RecordCount + 1;
				//to fill job data in the TStringGrid
				while (!fmrJobList->DataSet_Job->Eof)
				{
					fmrJobList->gridJobList->Cells[0][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("job_id")->AsString;
					fmrJobList->gridJobList->Cells[1][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("job_number")->AsString;
					fmrJobList->gridJobList->Cells[2][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("job_description")->AsString;
					fmrJobList->gridJobList->Cells[3][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("customer")->AsString;
					fmrJobList->gridJobList->Cells[4][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("mobile_number")->AsString;
					fmrJobList->gridJobList->Cells[5][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("status_name")->AsString;
					fmrJobList->gridJobList->Cells[6][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("user_name")->AsString;
					fmrJobList->gridJobList->Cells[7][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("time_spent")->AsString;
					fmrJobList->gridJobList->Cells[8][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("customer_id")->AsString;
					fmrJobList->gridJobList->Cells[9][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("status_id")->AsString;
					fmrJobList->gridJobList->Cells[10][rowCounter] =
								fmrJobList->DataSet_Job->FieldByName("login_id")->AsString;
					rowCounter++;
					fmrJobList->DataSet_Job->Next();
				}
				fmrJobList->gridJobList->ColCount = 8;
				fmrJobList->DataSet_Job->First();

				ShowMessage("Save Record!!!");

				frmJob->Close();
			}
			catch (EADOError& e)
			{
				MessageDlg("Error while connecting", mtError,
						  TMsgDlgButtons() << mbOK, 0);
				return;
			}
		}
	}
}
//---------------------------------------------------------------------------
//empty form fields on form show
void __fastcall TfrmJob::FormShow(TObject *Sender)
{
	DataBaseModule->ADOTable_login->Active = false;
	DataBaseModule->ADOTable_login->Active = true;

	DataBaseModule->ADOTable_Status->Active = false;
	DataBaseModule->ADOTable_Status->Active = true;

	DataBaseModule->ADOTable_Customer->Active = false;
	DataBaseModule->ADOTable_Customer->Active = true;

	//when click on Grid data from list page
	if(this->txtJob->Text != "")
	{
		this->txtJob->Enabled = false;
		this->memo1->Enabled = false;
		this->ddlAssigned->Enabled = false;
		this->ddlCustomer->Enabled = false;
		this->ddlStatus->Enabled = false;
		this->btnSave->Caption = "Close";
	}
    //when click on Add button
	else
	{
		this->txtJob->Enabled = true;
		this->memo1->Enabled = true;
		this->ddlAssigned->Enabled = true;
		this->ddlCustomer->Enabled = true;
		this->ddlStatus->Enabled = true;
		this->btnSave->Caption = "Save";
	}
}
//---------------------------------------------------------------------------

