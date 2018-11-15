//---------------------------------------------------------------------------

#ifndef ConnectionDataModuleH
#define ConnectionDataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataBaseModule : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *DBConnection;
	TADOTable *ADOTable_login;
	TADOTable *ADOTable_Customer;
	TADOTable *ADOTable_Status;
private:	// User declarations
public:		// User declarations
	__fastcall TDataBaseModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataBaseModule *DataBaseModule;
//---------------------------------------------------------------------------
#endif
