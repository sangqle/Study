using QuanLyQuanCafe.DAO;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuanLyQuanCafe
{
    public partial class fAdmin : Form
    {
        public fAdmin()
        {
            InitializeComponent();
            LoadComponents();
        }

        void LoadComponents()
        {
            LoadDateTimePickerBill();
            LoadListBillByDate(dtpkFromDate.Value, dtpkToDate.Value);
            LoadListFood();
            LoadListAccount();
            LoadTableList();
            AddFoodBinding();
            GetListCategories();
            AddCategoryBinding();
            AddTableBiding();
            AddAccountBinding();
        }

        private void fAdmin_Load(object sender, EventArgs e)
        {

        }
        void LoadDateTimePickerBill()
        {
            DateTime today = DateTime.Now;
            dtpkFromDate.Value = new DateTime(today.Year, today.Month, 1);
            dtpkToDate.Value = dtpkFromDate.Value.AddMonths(1).AddDays(-1);
        }
        void LoadListBillByDate(DateTime checkIn, DateTime checkOut)
        {
            dtgvBill.DataSource = BillDAO.Instance.GetBillListByDate(checkIn, checkOut);
        }
        private void btnViewBill_Click(object sender, EventArgs e)
        {
            LoadListBillByDate(dtpkFromDate.Value, dtpkToDate.Value);

        }

        private void dtgvBill_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        // Binding Datasource
        void AddFoodBinding()
        {
            txbFoodName.DataBindings.Add(new Binding("Text", dtgvFood.DataSource, "Name"));
        }

        void AddCategoryBinding()
        {
            txbCategoryID.DataBindings.Add(new Binding("Text", dtgvCategory.DataSource, "id"));
            txbCategoryName.DataBindings.Add(new Binding("Text", dtgvCategory.DataSource, "Name"));
            
        }

        void AddTableBiding()
        {
            txbTableName.DataBindings.Add(new Binding("Text", dtgvTable.DataSource, "Name"));
            txbTableID.DataBindings.Add(new Binding("Text", dtgvTable.DataSource, "id"));

        }

        void AddAccountBinding()
        {
            txbUserName.DataBindings.Add(new Binding("Text", dtgvAccount.DataSource, "UserName"));
            txbDisplayName.DataBindings.Add(new Binding("Text", dtgvAccount.DataSource, "DisplayName"));
        }


        void LoadListFood()
        {
            dtgvFood.DataSource = FoodDAO.Instance.GetListFood();
        }
        private void btnShowFood_Click(object sender, EventArgs e)
        {
            LoadListFood();
        }

        void LoadListAccount()
        {
            dtgvAccount.DataSource = AccountDAO.Instance.GetListAccount();
        }
        private void btnShowAccount_Click(object sender, EventArgs e)
        {
            LoadListAccount();
        }

        void LoadTableList()
        {
            dtgvTable.DataSource = TableDAO.Instance.LoadTableList();
        }

        private void btnShowTable_Click(object sender, EventArgs e)
        {
            LoadTableList();
        }

        void GetListCategories()
        {
            dtgvCategory.DataSource = CategoryDAO.Instance.GetListCategories();
        }
        private void btnShowCategory_Click(object sender, EventArgs e)
        {
            GetListCategories();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
