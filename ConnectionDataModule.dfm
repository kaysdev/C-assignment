object DataBaseModule: TDataBaseModule
  OldCreateOrder = False
  Height = 362
  Width = 388
  object DBConnection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=Firewall#121;Persist Security Info=' +
      'True;User ID=sa;Initial Catalog=Test;Data Source=KAYS-LPT-15;Use' +
      ' Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Wo' +
      'rkstation ID=KAYS-LPT-15;Use Encryption for Data=False;Tag with ' +
      'column collation when possible=False'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 32
    Top = 8
  end
  object ADOTable_login: TADOTable
    Connection = DBConnection
    TableName = 'login'
    Left = 128
    Top = 8
  end
  object ADOTable_Customer: TADOTable
    Connection = DBConnection
    TableName = 'Customer'
    Left = 240
    Top = 8
  end
  object ADOTable_Status: TADOTable
    Connection = DBConnection
    TableName = 'Status'
    Left = 32
    Top = 80
  end
end
