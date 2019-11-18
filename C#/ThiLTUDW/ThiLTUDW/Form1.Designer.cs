namespace ThiLTUDW
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
            this.pnlTinhTienDien = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tbxDienCu = new System.Windows.Forms.TextBox();
            this.tbxDienMoi = new System.Windows.Forms.TextBox();
            this.btnTinhTien = new System.Windows.Forms.Button();
            this.btnHuyBo = new System.Windows.Forms.Button();
            this.pnlKetQua = new System.Windows.Forms.Panel();
            this.tbxDienTieuThu = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.tbxPhiThueBao = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.tbxVuotDinhMuc = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.tbxTienVuotDinhMuc = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.tbxTongTien = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.pnlTinhTienDien.SuspendLayout();
            this.pnlKetQua.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlTinhTienDien
            // 
            this.pnlTinhTienDien.Controls.Add(this.btnHuyBo);
            this.pnlTinhTienDien.Controls.Add(this.btnTinhTien);
            this.pnlTinhTienDien.Controls.Add(this.tbxDienMoi);
            this.pnlTinhTienDien.Controls.Add(this.tbxDienCu);
            this.pnlTinhTienDien.Controls.Add(this.label2);
            this.pnlTinhTienDien.Controls.Add(this.label1);
            this.pnlTinhTienDien.Location = new System.Drawing.Point(12, 12);
            this.pnlTinhTienDien.Name = "pnlTinhTienDien";
            this.pnlTinhTienDien.Size = new System.Drawing.Size(389, 270);
            this.pnlTinhTienDien.TabIndex = 0;
            this.pnlTinhTienDien.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(25, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(102, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "Chỉ số điện cũ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(25, 69);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(132, 18);
            this.label2.TabIndex = 1;
            this.label2.Text = "Chỉ số điện hiện tại";
            // 
            // tbxDienCu
            // 
            this.tbxDienCu.Location = new System.Drawing.Point(205, 26);
            this.tbxDienCu.Name = "tbxDienCu";
            this.tbxDienCu.Size = new System.Drawing.Size(146, 20);
            this.tbxDienCu.TabIndex = 2;
            // 
            // tbxDienMoi
            // 
            this.tbxDienMoi.Location = new System.Drawing.Point(205, 70);
            this.tbxDienMoi.Name = "tbxDienMoi";
            this.tbxDienMoi.Size = new System.Drawing.Size(146, 20);
            this.tbxDienMoi.TabIndex = 3;
            this.tbxDienMoi.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // btnTinhTien
            // 
            this.btnTinhTien.Location = new System.Drawing.Point(288, 114);
            this.btnTinhTien.Name = "btnTinhTien";
            this.btnTinhTien.Size = new System.Drawing.Size(63, 26);
            this.btnTinhTien.TabIndex = 4;
            this.btnTinhTien.Text = "Tính Tiền";
            this.btnTinhTien.UseVisualStyleBackColor = true;
            this.btnTinhTien.Click += new System.EventHandler(this.btnTinhTien_Click);
            // 
            // btnHuyBo
            // 
            this.btnHuyBo.Location = new System.Drawing.Point(205, 114);
            this.btnHuyBo.Name = "btnHuyBo";
            this.btnHuyBo.Size = new System.Drawing.Size(65, 26);
            this.btnHuyBo.TabIndex = 5;
            this.btnHuyBo.Text = "Hủy Bỏ";
            this.btnHuyBo.UseVisualStyleBackColor = true;
            // 
            // pnlKetQua
            // 
            this.pnlKetQua.Controls.Add(this.tbxTongTien);
            this.pnlKetQua.Controls.Add(this.label7);
            this.pnlKetQua.Controls.Add(this.tbxTienVuotDinhMuc);
            this.pnlKetQua.Controls.Add(this.label6);
            this.pnlKetQua.Controls.Add(this.tbxVuotDinhMuc);
            this.pnlKetQua.Controls.Add(this.label5);
            this.pnlKetQua.Controls.Add(this.tbxPhiThueBao);
            this.pnlKetQua.Controls.Add(this.label4);
            this.pnlKetQua.Controls.Add(this.tbxDienTieuThu);
            this.pnlKetQua.Controls.Add(this.label3);
            this.pnlKetQua.Location = new System.Drawing.Point(407, 12);
            this.pnlKetQua.Name = "pnlKetQua";
            this.pnlKetQua.Size = new System.Drawing.Size(316, 270);
            this.pnlKetQua.TabIndex = 1;
            // 
            // tbxDienTieuThu
            // 
            this.tbxDienTieuThu.Location = new System.Drawing.Point(171, 25);
            this.tbxDienTieuThu.Name = "tbxDienTieuThu";
            this.tbxDienTieuThu.Size = new System.Drawing.Size(125, 20);
            this.tbxDienTieuThu.TabIndex = 4;
            this.tbxDienTieuThu.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(17, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(89, 18);
            this.label3.TabIndex = 3;
            this.label3.Text = "Điện tiêu thụ";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // tbxPhiThueBao
            // 
            this.tbxPhiThueBao.Location = new System.Drawing.Point(171, 70);
            this.tbxPhiThueBao.Name = "tbxPhiThueBao";
            this.tbxPhiThueBao.Size = new System.Drawing.Size(125, 20);
            this.tbxPhiThueBao.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(17, 69);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(125, 18);
            this.label4.TabIndex = 5;
            this.label4.Text = "Thuê bao điện thế";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // tbxVuotDinhMuc
            // 
            this.tbxVuotDinhMuc.Location = new System.Drawing.Point(171, 118);
            this.tbxVuotDinhMuc.Name = "tbxVuotDinhMuc";
            this.tbxVuotDinhMuc.Size = new System.Drawing.Size(125, 20);
            this.tbxVuotDinhMuc.TabIndex = 8;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(17, 117);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(102, 18);
            this.label5.TabIndex = 7;
            this.label5.Text = "Vượt định mức";
            // 
            // tbxTienVuotDinhMuc
            // 
            this.tbxTienVuotDinhMuc.Location = new System.Drawing.Point(171, 169);
            this.tbxTienVuotDinhMuc.Name = "tbxTienVuotDinhMuc";
            this.tbxTienVuotDinhMuc.Size = new System.Drawing.Size(125, 20);
            this.tbxTienVuotDinhMuc.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(17, 168);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(132, 18);
            this.label6.TabIndex = 9;
            this.label6.Text = "Tiền vượt đinh mức";
            // 
            // tbxTongTien
            // 
            this.tbxTongTien.Location = new System.Drawing.Point(171, 212);
            this.tbxTongTien.Name = "tbxTongTien";
            this.tbxTongTien.Size = new System.Drawing.Size(125, 20);
            this.tbxTongTien.TabIndex = 12;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(17, 211);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(76, 18);
            this.label7.TabIndex = 11;
            this.label7.Text = "Thành tiền";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(735, 294);
            this.Controls.Add(this.pnlKetQua);
            this.Controls.Add(this.pnlTinhTienDien);
            this.Name = "Form1";
            this.Text = "Tính Tiền Điện";
            this.pnlTinhTienDien.ResumeLayout(false);
            this.pnlTinhTienDien.PerformLayout();
            this.pnlKetQua.ResumeLayout(false);
            this.pnlKetQua.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlTinhTienDien;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbxDienMoi;
        private System.Windows.Forms.TextBox tbxDienCu;
        private System.Windows.Forms.Button btnHuyBo;
        private System.Windows.Forms.Button btnTinhTien;
        private System.Windows.Forms.Panel pnlKetQua;
        private System.Windows.Forms.TextBox tbxDienTieuThu;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbxTienVuotDinhMuc;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox tbxVuotDinhMuc;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox tbxPhiThueBao;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox tbxTongTien;
        private System.Windows.Forms.Label label7;

    }
}

