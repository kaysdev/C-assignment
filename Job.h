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
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TLabel *lblStartTime;
	TLabel *lblEndTime;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TTabSheet *TabSheet1;
	TLabel *lblCustomer;
	TLabel *lblDescription;
	TLabel *lblStatus;
	TLabel *lblAssigned;
	TLabel *lblJobNumber;
	TEdit *txtJob;
	TDBLookupComboBox *ddlCustomer;
	TADOTable *ADOTable_customer;
	TDataSource *DataSource_Customer;
	TADOTable *ADOTable_Status;
	TDataSource *DataSource_Status;
	TDBLookupComboBox *ddlStatus;
	TDBLookupComboBox *ddlAssigned;
	TADOTable *ADOTable_assigned;
	TDataSource *DataSource_assigned;
	TMemo *memo1;
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmJob(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmJob *frmJob;
//---------------------------------------------------------------------------
#endif
