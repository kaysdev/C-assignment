//---------------------------------------------------------------------------

#ifndef CustomerH
#define CustomerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TfrmCustomer : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblFirstName;
	TLabel *lblLastName;
	TLabel *Label1;
	TEdit *txtFirstName;
	TEdit *txtLastName;
	TEdit *txtMobileNumber;
	TButton *btnSave;
	TADOConnection *ADOConnection1;
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmCustomer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCustomer *frmCustomer;
//---------------------------------------------------------------------------
#endif
