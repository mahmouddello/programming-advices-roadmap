using System;
using System.Windows.Forms;

namespace _16___First_Windows_Forms_Project
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void btnShowForm1_Click(object sender, EventArgs e)
        {
            Form form1 = new Form1();
            form1.Show();
        }

        private void btnShowFormDialo_Click(object sender, EventArgs e)
        {
            Form form1 = new Form1();
            form1.ShowDialog();
        }

        private void btnShowDialogForm_Click(object sender, EventArgs e)
        {
            Form f = new DialogsForm();
            f.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm = new frmChkRadioGroup();
            frm.ShowDialog();
        }

        private void ShowMoreAboutTextboxForm_Click(object sender, EventArgs e)
        {
            Form form = new MoreAboutTextBox();
            form.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new MaskedTextboxForm();
            form.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form form = new ComboBoxForm();
            form.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form form = new LinkLabelForm();
            form.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form form = new CheckedListBoxForm();
            form.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form form = new DateTimePickerForm();
            form.ShowDialog();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Form form = new MonthCalendarForm();
            form.ShowDialog();
        }
    }
}
