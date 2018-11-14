//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("JobList.cpp", fmrJobList);
USEFORM("Login.cpp", frmLogin);
USEFORM("Customer.cpp", frmCustomer);
USEFORM("CustomerList.cpp", frmCustomerList);
USEFORM("Dashboard.cpp", frmDashboard);
USEFORM("Job.cpp", frmJob);
USEFORM("ConnectionDataModule.cpp", DataModule1); /* TDataModule: File Type */
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfrmLogin), &frmLogin);
		Application->CreateForm(__classid(TfrmDashboard), &frmDashboard);
		Application->CreateForm(__classid(TfmrJobList), &fmrJobList);
		Application->CreateForm(__classid(TfrmCustomerList), &frmCustomerList);
		Application->CreateForm(__classid(TfrmCustomer), &frmCustomer);
		Application->CreateForm(__classid(TfrmJob), &frmJob);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
