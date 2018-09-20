<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="AspNet_Homework.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Hüseyin Eren Güler</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
             <asp:Panel ID="Panel1" runat="server" GroupingText="EXAMPLE DATABASE" Width="750px">
                 <p><asp:GridView ID="GridView1" runat="server" Height="25px" HorizontalAlign="Center" Width="700px"></asp:GridView></p>
             </asp:Panel><br />

            <asp:Panel ID="Panel2" runat="server" GroupingText="OPERATIONS" Width="750px">
                <p>Show Author Name: <asp:DropDownList ID="DropDownList1" runat="server" 
                                  Height="25px" Width="200px" 
                                  OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged"
                                  ViewStateMode="Enabled" EnableViewState="true"
                                  AutoPostBack="true"></asp:DropDownList></p>
                <p>The Author is: <asp:Label ID="Label1" Text="None!" runat="server"></asp:Label></p><br />

                <p>Delete Book: <asp:DropDownList ID="DropDownList2" runat="server" 
                                  Height="25px" Width="200px" 
                                  OnSelectedIndexChanged="DropDownList2_SelectedIndexChanged"
                                  ViewStateMode="Enabled" EnableViewState="true"
                                  AutoPostBack="true"></asp:DropDownList></p>
                <p>Status: <asp:Label ID="Label2" Text="None!" runat="server"></asp:Label></p>
            </asp:Panel><br />

            <asp:Panel ID="Panel3" runat="server" HorizontalAlign="Center" GroupingText="Programming Languages 206 Course, C#-Asp.Net Homework" Width="750px">
                <p style="color:red;"> <i> Hüseyin Eren Güler </i> </p>
                <p style="color:red;"> <i> 15050111014 </i> </p>
                <p style="color:red;"> <i> Computer Engineering </i> </p>
                <p style="color:black;"> <i> 26/05/2018 </i> </p>
            </asp:Panel><br />
        </div>
    </form>       
    </body>
</html>