//---------------------------------------------------------------------------

#ifndef CustomerListH
#define CustomerListH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmCustomerList : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TButton *btnAddNew;
	TStringGrid *gridCustomerList;
	TADOTable *ADOTable1;
	void __fastcall btnAddNewClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall gridCustomerListSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmCustomerList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCustomerList *frmCustomerList;
//---------------------------------------------------------------------------
#endif
