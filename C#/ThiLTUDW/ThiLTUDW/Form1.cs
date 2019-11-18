using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThiLTUDW
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnTinhTien_Click(object sender, EventArgs e)
        {
            double csDienCu = Convert.ToDouble(tbxDienCu.Text);
            double csDienMoi = Convert.ToDouble(tbxDienMoi.Text);

            if (csDienMoi < csDienCu || csDienCu < 0 || csDienMoi < 0)
            {
                MessageBox.Show("Chi số điện không hợp lệ. vui lòng nhập lại");
            }

            double thueBaoDienThe = 1000;
            double dinhMucDien = 50;
            double muc1 = 450;
            double muc2 = 700;
            double muc3 = 910;
            double muc4 = 1200;

            double csDienTieuThu = csDienMoi - csDienCu;
            double csVuotDinhMuc = csDienTieuThu - dinhMucDien;
            double tienTrongHanMuc = csDienTieuThu*muc1;

            double tienMuc2 = 0;
            double tienMuc3 = 0;
            double tienMuc4 = 0;
            double tienVuotDinhMuc = 0;

            //csVuotDinhMuc = 5 7
            if(csVuotDinhMuc < 0) {csVuotDinhMuc = 0;}
            else
            {
                if (csVuotDinhMuc <= 50)
                {
                    tienMuc2 = csVuotDinhMuc * muc2;
                }
                else if (csVuotDinhMuc > 50 && csVuotDinhMuc <= 100)
                {
                    tienMuc3 = (csVuotDinhMuc - 50) * muc3;
                    tienMuc2 = 50 * muc2;
                }
                else if (csVuotDinhMuc > 100)
                {
                    tienMuc4 = (csVuotDinhMuc - 100) * muc4;
                    tienMuc3 = 50 * muc3;
                    tienMuc2 = 50 * muc2;
                }
            }
           

            tienVuotDinhMuc = tienMuc2 + tienMuc3 + tienMuc4;
            tbxDienTieuThu.Text = Convert.ToString(csDienTieuThu);
            tbxPhiThueBao.Text = "1000";
            tbxVuotDinhMuc.Text = Convert.ToString(csVuotDinhMuc);
            tbxTienVuotDinhMuc.Text = Convert.ToString(tienVuotDinhMuc);

           
            tbxTongTien.Text =  Convert.ToString(tienVuotDinhMuc + tienTrongHanMuc + thueBaoDienThe);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
    }
}
