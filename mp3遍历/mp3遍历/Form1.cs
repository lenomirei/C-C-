using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mp3遍历
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listBox1.HorizontalScrollbar = true;
            listBox1.ScrollAlwaysVisible = true;
            listBox1.SelectionMode = SelectionMode.MultiExtended;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog folderbrowser = new FolderBrowserDialog();
            if (folderbrowser.ShowDialog() == DialogResult.OK)
            {
                textBox1.Text = folderbrowser.SelectedPath;
                DirectoryInfo dinfo = new DirectoryInfo(textBox1.Text);
                FileStreamInfo[] finfo = dinfo.GetFileSystemInfos();
                listBox1.Items.AddRange(finfo);

            }
        }
    }
}
