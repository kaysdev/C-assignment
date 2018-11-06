//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Login.cpp", frmLogin);
USEFORM("JobList.cpp", fmrJobList);
USEFORM("Dashboard.cpp", frmDashboard);
USEFORM("CustomerList.cpp", frmCustomerList);
USEFORM("Customer.cpp", frmCustomer);
USEFORM("Job.cpp", frmJob);
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
