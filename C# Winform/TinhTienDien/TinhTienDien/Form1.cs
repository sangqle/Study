using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TinhTienDien
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

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            pnlTtThanhtoan.Visible = false;
        }

        private void pnlTtThanhtoan_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Tinh tien
            try {
                double thueBaoDienKe = Convert.ToDouble(txtThuebaodienke.Text);
                double chisoDienCu = Convert.ToDouble(txtChisodiencu.Text);
                double chisoDienMoi = Convert.ToDouble(txtChisodienmoi.Text);
                double dinhmuc = Convert.ToDouble(txtDinhmuc.Text);

                if (chisoDienCu > chisoDienMoi || chisoDienCu < 0 || chisoDienMoi < 0 || dinhmuc < 0 || thueBaoDienKe < 0)
                {
                    MessageBox.Show("Chỉ số điện không hợp lệ, Các chỉ số không được âm.");
                }
                double dienTieuThu = chisoDienMoi - chisoDienCu;
                double chisoVuotDinhmuc = dienTieuThu - dinhmuc;
                double tongTien = 0;
                if (chisoVuotDinhmuc > 0 && chisoVuotDinhmuc <= 50) {
                    tongTien = dinhmuc * 450 + chisoVuotDinhmuc * 700;
                } else if(chisoVuotDinhmuc > 50 && chisoVuotDinhmuc < 100) {
                    tongTien = (dinhmuc * 450) + (50 * 700) + (chisoVuotDinhmuc - 50) * 910;
                }
                else if (chisoVuotDinhmuc >= 100)
                {
                    tongTien = (dinhmuc * 450) + (50 * 700) + (50 * 910) + (chisoVuotDinhmuc - 100) * 1200;
                }
                else
                {
                    tongTien = dienTieuThu * 450;
                }
                
                // Hiển thị
                txtKhachhang.Text = txtHoten.Text;
                txtDientieuthu.Text = Convert.ToString(dienTieuThu);
                txtTongtien.Text = Convert.ToString(tongTien + thueBaoDienKe);

            }
            catch (Exception err) {
                MessageBox.Show("Thông tin không hợp lệ! Vui lòng nhập đầy đủ thông tin!!!", "Thông báo");
            }

            pnlTtThanhtoan.Visible = true;
        }

        private void txtTongtien_Click(object sender, EventArgs e)
        {

        }

        private void txtThuebaodienke_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtChisodiencu_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtChisodienmoi_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
