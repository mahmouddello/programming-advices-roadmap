using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _23___ListView_Control
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(IDTextBox.Text) || string.IsNullOrWhiteSpace(NameTextBox.Text))
            {
                MessageBox.Show("ID or Name not filled correctly!");
                return;
            }

            ListViewItem item = new ListViewItem(IDTextBox.Text);
            item.SubItems.Add(NameTextBox.Text.Trim());
            item.ImageIndex = 0;

            listView1.Items.Add(item);

            IDTextBox.Clear();
            NameTextBox.Clear();
            IDTextBox.Focus();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listView1.View = View.Details;
            RBDetails.Checked = true;
        }

        private void ControlListView(object sender, EventArgs e)
        {
            RadioButton currentButton = (RadioButton)sender;

            switch (currentButton.Tag.ToString())
            {
                case "Details":
                    listView1.View = View.Details;
                    break;

                case "LargeIcon":
                    listView1.View = View.LargeIcon;
                    break;

                case "SmallIcon":
                    listView1.View = View.SmallIcon;
                    break;

                case "List":
                    listView1.View = View.List;
                    break;

                case "Tile":
                    listView1.View = View.Tile;
                    break;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int lastID = 1;

            if (listView1.Items.Count > 0)
            {
                ListViewItem lastItem = listView1.Items[listView1.Items.Count - 1];
                lastID = int.Parse(lastItem.SubItems[0].Text);
            }

            for (int i = lastID; i < lastID + 10; i++)
            {
                ListViewItem item = new ListViewItem(i.ToString());
                item.SubItems.Add("Person"+i);
                item.ImageIndex = 0;

                listView1.Items.Add(item);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listView1.Items.Count > 0)
                listView1.SelectedItems[0].Remove();
        }
    }
}
