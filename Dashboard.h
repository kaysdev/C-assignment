//---------------------------------------------------------------------------

#ifndef DashboardH
#define DashboardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmDashboard : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Jobs1;
	TMenuItem *Customer1;
	TMenuItem *Jobs2;
	void __fastcall Customer1Click(TObject *Sender);
	void __fastcall Jobs2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmDashboard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDashboard *frmDashboard;
//---------------------------------------------------------------------------
#endif
