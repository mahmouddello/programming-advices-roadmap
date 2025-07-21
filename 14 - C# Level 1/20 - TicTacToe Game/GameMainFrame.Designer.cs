namespace _20___TicTacToe_Game
{
    partial class GameMainFrame
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GameMainFrame));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.BtnRestartGame = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.BoardPosition1 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.BoardPosition4 = new System.Windows.Forms.PictureBox();
            this.BoardPosition5 = new System.Windows.Forms.PictureBox();
            this.BoardPosition9 = new System.Windows.Forms.PictureBox();
            this.BoardPosition6 = new System.Windows.Forms.PictureBox();
            this.BoardPosition3 = new System.Windows.Forms.PictureBox();
            this.BoardPosition2 = new System.Windows.Forms.PictureBox();
            this.BoardPosition8 = new System.Windows.Forms.PictureBox();
            this.BoardPosition7 = new System.Windows.Forms.PictureBox();
            this.LblPlayerTurn = new System.Windows.Forms.Label();
            this.LblGameWinner = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition7)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Rubik Dirt", 20F);
            this.label1.ForeColor = System.Drawing.Color.Orange;
            this.label1.Location = new System.Drawing.Point(45, 258);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(106, 48);
            this.label1.TabIndex = 1;
            this.label1.Text = "Turn";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Rubik Dirt", 20F);
            this.label2.ForeColor = System.Drawing.Color.GreenYellow;
            this.label2.Location = new System.Drawing.Point(45, 411);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(147, 48);
            this.label2.TabIndex = 2;
            this.label2.Text = "Winner";
            // 
            // BtnRestartGame
            // 
            this.BtnRestartGame.BackColor = System.Drawing.Color.Black;
            this.BtnRestartGame.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.BtnRestartGame.Font = new System.Drawing.Font("Rubik Dirt", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BtnRestartGame.ForeColor = System.Drawing.Color.Red;
            this.BtnRestartGame.Location = new System.Drawing.Point(27, 572);
            this.BtnRestartGame.Name = "BtnRestartGame";
            this.BtnRestartGame.Size = new System.Drawing.Size(230, 76);
            this.BtnRestartGame.TabIndex = 3;
            this.BtnRestartGame.Text = "Restart Game";
            this.BtnRestartGame.UseVisualStyleBackColor = false;
            this.BtnRestartGame.Click += new System.EventHandler(this.BtnRestartGame_Click);
            this.BtnRestartGame.MouseLeave += new System.EventHandler(this.BtnRestartGame_MouseLeave);
            this.BtnRestartGame.MouseHover += new System.EventHandler(this.BtnRestartGame_MouseHover);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Rubik Dirt", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.DodgerBlue;
            this.label3.Location = new System.Drawing.Point(424, 25);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(364, 52);
            this.label3.TabIndex = 4;
            this.label3.Text = "Tic-Tac-Toe Game";
            // 
            // BoardPosition1
            // 
            this.BoardPosition1.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition1.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition1.Location = new System.Drawing.Point(340, 150);
            this.BoardPosition1.Name = "BoardPosition1";
            this.BoardPosition1.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition1.TabIndex = 5;
            this.BoardPosition1.TabStop = false;
            this.BoardPosition1.Tag = "1";
            this.BoardPosition1.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition1.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition1.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::_20___TicTacToe_Game.Properties.Resources.tic_tac_toe_logo;
            this.pictureBox1.Location = new System.Drawing.Point(53, 53);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(204, 143);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Tag = "MainPic";
            // 
            // BoardPosition4
            // 
            this.BoardPosition4.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition4.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition4.Location = new System.Drawing.Point(340, 337);
            this.BoardPosition4.Name = "BoardPosition4";
            this.BoardPosition4.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition4.TabIndex = 6;
            this.BoardPosition4.TabStop = false;
            this.BoardPosition4.Tag = "4";
            this.BoardPosition4.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition4.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition4.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition5
            // 
            this.BoardPosition5.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition5.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition5.Location = new System.Drawing.Point(571, 338);
            this.BoardPosition5.Name = "BoardPosition5";
            this.BoardPosition5.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition5.TabIndex = 7;
            this.BoardPosition5.TabStop = false;
            this.BoardPosition5.Tag = "5";
            this.BoardPosition5.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition5.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition5.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition9
            // 
            this.BoardPosition9.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition9.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition9.Location = new System.Drawing.Point(802, 526);
            this.BoardPosition9.Name = "BoardPosition9";
            this.BoardPosition9.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition9.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition9.TabIndex = 8;
            this.BoardPosition9.TabStop = false;
            this.BoardPosition9.Tag = "9";
            this.BoardPosition9.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition9.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition9.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition6
            // 
            this.BoardPosition6.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition6.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition6.Location = new System.Drawing.Point(802, 338);
            this.BoardPosition6.Name = "BoardPosition6";
            this.BoardPosition6.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition6.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition6.TabIndex = 9;
            this.BoardPosition6.TabStop = false;
            this.BoardPosition6.Tag = "6";
            this.BoardPosition6.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition6.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition6.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition3
            // 
            this.BoardPosition3.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition3.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition3.Location = new System.Drawing.Point(802, 150);
            this.BoardPosition3.Name = "BoardPosition3";
            this.BoardPosition3.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition3.TabIndex = 10;
            this.BoardPosition3.TabStop = false;
            this.BoardPosition3.Tag = "3";
            this.BoardPosition3.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition3.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition3.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition2
            // 
            this.BoardPosition2.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition2.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition2.Location = new System.Drawing.Point(571, 150);
            this.BoardPosition2.Name = "BoardPosition2";
            this.BoardPosition2.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition2.TabIndex = 11;
            this.BoardPosition2.TabStop = false;
            this.BoardPosition2.Tag = "2";
            this.BoardPosition2.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition2.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition2.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition8
            // 
            this.BoardPosition8.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition8.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition8.Location = new System.Drawing.Point(571, 526);
            this.BoardPosition8.Name = "BoardPosition8";
            this.BoardPosition8.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition8.TabIndex = 12;
            this.BoardPosition8.TabStop = false;
            this.BoardPosition8.Tag = "8";
            this.BoardPosition8.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition8.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition8.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // BoardPosition7
            // 
            this.BoardPosition7.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.BoardPosition7.Image = global::_20___TicTacToe_Game.Properties.Resources.QuestionMark;
            this.BoardPosition7.Location = new System.Drawing.Point(340, 524);
            this.BoardPosition7.Name = "BoardPosition7";
            this.BoardPosition7.Size = new System.Drawing.Size(144, 122);
            this.BoardPosition7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.BoardPosition7.TabIndex = 13;
            this.BoardPosition7.TabStop = false;
            this.BoardPosition7.Tag = "7";
            this.BoardPosition7.Click += new System.EventHandler(this.PictureBox_Click);
            this.BoardPosition7.MouseEnter += new System.EventHandler(this.PictureBox_MouseEnter);
            this.BoardPosition7.MouseLeave += new System.EventHandler(this.PictureBox_MouseLeave);
            // 
            // LblPlayerTurn
            // 
            this.LblPlayerTurn.AutoSize = true;
            this.LblPlayerTurn.Font = new System.Drawing.Font("Rubik Dirt", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblPlayerTurn.ForeColor = System.Drawing.Color.Orange;
            this.LblPlayerTurn.Location = new System.Drawing.Point(44, 322);
            this.LblPlayerTurn.Name = "LblPlayerTurn";
            this.LblPlayerTurn.Size = new System.Drawing.Size(260, 52);
            this.LblPlayerTurn.TabIndex = 14;
            this.LblPlayerTurn.Text = "PlaceHolder";
            // 
            // LblGameWinner
            // 
            this.LblGameWinner.AutoSize = true;
            this.LblGameWinner.Font = new System.Drawing.Font("Rubik Dirt", 20F);
            this.LblGameWinner.ForeColor = System.Drawing.Color.GreenYellow;
            this.LblGameWinner.Location = new System.Drawing.Point(45, 471);
            this.LblGameWinner.Name = "LblGameWinner";
            this.LblGameWinner.Size = new System.Drawing.Size(238, 48);
            this.LblGameWinner.TabIndex = 15;
            this.LblGameWinner.Text = "PlaceHolder";
            // 
            // GameMainFrame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(120F, 120F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(982, 753);
            this.Controls.Add(this.LblGameWinner);
            this.Controls.Add(this.LblPlayerTurn);
            this.Controls.Add(this.BoardPosition7);
            this.Controls.Add(this.BoardPosition8);
            this.Controls.Add(this.BoardPosition2);
            this.Controls.Add(this.BoardPosition3);
            this.Controls.Add(this.BoardPosition6);
            this.Controls.Add(this.BoardPosition9);
            this.Controls.Add(this.BoardPosition5);
            this.Controls.Add(this.BoardPosition4);
            this.Controls.Add(this.BoardPosition1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.BtnRestartGame);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.ForeColor = System.Drawing.Color.Black;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "GameMainFrame";
            this.Text = "Tic-Tac-Toe";
            this.Load += new System.EventHandler(this.GameMainFrame_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.GameMainFrame_Paint);
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BoardPosition7)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button BtnRestartGame;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.PictureBox BoardPosition1;
        private System.Windows.Forms.PictureBox BoardPosition4;
        private System.Windows.Forms.PictureBox BoardPosition5;
        private System.Windows.Forms.PictureBox BoardPosition9;
        private System.Windows.Forms.PictureBox BoardPosition6;
        private System.Windows.Forms.PictureBox BoardPosition3;
        private System.Windows.Forms.PictureBox BoardPosition2;
        private System.Windows.Forms.PictureBox BoardPosition8;
        private System.Windows.Forms.PictureBox BoardPosition7;
        private System.Windows.Forms.Label LblPlayerTurn;
        private System.Windows.Forms.Label LblGameWinner;
    }
}

