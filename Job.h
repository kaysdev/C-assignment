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
	TDBLookupComboBox *ddlCustomer;
	TDataSource *DataSource_Customer;
	TDataSource *DataSource_Status;
	TDBLookupComboBox *ddlStatus;
	TDBLookupComboBox *ddlAssigned;
	TDataSource *DataSource_assigned;
	TPageControl *Tab;
	TTabSheet *Time_Tab;
	TLabel *lblStartTime;
	TLabel *lblEndTime;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TTabSheet *Detail_Tab;
	TLabel *lblCustomer;
	TLabel *lblDescription;
	TLabel *lblStatus;
	TLabel *lblAssigned;
	TLabel *lblJobNumber;
	TMemo *memo1;
	TEdit *txtJob;
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
