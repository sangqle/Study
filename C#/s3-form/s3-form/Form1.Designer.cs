namespace s3_form
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
            this.login = new System.Windows.Forms.Button();
            this.clear = new System.Windows.Forms.Button();
            this.cancel = new System.Windows.Forms.Button();
            this.savePass = new System.Windows.Forms.CheckBox();
            this.userNameInput = new System.Windows.Forms.TextBox();
            this.passwordInput = new System.Windows.Forms.TextBox();
            this.userName = new System.Windows.Forms.Label();
            this.password = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // login
            // 
            this.login.Location = new System.Drawing.Point(154, 173);
            this.login.Name = "login";
            this.login.Size = new System.Drawing.Size(89, 28);
            this.login.TabIndex = 0;
            this.login.Text = "Login";
            this.login.UseVisualStyleBackColor = true;
            this.login.Click += new System.EventHandler(this.button1_Click);
            // 
            // clear
            // 
            this.clear.Location = new System.Drawing.Point(249, 173);
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(89, 28);
            this.clear.TabIndex = 1;
            this.clear.Text = "Clear";
            this.clear.UseVisualStyleBackColor = true;
            this.clear.Click += new System.EventHandler(this.button2_Click);
            // 
            // cancel
            // 
            this.cancel.Location = new System.Drawing.Point(344, 173);
            this.cancel.Name = "cancel";
            this.cancel.Size = new System.Drawing.Size(89, 28);
            this.cancel.TabIndex = 2;
            this.cancel.Text = "Cancel";
            this.cancel.UseVisualStyleBackColor = true;
            this.cancel.Click += new System.EventHandler(this.button3_Click);
            // 
            // savePass
            // 
            this.savePass.AutoSize = true;
            this.savePass.Location = new System.Drawing.Point(121, 134);
            this.savePass.Name = "savePass";
            this.savePass.Size = new System.Drawing.Size(77, 17);
            this.savePass.TabIndex = 3;
            this.savePass.Text = "Remember";
            this.savePass.UseVisualStyleBackColor = true;
            this.savePass.CheckedChanged += new System.EventHandler(this.savePass_CheckedChanged);
            // 
            // userNameInput
            // 
            this.userNameInput.Location = new System.Drawing.Point(217, 38);
            this.userNameInput.Name = "userNameInput";
            this.userNameInput.Size = new System.Drawing.Size(195, 20);
            this.userNameInput.TabIndex = 4;
            this.userNameInput.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // passwordInput
            // 
            this.passwordInput.Location = new System.Drawing.Point(217, 84);
            this.passwordInput.Name = "passwordInput";
            this.passwordInput.Size = new System.Drawing.Size(195, 20);
            this.passwordInput.TabIndex = 5;
            this.passwordInput.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // userName
            // 
            this.userName.AutoSize = true;
            this.userName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.userName.Location = new System.Drawing.Point(111, 38);
            this.userName.Name = "userName";
            this.userName.Size = new System.Drawing.Size(69, 13);
            this.userName.TabIndex = 6;
            this.userName.Text = "User Name";
            this.userName.Click += new System.EventHandler(this.label1_Click);
            // 
            // password
            // 
            this.password.AutoSize = true;
            this.password.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.password.Location = new System.Drawing.Point(118, 91);
            this.password.Name = "password";
            this.password.Size = new System.Drawing.Size(61, 13);
            this.password.TabIndex = 7;
            this.password.Text = "Password";
            this.password.Click += new System.EventHandler(this.label2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(567, 256);
            this.Controls.Add(this.password);
            this.Controls.Add(this.userName);
            this.Controls.Add(this.passwordInput);
            this.Controls.Add(this.userNameInput);
            this.Controls.Add(this.savePass);
            this.Controls.Add(this.cancel);
            this.Controls.Add(this.clear);
            this.Controls.Add(this.login);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button login;
        private System.Windows.Forms.Button clear;
        private System.Windows.Forms.Button cancel;
        private System.Windows.Forms.CheckBox savePass;
        private System.Windows.Forms.TextBox userNameInput;
        private System.Windows.Forms.TextBox passwordInput;
        private System.Windows.Forms.Label userName;
        private System.Windows.Forms.Label password;
    }
}

