using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _17___PizzaMaker_App
{
    public partial class PizzaMaker : Form
    {
        public PizzaMaker()
        {
            InitializeComponent();
            rbSmall.Checked = true;
            rbThin.Checked = true;
            rbEatIn.Checked = true;
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
            {
                LblSizeResult.Text = rbSmall.Text;
                return;
            }

            if (rbMedium.Checked)
            {
                LblSizeResult.Text = rbMedium.Text;
                return;
            }

            if (rbLarge.Checked)
            {
                LblSizeResult.Text = rbLarge.Text;
                return;
            }
        }

        void UpdateCrustType()
        {
            UpdateTotalPrice();

            if (rbThin.Checked)
            {
                LblCrustResult.Text = rbThin.Text;
                return;
            }

            if (rbThick.Checked)
            {
                LblCrustResult.Text = rbThick.Text;
                return;
            }
        }

        void UpdateWhereToEat()
        {
            if (rbEatIn.Checked)
            {
                LblWTEResult.Text = rbEatIn.Text;
                return;
            }

            if (rbTakeout.Checked)
            {
                LblWTEResult.Text = rbTakeout.Text;
                return;
            }
        }

        void UpdateToppings()
        {
            UpdateTotalPrice();
            
            string Toppings = "";

            if (ChkExtraCheese.Checked)
                Toppings += ChkExtraCheese.Text;

            if (ChkOnion.Checked)
                Toppings += ", " + ChkOnion.Text;

            if (ChkMushrooms.Checked)
                Toppings += ", " + ChkMushrooms.Text;

            if (ChkOlives.Checked)
                Toppings += ", " + ChkOlives.Text;

            if (ChkTomatoes.Checked)
                Toppings += ", " + ChkTomatoes.Text;

            if (ChkGreenPeppers.Checked)
                Toppings += ", " + ChkGreenPeppers.Text;

            // removes extra comma at beginning
            if (Toppings.StartsWith(","))
                Toppings = Toppings.Substring(1, Toppings.Length - 1).Trim();

            if (Toppings == "")
                Toppings = "No Toppings";

            LblToppingsResult.Text = Toppings;
        }

        float GetSelectedSizePrice()
        {
            if (rbSmall.Checked)
                return Convert.ToSingle(rbSmall.Tag);

            else if (rbMedium.Checked)
                return Convert.ToSingle(rbMedium.Tag);

            else
                return Convert.ToSingle(rbLarge.Tag);
        }

        float GetSelectedCrustPrice()
        {
            if (rbThin.Checked)
                return Convert.ToSingle(rbThin.Tag);

            return Convert.ToSingle(rbThick.Tag);
        }

        void UpdateTotalPrice()
        {
            LblTotalPrice.Text = "$" + CalculateTotalPrice().ToString(); 
        }

        float CalculateToppingsPrice()
        {
            float ToppingTotalPrice = 0;

            if (ChkExtraCheese.Checked)
                ToppingTotalPrice += Convert.ToSingle(ChkExtraCheese.Tag);

            if (ChkOnion.Checked)
                ToppingTotalPrice += Convert.ToSingle(ChkOnion.Tag);

            if (ChkMushrooms.Checked)
                ToppingTotalPrice += Convert.ToSingle(ChkMushrooms.Tag);

            if (ChkOlives.Checked)
                ToppingTotalPrice += Convert.ToSingle(ChkOlives.Tag);

            if (ChkTomatoes.Checked)
                ToppingTotalPrice += Convert.ToSingle(ChkTomatoes.Tag);

            if (ChkGreenPeppers.Checked)
                ToppingTotalPrice += Convert.ToSingle(ChkGreenPeppers.Tag);

            return ToppingTotalPrice;
        }

        float CalculateTotalPrice()
        {
            return GetSelectedSizePrice() + CalculateToppingsPrice() + GetSelectedCrustPrice();
        }

        private void GbPizzaSize_Enter(object sender, EventArgs e)
        {

        }

        private void GbCrust_Enter(object sender, EventArgs e)
        {

        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbThin_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
        }

        private void rbThick_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void rbTakeout_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void BtnOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm your order to proceed", "Order", MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                MessageBox.Show("Order placed successfully!");
                GbPizzaSize.Enabled = false;
                GbCrust.Enabled = false;
                GbToppings.Enabled = false;
                GbWhereToEat.Enabled = false;
                BtnOrderPizza.Enabled = false;
            }
        }

        private void ChkExtraCheese_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ChkOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ChkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ChkOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ChkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ChkGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void LblTotalPrice_Click(object sender, EventArgs e)
        {

        }

        private void BtnResetForm_Click(object sender, EventArgs e)
        {
            GbPizzaSize.Enabled = true;
            rbSmall.Checked = true;

            GbCrust.Enabled = true;
            rbThin.Checked = true;

            // Toppings
            GbToppings.Enabled = true;
            ChkExtraCheese.Checked = false;
            ChkOnion.Checked = false;
            ChkMushrooms.Checked = false;
            ChkOlives.Checked = false;
            ChkTomatoes.Checked = false;
            ChkGreenPeppers.Checked = false;

            // Where to eat
            GbWhereToEat.Enabled = true;
            rbEatIn.Checked = true;

            MessageBox.Show("Form reset successfully", "Reset", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
    }
}
