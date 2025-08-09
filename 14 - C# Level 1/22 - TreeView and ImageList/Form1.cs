using System;
using System.Windows.Forms;

namespace _22___TreeView_and_ImageList
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            this.CheckTreeViewNode(e.Node);
        }

        private void CheckTreeViewNode(TreeNode node)
        {
            foreach (TreeNode childNode in node.Nodes)
            {
                childNode.Checked = node.Checked;

                if (childNode.Nodes.Count > 0)
                    this.CheckTreeViewNode(childNode);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            treeView1.Nodes.Add("Hamdi");
        }

        private void treeView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show(treeView1.SelectedNode.Text);
        }

        private void treeView1_AfterCollapse(object sender, TreeViewEventArgs e)
        {

        }

        private void treeView1_AfterCheck(object sender, TreeViewEventArgs e)
        {
            this.CheckTreeViewNode(e.Node);

        }
    }
}
