namespace TinhTienDien
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.pnlTt = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.pnlTtKhachhang = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.txtHoten = new System.Windows.Forms.TextBox();
            this.txtThuebaodienke = new System.Windows.Forms.TextBox();
            this.txtChisodiencu = new System.Windows.Forms.TextBox();
            this.txtChisodienmoi = new System.Windows.Forms.TextBox();
            this.txtDinhmuc = new System.Windows.Forms.TextBox();
            this.pnlTtThanhtoan = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.btnTinhtien = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.txtKhachhang = new System.Windows.Forms.Label();
            this.txtDientieuthu = new System.Windows.Forms.Label();
            this.txtTongtien = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.pnlTt.SuspendLayout();
            this.pnlTtThanhtoan.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.btnTinhtien);
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.txtDinhmuc);
            this.panel1.Controls.Add(this.txtChisodienmoi);
            this.panel1.Controls.Add(this.txtChisodiencu);
            this.panel1.Controls.Add(this.txtThuebaodienke);
            this.panel1.Controls.Add(this.txtHoten);
            this.panel1.Controls.Add(this.label10);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.pnlTtKhachhang);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(306, 291);
            this.panel1.TabIndex = 0;
            // 
            // pnlTt
            // 
            this.pnlTt.Controls.Add(this.pnlTtThanhtoan);
            this.pnlTt.Controls.Add(this.label8);
            this.pnlTt.Controls.Add(this.label7);
            this.pnlTt.Controls.Add(this.label6);
            this.pnlTt.Controls.Add(this.label1);
            this.pnlTt.Location = new System.Drawing.Point(324, 12);
            this.pnlTt.Name = "pnlTt";
            this.pnlTt.Size = new System.Drawing.Size(271, 291);
            this.pnlTt.TabIndex = 1;
            this.pnlTt.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(79, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(110, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Thông tin Thanh toán";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // pnlTtKhachhang
            // 
            this.pnlTtKhachhang.AutoSize = true;
            this.pnlTtKhachhang.Location = new System.Drawing.Point(85, 16);
            this.pnlTtKhachhang.Name = "pnlTtKhachhang";
            this.pnlTtKhachhang.Size = new System.Drawing.Size(112, 13);
            this.pnlTtKhachhang.TabIndex = 0;
            this.pnlTtKhachhang.Text = "Thông tin khách hàng";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(20, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(43, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Họ Tên";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(20, 90);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(91, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Tiền thuê điện kế";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(20, 127);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Chỉ số điện cũ";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(22, 164);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(79, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Chỉ số điện mới";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(32, 51);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(65, 13);
            this.label6.TabIndex = 1;
            this.label6.Text = "Khách hàng";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(35, 90);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(67, 13);
            this.label7.TabIndex = 2;
            this.label7.Text = "Điện tiêu thụ";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(35, 127);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(52, 13);
            this.label8.TabIndex = 3;
            this.label8.Text = "Tổng tiền";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(22, 203);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(69, 13);
            this.label10.TabIndex = 5;
            this.label10.Text = "Kw định mức";
            // 
            // txtHoten
            // 
            this.txtHoten.Location = new System.Drawing.Point(147, 51);
            this.txtHoten.Name = "txtHoten";
            this.txtHoten.Size = new System.Drawing.Size(156, 20);
            this.txtHoten.TabIndex = 6;
            this.txtHoten.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // txtThuebaodienke
            // 
            this.txtThuebaodienke.Location = new System.Drawing.Point(147, 90);
            this.txtThuebaodienke.Name = "txtThuebaodienke";
            this.txtThuebaodienke.Size = new System.Drawing.Size(156, 20);
            this.txtThuebaodienke.TabIndex = 7;
            this.txtThuebaodienke.TextChanged += new System.EventHandler(this.txtThuebaodienke_TextChanged);
            // 
            // txtChisodiencu
            // 
            this.txtChisodiencu.Location = new System.Drawing.Point(147, 127);
            this.txtChisodiencu.Name = "txtChisodiencu";
            this.txtChisodiencu.Size = new System.Drawing.Size(156, 20);
            this.txtChisodiencu.TabIndex = 8;
            this.txtChisodiencu.TextChanged += new System.EventHandler(this.txtChisodiencu_TextChanged);
            // 
            // txtChisodienmoi
            // 
            this.txtChisodienmoi.Location = new System.Drawing.Point(147, 164);
            this.txtChisodienmoi.Name = "txtChisodienmoi";
            this.txtChisodienmoi.Size = new System.Drawing.Size(156, 20);
            this.txtChisodienmoi.TabIndex = 9;
            this.txtChisodienmoi.TextChanged += new System.EventHandler(this.txtChisodienmoi_TextChanged);
            // 
            // txtDinhmuc
            // 
            this.txtDinhmuc.Location = new System.Drawing.Point(147, 203);
            this.txtDinhmuc.Name = "txtDinhmuc";
            this.txtDinhmuc.Size = new System.Drawing.Size(156, 20);
            this.txtDinhmuc.TabIndex = 10;
            // 
            // pnlTtThanhtoan
            // 
            this.pnlTtThanhtoan.Controls.Add(this.txtTongtien);
            this.pnlTtThanhtoan.Controls.Add(this.txtDientieuthu);
            this.pnlTtThanhtoan.Controls.Add(this.txtKhachhang);
            this.pnlTtThanhtoan.Controls.Add(this.label9);
            this.pnlTtThanhtoan.Location = new System.Drawing.Point(108, 32);
            this.pnlTtThanhtoan.Name = "pnlTtThanhtoan";
            this.pnlTtThanhtoan.Size = new System.Drawing.Size(149, 127);
            this.pnlTtThanhtoan.TabIndex = 4;
            this.pnlTtThanhtoan.Paint += new System.Windows.Forms.PaintEventHandler(this.pnlTtThanhtoan_Paint);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(147, 242);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 11;
            this.button1.Text = "Hủy bỏ";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // btnTinhtien
            // 
            this.btnTinhtien.Location = new System.Drawing.Point(228, 242);
            this.btnTinhtien.Name = "btnTinhtien";
            this.btnTinhtien.Size = new System.Drawing.Size(75, 23);
            this.btnTinhtien.TabIndex = 12;
            this.btnTinhtien.Text = "Tính tiền";
            this.btnTinhtien.UseVisualStyleBackColor = true;
            this.btnTinhtien.Click += new System.EventHandler(this.button2_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(35, 19);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(0, 13);
            this.label9.TabIndex = 10;
            // 
            // txtKhachhang
            // 
            this.txtKhachhang.AutoSize = true;
            this.txtKhachhang.Location = new System.Drawing.Point(21, 19);
            this.txtKhachhang.Name = "txtKhachhang";
            this.txtKhachhang.Size = new System.Drawing.Size(61, 13);
            this.txtKhachhang.TabIndex = 11;
            this.txtKhachhang.Text = "?????????";
            // 
            // txtDientieuthu
            // 
            this.txtDientieuthu.AutoSize = true;
            this.txtDientieuthu.Location = new System.Drawing.Point(24, 57);
            this.txtDientieuthu.Name = "txtDientieuthu";
            this.txtDientieuthu.Size = new System.Drawing.Size(61, 13);
            this.txtDientieuthu.TabIndex = 12;
            this.txtDientieuthu.Text = "?????????";
            // 
            // txtTongtien
            // 
            this.txtTongtien.AutoSize = true;
            this.txtTongtien.Location = new System.Drawing.Point(27, 94);
            this.txtTongtien.Name = "txtTongtien";
            this.txtTongtien.Size = new System.Drawing.Size(61, 13);
            this.txtTongtien.TabIndex = 13;
            this.txtTongtien.Text = "?????????";
            this.txtTongtien.Click += new System.EventHandler(this.txtTongtien_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(607, 315);
            this.Controls.Add(this.pnlTt);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.pnlTt.ResumeLayout(false);
            this.pnlTt.PerformLayout();
            this.pnlTtThanhtoan.ResumeLayout(false);
            this.pnlTtThanhtoan.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel pnlTt;
        private System.Windows.Forms.Label pnlTtKhachhang;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtDinhmuc;
        private System.Windows.Forms.TextBox txtChisodienmoi;
        private System.Windows.Forms.TextBox txtChisodiencu;
        private System.Windows.Forms.TextBox txtThuebaodienke;
        private System.Windows.Forms.TextBox txtHoten;
        private System.Windows.Forms.Panel pnlTtThanhtoan;
        private System.Windows.Forms.Button btnTinhtien;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label txtKhachhang;
        private System.Windows.Forms.Label txtTongtien;
        private System.Windows.Forms.Label txtDientieuthu;
    }
}

