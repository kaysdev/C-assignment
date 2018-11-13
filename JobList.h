//---------------------------------------------------------------------------

#ifndef JobListH
#define JobListH
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
class TfmrJobList : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TAutoIncField *ADOQuery1job_id;
	TIntegerField *ADOQuery1job_number;
	TMemoField *ADOQuery1job_description;
	TStringField *ADOQuery1customer_name;
	TStringField *ADOQuery1mobile_number;
	TStringField *ADOQuery1user_name;
	TFloatField *ADOQuery1time_spent;
	TStringField *ADOQuery1status_name;
	TStringGrid *gridJobList;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmrJobList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmrJobList *fmrJobList;
//---------------------------------------------------------------------------
#endif
