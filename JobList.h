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
	TButton *BtnAddJob;
	TStringGrid *gridJobList;
	TADODataSet *DataSet_Job;
	void __fastcall BtnAddJobClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall gridJobListSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);

private:	// User declarations
public:		// User declarations
	__fastcall TfmrJobList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmrJobList *fmrJobList;
//---------------------------------------------------------------------------
#endif
