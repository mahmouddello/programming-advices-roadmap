namespace _17___PizzaMaker_App
{
    partial class PizzaMaker
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
            this.label1 = new System.Windows.Forms.Label();
            this.GbPizzaSize = new System.Windows.Forms.GroupBox();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.rbMedium = new System.Windows.Forms.RadioButton();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.GbCrust = new System.Windows.Forms.GroupBox();
            this.rbThick = new System.Windows.Forms.RadioButton();
            this.rbThin = new System.Windows.Forms.RadioButton();
            this.GbToppings = new System.Windows.Forms.GroupBox();
            this.ChkGreenPeppers = new System.Windows.Forms.CheckBox();
            this.ChkTomatoes = new System.Windows.Forms.CheckBox();
            this.ChkOnion = new System.Windows.Forms.CheckBox();
            this.ChkOlives = new System.Windows.Forms.CheckBox();
            this.ChkMushrooms = new System.Windows.Forms.CheckBox();
            this.ChkExtraCheese = new System.Windows.Forms.CheckBox();
            this.GbWhereToEat = new System.Windows.Forms.GroupBox();
            this.rbTakeout = new System.Windows.Forms.RadioButton();
            this.rbEatIn = new System.Windows.Forms.RadioButton();
            this.LblOrderSummary = new System.Windows.Forms.Label();
            this.LblSize = new System.Windows.Forms.Label();
            this.LblCrust = new System.Windows.Forms.Label();
            this.LblWhereToEat = new System.Windows.Forms.Label();
            this.LblToppings = new System.Windows.Forms.Label();
            this.LblSizeResult = new System.Windows.Forms.Label();
            this.LblCrustResult = new System.Windows.Forms.Label();
            this.LblWTEResult = new System.Windows.Forms.Label();
            this.LblToppingsResult = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.BtnOrderPizza = new System.Windows.Forms.Button();
            this.LblTotalPrice = new System.Windows.Forms.Label();
            this.BtnResetForm = new System.Windows.Forms.Button();
            this.GbPizzaSize.SuspendLayout();
            this.GbCrust.SuspendLayout();
            this.GbToppings.SuspendLayout();
            this.GbWhereToEat.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Palatino Linotype", 36F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Crimson;
            this.label1.Location = new System.Drawing.Point(412, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(452, 82);
            this.label1.TabIndex = 0;
            this.label1.Text = "Make Your Pizza";
            // 
            // GbPizzaSize
            // 
            this.GbPizzaSize.Controls.Add(this.rbLarge);
            this.GbPizzaSize.Controls.Add(this.rbMedium);
            this.GbPizzaSize.Controls.Add(this.rbSmall);
            this.GbPizzaSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GbPizzaSize.Location = new System.Drawing.Point(64, 134);
            this.GbPizzaSize.Name = "GbPizzaSize";
            this.GbPizzaSize.Size = new System.Drawing.Size(313, 226);
            this.GbPizzaSize.TabIndex = 1;
            this.GbPizzaSize.TabStop = false;
            this.GbPizzaSize.Text = "Size";
            this.GbPizzaSize.Enter += new System.EventHandler(this.GbPizzaSize_Enter);
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Location = new System.Drawing.Point(47, 160);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(73, 24);
            this.rbLarge.TabIndex = 2;
            this.rbLarge.TabStop = true;
            this.rbLarge.Tag = "30";
            this.rbLarge.Text = "Large";
            this.rbLarge.UseVisualStyleBackColor = true;
            this.rbLarge.CheckedChanged += new System.EventHandler(this.rbLarge_CheckedChanged);
            // 
            // rbMedium
            // 
            this.rbMedium.AutoSize = true;
            this.rbMedium.Location = new System.Drawing.Point(47, 105);
            this.rbMedium.Name = "rbMedium";
            this.rbMedium.Size = new System.Drawing.Size(89, 24);
            this.rbMedium.TabIndex = 1;
            this.rbMedium.TabStop = true;
            this.rbMedium.Tag = "25";
            this.rbMedium.Text = "Medium";
            this.rbMedium.UseVisualStyleBackColor = true;
            this.rbMedium.CheckedChanged += new System.EventHandler(this.rbMedium_CheckedChanged);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Location = new System.Drawing.Point(47, 50);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(72, 24);
            this.rbSmall.TabIndex = 0;
            this.rbSmall.TabStop = true;
            this.rbSmall.Tag = "20";
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            this.rbSmall.CheckedChanged += new System.EventHandler(this.rbSmall_CheckedChanged);
            // 
            // GbCrust
            // 
            this.GbCrust.Controls.Add(this.rbThick);
            this.GbCrust.Controls.Add(this.rbThin);
            this.GbCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GbCrust.Location = new System.Drawing.Point(64, 400);
            this.GbCrust.Name = "GbCrust";
            this.GbCrust.Size = new System.Drawing.Size(259, 164);
            this.GbCrust.TabIndex = 3;
            this.GbCrust.TabStop = false;
            this.GbCrust.Text = "Crust";
            this.GbCrust.Enter += new System.EventHandler(this.GbCrust_Enter);
            // 
            // rbThick
            // 
            this.rbThick.AutoSize = true;
            this.rbThick.Location = new System.Drawing.Point(47, 105);
            this.rbThick.Name = "rbThick";
            this.rbThick.Size = new System.Drawing.Size(70, 24);
            this.rbThick.TabIndex = 1;
            this.rbThick.Tag = "10";
            this.rbThick.Text = "Thick";
            this.rbThick.UseVisualStyleBackColor = true;
            this.rbThick.CheckedChanged += new System.EventHandler(this.rbThick_CheckedChanged);
            // 
            // rbThin
            // 
            this.rbThin.AutoSize = true;
            this.rbThin.Location = new System.Drawing.Point(47, 50);
            this.rbThin.Name = "rbThin";
            this.rbThin.Size = new System.Drawing.Size(62, 24);
            this.rbThin.TabIndex = 0;
            this.rbThin.Tag = "0";
            this.rbThin.Text = "Thin";
            this.rbThin.UseVisualStyleBackColor = true;
            this.rbThin.CheckedChanged += new System.EventHandler(this.rbThin_CheckedChanged);
            // 
            // GbToppings
            // 
            this.GbToppings.Controls.Add(this.ChkGreenPeppers);
            this.GbToppings.Controls.Add(this.ChkTomatoes);
            this.GbToppings.Controls.Add(this.ChkOnion);
            this.GbToppings.Controls.Add(this.ChkOlives);
            this.GbToppings.Controls.Add(this.ChkMushrooms);
            this.GbToppings.Controls.Add(this.ChkExtraCheese);
            this.GbToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GbToppings.Location = new System.Drawing.Point(462, 134);
            this.GbToppings.Name = "GbToppings";
            this.GbToppings.Size = new System.Drawing.Size(330, 226);
            this.GbToppings.TabIndex = 4;
            this.GbToppings.TabStop = false;
            this.GbToppings.Text = "Toppings";
            // 
            // ChkGreenPeppers
            // 
            this.ChkGreenPeppers.AutoSize = true;
            this.ChkGreenPeppers.Location = new System.Drawing.Point(174, 159);
            this.ChkGreenPeppers.Name = "ChkGreenPeppers";
            this.ChkGreenPeppers.Size = new System.Drawing.Size(144, 24);
            this.ChkGreenPeppers.TabIndex = 6;
            this.ChkGreenPeppers.Tag = "5";
            this.ChkGreenPeppers.Text = "Green Peppers";
            this.ChkGreenPeppers.UseVisualStyleBackColor = true;
            this.ChkGreenPeppers.CheckedChanged += new System.EventHandler(this.ChkGreenPeppers_CheckedChanged);
            // 
            // ChkTomatoes
            // 
            this.ChkTomatoes.AutoSize = true;
            this.ChkTomatoes.Location = new System.Drawing.Point(30, 159);
            this.ChkTomatoes.Name = "ChkTomatoes";
            this.ChkTomatoes.Size = new System.Drawing.Size(105, 24);
            this.ChkTomatoes.TabIndex = 5;
            this.ChkTomatoes.Tag = "5";
            this.ChkTomatoes.Text = "Tomatoes";
            this.ChkTomatoes.UseVisualStyleBackColor = true;
            this.ChkTomatoes.CheckedChanged += new System.EventHandler(this.ChkTomatoes_CheckedChanged);
            // 
            // ChkOnion
            // 
            this.ChkOnion.AutoSize = true;
            this.ChkOnion.Location = new System.Drawing.Point(174, 49);
            this.ChkOnion.Name = "ChkOnion";
            this.ChkOnion.Size = new System.Drawing.Size(75, 24);
            this.ChkOnion.TabIndex = 3;
            this.ChkOnion.Tag = "5";
            this.ChkOnion.Text = "Onion";
            this.ChkOnion.UseVisualStyleBackColor = true;
            this.ChkOnion.CheckedChanged += new System.EventHandler(this.ChkOnion_CheckedChanged);
            // 
            // ChkOlives
            // 
            this.ChkOlives.AutoSize = true;
            this.ChkOlives.Location = new System.Drawing.Point(174, 104);
            this.ChkOlives.Name = "ChkOlives";
            this.ChkOlives.Size = new System.Drawing.Size(78, 24);
            this.ChkOlives.TabIndex = 2;
            this.ChkOlives.Tag = "5";
            this.ChkOlives.Text = "Olives";
            this.ChkOlives.UseVisualStyleBackColor = true;
            this.ChkOlives.CheckedChanged += new System.EventHandler(this.ChkOlives_CheckedChanged);
            // 
            // ChkMushrooms
            // 
            this.ChkMushrooms.AutoSize = true;
            this.ChkMushrooms.Location = new System.Drawing.Point(30, 104);
            this.ChkMushrooms.Name = "ChkMushrooms";
            this.ChkMushrooms.Size = new System.Drawing.Size(119, 24);
            this.ChkMushrooms.TabIndex = 1;
            this.ChkMushrooms.Tag = "5";
            this.ChkMushrooms.Text = "Mushrooms";
            this.ChkMushrooms.UseVisualStyleBackColor = true;
            this.ChkMushrooms.CheckedChanged += new System.EventHandler(this.ChkMushrooms_CheckedChanged);
            // 
            // ChkExtraCheese
            // 
            this.ChkExtraCheese.AutoSize = true;
            this.ChkExtraCheese.Location = new System.Drawing.Point(30, 49);
            this.ChkExtraCheese.Name = "ChkExtraCheese";
            this.ChkExtraCheese.Size = new System.Drawing.Size(132, 24);
            this.ChkExtraCheese.TabIndex = 0;
            this.ChkExtraCheese.Tag = "5";
            this.ChkExtraCheese.Text = "Extra Cheese";
            this.ChkExtraCheese.UseVisualStyleBackColor = true;
            this.ChkExtraCheese.CheckedChanged += new System.EventHandler(this.ChkExtraCheese_CheckedChanged);
            // 
            // GbWhereToEat
            // 
            this.GbWhereToEat.Controls.Add(this.rbTakeout);
            this.GbWhereToEat.Controls.Add(this.rbEatIn);
            this.GbWhereToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GbWhereToEat.Location = new System.Drawing.Point(462, 415);
            this.GbWhereToEat.Name = "GbWhereToEat";
            this.GbWhereToEat.Size = new System.Drawing.Size(229, 85);
            this.GbWhereToEat.TabIndex = 4;
            this.GbWhereToEat.TabStop = false;
            this.GbWhereToEat.Text = "Where to Eat?";
            // 
            // rbTakeout
            // 
            this.rbTakeout.AutoSize = true;
            this.rbTakeout.Location = new System.Drawing.Point(126, 50);
            this.rbTakeout.Name = "rbTakeout";
            this.rbTakeout.Size = new System.Drawing.Size(98, 24);
            this.rbTakeout.TabIndex = 1;
            this.rbTakeout.TabStop = true;
            this.rbTakeout.Text = "Take Out";
            this.rbTakeout.UseVisualStyleBackColor = true;
            this.rbTakeout.CheckedChanged += new System.EventHandler(this.rbTakeout_CheckedChanged);
            // 
            // rbEatIn
            // 
            this.rbEatIn.AutoSize = true;
            this.rbEatIn.Location = new System.Drawing.Point(22, 50);
            this.rbEatIn.Name = "rbEatIn";
            this.rbEatIn.Size = new System.Drawing.Size(73, 24);
            this.rbEatIn.TabIndex = 0;
            this.rbEatIn.TabStop = true;
            this.rbEatIn.Text = "Eat In";
            this.rbEatIn.UseVisualStyleBackColor = true;
            this.rbEatIn.CheckedChanged += new System.EventHandler(this.rbEatIn_CheckedChanged);
            // 
            // LblOrderSummary
            // 
            this.LblOrderSummary.AutoSize = true;
            this.LblOrderSummary.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblOrderSummary.Location = new System.Drawing.Point(953, 134);
            this.LblOrderSummary.Name = "LblOrderSummary";
            this.LblOrderSummary.Size = new System.Drawing.Size(128, 20);
            this.LblOrderSummary.TabIndex = 5;
            this.LblOrderSummary.Text = "Order Summary";
            // 
            // LblSize
            // 
            this.LblSize.AutoSize = true;
            this.LblSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblSize.Location = new System.Drawing.Point(953, 183);
            this.LblSize.Name = "LblSize";
            this.LblSize.Size = new System.Drawing.Size(58, 20);
            this.LblSize.TabIndex = 6;
            this.LblSize.Text = "Size: ";
            // 
            // LblCrust
            // 
            this.LblCrust.AutoSize = true;
            this.LblCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblCrust.Location = new System.Drawing.Point(953, 243);
            this.LblCrust.Name = "LblCrust";
            this.LblCrust.Size = new System.Drawing.Size(67, 20);
            this.LblCrust.TabIndex = 7;
            this.LblCrust.Text = "Crust: ";
            // 
            // LblWhereToEat
            // 
            this.LblWhereToEat.AutoSize = true;
            this.LblWhereToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblWhereToEat.Location = new System.Drawing.Point(953, 415);
            this.LblWhereToEat.Name = "LblWhereToEat";
            this.LblWhereToEat.Size = new System.Drawing.Size(131, 20);
            this.LblWhereToEat.TabIndex = 8;
            this.LblWhereToEat.Text = "Where to Eat: ";
            // 
            // LblToppings
            // 
            this.LblToppings.AutoSize = true;
            this.LblToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblToppings.Location = new System.Drawing.Point(953, 297);
            this.LblToppings.Name = "LblToppings";
            this.LblToppings.Size = new System.Drawing.Size(97, 20);
            this.LblToppings.TabIndex = 9;
            this.LblToppings.Text = "Toppings: ";
            // 
            // LblSizeResult
            // 
            this.LblSizeResult.AutoSize = true;
            this.LblSizeResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblSizeResult.Location = new System.Drawing.Point(1020, 186);
            this.LblSizeResult.Name = "LblSizeResult";
            this.LblSizeResult.Size = new System.Drawing.Size(0, 20);
            this.LblSizeResult.TabIndex = 10;
            // 
            // LblCrustResult
            // 
            this.LblCrustResult.AutoSize = true;
            this.LblCrustResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblCrustResult.Location = new System.Drawing.Point(1020, 243);
            this.LblCrustResult.Name = "LblCrustResult";
            this.LblCrustResult.Size = new System.Drawing.Size(0, 20);
            this.LblCrustResult.TabIndex = 11;
            // 
            // LblWTEResult
            // 
            this.LblWTEResult.AutoSize = true;
            this.LblWTEResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblWTEResult.Location = new System.Drawing.Point(1099, 415);
            this.LblWTEResult.Name = "LblWTEResult";
            this.LblWTEResult.Size = new System.Drawing.Size(0, 20);
            this.LblWTEResult.TabIndex = 14;
            // 
            // LblToppingsResult
            // 
            this.LblToppingsResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblToppingsResult.Location = new System.Drawing.Point(953, 327);
            this.LblToppingsResult.Name = "LblToppingsResult";
            this.LblToppingsResult.Size = new System.Drawing.Size(299, 88);
            this.LblToppingsResult.TabIndex = 15;
            this.LblToppingsResult.Text = "No Toppings";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(953, 450);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 20);
            this.label2.TabIndex = 16;
            this.label2.Text = "Total Price:";
            // 
            // BtnOrderPizza
            // 
            this.BtnOrderPizza.Location = new System.Drawing.Point(426, 563);
            this.BtnOrderPizza.Name = "BtnOrderPizza";
            this.BtnOrderPizza.Size = new System.Drawing.Size(151, 56);
            this.BtnOrderPizza.TabIndex = 19;
            this.BtnOrderPizza.Text = "Order Pizza";
            this.BtnOrderPizza.UseVisualStyleBackColor = true;
            this.BtnOrderPizza.Click += new System.EventHandler(this.BtnOrderPizza_Click);
            // 
            // LblTotalPrice
            // 
            this.LblTotalPrice.AutoSize = true;
            this.LblTotalPrice.Font = new System.Drawing.Font("Verdana", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LblTotalPrice.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.LblTotalPrice.Location = new System.Drawing.Point(955, 505);
            this.LblTotalPrice.Name = "LblTotalPrice";
            this.LblTotalPrice.Size = new System.Drawing.Size(75, 73);
            this.LblTotalPrice.TabIndex = 20;
            this.LblTotalPrice.Text = "$";
            this.LblTotalPrice.Click += new System.EventHandler(this.LblTotalPrice_Click);
            // 
            // BtnResetForm
            // 
            this.BtnResetForm.Location = new System.Drawing.Point(661, 563);
            this.BtnResetForm.Name = "BtnResetForm";
            this.BtnResetForm.Size = new System.Drawing.Size(151, 56);
            this.BtnResetForm.TabIndex = 21;
            this.BtnResetForm.Text = "Reset Form";
            this.BtnResetForm.UseVisualStyleBackColor = true;
            this.BtnResetForm.Click += new System.EventHandler(this.BtnResetForm_Click);
            // 
            // PizzaMaker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1257, 686);
            this.Controls.Add(this.BtnResetForm);
            this.Controls.Add(this.LblTotalPrice);
            this.Controls.Add(this.BtnOrderPizza);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.LblToppingsResult);
            this.Controls.Add(this.LblWTEResult);
            this.Controls.Add(this.LblCrustResult);
            this.Controls.Add(this.LblSizeResult);
            this.Controls.Add(this.LblToppings);
            this.Controls.Add(this.LblWhereToEat);
            this.Controls.Add(this.LblCrust);
            this.Controls.Add(this.LblSize);
            this.Controls.Add(this.LblOrderSummary);
            this.Controls.Add(this.GbWhereToEat);
            this.Controls.Add(this.GbToppings);
            this.Controls.Add(this.GbCrust);
            this.Controls.Add(this.GbPizzaSize);
            this.Controls.Add(this.label1);
            this.Name = "PizzaMaker";
            this.Text = "Pizza Maker";
            this.GbPizzaSize.ResumeLayout(false);
            this.GbPizzaSize.PerformLayout();
            this.GbCrust.ResumeLayout(false);
            this.GbCrust.PerformLayout();
            this.GbToppings.ResumeLayout(false);
            this.GbToppings.PerformLayout();
            this.GbWhereToEat.ResumeLayout(false);
            this.GbWhereToEat.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox GbPizzaSize;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.RadioButton rbMedium;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.GroupBox GbCrust;
        private System.Windows.Forms.RadioButton rbThick;
        private System.Windows.Forms.RadioButton rbThin;
        private System.Windows.Forms.GroupBox GbToppings;
        private System.Windows.Forms.CheckBox ChkGreenPeppers;
        private System.Windows.Forms.CheckBox ChkTomatoes;
        private System.Windows.Forms.CheckBox ChkOnion;
        private System.Windows.Forms.CheckBox ChkOlives;
        private System.Windows.Forms.CheckBox ChkMushrooms;
        private System.Windows.Forms.CheckBox ChkExtraCheese;
        private System.Windows.Forms.GroupBox GbWhereToEat;
        private System.Windows.Forms.RadioButton rbTakeout;
        private System.Windows.Forms.RadioButton rbEatIn;
        private System.Windows.Forms.Label LblOrderSummary;
        private System.Windows.Forms.Label LblSize;
        private System.Windows.Forms.Label LblCrust;
        private System.Windows.Forms.Label LblWhereToEat;
        private System.Windows.Forms.Label LblToppings;
        private System.Windows.Forms.Label LblSizeResult;
        private System.Windows.Forms.Label LblCrustResult;
        private System.Windows.Forms.Label LblWTEResult;
        private System.Windows.Forms.Label LblToppingsResult;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button BtnOrderPizza;
        private System.Windows.Forms.Label LblTotalPrice;
        private System.Windows.Forms.Button BtnResetForm;
    }
}

