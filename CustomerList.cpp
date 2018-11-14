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
	ADOTable1->Active = false;
	ADOTable1->Active = true;
	gridCustomerList->Cells[0][0] = "Customer Id";
	gridCustomerList->ColWidths[0] = 80;
	gridCustomerList->Cells[1][0] = "First Name";
	gridCustomerList->ColWidths[1] = 80;
	gridCustomerList->Cells[2][0] = "Last Name";
	gridCustomerList->ColWidths[2] = 80;
	gridCustomerList->Cells[3][0] = "Mobile Number";
	gridCustomerList->ColWidths[3] = 100;
	int rowCounter = 1;
	gridCustomerList->RowCount = ADOTable1->RecordCount+1;
	//to fill customer data in the TStringGrid
	while (!ADOTable1->Eof)
	{
		gridCustomerList->Cells[0][rowCounter] =
					ADOTable1->FieldByName("customer_id")->AsString;
		gridCustomerList->Cells[1][rowCounter] =
					ADOTable1->FieldByName("first_name")->AsString;
		gridCustomerList->Cells[2][rowCounter] =
					ADOTable1->FieldByName("last_name")->AsString;
		gridCustomerList->Cells[3][rowCounter] =
					ADOTable1->FieldByName("mobile_number")->AsString;
		rowCounter++;
		ADOTable1->Next();
	}

	ADOTable1->First();
}
//---------------------------------------------------------------------------

