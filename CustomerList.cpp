//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CustomerList.h"
#include "Customer.h"
#include "ConnectionDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCustomerList *frmCustomerList;
//---------------------------------------------------------------------------
__fastcall TfrmCustomerList::TfrmCustomerList(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//on click on Add new customer button
void __fastcall TfrmCustomerList::btnAddNewClick(TObject *Sender)
{
	frmCustomer->txtFirstName->Text = "";
	frmCustomer->txtLastName->Text = "";
	frmCustomer->txtMobileNumber->Text = "";
	frmCustomer->ShowModal();
}
//---------------------------------------------------------------------------

//on click on cell of TStringGrid
void __fastcall TfrmCustomerList::gridCustomerListSelectCell(TObject *Sender,
		int ACol, int ARow, bool &CanSelect)
{
	if(ARow != 0)  // if the header row is not selected
	{
		frmCustomer->txtFirstName->Text = gridCustomerList->Cells[1][ARow];
		frmCustomer->txtLastName->Text = gridCustomerList->Cells[2][ARow];
		frmCustomer->txtMobileNumber->Text = gridCustomerList->Cells[3][ARow];
		frmCustomer->ShowModal();
	}
}
void __fastcall TfrmCustomerList::FormShow(TObject *Sender)
{
	//to display the column name in TStringGrid
	DataBaseModule->ADOTable_Customer->Active = false;
	DataBaseModule->ADOTable_Customer->Active = true;
	gridCustomerList->Cells[0][0] = "Customer Id";
	gridCustomerList->ColWidths[0] = 80;
	gridCustomerList->Cells[1][0] = "First Name";
	gridCustomerList->ColWidths[1] = 80;
	gridCustomerList->Cells[2][0] = "Last Name";
	gridCustomerList->ColWidths[2] = 80;
	gridCustomerList->Cells[3][0] = "Mobile Number";
	gridCustomerList->ColWidths[3] = 100;
	int rowCounter = 1;
    DataSet_Customer->Active = true;
	gridCustomerList->RowCount = DataSet_Customer->RecordCount + 1;
	//to fill customer data in the TStringGrid
	while (!DataSet_Customer->Eof)
	{
		gridCustomerList->Cells[0][rowCounter] =
					DataSet_Customer->FieldByName("customer_id")->AsString;
		gridCustomerList->Cells[1][rowCounter] =
					DataSet_Customer->FieldByName("first_name")->AsString;
		gridCustomerList->Cells[2][rowCounter] =
					DataSet_Customer->FieldByName("last_name")->AsString;
		gridCustomerList->Cells[3][rowCounter] =
					DataSet_Customer->FieldByName("mobile_number")->AsString;
		rowCounter++;
		DataSet_Customer->Next();
	}

	DataSet_Customer->First();
}
//---------------------------------------------------------------------------

