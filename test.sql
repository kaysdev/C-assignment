USE [Test]
GO
/****** Object:  Table [dbo].[Customer]    Script Date: 11/12/2018 18:49:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Customer](
	[customer_id] [int] IDENTITY(1,1) NOT NULL,
	[first_name] [varchar](30) NULL,
	[last_name] [varchar](30) NULL,
	[mobile_number] [varchar](20) NULL,
	[is_active] [bit] NULL CONSTRAINT [DF_Customer_isActive]  DEFAULT ((1)),
	[entry_date] [datetime] NULL CONSTRAINT [DF_Customer_entry_date]  DEFAULT (getdate()),
	[last_update_date] [datetime] NULL CONSTRAINT [DF_Customer_last_update_date]  DEFAULT (getdate()),
 CONSTRAINT [PK_Customer] PRIMARY KEY CLUSTERED 
(
	[customer_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Job]    Script Date: 11/12/2018 18:49:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Job](
	[job_id] [int] IDENTITY(1,1) NOT NULL,
	[job_number] [int] NULL,
	[customer_id] [int] NULL,
	[job_description] [text] NULL,
	[status_id] [int] NULL,
	[assigned_to] [int] NULL,
	[time_spent] [float] NULL,
	[entry_date] [datetime] NULL,
	[last_update_date] [datetime] NULL,
 CONSTRAINT [PK_Job] PRIMARY KEY CLUSTERED 
(
	[job_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[login]    Script Date: 11/12/2018 18:49:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[login](
	[login_id] [int] IDENTITY(1,1) NOT NULL,
	[user_name] [varchar](50) NULL,
	[password] [varchar](20) NULL,
	[is_active] [bit] NULL,
	[entry_date] [datetime] NULL CONSTRAINT [DF_login_entry_date]  DEFAULT (getdate()),
	[last_update_date] [datetime] NULL CONSTRAINT [DF_login_last_update_date]  DEFAULT (getdate()),
 CONSTRAINT [PK_login] PRIMARY KEY CLUSTERED 
(
	[login_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Status]    Script Date: 11/12/2018 18:49:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Status](
	[status_id] [int] IDENTITY(1,1) NOT NULL,
	[status_name] [varchar](20) NULL,
	[is_active] [bit] NULL,
	[entry_date] [datetime] NULL CONSTRAINT [DF_Status_entry_date]  DEFAULT (getdate()),
	[last_update_date] [datetime] NULL CONSTRAINT [DF_Status_last_update_date]  DEFAULT (getdate()),
 CONSTRAINT [PK_Status] PRIMARY KEY CLUSTERED 
(
	[status_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Customer] ON 

INSERT [dbo].[Customer] ([customer_id], [first_name], [last_name], [mobile_number], [is_active], [entry_date], [last_update_date]) VALUES (1, N'Sunita', N'Saloni', N'9988010630', 1, CAST(N'2018-11-05 20:50:04.113' AS DateTime), CAST(N'2018-11-05 20:50:04.113' AS DateTime))
INSERT [dbo].[Customer] ([customer_id], [first_name], [last_name], [mobile_number], [is_active], [entry_date], [last_update_date]) VALUES (2, N'Saloni', N'Suneja', N'7009732182', 1, CAST(N'2018-11-05 20:50:35.293' AS DateTime), CAST(N'2018-11-05 20:50:35.293' AS DateTime))
INSERT [dbo].[Customer] ([customer_id], [first_name], [last_name], [mobile_number], [is_active], [entry_date], [last_update_date]) VALUES (3, N'Bill', N'Burch', N'98988887889', 1, CAST(N'2018-11-05 20:57:08.667' AS DateTime), CAST(N'2018-11-05 20:57:08.667' AS DateTime))
SET IDENTITY_INSERT [dbo].[Customer] OFF
SET IDENTITY_INSERT [dbo].[login] ON 

INSERT [dbo].[login] ([login_id], [user_name], [password], [is_active], [entry_date], [last_update_date]) VALUES (1, N'saloni', N'123', 1, CAST(N'2018-10-31 11:11:00.000' AS DateTime), NULL)
INSERT [dbo].[login] ([login_id], [user_name], [password], [is_active], [entry_date], [last_update_date]) VALUES (2, N'sunita', N'123', 1, CAST(N'2018-10-31 12:00:00.000' AS DateTime), NULL)
INSERT [dbo].[login] ([login_id], [user_name], [password], [is_active], [entry_date], [last_update_date]) VALUES (3, N'chinmaya', N'321', 1, CAST(N'2018-10-31 12:30:00.000' AS DateTime), NULL)
INSERT [dbo].[login] ([login_id], [user_name], [password], [is_active], [entry_date], [last_update_date]) VALUES (4, N'vatish', N'4321', 1, CAST(N'2018-10-31 16:50:29.853' AS DateTime), CAST(N'2018-10-31 16:50:29.853' AS DateTime))
SET IDENTITY_INSERT [dbo].[login] OFF
SET IDENTITY_INSERT [dbo].[Status] ON 

INSERT [dbo].[Status] ([status_id], [status_name], [is_active], [entry_date], [last_update_date]) VALUES (1, N'Open', 1, NULL, NULL)
INSERT [dbo].[Status] ([status_id], [status_name], [is_active], [entry_date], [last_update_date]) VALUES (2, N'Closed', 1, NULL, NULL)
INSERT [dbo].[Status] ([status_id], [status_name], [is_active], [entry_date], [last_update_date]) VALUES (3, N'In Progress', 1, NULL, NULL)
SET IDENTITY_INSERT [dbo].[Status] OFF
ALTER TABLE [dbo].[Job] ADD  CONSTRAINT [DF_Job_entry_date]  DEFAULT (getdate()) FOR [entry_date]
GO
ALTER TABLE [dbo].[Job] ADD  CONSTRAINT [DF_Job_last_update_date]  DEFAULT (getdate()) FOR [last_update_date]
GO
ALTER TABLE [dbo].[Job]  WITH CHECK ADD  CONSTRAINT [FK_Job_Customer] FOREIGN KEY([customer_id])
REFERENCES [dbo].[Customer] ([customer_id])
GO
ALTER TABLE [dbo].[Job] CHECK CONSTRAINT [FK_Job_Customer]
GO
ALTER TABLE [dbo].[Job]  WITH CHECK ADD  CONSTRAINT [FK_Job_login] FOREIGN KEY([job_id])
REFERENCES [dbo].[login] ([login_id])
GO
ALTER TABLE [dbo].[Job] CHECK CONSTRAINT [FK_Job_login]
GO
ALTER TABLE [dbo].[Job]  WITH CHECK ADD  CONSTRAINT [FK_Job_Status] FOREIGN KEY([status_id])
REFERENCES [dbo].[Status] ([status_id])
GO
ALTER TABLE [dbo].[Job] CHECK CONSTRAINT [FK_Job_Status]
GO
EXEC sys.sp_addextendedproperty @name=N'MS_Description', @value=N'0 for inactive and 1 for active' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'Customer', @level2type=N'COLUMN',@level2name=N'is_active'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_Description', @value=N'' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'Job', @level2type=N'COLUMN',@level2name=N'status_id'
GO
