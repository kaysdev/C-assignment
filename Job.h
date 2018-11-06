//---------------------------------------------------------------------------

#ifndef JobH
#define JobH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmJob : public TForm
{
__published:	// IDE-managed Components
	TButton *btnSave;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TADOTable *ADOTable2;
	TADOTable *ADOTable3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TLabel *lblCustomer;
	TLabel *lblDescription;
	TComboBox *ddlStatus;
	TLabel *lblStatus;
	TLabel *lblAssigned;
	TComboBox *ddlUser;
	TEdit *txtJob;
	TLabel *lblJobNumber;
	TLabel *lblStartTime;
	TLabel *lblEndTime;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TDataSource *DataSource1;
	TDBLookupComboBox *ddlCustomer;
	TMemo *memo1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmJob(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmJob *frmJob;
//---------------------------------------------------------------------------
#endif
