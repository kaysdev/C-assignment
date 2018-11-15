//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Customer.h"
#include "CustomerList.h"
#include "ConnectionDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCustomer *frmCustomer;
//---------------------------------------------------------------------------
__fastcall TfrmCustomer::TfrmCustomer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//save the customer information in database
void __fastcall TfrmCustomer::btnSaveClick(TObject *Sender)
{
	if(this->btnSave->Caption == "Close")
	{
        frmCustomer->Close();
	}
	else
	{
		//when first name textbox is empty
		if(this->txtFirstName->Text.Trim() == "")
		{
			ShowMessage("Please enter valid first name!");
		}
		//when last name textbox is empty
		else if(this->txtLastName->Text.Trim() == "")
		{
			ShowMessage("Please enter valid last name!");
		}
		//when mobile number textbox is empty
		else if(this->txtMobileNumber->Text.Trim() == "")
		{
			ShowMessage("Please enter valid mobile number!");
		}
		//when the mobile number length is less than 8 characters
		else if(this->txtMobileNumber->Text.Length() < 8)
		{
			ShowMessage("Please enter valid mobile number!");
		}
		//when all the fields are filled in the form
		else
		{
			TADOQuery* ADOQuery;
			/* SQL Query to insert the customer data into customer table*/
			String SQLStr = "INSERT INTO Customer (first_name,last_name, \
							mobile_number) VALUES ('"+this->txtFirstName->Text\
							+ "', '" + this->txtLastName->Text + "','"
							+ this->txtMobileNumber->Text + "');";
			ADOQuery = new TADOQuery(this);
			ADOQuery->Connection = DataBaseModule->DBConnection;

			ADOQuery->Prepared = true;
			ADOQuery->SQL->Clear();
			ADOQuery->SQL->Add(SQLStr);
			try
			{
				ADOQuery->ExecSQL(); // this will save the customer record in database
				ADOQuery->Close();
				frmCustomerList->DataSet_Customer->Active = false;
				frmCustomerList->DataSet_Customer->Active = true;
				frmCustomerList->DataSet_Customer->Refresh();

				int rowCounter = 1;
				frmCustomerList->gridCustomerList->RowCount =
								DataBaseModule->ADOTable_Customer->RecordCount + 1;

				while (!DataBaseModule->ADOTable_Customer->Eof)
				{
					frmCustomerList->gridCustomerList->Cells[0][rowCounter] =
								frmCustomerList->DataSet_Customer->
								FieldByName("customer_id")->AsString;
					frmCustomerList->gridCustomerList->Cells[1][rowCounter] =
								frmCustomerList->DataSet_Customer->
								FieldByName("first_name")->AsString;
					frmCustomerList->gridCustomerList->Cells[2][rowCounter] =
								frmCustomerList->DataSet_Customer->
								FieldByName("last_name")->AsString;
					frmCustomerList->gridCustomerList->Cells[3][rowCounter] =
								frmCustomerList->DataSet_Customer->
								FieldByName("mobile_number")->AsString;
					rowCounter++;

					frmCustomerList->DataSet_Customer->Next();
				}
				frmCustomerList->gridCustomerList->Refresh();
				frmCustomerList->DataSet_Customer->First();

				ShowMessage("Record Saved");
				frmCustomer->Close();

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
void __fastcall TfrmCustomer::FormShow(TObject *Sender)
{
    //when click on Grid data from list page
	if(this->txtFirstName->Text != "")
	{
		this->txtFirstName->Enabled = false;
		this->txtLastName->Enabled = false;
		this->txtMobileNumber->Enabled = false;
		this->btnSave->Caption = "Close";
	}
    //when click on Add button
	else
	{
		this->txtFirstName->Enabled = true;
		this->txtLastName->Enabled = true;
		this->txtMobileNumber->Enabled = true;
		this->btnSave->Caption = "Save";
	}
}
//---------------------------------------------------------------------------
