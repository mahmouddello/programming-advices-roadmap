using System;
using System.Windows.Forms;
using BusinessLayer;

namespace PresentationLayer
{
    public partial class frmListContacts : Form
    {
        public frmListContacts()
        {
            InitializeComponent();
        }

        private void _RefreshContactList()
        {
            dgvAllContacts.DataSource = Contact.GetAllContacts();
        }

        private void frmListContacts_Load(object sender, EventArgs e)
        {
            _RefreshContactList();
        }

        private void cmpOptions_Opening(object sender, System.ComponentModel.CancelEventArgs e)
        {

        }

        private void updateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int currentRowContactID = (int)dgvAllContacts.CurrentRow.Cells[0].Value;

            frmAddUpdateContact form = new frmAddUpdateContact(currentRowContactID);
            form.ShowDialog();

            _RefreshContactList(); // refresh contact after closing the form
        }

        private void btnAddNewContact_Click(object sender, EventArgs e)
        {
            frmAddUpdateContact form = new frmAddUpdateContact(-1);
            form.ShowDialog();

            _RefreshContactList(); // refresh contact after closing the form
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int currentRowContactID = (int)dgvAllContacts.CurrentRow.Cells[0].Value;

            if (MessageBox.Show
            (
                $"Are you sure you want to delete the contact with id {currentRowContactID} ?",
                "Confirm",
                MessageBoxButtons.OKCancel
            ) == DialogResult.OK)
            {
                if (Contact.Delete(currentRowContactID))
                {
                    MessageBox.Show("Deleted Successfully!");
                    _RefreshContactList();
                }
                else
                    MessageBox.Show("Failed!");
            }
        }
    }
}
