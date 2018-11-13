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

void __fastcall TfrmJob::btnSaveClick(TObject *Sender)
{
	//ShowMessage(ddlCustomer->KeyValue);
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
		ADOQuery->Connection = ADOConnection1;

		ADOQuery->Prepared = true;
		ADOQuery->SQL->Clear();
		ADOQuery->SQL->Add(SQLStr);
		try
		{
			ADOQuery->ExecSQL(); // this will save the customer record in database
			ADOQuery->Close();
			ShowMessage("Save Record!!!");
		}
		catch (EADOError& e)
		{
			MessageDlg("Error while connecting", mtError,
					  TMsgDlgButtons() << mbOK, 0);
			return;
		}
	}
}
//---------------------------------------------------------------------------
//empty form fields on form show
void __fastcall TfrmJob::FormShow(TObject *Sender)
{
   txtJob->Text = "";
   ddlCustomer->KeyValue = "";
   ddlStatus->KeyValue = "";
   ddlAssigned->KeyValue = "";
   memo1->Text = "";
}
//---------------------------------------------------------------------------
