using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql.Data.MySqlClient;
using System.Configuration;
using System.Data;

namespace AspNet_Homework
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        static string connString = ConfigurationManager.ConnectionStrings["LibraryDB"].ToString();
        MySqlConnection connection = new MySqlConnection(connString);
        MySqlCommand command;
        MySqlDataAdapter dataAdapter; // cursor

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!this.IsPostBack)
            {
                reloadData();
            }
        }

        private void reloadData()
        {
            // Fill Data Grid View.
            command = new MySqlCommand("SELECT * FROM BOOK", connection);
            dataAdapter = new MySqlDataAdapter(command);
            DataTable dt = new DataTable();
            dataAdapter.Fill(dt);
            GridView1.DataSource = dt;
            GridView1.DataBind();

            // Fill Drop Down List with Book Name.
            command = new MySqlCommand("SELECT BookName, Author FROM BOOK", connection);
            dataAdapter = new MySqlDataAdapter(command);
            DropDownList1.DataSource = dt;
            DropDownList1.DataTextField = "BookName";
            DropDownList1.DataValueField = "Author";
            DropDownList1.DataBind();
            DropDownList1.Items.Insert(0, new ListItem("Select Book!", "None!"));

            // Fill Drop Down List with Book ID.
            command = new MySqlCommand("SELECT ISBN FROM BOOK", connection);
            dataAdapter = new MySqlDataAdapter(command);
            DropDownList2.DataSource = dt;
            DropDownList2.DataTextField = "ISBN";
            DropDownList2.DataValueField = "ISBN";
            DropDownList2.DataBind();
            DropDownList2.Items.Insert(0, new ListItem("Select ISBN!", "None!"));
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string authorName = DropDownList1.SelectedItem.Value;
            Label1.Text = authorName;
        }

        protected void DropDownList2_SelectedIndexChanged(object sender, EventArgs e)
        {
            string bookID = DropDownList2.SelectedItem.Text;
            String query = "DELETE FROM book WHERE ISBN=" + bookID + "";

            try
            {
                command = new MySqlCommand(query, connection);
                connection.Open();
                command.ExecuteNonQuery();

                Label2.Text = "Book was successfully deleted!";
            }

            catch
            {
                Label2.Text = "Book was not deleted! There is some error.";
            }

            finally
            {
                connection.Close();
                reloadData();
            }
        }
    }
}