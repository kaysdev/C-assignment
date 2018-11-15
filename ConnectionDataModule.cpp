//---------------------------------------------------------------------------


#pragma hdrstop

#include "ConnectionDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataBaseModule *DataBaseModule;
//---------------------------------------------------------------------------
__fastcall TDataBaseModule::TDataBaseModule(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

