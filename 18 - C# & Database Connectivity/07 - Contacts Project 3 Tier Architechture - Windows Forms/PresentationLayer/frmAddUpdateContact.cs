using BusinessLayer;
using System;
using System.Data;
using System.Diagnostics.Contracts;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace PresentationLayer
{
    public partial class frmAddUpdateContact : Form
    {

        int _contactID;
        Contact _contact;
        
        enum enMode { AddNew = 0, Update = 1 }
        enMode _Mode = enMode.AddNew;

        public frmAddUpdateContact(int contactID)
        {
            InitializeComponent();

            _contactID = contactID;

            if (_contactID == -1)
                _Mode = enMode.AddNew;
            else
                _Mode = enMode.Update;
        }

        private void frmAddUpdateContact_Load(object sender, EventArgs e)
        {
            _LoadContactData();
        }

        private void _LoadCountriesCombobox()
        {
            DataTable dt = Country.ListAllCountries();

            foreach (DataRow dr in dt.Rows)
                cbCountry.Items.Add(dr["CountryName"]);
        }

        private void _LoadContactData()
        {
            _LoadCountriesCombobox();
            cbCountry.SelectedIndex = 0; // default
            
            if (_contactID == -1)
            {
                _contact = new Contact();
                lblFormMode.Text = "Add new Contact";
                return;
            }

            _contact = Contact.Find(_contactID);

            if (_contact == null)
            {
                MessageBox.Show($"This form will be closed because there's no Contact with ID = {_contactID}");
                this.Close();
                return;
            }

            lblFormMode.Text = $"Edit contact id = {_contactID}";
            lblContactID.Text = _contact.ID.ToString();
            tbFirstName.Text = _contact.FirstName;
            tbLastName.Text = _contact.LastName;
            tbEmail.Text = _contact.Email;
            tbPhone.Text = _contact.Phone;
            dtpDateOfBirth.Value = _contact.DateOfBirth;
            tbAddress.Text = _contact.Address;

            if (!string.IsNullOrWhiteSpace(_contact.ImagePath) && File.Exists(_contact.ImagePath))
            {
                llRemoveImage.Visible = true;
                pbContact.Image = Image.FromFile(_contact.ImagePath);
            }
            else
                llRemoveImage.Visible = false;

            cbCountry.SelectedIndex = cbCountry.FindString(Country.FindByID(_contact.CountryID).CountryName);
        }

        private void llSetImage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            
            dialogSetImage.InitialDirectory = @"E:\Photos";
            dialogSetImage.Title = "Choose an Image";

            dialogSetImage.DefaultExt = "png";
            dialogSetImage.Filter = "Image Files|*.jpg;*.jpeg;*.png;";

            if (dialogSetImage.ShowDialog() == DialogResult.OK)
            {
                pbContact.Image = Image.FromFile(dialogSetImage.FileName);
                _contact.ImagePath = dialogSetImage.FileName;
                llRemoveImage.Visible = true;
            }
        }
        
        private void llRemoveImage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            pbContact.Image = null;
            _contact.ImagePath = null;
            llRemoveImage.Visible = false;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            _contact.FirstName = tbFirstName.Text;
            _contact.LastName = tbLastName.Text;
            _contact.Email = tbEmail.Text;
            _contact.Phone = tbPhone.Text;
            _contact.DateOfBirth = dtpDateOfBirth.Value;
            _contact.Address = tbAddress.Text;
            _contact.CountryID = Country.FindByName(cbCountry.SelectedItem.ToString()).CountryID;

            if (_contact.Save())
                MessageBox.Show("Updated Successfully!");
            else
                MessageBox.Show("Failed!");

            _Mode = enMode.Update;
            lblFormMode.Text = "Edit Contact ID = " + _contact.ID;
            lblContactID.Text = _contact.ID.ToString();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
